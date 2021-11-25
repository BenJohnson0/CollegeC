//Ben Johnson 18-02-21
//Program for converting temperatures into fahrenheit and kelvin
// ?? couldnt get the kelvin value to convert ??

#include <stdio.h>
#define VALUE 5 //array size value declaration

//declare functions and celsius temp value array
float convert_temp(float ctemps[VALUE]);
float in_Kelvin(float);
float ctemps[VALUE];
    
int main() {
    
    //declare variables celsius average and i for loops
    float avg_celsius;
    int i;
    
    //user input temperatures
    printf("Enter 5 floating point temperature values (Celcius):\n");
    
    //scan values into array
    for (i=0; i<5; i++)
    {
        scanf("%f", &ctemps[i]);
    }
    
    
    avg_celsius = convert_temp(ctemps); //call average celsius function
    
    printf("\nAverage Celsius = %.2f\n", avg_celsius); 
    
    in_Kelvin(avg_celsius); //call average kelvin function
    
    printf("Average Kelvin = %.2f\n", avg_celsius);
    
    return 0;
    
}

float in_Kelvin(float avg_celsius) //function for getting celsius to kelvin average
{
    float kelvin_val;
    
    kelvin_val = (273 + avg_celsius);
    
    return kelvin_val; 
}

float convert_temp(float ctemps[]) //function for converting celsius to fahrenheit
{
    int i;
    float average;
    float ftemps[VALUE]; //fahrenheit values array
    
    average = ((ctemps[0] + ctemps[1] + ctemps[2] + ctemps[3] + ctemps[4]) / 5); //calculating average 
    
    for (i=0; i<5; i++)
    {
        ftemps[i] = (((ctemps[i] * 9) / 5) + 32); 
    }
    
    for (i=0; i<5; i++)
    {
        printf("Celsius %.2f = Fahrenheit %.2f\n", ctemps[i], ftemps[i]); //print results side by side
    }
    
    return average; //return average 
}
