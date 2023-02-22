/* Copyright 2021 Mike Tsao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

// 68keys.h

#pragma once

#include "quantum.h"

#define LAYOUT_ortho_6x18( \
    k01, k02, k03, k04, k05, k06, k07, k08, k09, k110, k011, k012, k013, k014, K015, K016, K017, K018, \
    k11, k12, k13, k14, k15, k16, k17, k18, k19, k210, k111, k112, k113, k114, K115, K116, K117, K118, \
    k21, k22, k23, k24, k25, k26, k27, k28, k29, k310, k211, k212, k213, k214, K215, K216, K217, K218, \
    k31, k32, k33, k34, k35, k36, k37, k38, k39, k410, k311, k312, k313, k314, K315, K316, K317, K318, \
    k41, k42, k43, k44, k45, k46, k47, k48, k49, k510, k411, k412, k413, k414, K415, K416, K417, K418, \
    k51, k52, k53, k54, k55, k56, k57, k58, k59, k610, k511, k512, k513, k514, K515, K516, K517, K518  \
) { \
    {k01, k02, k03, k04, k05, k06, k07, k08, k09, k110, k011, k012, k013, k014, K015, K016, K017, K018}, \
    {k11, k12, k13, k14, k15, k16, k17, k18, k19, k210, k111, k112, k113, k114, K115, K116, K117, K118}, \
    {k21, k22, k23, k24, k25, k26, k27, k28, k29, k310, k211, k212, k213, k214, K215, K216, K217, K218}, \
    {k31, k32, k33, k34, k35, k36, k37, k38, k39, k410, k311, k312, k313, k314, K315, K316, K317, K318}, \
    {k41, k42, k43, k44, k45, k46, k47, k48, k49, k510, k411, k412, k413, k414, K415, K416, K417, K418}, \
    {k51, k52, k53, k54, k55, k56, k57, k58, k59, k610, k511, k512, k513, k514, K515, K516, K517, K518}  \
}
