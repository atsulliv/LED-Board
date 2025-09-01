import matplotlib.pyplot as plt
import numpy as np
import time

# LED Wall configuration
WIDTH = 36
HEIGHT = 16
NUM_LEDS = WIDTH * HEIGHT

# Initialize framebuffer (all LEDs off)
OFF = (0, 0, 0)
leds = [[OFF for x in range(WIDTH)] for y in range(HEIGHT)]

# --- Create figure ONCE ---
fig, ax = plt.subplots()
fig.patch.set_facecolor("dodgerblue")   # outside background
ax.axis("off")

# Display initial image
im = ax.imshow(np.array(leds, dtype=np.uint8))
plt.ion()   # interactive mode on
plt.show()

def show():
    """Update the LED wall without recreating the figure"""
    im.set_data(np.array(leds, dtype=np.uint8))
    plt.pause(0.01)


def set_pixel_snake(index, color):
    """Snake layout starting from the top-right corner"""
    (row, col) = index_to_xy(index)
    leds[row][col] = color

# row = y
# col = x
def xy_to_index(x, y):
    """Convert (col, row) → linear index in snake order"""
    if y % 2 == 0:
        # even rows are reversed (right → left)
        x = WIDTH - 1 - x
    return y * WIDTH + x


def index_to_xy(index):
    """Convert linear index → (row, col) in snake order"""
    row = index // WIDTH
    col = index % WIDTH

    if row % 2 == 0:  
        # even rows go right → left
        col = WIDTH - 1 - col
        
    return row, col

def clear_row_one():
    """Clear only the first 8 rows (row 0–7)"""
    for y in range(8):
        for x in range(WIDTH):
            leds[y][x] = OFF

def clear_row_two():
    """Clear only the second 8 rows (row 8–15)"""
    for y in range(8, 16):
        for x in range(WIDTH):
            leds[y][x] = OFF

def fill_color(color):
    for y in range(HEIGHT):
        for x in range(WIDTH):
            leds[y][x] = color

def clear():
    fill_color(OFF)



