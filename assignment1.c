/*Ben Johnson
Started 6/11/20 
Program made to simulate an ATM and allow users to manage their PIN
For error checking, I used the C library <string.h>, for functions for manipulating arrays.
*/

#include <stdio.h>
#include <string.h>

int main() {
    
    int option; //user input from menu
    char pin[5] = "1234"; //assign PIN
    char enteredpin[5]; //declaring array for user entered PIN
    int compare; //for error checking in case 1 & 2
    int compare2; //for error checking in case 1 & 2
    int pin1len; //declaring newpin string length (error checking, case 2)
    int pin2len; //declaring newpin2 string length (error checking, case 2)
    char newpin[5]; //case 2 new PIN array
    char newpin2[5]; //case 2 PIN verification  array
    int x = 0; //successful inputs
    int y = 0; //unsuccessful inputs
    
    do{
        printf("\n1. Enter PIN and verify correct.\n2. Change PIN.\n3. Display the number of times the PIN was entered successfully and unsuccessfully.\n4. Exit program.\n\nPlease select one option from above: "); //display initial menu with 4 options
        scanf("%d", &option); //scan user input and assign to "option"
        
        switch(option){ //start switch
        case 1:{ //start case 1
            printf("\nEnter your PIN: ");
            scanf("%c", enteredpin);
            fgets(enteredpin, 5, stdin); //fgets stores user input as a string in enteredpin
            compare = strcmp(enteredpin, pin); //strcmp compares the values in the 2 strings, in this case the enteredpin and pin
            
                if (compare == 0){ //if the user entered PIN matches, it is verified
                    printf("PIN verification successful.\n", x++);
                }
                    else{ //otherwise it fails
                        printf("PIN verification failed.\n", y++);
                    }
            break; //return to menu
        } //end case 1
  
  
        case 2:{ //start case 2
            printf("\nEnter new PIN: ");
            scanf("%c", &newpin);
            fgets(newpin, 5, stdin);
            
            printf("Please confirm new PIN: ");
            scanf("%c", &newpin2);
            fgets(newpin2, 5, stdin);
            
            pin1len = strlen(newpin); //check string length of newpin
            pin2len = strlen(newpin2); //check string length of newpin2
            compare2 = strcmp(newpin, newpin2); //compare string lengths
            
            if (pin1len && pin2len != 4){//if statement in case PIN is > or < 4 digits
                printf("PIN must be 4 digits only, returning to menu.\n", y++);
                break;
            }//end if (pinlen)
                else{
                    if (compare2 == 0){
                        memcpy(pin, newpin2, sizeof(5));
                        printf("PIN change successful.\n", x++); 
                    } //end if (case 2)
                        else{
                            printf("Incorrect PIN entered, try again.\n", y++);  
                        } //end else (case 2)
            }//end else (pinlen)
                    break;
            } //end case 2


        case 3:{ //start case 3
            printf("Successful entries: %d\nUnsuccessful entries: %d\n", x, y);
        } //end case 3
        break;


        default:{ //start default
        if (option != 4){ //if option != 1,2,3 or 4, error message is printed
            printf("\nInvalid input, try again.\n");
        }//end if default
        }//end default
        break;
       }//end switch
    } //end do
    while (option != 4); //option 4 is selected, program terminates with message
    printf("Program terminated, goodbye.");
    
return 0;

} //end main