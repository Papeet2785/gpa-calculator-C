#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void input_mode(int num_of_classes, char current_input, float current_input_num, float grades[]) {
    // initializing variables
    char weight = '\0';
    float weight_num = 0;

    // mode welcome message
    printf("\n Input mode is selected for the GPA Calculator!\n\n");
    for(int i = 0; i < num_of_classes; i++){
    
    // inputting weights
        printf(" What type of class is it? Enter the first letter (A for AP, H for Honors, and S for Standard): ");
        scanf(" %c", &weight);
        weight = toupper(weight);
        if(weight == 'A'){
            printf(" Nice Course Rigor!\n");
            weight_num = 1;
        }
        else if(weight == 'H'){
            printf(" Nice!\n");
            weight_num = 0.5;
        }
        else if(weight == 'S'){
            weight_num = 0;
        }
        else {
            printf(" -_- ... Will assume Standard for invalid input.\n");
            weight_num = 0;
        }

    // inputting grades
        printf("\n What are your grades in that class? Enter a letter (A, B, C, D, F): ");
        scanf(" %c", &current_input);
        current_input = toupper(current_input);
        if(current_input == 'A'){
            current_input_num = 4;
        }
        else if(current_input == 'B'){
            current_input_num = 3;
        }
        else if(current_input == 'C'){
            current_input_num = 2;
        }
        else if(current_input == 'D'){
            current_input_num = 1;
        }
        else if(current_input == 'F'){
            current_input_num = 0;
        }
        else {
            printf(" -_- ... Will assume C grade for invalid input.\n");
            current_input_num = 2;
        }
        if(current_input_num < 3){
            printf(" You might have to Lock in! There's room for improvement.\n");
        }
        else{
            printf(" Good Job!\n");
        }

    // appending (input + weight) into list of grades
        grades[i] = current_input_num + weight_num;
        printf(" Grade Added!\n\n");
    }

}

void average_mode(int num_of_classes, float current_input_num, float grades[]) {
    printf("\n Average mode is selected for the GPA Calculator!\n\n");

    // inputting GPAs to be averaged for final GPA
    for(int k = 0; k < num_of_classes; k++){
        printf(" Input Grade no. %d: ", (k + 1));
        scanf("%f", &current_input_num);
    
    // appending input into list of grades to be averaged.
        grades[k] = current_input_num;
        printf(" Grade Added!\n\n");
    }
}

int main() {
    
    // initializing variables
    bool keep_on = true;
    char keep_on_choice = '\0';
    int num_of_classes = 0;
    char mode = '\0';
    float current_input_num = 0;
    char current_input = '\0';
    float grades[20] = {0};
    float GPA = 0;

    // welcome message
    printf("*** PAPEET2785'S GPA CALCULATOR ***\n\n");
    printf(" To use this GPA Calculator, you must follow the instructions, and enter input as you wish. :)\n");
    printf(" You are first asked for how many classes you have (enter a maximum of 20).\n");
    printf(" Then you can choose between two modes:\n");
    printf(" - I'd recommend Input mode to find your GPA per semester. There's more handholding, and default options.\n");
    printf(" - I'd recommend Average mode for after you've made a list of the semester GPAs to average them.\n");
    printf(" At the end of the program, you can choose to exit my calculator, or repeat it (including choosing a new mode).\n");
    printf(" This is done so that you can run this program once!\n");
    printf(" Enjoy!!! :)\n\n");

    // while loop to keep it on forever until user turns it off
    while(keep_on){
        // resetting GPA after every iteration
        GPA = 0;
        // number of classes
        printf(" How many classes do you have?\n");
        scanf("%d", &num_of_classes);
        printf("\n");

        printf(" This calculator offers 2 modes:\n");
        printf("    - Input mode (I): enter class types and grades one at a time\n");
        printf("    - Average mode (A): paste all GPA-formatted numbers in one go.\n");
        printf(" Choose mode. Invalid input defaults to Input mode: ");
        scanf(" %c", &mode);
        mode = toupper(mode);
        if(mode == 'I'){
            input_mode(num_of_classes, current_input, current_input_num, grades);
        }
        else if(mode == 'A'){
            average_mode(num_of_classes, current_input_num, grades);
        }
        else{
            input_mode(num_of_classes, current_input, current_input_num, grades);
        }

        // summing up all the final grades in the list
        for(int j = 0; j < num_of_classes; j++){
            GPA += grades[j];
        }

        // dividing it by number of classes for the average
        GPA /= num_of_classes;

        // final output
        printf(" You GPA is %.3f!\n", GPA);
        if(GPA < 4){
            printf(" Nice, but there's room for improvement. You may have to work harder next semester!\n");
        }
        else{
            printf(" Keep up with the good work. You're a Star!\n");
        }
        printf(" Do you want to keep using the Calculator? You can calculate GPA for another semester, or switch modes. :)\n");
        printf(" (Y for Yes, N for No)\n");
        scanf(" %c", &keep_on_choice);
        keep_on_choice = toupper(keep_on_choice);
        if(keep_on_choice == 'N'){
            keep_on = false;
            printf(" Thank you so much for using my GPA Calculator! :)\n");
        }
    }
    return 0;
}