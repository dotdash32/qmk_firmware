# cameldox38

![cameldox38](http://i.imgur.com/Zpoep7N.png)

A non-split way for me to test my new layout from a high school project.

* Keyboard Maintainer: [Gayley Scientific](https://github.com/dotdash32)
* Hardware Supported: Handwire only
* Hardware Availability: Laser cut (dxf's [here](https://github.com/dotdash32/Cases/tree/master/CamelDox%2038))

Make example for this keyboard (after setting up your build environment):

    qmk compile --kb cameldox32

Flashing example for this keyboard:

    qmk flash --kb cameldox32 --km <yours>

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
