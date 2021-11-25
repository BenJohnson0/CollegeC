// Ben Johnson, 9/11/20, C20316733, programiz.com (Program for a guessing game between 1-10)
#include <stdio.h>
#include <stdlib.h> // this header file is required for the rand() function
int main()
{
    //declaring variables
    int num;
    int user_num; //user input
    int count = 0; //counter in while loop
    int same = 0; //counting same num
    int diff = 0; //counting different num
    
    while (count != 5)
    {
        printf("\nEnter a number between 1-10: ");
        scanf("%d", &user_num);
        
        if (user_num > 10 || user_num < 1){ //error message for user_num > 10 or < 1
            printf("Invalid input. Try again.\n");
            break; 
        }
        
        printf("Generating a random number between 1 – 10\n");
        count++; //increment count
        
        num = rand() % 10 + 1; // num is assigned a random number generated between 1 – 10
    
        if (user_num == num){
            printf("Same numbers.\n", same++);
        } //end if
        else{
            printf("Different numbers, try again.\n", diff++);
        } //end else

        if (count == 5){ //display the final same/different count
            printf("\nSame numbers entered %d times.\nDifferent numbers entered %d times.", same, diff);
        }//end if

    } //end while
     return 0;
} // end main
