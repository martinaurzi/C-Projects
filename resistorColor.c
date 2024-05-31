/* If you want to build something using a Raspberry Pi, you'll probably use resistors.
   For this exercise, you need to know two things about them:
   - Each resistor has a resistance value.
   - Resistors are small - so small in fact that if you printed the resistance value on them, it would be hard to read.

   To get around this problem, manufacturers print color-coded bands onto the resistors to denote their resistance values.
   Each band has a position and a numeric value.
   The first 2 bands of a resistor have a simple encoding scheme: each color maps to a single number.

   In this exercise you are going to create a helpful program so that you don't have to remember the values of the bands.

   These colors are encoded as follows:
   - Black: 0
   - Brown: 1
   - Red: 2
   - Orange: 3
   - Yellow: 4
   - Green: 5
   - Blue: 6
   - Violet: 7
   - Grey: 8
   - White: 9

   The goal of this exercise is to create a way:
   - to look up the numerical value associated with a particular color band
   - to list the different band colors

   Mnemonics map the colors to the numbers, that, when stored as an array,
   happen to map to their index in the array: Better Be Right Or Your Great Big Values Go Wrong.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_COLOR 10

typedef struct Band{
    char color[7];
    int value;
} TBand;

void print_band_colors(TBand res_band[N_COLOR]){
    printf("The band colors are:\n");
    for(int i=0; i < N_COLOR; i++)
        printf("- %s\n", res_band[i].color);

    printf("\n");
}

int return_numerical_value(char color[7], TBand resistors[N_COLOR]){
    int i = 0;

    do {
        if(strcmp(color, resistors[i].color) == 0)
            return resistors[i].value;

        i++;
    }while(i < N_COLOR);

    return -1;
}

int menu(void){
    int choice = 0;

    do{
        printf("\n***RESISTOR COLOR***\n"
               "1. Numerical Value given the color of the band\n"
               "2. List the different band colors\n"
               "0. Exit\n\n"
               "Choose: ");
        scanf("%d", &choice);
    }while(choice < 0 || choice > 2);

    return choice;
}

int main(void){
    int choice = 0, numerical_value = 0;
    char band_color[7];
    char* colors[N_COLOR] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Grey", "White"};
    TBand resistors_band[N_COLOR];

    for(int i= 0; i < N_COLOR; i++){
        strcpy(resistors_band[i].color, colors[i]);
        resistors_band[i].value = i;
    }

    do{
        choice = menu();

        switch(choice){
        case 1:
          printf("Insert the band color: ");
          scanf("%s", band_color);
          if((numerical_value = return_numerical_value(band_color, resistors_band)) == -1)
            printf("This color does not exit.\n");
          else
            printf("The numerical value associated with %s is %d.\n", band_color, numerical_value);
          break;

        case 2:
          print_band_colors(resistors_band);
          break;
        }

    } while(choice != 0);

    return 0;
}
