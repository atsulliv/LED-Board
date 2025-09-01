#include <FastLED.h>
#include "font_5x7.h"

#define WIDTH 36
#define HEIGHT 16
#define NUM_LEDS (WIDTH * HEIGHT)
#define LED_PIN 2

CRGB leds[NUM_LEDS];

// Helper struct to return both coordinates
struct Point {
  int x;
  int y;
};

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

Point index_to_xy(int index) {
  Point p;
  int y = index / WIDTH;
  int x_in_row = index % WIDTH;

  if (y % 2 == 0) {
    // even rows are reversed
    p.x = WIDTH - 1 - x_in_row;
  } else {
    // odd rows normal
    p.x = x_in_row;
  }
  p.y = y;

  return p;
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


int char_to_index(char c) {
  if (c >= 'A' && c <= 'C') return c - 'A'; // A=0, B=1, C=2
  return -1; // unsupported char
}

void drawChar(char c, int xOffset, int yOffset, CRGB color) {
  int idx = char_to_index(c);
  if (idx < 0) return; // unsupported char

  for (int col = 0; col < 5; col++) {
    uint8_t column = font5x7[idx][col];
    for (int row = 0; row < 7; row++) {
      if (column & (1 << row)) {
        int x = xOffset + col;
        int y = yOffset + row;
        leds[xy_to_index(x, y)] = color;
      }
    }
  }
}


void setup() {
  delay(3000); // Powerup delay
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // clear screen
  fill_solid(leds, NUM_LEDS, CRGB::Blue);

  drawChar('A', 2, 2, CRGB::Yellow);
  drawChar('B', 10, 2, CRGB::Yellow);
  drawChar('C', 18, 2, CRGB::Yellow);

  // push to LEDs
  FastLED.show();
  delay(1000);
}