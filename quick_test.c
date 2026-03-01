#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

void display_options();
// void get_user_choice(int expected_inputs[], size_t len_expected_inputs, char user_choice[], size_t user_choice_size, bool *is_valid_input, bool *is_useful_input);

int main(){
    bool user_wants_to_continue = true;
    char user_choice[10] = "";
    bool is_valid_input = false;
    bool is_useful_input = false;
    int menu_expected_inputs[] = {1, 2, 3, 4};
    int len_menu_expected_inputs = sizeof(menu_expected_inputs);

    display_options();
    printf("\nEnter the corresponding number for your selection: ");
    while((!is_valid_input)){
        if(fgets(user_choice, sizeof(user_choice), stdin)){
            is_valid_input = true;
            break;
        }
        printf("please enter a number 1-4: ");
    }
    
    return 0;
}

// functions
void display_options(){
    printf("\n==== Utility Program ====\n");
    printf("1. Basic Calculator\n");
    printf("2. Number Analyzer\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n\n");
}