/* 
Ben Johnson, started 23-02-21.

A security authentication program based on an access
code (4 single-digit integer numbers between 0-9). Allows the user to encrypt,
decrypt and verify the code.

Compiled using VSC.
*/

#include <stdio.h> //standard input/output library
#include <stdlib.h> //various functions library including exit()

#define VALUE 4 //define code array sizes

//function signatures
int enter_code();
int encrypt_code();
int decrypt_code();
int attempts();
int exit_program();
int menu();
int compare();

int sInputs; //for counting successful matches
int unInputs; //for counting unsuccessful matches

int menu() //function for menu
{ //menu start

    int option; //user enters option from menu
    //char *letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    //int i;

    //selection menu with 5 options
    printf("\n1. Enter any code.");   
    printf("\n2. Encrypt code and verify if correct.");
    printf("\n3. Decrypt code.");
    printf("\n4. Display successful/unsuccessful matches.");
    printf("\n5. Exit program.\n\n");
    scanf("%d", &option); //scan input into "option" variable

    //error checking on option input
    if (option < 1 || option > 5)
    {
        printf("\n--- Please select a valid option and try again. ---\n");
    }

    /*
    Couldnt get character error checking to work

    for (i=0; i<52; i++)
    {
        if (option = letters[i])
        {
            printf("\n--- Please select a number between 1 and 5 ---\n");
        }
    }
    */

    return option;
    
} //menu end

int main() 
{ //start main

    int access_code[VALUE] = {4,5,2,3}; //assigned access code 4523
    int user_code[VALUE]; //user entered code array
    int encrypted_code; //to error check for an already encrypted code
    int decrypt_ready; //to error check if a code can be decrypted yet

    int end = 0;
    while (end != 1)
    { //open while loop to display menu while end != 1

        int opt;
        opt = menu(); //call menu
        switch(opt) //switch statement for the user selected option
        { //start switch

        //option 1 takes user's code into user_code array
        case 1:
            enter_code(user_code);
            encrypted_code = 0;
            break;

        //option 2 encrypts the code and increments the matches counter
        case 2:
            if (encrypted_code == 1) //error message displayed when counter = 1
            {
                printf("Cannot encrypt an already encrypted code, try again.\n\n");
                break;
            }
            
            printf("\nEncrypted code:\t");
            encrypt_code(user_code, sInputs, unInputs);
            compare(user_code, access_code);
            printf("\n");
            encrypted_code++; //increment counter, for error checking
            decrypt_ready++; //increment counter, for error checking
            break;

        //option 3 decrypts the code
        case 3:
            if (decrypt_ready == 1) 
            {
                printf("\nDecrypted code:\t");
                decrypt_code(user_code);
                printf("\n");
                break;
            }
            else
            {
                printf("\nPlease encrypt your access code first.\n\n"); //error message displayed if code is not encrypted yet
                break;
            }
            
        //option 4 displays successful/unsuccessful matches
        case 4:
            attempts(sInputs, unInputs);
            break;

        //option 5 ends the program
        case 5:
            exit_program();
            break;

        } //end switch
    }// end while
} //end main

    
int enter_code(int user_code[VALUE]) //function for code verification
{
    int i; //for the for loop
    int InvalidInput = 0; //variable used to make sure entered code is within bounds (0000-9999)

    printf("Enter code:\n"); //prompt user for a code
    
    for (i=0; i<4; i++)
    {
        scanf("%1d", &*(user_code + i));
    }

    //error checking user_code
    for (i=0; i<4; i++)
    {
        if( *(user_code + i) > 9999 || *(user_code + i) < 0000)
        {
            InvalidInput++;
        }
    }

    //if code is invalid, display error message
    if (InvalidInput != 0)
    {
        printf("\n--- Invalid, try again ---\n");
    }

}

int encrypt_code(int user_code[VALUE], int access_code[VALUE])
{
    int x[2]; //temporary variable array for swapping values
    int i; //for loops

    //swapping [0] and [2]
    *(x) = *(user_code);
    *(user_code) = *(user_code + 2);
    *(user_code + 2) = *(x);

    //swapping [1] and [3]
    *(x + 1) = *(user_code + 1);
    *(user_code + 1) = *(user_code + 3);
    *(user_code + 3) = *(x + 1);

    //iterate through the values, if they are greater than 9, set it to 0
    for(i=0; i<4; i++)
    {// start for
        if( *(user_code + i) > 9)
        { 
            *(user_code + i) = 0;
        } 
    }// end for

    //display encrypted code
    for(i=0; i<4; i++)
    {
        (*(user_code + i))++;
        printf("%d ", user_code[i]);
    } 
}

int decrypt_code(int user_code[VALUE])
{
    int x[2]; //temporary variable for swapping values
    int i; //for loops

    //iterate through the values, if they are equal to -1, set it to 9
    for(i=0; i<4; i++)
    {// start for
        *(user_code + i) = *(user_code + i) - 1; //subtract 1 from each value

        if( *(user_code + i) <= -1)
        { 
            *(user_code + i) = 9;
        } 
    }// end for

    //swapping [2] and [0]
    *(x) = *(user_code);
    *(user_code) = *(user_code + 2);
    *(user_code + 2) = *(x);

    //swapping [1] and [3]
    *(x + 1) = *(user_code + 1);
    *(user_code + 1) = *(user_code + 3);
    *(user_code + 3) = *(x + 1);

    //display decrypted code
    for(i=0; i<4; i++)
    {
        printf("%d ", *(user_code + i));
    } 

}

int attempts(int sInputs, int unInputs)
{
    //displaying appropriate message for successful/unsuccessful inputs
    printf("\nSuccessful inputs: %d\n", sInputs);
    printf("Unsuccessful inputs: %d\n", unInputs);
}

int exit_program()
{
    printf("--- Program terminated, goodbye. ---\n\n"); //termination message 
    exit(0); //exit function ends the program
}

int compare(int user_code[VALUE], int access_code[VALUE])
{

    int i; //for loop
    int compare = 0; //compare the array values

    //for loop to compare the arrays
    for (i=0; i<4; i++)
    {
        if( *(user_code + i) == *(access_code + i) )
        { //start if
            compare++; //compare the code values one by one and increment when they match
        } //end if
    } //end for

        if (compare == 4) // if/when the codes match 
        {//start if
            printf("\n--- Correct code entered ---\n"); 
            sInputs++;
        }// end if 

        else //if the codes do not match
        {//start else
            printf("\n--- Wrong code entered ---\n");
            unInputs++;
        }//end else 
}