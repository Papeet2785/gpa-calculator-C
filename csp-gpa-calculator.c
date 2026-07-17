#include <stdio.h>
#include <ctype.h>

int main() {
    
    // initializing variables
    int num_of_classes = 0;
    char weight = '\0';
    float weight_num = 0;
    int current_input_num = 0;
    char current_input = '\0';
    float grades[20] = {0};
    float GPA = 0;

    // welcome message
    printf("Welcome to the GPA Calculator!\n");
    printf("\n");

    // number of classes
    printf("How many classes do you have?\n");
    printf("max 20 can be entered, find GPA per semester, then average it all up for your final GPA\n");
    scanf("%d", &num_of_classes);
    printf("\n");

    for(int i = 0; i < num_of_classes; i++){
    
    // inputting weights
        printf("What type of class is it? Enter the first letter (A for AP, H for Honors, and S for Standard): ");
        scanf(" %c", &weight);
        weight = toupper(weight);
        if(weight == 'A'){
            printf("Nice Course Rigor!\n");
            weight_num = 1;
        }
        else if(weight == 'H'){
            printf("Nice!\n");
            weight_num = 0.5;
        }
        else if(weight == 'S'){
            weight_num = 0;
        }
        else {
            printf("-_- ... Will assume Standard for invalid input.\n");
            weight_num = 0;
        }

    // inputting grades
        printf("What are your grades in that class? Enter a letter (A, B, C, D, F): ");
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
            printf("-_- ... Will assume C grade for invalid input.\n");
            current_input_num = 2;
        }
        if(current_input_num < 3){
            printf("You might have to Lock in! There's room for improvement.\n");
        }
        else{
            printf("Good Job!\n");
        }

    // appending (input + weight) into list of grades
        grades[i] = current_input_num + weight_num;
        printf("\n");
        printf("Grade Added!\n");
        printf("\n");
    }

    // summing up all the final grades in the list
    for(int j = 0; j < num_of_classes; j++){
        GPA += grades[j];
    }

    // dividing it by number of classes for the average
    GPA /= num_of_classes;

    // final output
    printf("You GPA is %.3f!\n", GPA);
    if(GPA < 4){
        printf("Nice, but there's room for improvement. You may have to work harder next semester!\n");
    }
    else{
        printf("Keep up with the good work. You're a Star!\n");
    }

    return 0;
}