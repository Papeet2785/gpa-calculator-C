#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void input_mode(int num_of_classes, char current_input, float current_input_num, float grades[]);
void average_mode(int num_of_classes, float current_input_num, float grades[]);

int main() {
    
    bool keep_on = true;
    char keep_on_choice = '\0';
    int num_of_classes = 0;
    char mode = '\0';
    float current_input_num = 0;
    char current_input = '\0';
    float grades[20] = {0};
    float GPA = 0;

    printf(
    "*** PAPEET2785'S GPA CALCULATOR ***\n\n"
    " To use this GPA Calculator, you must follow the instructions, and enter input as you wish. :)\n"
    " You are first asked for how many classes you have (enter a maximum of 20).\n"
    " Then you can choose between two modes:\n"
    " - I'd recommend Input mode to find your GPA per semester. There's more handholding, and default options.\n"
    " - I'd recommend Average mode for after you've made a list of the semester GPAs to average them.\n"
    " At the end of the program, you can choose to exit my calculator, or repeat it (including choosing a new mode).\n"
    " This is done so that you can run this program once!\n"
    " Enjoy!!! :)\n\n"
    );

    while(keep_on){
        GPA = 0;
        // number of classes
        printf(" How many classes do you have?\n");
        scanf("%d", &num_of_classes);
        printf("\n");

        printf(" This calculator offers 2 modes:\n"
       "    - Input mode (I): enter class types and grades one at a time\n"
       "    - Average mode (A): paste all GPA-formatted numbers in one go.\n"
       " Choose mode. Invalid input defaults to Input mode: ");
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

        // finding average of all the final grades in the list
        for(int j = 0; j < num_of_classes; j++){
            GPA += grades[j];
        }
        GPA /= num_of_classes;

        printf(" You GPA is %.3f!\n", GPA);
        if(GPA < 4){
            printf(" Nice, but there's room for improvement. You may have to work harder next semester!\n");
        }
        else{
            printf(" Keep up with the good work. You're a Star!\n");
        }
        printf(" Do you want to keep using the Calculator? You can calculate GPA for another semester, or switch modes. :)\n (Y for Yes, N for No)\n");
        scanf(" %c", &keep_on_choice);
        keep_on_choice = toupper(keep_on_choice);
        if(keep_on_choice == 'N'){
            keep_on = false;
            printf(" Thank you so much for using my GPA Calculator! :)\n");
        }
    }
    return 0;
}

void input_mode(int num_of_classes, char current_input, float current_input_num, float grades[]) {
    char weight = '\0';
    float weight_num = 0;

    printf("\n Input mode is selected for the GPA Calculator!\n\n");
    for(int i = 0; i < num_of_classes; i++){
    
    // inputting weights
        printf(" What type of class is it? Enter the first letter (A for AP, H for Honors, and S for Standard): ");
        scanf(" %c", &weight);
        weight = toupper(weight);
        switch(weight){
            case 'A':
                weight_num = 1;
                printf(" Nice! You're taking the APs!\n");
                break;
            case 'H':
                weight_num = 0.5;
                printf(" Nice course rigor!\n");
                break;
            case 'S':
                weight_num = 0;
                printf(" Good Choice!\n");
                break;
            default:
                weight_num = 0;
                printf(" -_-\n Will assume Standard class for invalid input.\n Good Choice!\n");
                break;
        }
    // inputting grades
        printf("\n What are your grades in that class? Enter a letter (A, B, C, D, F): ");
        scanf(" %c", &current_input);
        current_input = toupper(current_input);
        switch(current_input){
            case 'A':
                current_input_num = 4;
                printf(" Perfect!!!\n");
                break;
            case 'B':
                current_input_num = 3;
                printf(" Not too shabby! Don't worry about it.\n");
                break;
            case 'C':
                current_input_num = 2;
                printf(" Hmmm, you might have to lock in.\n");
                break;
            case 'D':
                current_input_num = 1;
                printf(" Well, at least it's not an F ...\n");
                break;
            case 'F':
                current_input_num = 0;
                printf(" Failed!!!\n");
                break;
            default:
                printf(" -_-\n Will assume C grade for invalid input.\n  Hmmm, you might have to lock in.\n");
                current_input_num = 2;
                break;
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