// lol
#include "LEDwall.h"
#include <stdint.h>
#include <stddef.h>
#include "ets_sys.h"
#include "os_type.h"
#include "osapi.h"
#include "gpio.h"


#define NUM_LEDS 576
#define BITS_PER_LED 24
#define REST_TIME_US 50

#define LED_PIN 2
#define GPIO_PORT

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} CRGB;

static CRGB leds[NUM_LEDS];  // array of RGB values

void LEDwall_init(void) {
    // Configure GPIO pin for LED data output
    // Clear the buffer to black
    for (size_t i = 0; i < NUM_LEDS; i++) {
        leds[i].r = 0;
        leds[i].g = 0;
        leds[i].b = 0;
    }
}

void ledwall_setPixel(uint16_t idx, uint8_t r, uint8_t g, uint8_t b);

void ledwall_fill(uint8_t r, uint8_t g, uint8_t b);

void ledwall_show(void);                 // Push out buffer to LEDs

static inline void send_bit(bool bit);   // Low-level WS2812 bit send


static inline void send_byte(uint8_t byte);


static void send_pixel(LED_t pixel);

