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
 *
 */
#pragma once

#define __MARLIN_FIRMWARE__

//
// Prefix header to acquire configurations
//

#include "../HAL/platforms.h"

#include "../core/boards.h"
#include "../core/macros.h"
#include "../core/millis_t.h"
#include "Version.h"

#if PRINTERMODELID == 1 // A5S
    #include "../../Configuration_A5S.h"
    //#warning Building for A5S

#else
    #if PRINTERMODELID == 2 // A1
        #include "../../Configuration_A1.h"
            //#warning Building for A1

    #else
        #if PRINTERMODELID == 3 // A5
            #include "../../Configuration_A5.h"
                //#warning Building for A5

        #else
            #include "../../Configuration.h"
                #error Building for default platform - please set printer model id
        #endif
    #endif
#endif

#include "Conditionals_LCD.h"
#include HAL_PATH(../HAL, inc/Conditionals_LCD.h)

#include "../core/drivers.h"
#include "../../Configuration_adv.h"

#include "Conditionals_adv.h"
#include HAL_PATH(../HAL, inc/Conditionals_adv.h)
