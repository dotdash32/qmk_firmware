# plus12 BLE

Based on https://github.com/sekigon-gonnoc/BLE-Micro-Pro.  
Their page is in Japanese, so these instructions are me redoing the process after Google MTL'd it for me.

## Setting up the build environment

These are modified with this current branch.  
It's always a good idea to pull from the most recent QMK updates from the master branch.

If you already use qmk_firmware and want to prepare another branch
    
    git remote add sekigon https://github.com/sekigon-gonnoc/qmk_firmware.git
    git fetch sekigon
    git checkout -b nrf52 sekigon/nrf52

If you already use qmk_firmware and want to put it in another folder

    git clone  -b nrf52 https://github.com/sekigon-gonnoc/qmk_firmware.git ble_micro_pro

When using for the first time

     git clone --depth 1 -b nrf52 https://github.com/sekigon-gonnoc/qmk_firmware.git

%% TODO: figure out how to pull my own branch here

We then need the [NRF5 SDK](https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/),
 which we can extract and save.

Then, we need to setup nrfutil.  

 **On Windows (TO CHECK):** Download it [here](https://github.com/NordicSemiconductor/pc-nrfutil/releases) and save it to `~ /qmk_util`.

**On Mac:** Install nrfutil with pip

    pip install nrfutil

If you get an error about `PyYAML`, you probably need to downgrade to a `pip` verion below 10.  There was a change in it handles uninstalls that breaks for some versions.  I found a workaround by downgrading `pip` and then upgrading it afterward.

    pip install pip==9.0.3
    pip install nrfutil
    pip install --upgrade pip




## Building

**NOTE:**  This requires Python2, and will error out at several points if you are using Python3.  There several functions buried pretty deep into the Nordic backend that use functions that are depreciated in Python3.  I used [pyenv](https://github.com/pyenv/pyenv) to manage versions, based on this tutorial [here](https://weknowinc.com/blog/running-multiple-python-versions-mac-osx).  Python2 is also depreciating at the start of 2020, so this might be fixed at some point.  I suspect its on Nordic's side, but that's hard to tell.

Set the SDK as an environment variable.  This will need to be re-run every time you open a new terminal instance.

    export NRFSDK15_ROOT=<path to sdk>
For example, replace `<path to sdk>` with `/Users/dotdash/nrfSDK/nRF5_SDK_15.0.0_a53641a`.  Be mindful that on Mac, when you drag and drop file locations, there can sometimes be an extra space added at the end.  Please delete that.

Now we can make the firmware!  

    make <keyboard>/<master or slave>:<keymap>:nrfutil

So in our case:

    make plus12/master:<keymap>:nrfutil
    make plus12/slave:<keymap>:nrfutil

When you see 
>Detecting USB port, put your controller into dfu-mode now

Reset the keyboard using the reset switch while its powered on or the programmed RESET key and it will flash and reboot.  Once it's done rebooting, it should be recognized as an HID keyboard.

## Split connection of Master and Slave

Pair the master and slave halves of the keyboard before pairing to a computer or other device.  This is important as the keyboard uses `id=0` as its other half, and every subsequent Bluetooth pair as a connectable device.

## Pairing with a Computer or other Device

Run `advertising_wo_whitelist()` (mapped to a key in the firmware), and then you can find the keyboard and connect on your device.

To pair with more devices, turn off Bluetooth on other paired devices and then run `advertising_wo_whitelist()` again and connect.

Once connected, you can use the command keys to pair to different ID's with `restart_advertising_id(id)`, which is again mapped to a command key in the firmware with a specific id value.  In the default firmware, these are right underneath the numbers.  `id=0` is assumed to be the other half of the keyboard, and goes up sequentially from there.