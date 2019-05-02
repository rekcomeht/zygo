#include "zygomorph.h"


#ifdef RGB_MATRIX_ENABLE
#define RGB_LEFT_HAND    { { 0 | ( 5 << 4) }, { 102,  0 }, 4}, \
    { { 0 | ( 4 << 4) }, {  81,  0 }, 4}, \
    { { 0 | ( 3 << 4) }, {  61,  0 }, 4}, \
    { { 0 | ( 2 << 4) }, {  41,  0 }, 4}, \
    { { 0 | ( 1 << 4) }, {  20,  0 }, 4}, \
    { { 0 | ( 0 << 4) }, {   0,  0 }, 1}, \
    { { 1 | ( 5 << 4) }, { 102, 16 }, 4}, \
    { { 1 | ( 4 << 4) }, {  81, 16 }, 4}, \
    { { 1 | ( 3 << 4) }, {  61, 16 }, 4}, \
    { { 1 | ( 2 << 4) }, {  41, 16 }, 4}, \
    { { 1 | ( 1 << 4) }, {  20, 16 }, 4}, \
    { { 1 | ( 0 << 4) }, {   0, 16 }, 1}, \
    { { 2 | ( 5 << 4) }, { 102, 32 }, 4}, \
    { { 2 | ( 4 << 4) }, {  81, 32 }, 4}, \
    { { 2 | ( 3 << 4) }, {  61, 32 }, 4}, \
    { { 2 | ( 2 << 4) }, {  41, 32 }, 4}, \
    { { 2 | ( 1 << 4) }, {  20, 32 }, 4}, \
    { { 2 | ( 0 << 4) }, {   0, 32 }, 1}, \
    { { 3 | ( 5 << 4) }, { 102, 48 }, 4}, \
    { { 3 | ( 4 << 4) }, {  81, 48 }, 4}, \
    { { 3 | ( 3 << 4) }, {  61, 48 }, 4}, \
    { { 3 | ( 2 << 4) }, {  41, 48 }, 4}, \
    { { 3 | ( 1 << 4) }, {  20, 48 }, 4}, \
    { { 3 | ( 0 << 4) }, {   0, 48 }, 1}, \
    { { 4 | ( 5 << 4) }, { 102, 64 }, 1}, \
    { { 4 | ( 4 << 4) }, {  81, 64 }, 1}, \
    { { 4 | ( 3 << 4) }, {  61, 64 }, 1}, \
    { { 4 | ( 2 << 4) }, {  41, 64 }, 1}, \
    { { 4 | ( 1 << 4) }, {  20, 64 }, 1}, \
    { { 4 | ( 0 << 4) }, {   0, 64 }, 1}

#define RGB_RIGHT_HAND    { { 0 | (11 << 4) }, { 224,  0 }, 1}, \
    { { 0 | (10 << 4) }, { 204,  0 }, 4}, \
    { { 0 | ( 9 << 4) }, { 183,  0 }, 4}, \
    { { 0 | ( 8 << 4) }, { 163,  0 }, 4}, \
    { { 0 | ( 7 << 4) }, { 143,  0 }, 4}, \
    { { 0 | ( 6 << 4) }, { 122,  0 }, 4}, \
    { { 1 | (11 << 4) }, { 224, 16 }, 1}, \
    { { 1 | (10 << 4) }, { 204, 16 }, 4}, \
    { { 1 | ( 9 << 4) }, { 183, 16 }, 4}, \
    { { 1 | ( 8 << 4) }, { 163, 16 }, 4}, \
    { { 1 | ( 7 << 4) }, { 143, 16 }, 4}, \
    { { 1 | ( 6 << 4) }, { 122, 16 }, 4}, \
    { { 2 | (11 << 4) }, { 224, 32 }, 1}, \
    { { 2 | (10 << 4) }, { 204, 32 }, 4}, \
    { { 2 | ( 9 << 4) }, { 183, 32 }, 4}, \
    { { 2 | ( 8 << 4) }, { 163, 32 }, 4}, \
    { { 2 | ( 7 << 4) }, { 143, 32 }, 4}, \
    { { 2 | ( 6 << 4) }, { 122, 32 }, 4}, \
    { { 3 | (11 << 4) }, { 224, 48 }, 1}, \
    { { 3 | (10 << 4) }, { 204, 48 }, 4}, \
    { { 3 | ( 9 << 4) }, { 183, 48 }, 4}, \
    { { 3 | ( 8 << 4) }, { 163, 48 }, 4}, \
    { { 3 | ( 7 << 4) }, { 143, 48 }, 4}, \
    { { 3 | ( 6 << 4) }, { 122, 48 }, 4}, \
    { { 4 | (11 << 4) }, { 224, 64 }, 1}, \
    { { 4 | (10 << 4) }, { 204, 64 }, 1}, \
    { { 4 | ( 9 << 4) }, { 183, 64 }, 1}, \
    { { 4 | ( 8 << 4) }, { 163, 64 }, 1}, \
    { { 4 | ( 7 << 4) }, { 143, 64 }, 1}, \
    { { 4 | ( 6 << 4) }, { 122, 64 }, 1}

rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
    // Left Hand
    RGB_LEFT_HAND//,
    // Right Hand
    //RGB_RIGHT_HAND
  };
#endif
