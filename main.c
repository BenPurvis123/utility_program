#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// function prototypes
void display_options();
long get_user_choice(int expected_inputs[], size_t len_expected_inputs, char user_choice[], size_t user_choice_size);
long continue_with_selection(char user_choice[], size_t user_choice_size);
double basic_calculator(char user_choice[], size_t user_choice_size);
void number_analyzer(char user_choice[], size_t user_choice_size);
double temperature_converter(char user_choice[], size_t user_choice_size);

int main(){
    bool user_wants_utility = true;
    char user_choice[10] = "";
    int menu_expected_inputs[] = {1, 2, 3, 4};
    int len_menu_expected_inputs = sizeof(menu_expected_inputs) / sizeof(menu_expected_inputs[0]);
    long choice = 0;

    display_options();
    while(user_wants_utility){
        choice = get_user_choice(menu_expected_inputs, len_menu_expected_inputs, user_choice, sizeof(user_choice));
        
        if(choice == 1){
            while(choice == 1){
                float answer = basic_calculator(user_choice, sizeof(user_choice));
                printf("\nAnswer (rounded to 4 decimal places): %.4f\n", answer);
                
                long user_wants_to_continue = continue_with_selection(user_choice, sizeof(user_choice));
                if(user_wants_to_continue == 0){
                    choice = 0;
                }
            }
            
            display_options(); // redisplay options (reprompt is covered through the main while loop)
        }

        else if(choice == 2){
            while(choice == 2){
                number_analyzer(user_choice, sizeof(user_choice));
                
                long user_wants_to_continue = continue_with_selection(user_choice, sizeof(user_choice));
                if(user_wants_to_continue == 0){
                    choice = 0;
                }
            }
            
            display_options(); // redisplay options (reprompt is covered through the main while loop)
        }

        else if(choice == 3){
            while(choice == 3){
                float answer = temperature_converter(user_choice, sizeof(user_choice));
                printf("Answer (rounded to 2 decimal places): %.2f\n", answer);

                long user_wants_to_continue = continue_with_selection(user_choice, sizeof(user_choice));
                if(user_wants_to_continue == 0){
                    choice = 0;
                }
            }

            display_options(); // redisplay options (reprompt is covered through the main while loop)
        }

        else if(choice == 4){
            printf("You choose to exit. goodbye.");
            user_wants_utility = false;
        }
    }

    return 0;
}

// functions
void display_options(){
    printf("\n\n==== Utility Program ====\n");
    printf("1. Basic Calculator\n");
    printf("2. Number Analyzer\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n\n");
}

long get_user_choice(int expected_inputs[], size_t len_expected_inputs, char user_choice[], size_t user_choice_size){
    long value = 0;

    printf("\nEnter your selection: ");
    while(1){
        if(!fgets(user_choice, user_choice_size, stdin)){
            printf("Input error. Please try again: ");
            continue;
        }

        user_choice[strcspn(user_choice, "\n")] = '\0';
        char *end;
        value = strtol(user_choice, &end, 10);

        if(end == user_choice || *end != '\0'){
            printf("Input error. Please enter a valid number (%d-%d): ", expected_inputs[0], expected_inputs[len_expected_inputs - 1]);
            continue;
        }

        for(size_t i = 0; i < len_expected_inputs; i++){
            if(value == expected_inputs[i]){
                return value;
            }
        }

        printf("Input error. Please enter a valid number (1-4): ");
    }
}

long continue_with_selection(char user_choice[], size_t user_choice_size){
    int continue_inputs[] = {0, 1};
    size_t len_continue_inputs = sizeof(continue_inputs) / sizeof(continue_inputs[0]);

    printf("\nWould you like to continue or choose another utility?");
    printf("\nEnter '1' to continue or '0' to select a different option.");
    long user_continue = get_user_choice(continue_inputs, len_continue_inputs, user_choice, user_choice_size);

    return user_continue;
}

