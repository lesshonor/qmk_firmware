# NCR-80

![NCR-80](https://i.imgur.com/kAjbAPLl.jpg)

> Re-imagination of the classic rebranded Cherry G81-3000 by NCR

NCR-80 is an affordable keyboard kit inspired by iconic vintage keyboards.

* Keyboard Maintainer: [The QMK Community](https://github.com/qmk)
* Hardware Supported:
  * NCR-80 R2 PCBs (ATmega32U4, atmel-dfu)
  * NCR-80 R3 PCBs (APM32F103CBT6, uf2boot)
    * Routing and some components are present on the PCB to support the addition of a solenoid on pin C14, though no further information about the circuit or necessary hardware is known.
    * Newer R3 PCBs have been spotted on AliExpress with an STM32F401 MCU. **The firmware for these PCBs is not the same as the APM32F103 firmware. Verify which PCB you have before flashing.**
* Hardware Availability:
  * R2 Hotswap: [AliExpress](https://www.aliexpress.com/item/1005003345941543.html) [Taobao 淘宝](https://item.taobao.com/item.htm?id=657482028672)
  * R2 Solder: [AliExpress](https://www.aliexpress.com/item/1005003364462523.html) [Taobao 淘宝](https://item.taobao.com/item.htm?id=657482028672)
  * R3: [YMDK](https://ymdkey.com/products/ncr-80-ncr80-r3-vintage-mechanical-keyboard-kit-ansi-iso-tkl-hotswap-via-supported)

Make example for this keyboard (after setting up your build environment):

    make ncr80/r2/hotswap:default
    make ncr80/r2/solder:default
    make ncr80/r3/f103:default

Flashing example for this keyboard:

    make ncr80/r2/hotswap:default:flash
    make ncr80/r2/solder:default:flash
    make ncr80/r3/f103:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard. This will also clear EEPROM, so it is a good first step if the keyboard is misbehaving.
* **Physical reset**:
  * R2: Briefly press the button on the back of the PCB
  * R3: Near the MCU there are two square pads with a circle in the middle. This is an unpopulated footprint for a reset button. Short these two pads twice in quick succession.
* **Keycode in layout**: There is no key mapped to `QK_BOOT` in the pre-created keymaps, but you may assign this key in any keymaps you create.

## Flashing

After entering the bootloader through one of the three methods above:

- R2: The keyboard will appear as an Atmel DFU device. It can be flashed using the QMK CLI or QMK Toolbox.
- R3: After entering the bootloader through one of the three methods above, the keyboard will appear as a USB mass storage device named `MT.KEY`. Copy the compiled `.uf2` file onto this device. The keyboard will reboot on completion with the new firmware loaded.
