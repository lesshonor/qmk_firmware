# Alphalpha+

![alphalpha+](https://i.imgur.com/qEJKoj2h.jpeg)

Inspired by [PyroL's iconic Alpha](https://github.com/PyrooL/Alpha), featuring an extra alpha key and spacebar.

* Keyboard Maintainer: [OTTIMO](https://github.com/subottimale)
* Hardware Supported: [Alphalpha+ v1 & v2](https://github.com/subottimale/alphalpha_plus).
  * v2 adds reset holes to the PCB, support for a WS2812 RGB LED strip, and additional bottom row options.
* Hardware Availability: Gerbers and cases are available in linked repository.

Make example for this keyboard (after setting up your build environment):

    make subottimale/alphalpha_plus/v1:default
    make subottimale/alphalpha_plus/v2:default

Flashing example for this keyboard:

    make subottimale/alphalpha_plus/v1:default:flash
    make subottimale/alphalpha_plus/v2:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard. This will also clear EEPROM, so it is a good first step if the keyboard is misbehaving.
* **Physical reset**:
  - v1: There is no reset mechanism on the PCB. Reset the Pro Micro or other compatible development board according to its instructions.
  - v2: Short the set of holes between the second and third row. When looking down at the assembled keyboard, these holes are on the left.
* **Keycode in layout**: `QK_BOOT` is mapped to the right-most key on the third row in the `default` keymap.
