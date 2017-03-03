#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE (size_t)256
#define NUMS_SIZE (size_t)36

char * translate_num_system(char * input_number, size_t old_base, size_t new_base, size_t num_length) {
    char nums[NUMS_SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
                    'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'G', 'K', 'L', 'M', 'N',
                    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    size_t decimal_result = 0;

    for (size_t i = 0; i < num_length; i++) {
        char current_digit = input_number[num_length - i - 1];
        int check = -1;

        for (size_t k = 0; k < old_base; k++) {
            if ((current_digit == nums[k]) || (current_digit == (nums[k] | 0x20u))) {
                check = k;
                break;
            }
        }
        if (check == -1)
            return NULL;

        decimal_result += check * (size_t)pow(old_base, i);
    }

    char * converted_number = malloc(MAX_SIZE * sizeof(char));
    for (size_t i = 0; i < MAX_SIZE; i++)
        converted_number[i] = '\0';

    size_t pos = 0;
    for (; pos < MAX_SIZE, decimal_result >= new_base; pos++) {
        size_t module = (decimal_result % new_base);

       converted_number[pos] = nums[module];
        decimal_result = decimal_result / new_base;
    }

   converted_number[pos] = nums[decimal_result];

    for (size_t i = 0; i < (pos + 1) / 2; i++) {
        char backup = converted_number[i];
       converted_number[i] = converted_number[pos - i];
       converted_number[pos - i] = backup;
    }

    return converted_number;
}

int main() {
    size_t old_base;
    printf("first numerix: ");
    scanf("%d", &old_base);
    if ( old_base < 2 || old_base > 36 ) {
        printf("[error]");
        return 0;
    }

    size_t new_base;
    printf("\nsecond numerix: ");
    scanf("%d", &new_base);
    if ( new_base > old_base || new_base < 2) {
        printf("[error]");
        return 0;
    }

    char * input_number = malloc(MAX_SIZE * sizeof(size_t));   
    for (int i = 0; i < MAX_SIZE; ++i) 
         input_number[i] = '\0';

    printf("\nnumber: ");
    scanf("%s", input_number);

    size_t input_number_lenght = strlen(input_number);
    char * res = translate_num_system(input_number, old_base, new_base, input_number_lenght);
    if (res == NULL) {
        printf("[error]");
    }

    printf("\nresult: %s", res);

    return 0;
}