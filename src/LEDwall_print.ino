#include <FastLED.h>

#define WIDTH 36
#define HEIGHT 16
#define NUM_LEDS (WIDTH * HEIGHT)
#define LED_PIN 2

CRGB leds[NUM_LEDS];

// Snake layout helper
int xy_to_index(int x, int y) {
  if (y % 2 == 0) {
    // even rows go right -> left
    return y * WIDTH + (WIDTH - 1 - x);
  } else {
    // odd rows left -> right
    return y * WIDTH + x;
  }
}

int index_to_xy(int index) {

}

void set_pixel(int x, int y, CRGB color) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    leds[xy_to_index(x, y)] = color;
  }
}

void fill_color(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
}

void clear() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
}

void clear_row_one() {
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    leds[i] = CRGB::Black;
  }
}

void clear_row_two() {
  for (int i = NUM_LEDS / 2; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
}




// 
void setup() {}


// the loop function that will get used
void loop() {}