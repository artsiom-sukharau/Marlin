/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * Adafruit Grand Central M4 pin assignments ported by Giuliano Zaro
 */
#ifndef ARDUINO_GRAND_CENTRAL_M4
  #error "Oops! Select 'Adafruit Grand Central M4' in 'Tools > Board.'"
#endif

#define BOARD_NAME "RuRAMPS4AGCM4 v1.3"

//
// Servos
//
#define SERVO0_PIN          5
#define SERVO1_PIN          3

//
// Limit Switches
//
#define X_MIN_PIN          45
#define X_MAX_PIN          39
#define Y_MIN_PIN          46
#define Y_MAX_PIN          41
#define Z_MIN_PIN          47
#define Z_MAX_PIN          43

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  49
#endif

//
// Steppers
//
#define X_STEP_PIN         37   // Support Extension Board
#define X_DIR_PIN          36
#define X_ENABLE_PIN       31
#ifndef X_CS_PIN
  #define X_CS_PIN         38
#endif

#define Y_STEP_PIN         32   // Support Extension Board
#define Y_DIR_PIN          35
#define Y_ENABLE_PIN       31
#ifndef Y_CS_PIN
  #define Y_CS_PIN         34
#endif

#define Z_STEP_PIN         30   // Support Extension Board
#define Z_DIR_PIN           2
#define Z_ENABLE_PIN       31
#ifndef Z_CS_PIN
  #define Z_CS_PIN         10
#endif

#define E0_STEP_PIN        29
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      33
#ifndef E0_CS_PIN
  #define E0_CS_PIN        14
#endif

#define E1_STEP_PIN        22
#define E1_DIR_PIN         24
#define E1_ENABLE_PIN      26
#ifndef E1_CS_PIN
  #define E1_CS_PIN        15
#endif

#define E2_STEP_PIN        25
#define E2_DIR_PIN         23
#define E2_ENABLE_PIN      27
#ifndef E2_CS_PIN
  #define E2_CS_PIN        74
#endif

#if USES_Z_MIN_PROBE_ENDSTOP
  #define Z_MIN_PROBE_PIN  49
#endif

#if HAS_FILAMENT_SENSOR
  #ifndef FIL_RUNOUT_PIN
    #define FIL_RUNOUT_PIN Y_MIN_PIN
  #endif
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN       13
#define HEATER_1_PIN       12
#define HEATER_2_PIN       11
#define HEATER_BED_PIN      7   // BED H1

#define FAN_PIN             9
#define FAN1_PIN            8
#define CONTROLLER_FAN_PIN -1

//
// Temperature Sensors
//
#define TEMP_0_PIN          0   // ANALOG A0
#define TEMP_1_PIN          1   // ANALOG A1
#define TEMP_2_PIN          2   // ANALOG A2
#define TEMP_3_PIN          3   // ANALOG A3
#define TEMP_BED_PIN        4   // ANALOG A4

// The thermocouple uses Analog pins
#if ENABLED(VER_WITH_THERMOCOUPLE) // Must be defined in Configuration.h
  #define TEMP_4_PIN        5   // A5
  #define TEMP_5_PIN        6   // A6 (Marlin 2.0 not support)
#endif

// SPI for Max6675 or Max31855 Thermocouple
/*
#if DISABLED(SDSUPPORT)
  #define MAX6675_SS_PIN   53
#else
  #define MAX6675_SS_PIN   49
#endif
*/

//
// Misc. Functions
//
#define SDSS                4
#define LED_PIN            -1   // 13 - HEATER_0_PIN
#define PS_ON_PIN          -1   // 57

// MKS TFT / Nextion Use internal USART-1
#define TFT_LCD_MODULE_COM        1
#define TFT_LCD_MODULE_BAUDRATE   115200

// ESP WiFi Use internal USART-2
#define ESP_WIFI_MODULE_COM       2
#define ESP_WIFI_MODULE_BAUDRATE  115200
#define ESP_WIFI_MODULE_RESET_PIN -1
#define PIGGY_GPIO_PIN            -1

//
// EEPROM
//
#define E2END             0x7FFF  // 32Kb (24lc256)
#define I2C_EEPROM                // EEPROM on I2C

//
// LCD / Controller
//
#if HAS_SPI_LCD

  #if EITHER(RADDS_DISPLAY, REPRAP_DISCOUNT_SMART_CONTROLLER)

    #error "Pin compatibility check needed!"
    #define BEEPER_PIN     54
    #define LCD_PINS_D4    48
    #define LCD_PINS_D7    53
    #define SD_DETECT_PIN  -1    // 51 can't be used, it's MOSI
    #define LCD_PINS_RS    55
    #define LCD_PINS_ENABLE 56

  #elif ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)

    #define BEEPER_PIN     54
    #define LCD_PINS_D4    48
    #define SD_DETECT_PIN  -1    // 51 can't be used, it's MOSI
    #define LCD_PINS_RS    55
    #define LCD_PINS_ENABLE 56

  #elif HAS_SSD1306_OLED_I2C

    #error "Pin compatibility check needed!"
    #define BEEPER_PIN     54
    #define LCD_SDSS       10
    #define SD_DETECT_PIN  -1    // 51 can't be used, it's MOSI

  #elif ENABLED(FYSETC_MINI_12864)

    #error "Pin compatibility check needed!"
    #define BEEPER_PIN     54
    #define DOGLCD_CS      56
    #define DOGLCD_A0      55

    //#define FORCE_SOFT_SPI    // Use this if default of hardware SPI causes display problems
                                // results in LCD soft SPI mode 3, SD soft SPI mode 0

    #define LCD_RESET_PIN  48   // Must be high or open for LCD to operate normally.

    #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
      #error "Pin compatibility check needed! Grand central M4 pins 50, 51 and 52 are not GPIO pins, they are wired to MISO, MOSI, and SCK."
      #ifndef RGB_LED_R_PIN
        #define RGB_LED_R_PIN 50   // D5
      #endif
      #ifndef RGB_LED_G_PIN
        #define RGB_LED_G_PIN 52   // D6
      #endif
      #ifndef RGB_LED_B_PIN
        #define RGB_LED_B_PIN 53   // D7
      #endif
    #elif ENABLED(FYSETC_MINI_12864_2_1)
      #error "Pin compatibility check needed! Grand central M4 pins 50, 51 and 52 are not GPIO pins, they are wired to MISO, MOSI, and SCK."
      #define NEOPIXEL_PIN 50   // D5
    #endif

  #elif ENABLED(MKS_MINI_12864)
    #error "Pin compatibility check needed! Grand central M4 pins 50, 51 and 52 are not GPIO pins, they are wired to MISO, MOSI, and SCK."
    #define ORIG_BEEPER_PIN 75

    #define DOGLCD_A0      52
    #define DOGLCD_CS      50

    #define SD_DETECT_PIN  -1    // 51 can't be used, it's MOSI

  #endif

  #if ENABLED(NEWPANEL)
    #define BTN_EN1        44
    #define BTN_EN2        42
    #define BTN_ENC        40
  #endif

#endif // HAS_SPI_LCD

//
// SD Support
//
#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION ONBOARD
#endif

#if SD_CONNECTION_IS(ONBOARD)
  #undef SDSS
  #define SDSS             83
  #undef SD_DETECT_PIN
  #define SD_DETECT_PIN    95
#endif
