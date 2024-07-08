# Vixen

![Vixen](https://i.imgur.com/YPusoAyh.jpg)

Taking inspiration from Prime_Elise, EM7, and Alice-style boards, Vixen is an evolution of the [babyV](keyboards/eyeohdesigns/babyv).

* Keyboard Maintainer: [Eye Oh Designs](https://github.com/joedinkle)
* Hardware Supported: Vixen (RP2040 MCU)
* Hardware Availability: Group buy took place between 2023-09-01 2000 UTC and 2023-09-16 0400 UTC on [Eye Oh Designs](https://eyeohdesigns.com/)

Make example for this keyboard (after setting up your build environment):

    make eyeohdesigns/vixen:default

Flashing example for this keyboard

    make eyeohdesigns/vixen:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard. This will also clear the emulated EEPROM, so it is a good first step if the keyboard is misbehaving.
* **Physical reset button**: Short the two holes in the center of the PCB near the bottom, and plug the board in.
* **Keycode in layout**: In the default keymap, `QK_BOOT` is mapped to the bottom-right key on the third (top) layer.

## Flashing

After entering the bootloader through one of the three methods above, the keyboard will appear as a USB mass storage device named `RPI-RP2`. If the CLI is unable to find this device, the compiled `.uf2` file can be manually copied to it. The keyboard will reboot on completion with the new firmware loaded.
