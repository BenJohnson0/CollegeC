/* 
Program description: A program designed to take user inputs for gallons and miles, store them in arrays and calculate the miles per gallon value, all while using pointer notation.
Ben Johnson C20316733
started 7/12/2020 2:15pm 
finished 7/12/2020 2:44pm
*/

#include <stdio.h>

int main() {
    
    //declaration of arrays and i, j variables
    float gallons[5]; 
    float miles[5];
    float mpg[5]; 
    int i, j; 
    
    
    printf("Enter gallon values:\n");
    for (i=0; i<5; i++)
    {
        scanf("%f", &*(gallons + i)); //user enters the gallon values and are stored in the gallons[5] array
    }
    
    
    printf("\nEnter mile values:\n");
    for (j=0; j<5; j++)
    {
        scanf("%f", &*(miles + j)); //user enters the miles values and are stored in the miles[5] array
    }
    
    
    printf("\nMiles per gallon:\n");
    for (i=0; i<5; i++){
        *(mpg + i) = *(miles + i) / *(gallons + i); //using pointer notation, the mpg[5] array is filled with the results of miles/gallons calculation
        printf("%.3f\n", *(mpg+i)); //printing the final result, spaced nicely on a new line each time
    }
    
    return 0;
}