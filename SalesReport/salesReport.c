#include <stdio.h>
#include <stdlib.h>

int main() {

    /* Read the sales.txt file input */

    FILE *file; // File pointer
    double monthlySales[12]; // Array to store the 12 values
    // Array of month names for display purposes
    // We use the asterisk (*) to indicate that this is an array of pointers to char (strings)
    const char *months[12] = {"January", "February", "March", "April", "May", "June",
                 "July", "August", "September", "October", "November", "December"};
    int i = 0;

    // Open the file for reading
    file = fopen("sales.txt", "r");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read values line by line and store them in the array monthlySales
    // Continue until we have read 12 values or reached the end of the file
    while (i < 12 && fscanf(file, "%lf", &monthlySales[i]) == 1) {
        i++; // Move to the next index for the next value
    }

    // Close the file
    fclose(file);

    /* Monthly Sales Report: Properly Aligned */
    printf("Monthly Sales Report for 2024\n\n");

    // Align the headers with the same widths as the data
    printf("%-12s %7s\n", "Month", "Sales"); 

    for (i = 0; i < 12; i++) {
        // -12s for the name, 10.2f for the money
        printf("%-12s %10.2f\n", months[i], monthlySales[i]);
    }

    return 0;
}