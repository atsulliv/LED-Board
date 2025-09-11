#include <FastLED.h>
#include "font_5x7.h"

#define WIDTH 36
#define HEIGHT 16
#define NUM_LEDS (WIDTH * HEIGHT)
#define LED_PIN 2
#define BACKGROUND CRGB::Blue

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

// given a snake-patterned index, returns a (col, row) Point object.
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

// sets pixel in code to a specified color.
void set_pixel(int x, int y, CRGB color) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    leds[xy_to_index(x, y)] = color;
  }
}

// fills all LEDs with a certain color.
void fill_color(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
}

// fills all LEDs with black.
void clear() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
}

void clear_row_one() {
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    leds[i] = BACKGROUND;
  }
}

void clear_row_two() {
  for (int i = NUM_LEDS / 2; i < NUM_LEDS; i++) {
    leds[i] = BACKGROUND;
  }
}

int char_to_index(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A'; // A=0, B=1, C=2
  if (c == ' ') return 26;
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


// Draw a string with wrapping
void drawString(const char* text, int xStart, int yStart, CRGB color, int spacing = 1, int lineSpacing = 1) {
    int cursorX = xStart;
    int cursorY = yStart;
    int charWidth = 5;   // width of each character
    int charHeight = 7;  // height of each character

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        int idx = char_to_index(c);
        if (idx < 0) continue; // unsupported char, skip

        // Horizontal wrap
        if (cursorX + charWidth > WIDTH) {
            cursorX = 0;
            cursorY += charHeight + lineSpacing;

            // If we exceed the first line height, clear row two
            if (cursorY >= charHeight + lineSpacing) {
                clear_row_two();
            }
        }

        // Vertical wrap / circular buffer
        if (cursorY + charHeight > HEIGHT) {
            // overwrite first row
            clear_row_one();
            cursorY = 0;
        }

        drawChar(c, cursorX, cursorY, color);

        cursorX += charWidth + spacing;
    }
}


// setup() and loop() functions in Arduino code below:
void setup() {
  delay(3000); // Powerup delay
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // clear screen
  fill_solid(leds, NUM_LEDS, CRGB::White);

  drawString("HOLA ", 0, 0, CRGB::Green);
  drawString("MEXICO", 0, 8, CRGB::Red);

  // push to LEDs
  FastLED.show();
  delay(1000);
}