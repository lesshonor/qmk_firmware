# Minisub

![Minisub PCB in a Hull case](https://i.imgur.com/9Y6LKlQh.png)

Minisub is a [MiniVan-compatible](https://trashman.wiki/keyboards/minivan) hotswap PCB designed by community member [rainkeebs](https://www.rainkeebs.mx/)

Keyboard Maintainer: QMK Community  
Hardware Supported: [Minisub PCB](https://trashman.wiki/en/community/pcbs/minisub) (atmega32u4, atmel-dfu)
Hardware Availability: Previously sold by [Rainkeebs](https://www.rainkeebs.mx/) and P3DStore.

Make example for this keyboard (after setting up your build environment):

    make rainkeebs/minisub:default

Flashing example for this keyboard:

    make rainkeebs/minisub:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top-left key and plug in the keyboard
* **Physical reset button**:
  - Rev 1.0: Briefly short the set of holes labeled RESET. When looking at the back, they are on the right side of the PCB.
  - Rev 1.1/Rev 2: Briefly press the button labeled RESET on the back of the PCB, on the lower-right.
* **Keycode in layout**: There is no key mapped to `QK_BOOT` in the pre-created keymaps, but you may assign this key in any keymaps you create.