double basic_calculator(char user_choice[], size_t user_choice_size){
    int calculator_expected_inputs[] = {1, 2};
    size_t len_calculator_expected_inputs = sizeof(calculator_expected_inputs) / sizeof(calculator_expected_inputs[0]);
    double value = 0.0;
    long num_inputs = 0;
    long operation = 0;

    char input_number[20] = "";
    double number = 0.0;

    printf("\n\n==== Basic Calculator ====\n");
    printf("\nPlease choose between 1 input or 2 inputs. ");
    num_inputs = get_user_choice(calculator_expected_inputs, len_calculator_expected_inputs, user_choice, user_choice_size);

    if(num_inputs == 1){
        printf("\n== Options that require 1 input == \n\n");
        printf("Square --> '1'\n");
        printf("Cube --> '2'\n");
        printf("Square root --> '3'\n");
        printf("Absolute value --> '4'\n");
        printf("Reciprocal --> '5'\n\n");
        printf("Type only the number that matches the property you would like to analyze (Don't type the quotations!)\n");
        
        int one_input_expected_operations[] = {1, 2, 3, 4, 5};
        size_t len_one_input_expected_operations = sizeof(one_input_expected_operations) / sizeof(one_input_expected_operations[0]);

        operation = get_user_choice(one_input_expected_operations, len_one_input_expected_operations, user_choice, user_choice_size);
        
        printf("Please enter your number: ");
        while(1){
            if(!fgets(input_number, sizeof(input_number), stdin)){
                printf("Input error. Please try again: ");
                continue;
            }

            input_number[strcspn(input_number, "\n")] = '\0';
            char *end;
            number = strtod(input_number, &end);

            if(end == input_number || *end != '\0'){
                printf("Input error. Please enter an integer: ");
                continue;
            }
            break;
        }

        switch(operation){
            case 1:
                value = number * number;
                break;

            case 2:
                value = number * number * number;
                break;

            case 3:
                value = sqrt(number);
                break;

            case 4:
                if(number < 0){
                    value = -1.0 * number;
                }
                else{
                    value = number;
                }
                break;
            
            case 5:
                value = 1.0 / number;
                break;
        }  
    }

    else if(num_inputs == 2){
        char input_number2[20] = "";
        double number2 = 0.0;
        
        printf("\n== Options that require 2 inputs == \n\n");
        printf("Addition --> '1'\n");
        printf("Subtraction --> '2'\n");
        printf("Multiplication --> '3'\n");
        printf("Division --> '4'\n");
        printf("Power --> '5'\n\n");
        printf("Type only the number that matches the property you would like to analyze (Don't type the quotations!)\n");
        
        int two_input_expected_operations[] = {1, 2, 3, 4, 5};
        size_t len_two_input_expected_operations = sizeof(two_input_expected_operations) / sizeof(two_input_expected_operations[0]);

        operation = get_user_choice(two_input_expected_operations, len_two_input_expected_operations, user_choice, user_choice_size);
        
        printf("\nEnter your first number: ");
        while(1){
            if(!fgets(input_number, sizeof(input_number), stdin)){
                printf("Input error. Please try again: ");
                continue;
            }

            input_number[strcspn(input_number, "\n")] = '\0';
            char *end;
            number = strtod(input_number, &end);

            if(end == input_number || *end != '\0'){
                printf("Input error. Please enter an integer: ");
                continue;
            }
            break;
        }

        printf("\nEnter your second number: ");
        while(1){
            if(!fgets(input_number2, sizeof(input_number2), stdin)){
                printf("Input error. Please try again: ");
                continue;
            }

            input_number2[strcspn(input_number2, "\n")] = '\0';
            char *end;
            number2 = strtod(input_number2, &end);

            if(end == input_number2 || *end != '\0'){
                printf("Input error. Please enter an integer: ");
                continue;
            }
            
            if(number2 == 0){
                printf("Division by zero is undefined. Please enter a nonzero divisor: ");
                continue;
            }
            break;
        }

        switch(operation){
            case 1:
                value = number + number2;
                break;

            case 2:
                value = number - number2;
                break;

            case 3:
                value = number * number2;
                break;

            case 4:
                value = number / number2;
                break;
            
            case 5:
                value = pow(number, number2);
                break;
        }  
    }
    
    return value;
}

