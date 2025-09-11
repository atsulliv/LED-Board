# LED-Board  
**Summer 2025 Project by Aidan Sullivan, Yiling Li**  

This project is a custom-built LED display board inspired by [Tech Random’s *How to Build a Massive LED Wall on a Budget*](https://www.youtube.com/watch?v=PiaS8zfuBHo). It combines hardware design, embedded programming, and creative applications for interactive visuals.  

---

## Specs  
For WS2812 LEDs, each pixel requires 24 bits, each bit taking ~1.25 µs, plus a ~50 µs reset time after all pixels. 

General Formula:
t_frame ≈ (N × 24 × 1.25 µs) + 50 µs
f_frame ≈ 1 / t_frame

For this board (16×36 = 576 pixels):  
t_frame ≈ (576 × 30 µs) + 50 µs ≈ 17.3 ms
f_frame ≈ ~58 fps

- Microcontroller Used: ESP8266   

---

## Features  

### Hardware  
- 16×36 LED matrix built with WS2812 strips  
- Custom-built frame with diffuser for smoother light output  
- Step-down converter for stable power management  

### Software  
- Pixel-level control  
- Text rendering with wrapping support  
- Full-board fill functions  

---

## Implementation  
Currently supports:  
- Writing to single pixels  
- Displaying and wrapping text  
- Filling the LED board with colors  

---

## Future Directions  
- Wireless data transmission with direct API integration (weather, flight-tracking, etc.)  
- Interactive games (Pong, Tetris, etc.)  
- Integration with the [Musical Glove Project](https://github.com/atsulliv/musical-glove) for synchronized visualizations  
