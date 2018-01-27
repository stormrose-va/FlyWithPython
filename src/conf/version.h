/*-
 * Copyright (c) 2017, 2018 The Stormrose Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef __FWP_VERSION_H
#define __FWP_VERSION_H

#include <stdint.h>


/*
 * Do not change these definitions!
 */

#define _FWP_DEV      0x00
#define _FWP_ALPHA    0x33
#define _FWP_BETA     0x66
#define _FWP_RC       0x99
#define _FWP_FINAL    0xFF

/*
 * Configure release information here
 */

#define _FWP_VERSION_MAJOR       1
#define _FWP_VERSION_MINOR       0
#define _FWP_VERSION_PATCH       0
#define _FWP_VERSION_FLAVOUR     _FWP_DEV
#define _FWP_VERSION_SUFFX       0

/*
 * The pattern for the numeric version follows this syntax:
 *
 *   0xAABBCCDDEE
 *
 * AA is the major, BB the minor and CC the patch version.
 * DD represents the flavour and EE the suffix (only applicable
 * to ALPHA, BETA and RC flavours; otherwise it will
 * be ignored and should be set to 0).
 * Each of them always represented as two-digit hex number.
 */
#define _FWP_VERSION_NUM \
      (((uint64_t) _FWP_VERSION_MAJOR)   << 32) \
    | (((uint64_t) _FWP_VERSION_MINOR)   << 24) \
    | (((uint64_t) _FWP_VERSION_PATCH)   << 16) \
    | (((uint64_t) _FWP_VERSION_FLAVOUR) << 8) \
    | ((uint64_t)  _FWP_VERSION_SUFFX)

#endif /* __FWP_VERSION_H */
