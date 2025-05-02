# hamborger

![hamborger](https://cdn.discordapp.com/attachments/1140995246470205473/1367994383026229340/20250428_190432.jpg?ex=68169b8d&is=68154a0d&hm=8be27b8422405704da610455ee8e7085cdaac8bd4d4ae43f8343c22715e206d6)

A 3x10 keyboard with multiple layout options. Small enough to [take to space!](https://github.com/jeremyisyes/space-station-zmk-module)

* Keyboard Maintainer: [upset](https://github.com/jeremyisyes)
* Hardware Supported: hamborger PCB (STM32F072, stm32-dfu)
* Hardware Availability: uhhh DM upset on discord ig

Make example for this keyboard (after setting up your build environment):

    make upset/hamborger:default

Flashing example for this keyboard:

    make upset/hamborger:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard. This will also clear emulated EEPROM, so it is a good first step if the keyboard is misbehaving.
* **Physical reset button**: Hold down the BOOT button and plug the keyboard in.
* **Keycode in layout**: There is no key mapped to `QK_BOOT` in the pre-created keymaps, but you may assign this key in any keymaps you create.