void number_analyzer(char user_choice[], size_t user_choice_size){
    int analyzer_expected_inputs[] = {0, 1, 2, 3};
    size_t len_analyzer_expected_inputs = sizeof(analyzer_expected_inputs) / sizeof(analyzer_expected_inputs[0]);
    
    char input_to_analyze[20] = "";
    long value_to_analyze = 0;

    printf("\n\n==== Number Analyzer ====\n");
    printf("\nWhat number would you like to analyze? ");
    
    while(1){
        if(!fgets(input_to_analyze, sizeof(input_to_analyze), stdin)){
            printf("Input error. Please try again: ");
            continue;
        }

        input_to_analyze[strcspn(input_to_analyze, "\n")] = '\0';
        char *end;
        value_to_analyze = strtol(input_to_analyze, &end, 10);

        if(end == input_to_analyze || *end != '\0'){
            printf("Input error. Please enter an integer: ");
            continue;
        }
        break;
    }

    printf("\n -- Options For Properties To Analyze -- \n\n");
    printf("Prime --> '0'\n");
    printf("Polarity --> '1'\n");
    printf("Parity --> '2'\n");
    printf("Factors --> '3'\n\n");
    printf("Type only the number that matches the property you would like to analyze (Don't type the quotations!)\n");

    int selection = get_user_choice(analyzer_expected_inputs, len_analyzer_expected_inputs, user_choice, user_choice_size);

    switch(selection){
        case 0:
            if(value_to_analyze < 2){
                printf("The prime function only works for integer ≥ 2.\n");
            }
            else{
                bool is_prime = true; 
                
                for(int i = 2; i < value_to_analyze; i++){
                    if(value_to_analyze % i == 0){
                       is_prime = false;
                       break;
                    }
                }

                if(is_prime){
                    printf("%ld is prime.\n", value_to_analyze);
                }
                else{
                    printf("%ld is NOT prime.\n", value_to_analyze);
                }
            }
            break;

        case 1:
            if(value_to_analyze > 0){
                printf("%ld is positive.\n", value_to_analyze);
            }
            else if(value_to_analyze < 0){
                printf("%ld is negative.\n", value_to_analyze);
            }
            else{
                printf("%ld is neither postive nor negative.\n", value_to_analyze);
            } 
            break;

        case 2:
            if(value_to_analyze % 2 == 0){
                printf("%ld is even.\n", value_to_analyze);
            }
            else{
                printf("%ld is odd.\n", value_to_analyze);
            }
            break;

        case 3:
            if(value_to_analyze == 0){
                printf("Zero has infinitely many factors.\n");
                break;
            }

            long n = value_to_analyze;
            if(value_to_analyze > 0){
                printf("Factors of %ld:\n", n);
            }
            else if(value_to_analyze < 0){
                n = value_to_analyze * -1;
                printf("Factors of %ld (from %ld):\n", n, value_to_analyze);
            }
            
            for(long i = 1; i < n; i++){
                if(n % i == 0){
                      printf("%ld, ", i);
                }
            }
            printf("%ld\n", n);
            break;

    }
}

