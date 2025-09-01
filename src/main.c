//
#include "LEDwall.h"
#include <stdint.h>
#include <stddef.h>

// -----------------------------
// Main loop (for demo)
// -----------------------------
int main(void) {
    ledwall_init();

    while (1) {
        // Example pattern
        ledwall_fill(255, 0, 0);   // Red
        ledwall_show();

        // delay_ms(500);   // (placeholder delay)
        
        ledwall_fill(0, 255, 0);   // Green
        ledwall_show();

        // delay_ms(500);

        ledwall_fill(0, 0, 255);   // Blue
        ledwall_show();

        // delay_ms(500);
    }
}