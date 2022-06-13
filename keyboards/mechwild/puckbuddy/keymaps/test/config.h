// Copyright 2022 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define OLED_UPDATE_INTERVAL 1000

#if defined(EEPROM_SPI)
    #define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A4
    #define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 8
    #define EXTERNAL_EEPROM_BYTE_COUNT 64000
    #define EXTERNAL_EEPROM_PAGE_SIZE 128
    #define EXTERNAL_EEPROM_ADDRESS_SIZE 2

    #ifndef ALT_CIRQUE_PIN //you MUST relocate the cirque pin in this case!
        #define ALT_CIRQUE_PIN
    #endif
#endif

#if defined(ALT_CIRQUE_PIN)
    #undef CIRQUE_PINNACLE_SPI_CS_PIN
    #define CIRQUE_PINNACLE_SPI_CS_PIN A1
#endif

#if defined(CONSOLE_ENABLE)
    #undef NO_DEBUG
    #undef NO_PRINT
#endif
