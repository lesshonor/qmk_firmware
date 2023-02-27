# NCR-80 R3

![NCR-80 R3](https://i.imgur.com/MucSJQUh.png)

> Re-imagination of the classic rebranded Cherry G81-3000 by NCR

Round 3 PCBs made available outside of China are hotswap-only, with no RGB or LED backlight support. Circuitry and some components are present on the PCB to support the addition of a solenoid, though no information about the circuit or necessary hardware has been provided by the manufacturer.

Bottom row layouts with 6.25u and 7u spacebars are supported along with ANSI and ISO.

* Keyboard Maintainer: [The QMK Community](https://github.com/qmk)
* Hardware Supported: [NCR-80 R3 (APM32F103CBT6)](https://www.aliexpress.com/item/3256804856662074.html)
* Hardware Availability: [AliExpress](https://www.aliexpress.com/i/3256804629840294.html), [YMDK](https://ymdkey.com/products/ncr-80-ncr80-r3-vintage-mechanical-keyboard-kit-ansi-iso-tkl-hotswap-via-supported)

Make example for this keyboard (after setting up your build environment):

    make mt/ncr80/r3:default

Flashing example for this keyboard:

    make mt/ncr80/r3:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard. This will also clear the emulated EEPROM, so it is a good first step if the keyboard is misbehaving.
* **Physical reset**: Near the MCU there are two square pads with a circle in the middle. This is an unpopulated footprint for a reset button. Short these two pads twice in quick succession.
* **Keycode in layout**: Press the key mapped to `QK_BOOT`. In the pre-supplied keymaps it is on the second layer, replacing the F12 key.

After entering the bootloader through one of the three methods above, the keyboard will appear as a USB mass storage device named `MT.KEY`. Copy the compiled `.uf2` file onto this device. The keyboard will reboot on completion with the new firmware loaded.
