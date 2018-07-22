/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */

//#undef USE_SERIAL
#define USE_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

/* TODO: figure out how to get I2C working for both the OLEDs and the matrix */
//#define SSD1306OLED

#define TAPPING_TERM 150

#undef	BACKLIGHT_LEVELS
#define	BACKLIGHT_LEVELS 8
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 8

#undef  RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define QMK_ESC_OUTPUT F1 // usually COL
#define QMK_ESC_INPUT D5 // usually ROW
#define QMK_LED B0
#define QMK_SPEAKER C6
