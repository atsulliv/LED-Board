import matplotlib.pyplot as plt
import numpy as np
import time


from simulated_env import *
from LEDwall_printf import *

# -----------------------------
# Example: Max current test simulation
# -----------------------------

def main():
    # Turn LEDs on one by one
    # while (1):
    #     clear()
    #     i = 0   # reset i
    #     for i in range(NUM_LEDS):
    #         set_pixel_snake(i, (255, 255, 255))
    #         show()
    #         time.sleep(0.01)
    while (1):
        clear()
        draw_text(0, 0, "HELLO WORLD", (255, 255, 255))  # white letters
        show()


if __name__ == "__main__":
    main()