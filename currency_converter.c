#include <stdio.h>

int option;
float euroval[3];
float dolval[3];

void change_to_Euro();
void change_to_Dollar();

int main() {
    
    printf("Please select an option:\n(1) Euro\n(2) Dollars\n(3) Exit program.\n\n");
    scanf("%d", &option);
    
    if (option == 1)
    {
        int i;
        printf("\nEnter 3 euro values: ");
        
        for(i=0; i<3; i++)
        {
            scanf("%f", &euroval[i]);
        }
    
    }
    
    if (option == 2)
    {
        int j;
        printf("\nEnter 3 dollar values: ");
        
        for(j=0; j<3; j++)
        {
            scanf("%f", &dolval[j]);
        }
    
    }
    
    if (option == 3)
    {
        printf("Program terminated, Goodbye.");
        exit(0);
    }
    
    
    
    return 0;
}