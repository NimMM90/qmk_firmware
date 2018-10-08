/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

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

#define USE_SERIAL
#define TAPPING_TERM 150
#define PREVENT_STUCK_MODIFIERS

#define QMK_ESC_OUTPUT F1 // usually COL
#define QMK_ESC_INPUT D5 // usually ROW
#define QMK_LED B0

#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
