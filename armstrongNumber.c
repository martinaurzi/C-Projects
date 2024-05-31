/* An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.
   For example:
   - 9 is an Armstrong number, because 9 = 9^1 = 9
   - 10 is not an Armstrong number, because 10 != 1^2 + 0^2 = 1
   - 153 is an Armstrong number, because: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
   - 154 is not an Armstrong number, because: 154 != 1^3 + 5^3 + 4^3 = 1 + 125 + 64 = 190
Write some code to determine whether a number is an Armstrong number.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define DIM 32

bool is_armstrong_number(int number){
    int power = 0, res = 0;
    char str_number[DIM];

    sprintf(str_number, "%d", number);
    power = strlen(str_number);

    for(int i=0; i<power; i++)
        res += pow(str_number[i] - '0', power);

    if(number==res)
        return true;

    return false;
}

int menu(void){
    int choice = 0;

    do{
        printf("\n***ARMSTRONG NUMBER***\n"
               "1. Start\n"
               "0. Exit\n"
               "Choose: ");

        scanf("%d", &choice);
    }while(choice < 0 || choice > 1);

    return choice;
}

int main(void){
    int number = 0, choice = 0 ;

    do {
        if((choice = menu()) == 1){
            printf("\nInsert a Number: ");
            scanf("%d", &number);

            if(is_armstrong_number(number))
              printf("%d is an Armstrong number.\n", number);
            else
              printf("%d is not an Armstrong number.\n", number);
        }

    } while(choice != 0);

    return 0;
}
