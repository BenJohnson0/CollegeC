/*
Author: Ben Johnson C20316733
Date: 22nd April 2021
Time: 10:15am - 11:45am

labtest4.c
Program that stores 2 passengers flight data in structures using functions, and then displays
the details after everything is entered. (Data includes Flight number, flight date, surname, first name
seat number and destination). Variables are declared within the struct in main() and then passed to the functions
using pass by reference.

Compiler: VSC
*/

//header files
#include <stdio.h>

//define SIZE as symbolic name to be used for each variable
#define SIZE 30

//structure for holding the flight date variables
struct flight_date
{
    int day;
    int month;
    int year;
};

//structure for holding all of the passengers details, including the nested struct
struct passenger_details
{
    struct flight_date flightdate;
    char firstname[SIZE];
    char surname[SIZE];
    char flight_num[SIZE]; 
    char seat_num[SIZE]; 
    char destination[SIZE];
};

//function declaration
void enterData(struct passenger_details *passenger); //function for entering passenger data
void displayData(struct passenger_details *passenger); //function for displaying passenger data

int main()
{
    struct passenger_details passenger[2]; //declare struct in main and amount of passengers, in this case, 2.

    printf("\n--- Enter passenger 1 details ---");
    enterData(&passenger[0]);

    printf("\n--- Enter passenger 2 details ---");
    enterData(&passenger[1]);

    printf("\n");

    printf("\n--- Passenger 1 details ---");
    displayData(&passenger[0]);

    printf("\n--- Passenger 2 details ---");
    displayData(&passenger[1]);

}//end main

void enterData(struct passenger_details *passenger)
{
    printf("\nEnter first name: "); //prompt user for input (firstname)
    fgets(passenger->firstname, SIZE, stdin); //fgets used to store string in the "firstname" variable in struct passenger details under name passenger

    printf("Enter surname: ");
    fgets(passenger->surname, SIZE, stdin);

    printf("Enter flight number: ");
    fgets(passenger->flight_num, SIZE, stdin);

    printf("Enter seat number: ");
    fgets(passenger->seat_num, SIZE, stdin);

    printf("Enter destination: ");
    fgets(passenger->destination, SIZE, stdin);

    //scanf used to store numeric data into nested struct variables flightdate.day, month and year.
    printf("Enter the flight date: (DD/MM/YYYY):");
    scanf("%d", &passenger->flightdate.day);
    scanf("%d", &passenger->flightdate.month);
    scanf("%d", &passenger->flightdate.year);

    while (getchar() != '\n'); //clear input buffer
}

void displayData(struct passenger_details *passenger)
{
    printf("\nFirst name: %s", passenger->firstname); //show first name
    printf("Surname: %s", passenger->surname); //show surname
    printf("Flight number: %s", passenger->flight_num); //show flight number
    printf("Seat number: %s", passenger->seat_num); //show seat number
    printf("Destination: %s", passenger->destination); //show destination
    printf("Flight date: %d/%d/%d\n\n", passenger->flightdate.day, passenger->flightdate.month, passenger->flightdate.year); //show flight date
}