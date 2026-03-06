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
        // -12s for the month, 10.2f for the sales value
        printf("%-12s %10.2f\n", months[i], monthlySales[i]);
    }

    /* Sales Summary Report (minimum, maximum, and average sales) */
    int maxIndex = 0; // To track the index of the maximum sales
    int minIndex = 0; // To track the index of the minimum sales
    double totalSales = 0;

    for (i = 0; i < 12; i++) {
        totalSales += monthlySales[i];
        if (monthlySales[i] < monthlySales[minIndex]) {
            minIndex = i;
        }
        if (monthlySales[i] > monthlySales[maxIndex]) {
            maxIndex = i;
        }
    }

    double averageSales = totalSales / 12;

    printf("\nSales Summary Report:\n");
    printf("Minimum Sales: %.2f  (%s)\n", monthlySales[minIndex], months[minIndex]);
    printf("Maximum Sales: %.2f  (%s)\n", monthlySales[maxIndex], months[maxIndex]);
    printf("Average Sales: %.2f\n", averageSales);

    /* Six-Month Moving Average Report */
    printf("\nSix-Month Moving Average Report:\n");

    // Calculate the six-month moving average for months 6 to 12 (index 5 to 11)
    for (i = 5; i < 12; i++) {
        double sum = 0;
        // Sum the sales for the current month and the previous 5 months
        for (int j = i - 5; j <= i; j++) {
            sum += monthlySales[j];
        }
        double average = sum / 6;
        printf("%-8s - %-9s %10.2f\n", months[i - 5], months[i], average);
    }

    /* Sales report (highest to lowest) */
    printf("\nSales Report (Highest to Lowest):\n");
    
    // Create an index array to track original month positions
    // (ie. indices[0] = 0 for January, indices[1] = 1 for February, etc.)
    int indices[12];
    for (i = 0; i < 12; i++) {
        indices[i] = i;
    }
    
    // Sort indices based on sales values (highest to lowest)
    for (i = 0; i < 12; i++) {
        int maxIndex = i;
        // Compare the sales values at the current index with the rest of the indices
        for (int j = i + 1; j < 12; j++) {
            if (monthlySales[indices[j]] > monthlySales[indices[maxIndex]]) {
                maxIndex = j;
            }
        }
        // Swap the indices to sort them based on sales values
        if (maxIndex != i) {
            int temp = indices[i];
            indices[i] = indices[maxIndex];
            indices[maxIndex] = temp;
        }
    }
    
    // Print using sorted indices to maintain correct month-sales pairing
    for (i = 0; i < 12; i++) {
        printf("%-12s $%9.2f\n", months[indices[i]], monthlySales[indices[i]]);
    }

    return 0;
}