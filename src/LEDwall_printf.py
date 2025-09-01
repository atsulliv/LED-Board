# LEDWall_printf.py
from simulated_env import *
from font_5x7 import *

import matplotlib.pyplot as plt
import numpy as np
import time


# def draw_char(x, y, char, color):
#     if char not in FONT_5x7:
#         return
#     bitmap = FONT_5x7[char]
#     for row in range(len(bitmap)):
#         for col in range(len(bitmap[row])):
#             if bitmap[row][col] == 1:
#                 index = xy_to_index(row, col)
#                 set_pixel_snake(index, color)

def draw_char(x, y, char, color):
    """Draw a single 5x7 character at top-left (x,y)"""
    if char not in FONT_5x7:
        return
    bitmap = FONT_5x7[char]
    for row in range(len(bitmap)):
        for col in range(len(bitmap[row])):
            if bitmap[row][col] == 1:
                led_x = x + col   # absolute matrix x
                led_y = y + row   # absolute matrix y
                if 0 <= led_x < WIDTH and 0 <= led_y < HEIGHT:
                    index = xy_to_index(led_x, led_y)
                    set_pixel_snake(index, color)


def draw_text(x, y, text, color, spacing=1, line_spacing=1):
    """
    Draw text starting at (x,y) using 5x7 font with wrapping.
    When exceeding two lines, overwrite the first line.
    """
    cursor_x = x
    cursor_y = y
    max_lines = HEIGHT // (7 + line_spacing)  # how many lines fit
    lines_drawn = 0

    for ch in text:
        if ch not in FONT_5x7:
            continue

        # Horizontal wrap
        if cursor_x + 5 > WIDTH:
            cursor_x = 0
            cursor_y += 7 + line_spacing
            if lines_drawn == 2:
                clear_row_two()
                lines_drawn = 0
            lines_drawn += 1

        # Vertical wrap / circular buffer
        if cursor_y + 7 > HEIGHT:
            # overwrite first line
            clear_row_one()
            cursor_y = 0

        draw_char(cursor_x, cursor_y, ch, color)
        cursor_x += 5 + spacing




