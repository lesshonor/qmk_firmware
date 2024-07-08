# vault35

![vault35](https://i.imgur.com/yw3Fvjxh.jpg)

This is a 30% HHKB or WKL-style variant of the vault45 with several bottom row options and rotary encoder support.

* Keyboard Maintainer: [projectcain](https://github.com/projectcain)
* Hardware Supported: Vault35 PCB (atmega32u4 and rp2040)
* Hardware Availability: https://mechvault.net

Make example for this keyboard (after setting up your build environment):

    make projectcain/vault35/atmega32u4:default
    make projectcain/vault35/rp2040:default

Flashing example for this keyboard:

    make projectcain/vault35/atmega32u4:default:flash
    make projectcain/vault35/rp2040:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard. This will also clear EEPROM/emulated EEPROM, so it is a good first step if the keyboard is misbehaving.
* **Physical reset**:
  - atmega32u4: While the keyboard is plugged in, short the two pads labeled "Reset" on the left side of the PCB.
  - RP2040: Before the keyboard is plugged in, short the two holes labeled "Boot" on the left side of the PCB. Then plug the keyboard in, and disconnect the holes.
* **Keycode in layout**: `QK_BOOT` is mapped to the bottom-right key in the default keymap, on the base layer.
