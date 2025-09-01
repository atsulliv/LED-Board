
// include guards
#ifndef LEDwall_H
#define LEDwall_H

#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} CRGB;



/**
 * @brief Initialize the WS2812B driver.
 * @param pin GPIO pin connected to the LED data line.
 *
 * Sets up the GPIO for output. On Arduino this may just call pinMode(),
 * while on bare-metal it could configure registers directly.
 */
void ws2812b_init(int pin);               // optional setup


/**
 * @brief Send LED data to the WS2812B strip.
 * @param leds Pointer to an array of CRGB values.
 * @param count Number of LEDs in the array.
 *
 * This function iterates over the array and transmits each LED color
 * in GRB order using the WS2812B timing protocol.
 */
void ws2812b_show(CRGB *leds, int count); // main display function

#endif
