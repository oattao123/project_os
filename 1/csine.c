#include <stdio.h>
#include <math.h>

int main() {
    double x, sine_x;

    // Display the column headers
    printf("%-6s %-6s\n", "x", "sin(x)");

    for (x = -2 * M_PI; x <= 2 * M_PI; x += M_PI / 3) {
        sine_x = sin(x);

        // Display the values with 3 decimal points in 2 columns
        printf("%.3f %.3f\n", x, sine_x);
    }

    return 0;
}
