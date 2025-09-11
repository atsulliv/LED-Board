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


# Update the LED wall without recreating the figure
def show():
    im.set_data(np.array(leds, dtype=np.uint8))
    plt.pause(0.01)

# Snake layout starting from the top-right corner
def set_pixel_snake(index, color):
    (row, col) = index_to_xy(index)
    leds[row][col] = color

# row = y
# col = x
# Converts (col, row) to a linear index in snake order
def xy_to_index(x, y):
    
    if y % 2 == 0:
        # even rows are reversed (right → left)
        x = WIDTH - 1 - x
    return y * WIDTH + x

# """Converts linear index to (row, col) in snake order"""
def index_to_xy(index):
    row = index // WIDTH
    col = index % WIDTH

    if row % 2 == 0:  
        # even rows go right → left
        col = WIDTH - 1 - col
        
    return row, col


# Clear only the first 8 rows (row 0-7). Useful for text scrolling.
def clear_row_one():
    for y in range(8):
        for x in range(WIDTH):
            leds[y][x] = OFF

# Clear only the second 8 rows (row 8-15). Useful for text scrolling.
def clear_row_two():
    for y in range(8, 16):
        for x in range(WIDTH):
            leds[y][x] = OFF

# Fills the board entirely with one color.
def fill_color(color):
    for y in range(HEIGHT):
        for x in range(WIDTH):
            leds[y][x] = color

# Fills the board entirely with the "OFF" (black) color.
def clear():
    fill_color(OFF)