double temperature_converter(char user_choice[], size_t user_choice_size){
    int temperature_converter_inputs[] = {1, 2, 3};
    size_t len_temperature_converter_inputs = sizeof(temperature_converter_inputs) / sizeof(temperature_converter_inputs[0]);
    
    char input_temp[20] = "";
    double temp_to_convert = 0;
    long current_temp_scale = 0;

    long desired_output_scale = 0;
    double output_temp = 0;

    printf("\n\n==== Number Analyzer ====\n");
    printf("\n\nIs your temperature in Celsius, Fahrenheit, or Kelvin?\n");
    printf("Enter '1' for Fahrenheit\n");
    printf("Enter '2' for Celsius\n");
    printf("Enter '3' for Kelvin\n");

    current_temp_scale = get_user_choice(temperature_converter_inputs, len_temperature_converter_inputs, user_choice, user_choice_size);

    if(current_temp_scale == 1){
        printf("\nEnter the current temperature in Fahrenheit: ");
        
        while(1){
            if(!fgets(input_temp, sizeof(input_temp), stdin)){
                printf("Input error. Please try again: ");
                continue;
            }

            input_temp[strcspn(input_temp, "\n")] = '\0';
            char *end;
            temp_to_convert = strtod(input_temp, &end);

            if(end == input_temp || *end != '\0'){
                printf("Input error. Please enter a valid temperature: ");
                continue;
            }

            if(temp_to_convert < -459.67){
                printf("Input Error: The temperature entered is below absolute zero. Please enter a physically possible temperature: ");
                continue;
            }
            break;
        }

        int convert_from_fahrenheit_inputs[] = {1, 2};
        size_t len_convert_from_fahrenheit_inputs = sizeof(convert_from_fahrenheit_inputs) / sizeof(convert_from_fahrenheit_inputs[0]);
        
        printf("\nWould you like to convert it to Celsius or Kelvin?\n");
        printf("Enter '1' for converting to Celsius\n");
        printf("Enter '2' for converting to Kelvin\n");

        desired_output_scale = get_user_choice(convert_from_fahrenheit_inputs, len_convert_from_fahrenheit_inputs, user_choice, user_choice_size);

        if(desired_output_scale == 1){
            output_temp = (temp_to_convert - 32) * (5.0 / 9.0);
        }
        else if(desired_output_scale == 2){
            output_temp = (temp_to_convert - 32) * (5.0 / 9.0) + 273.15;
        }
    }
    
    else if(current_temp_scale == 2){
        printf("\nEnter the current temperature in Celsius: ");
        
        while(1){
            if(!fgets(input_temp, sizeof(input_temp), stdin)){
                printf("Input error. Please try again: ");
                continue;
            }

            input_temp[strcspn(input_temp, "\n")] = '\0';
            char *end;
            temp_to_convert = strtod(input_temp, &end);

            if(end == input_temp || *end != '\0'){
                printf("Input error. Please enter a valid temperature: ");
                continue;
            }

            if(temp_to_convert < -273.15){
                printf("Input Error: The temperature entered is below absolute zero. Please enter a physically possible temperature: ");
                continue;
            }

            break;
        }

        int convert_from_celsius_inputs[] = {1, 2};
        size_t len_convert_from_celsius_inputs = sizeof(convert_from_celsius_inputs) / sizeof(convert_from_celsius_inputs[0]);
        
        printf("\nWould you like to convert it to Fahrenheit or Kelvin?\n");
        printf("\nEnter '1' for converting to Fahrenheit\n");
        printf("\nEnter '2' for converting to Kelvin\n");

        desired_output_scale = get_user_choice(convert_from_celsius_inputs, len_convert_from_celsius_inputs, user_choice, user_choice_size);

        if(desired_output_scale == 1){
            output_temp = temp_to_convert * (9.0 / 5.0) + 32;
        }
        else if(desired_output_scale == 2){
            output_temp = temp_to_convert + 273.15;
        }
    }
    
    else if(current_temp_scale == 3){
        printf("\nEnter the current temperature in Kelvin: ");
        
        while(1){
            if(!fgets(input_temp, sizeof(input_temp), stdin)){
                printf("Input error. Please try again: ");
                continue;
            }

            input_temp[strcspn(input_temp, "\n")] = '\0';
            char *end;
            temp_to_convert = strtod(input_temp, &end);

            if(end == input_temp || *end != '\0'){
                printf("Input error. Please enter a valid temperature: ");
                continue;
            }

            if(temp_to_convert < 0){
                printf("Input Error: The temperature entered is below absolute zero. Please enter a physically possible temperature: ");
                continue;
            }
            break;
        }

        int convert_from_kelvin_inputs[] = {1, 2};
        size_t len_convert_from_kelvin_inputs = sizeof(convert_from_kelvin_inputs) / sizeof(convert_from_kelvin_inputs[0]);
        
        printf("\nWould you like to convert it to Fahrenheit or Celsius?\n");
        printf("\nEnter '1' for converting to Fahrenheit\n");
        printf("\nEnter '2' for converting to Celsius\n");

        desired_output_scale = get_user_choice(convert_from_kelvin_inputs, len_convert_from_kelvin_inputs, user_choice, user_choice_size);

        if(desired_output_scale == 1){
            output_temp = (temp_to_convert - 273.15) * (9.0 / 5.0) + 32;
        }
        else if(desired_output_scale == 2){
            output_temp = (temp_to_convert - 273.15);
        }
    }

    return output_temp;
}