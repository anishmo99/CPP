/* CP264 Spring 2021 Midterm */

/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * Type your academic honesty certification
 * in this box
 *
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * If you have any comments to the instructor
 * put it in this box
 *
 * ---------------------------------
 */

//---- Do not change imports -----------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
// #include "midterm.h"
// //---------------------------------------------

// //----------------- Task 1 ---------------------
int replace_char(char* file_name, char letter1, char letter2){
	// your code here
    char buffer[1000];
    FILE *fp = fopen("file_name", "w");
    while (fgets(buffer, 1000, fp) != NULL){
        replaceAll(buffer, letter1, letter2);
        fputs(buffer, );
    }
	return 0;
}

// //----------------- Task 2 ---------------------
// void update_array(int** array, const int size, int multiplier){
// 	// your code here
//     fp = fpoen("file_name", "w");
//     f)
// 	return;
}

// //----------------- Task 3 ---------------------
// char* sentence_to_words(char* sentence){
// 	//your code here
//     if(sentence == NULL){
//         printf("invalid input\n");
//         return;
//     }

//     if()

// 	return NULL;
// }

//----------------- Task 4 ---------------------
void update_pointers(float *array, const int size, float **ptr1, float **ptr2, char mode)
{
    //your code here
    if (array == NULL)
    {
        printf("Null array\n");
        return;
    }

    else if (size <= 0)
    {
        printf("invalid size\n");
        return;
    }

    else if (ptr1 == NULL || ptr2 == NULL)
    {
        printf("invalid pointer\n");
        return;
    }

    else if (mode != 'a' && mode != 'z')
    {
        printf("invalid mode\n");
        return;
    }

    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                float temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    if (mode == 'a')
    {
        // find min for ptr1
        ptr1 = &array[0];

        // fin max for ptr2
        ptr2 = &array[size - 1];
    }

    if (mode == 'z')
    {
        // find min for ptr2
        ptr1 = &array[0];

        // fin max for ptr1
        ptr2 = &array[size - 1];
    }
    return;
}

int main(){
    float *p1 = NULL, *p2 = NULL;
    float array[] = {10.20, 7.30, 5.60, 9.80, 11.20, 7.50};
    p1 = &array[0];
    p2 = &array[6 - 1];
    update_pointers(array, 6, &p1, &p2, 'a');
    printf("%f", &p1);
    printf("\n %f", &p2);
    return 0;
}