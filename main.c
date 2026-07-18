#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void run_input_mode(int class_count, float grades_list[]);
void run_average_mode(int class_count, float grades_list[]);

int main() {
    
    bool keep_on = true;
    char keep_on_choice = '\0';
    int class_count = 0;
    char mode = '\0';
    float grades_list[20] = {0};
    float gpa = 0;

    printf(
    "*** PAPEET2785'S GPA CALCULATOR ***\n\n");
    while (keep_on) {
        gpa = 0;
        printf(" How many classes do you have?\n");
        scanf("%d", &class_count);
        printf("\n");
        printf(" This calculator offers 2 modes:\n"
       "    - Input mode: i\n"
       "    - Average mode a\n"
       " Choose mode: ");
        scanf(" %c", &mode);
        mode = toupper(mode);
        switch (mode) {
            case 'I':
                run_input_mode(class_count, grades_list);
                break;
            case 'A':
                run_average_mode(class_count, grades_list);
                break;
            default:
                printf("Invalid mode chosen.\n");
                run_input_mode(class_count, grades_list);
                break;
        }
        for (int j = 0; j < class_count; j++) {
            gpa += grades_list[j];
        }
        gpa /= class_count;
        printf(" Your GPA is %.3f!\n", gpa);
        printf(" Do you want to keep using the Calculator? You can calculate GPA for another semester, or switch modes. :)\n"
             " (Y for Yes, N for No)\n");
        scanf(" %c", &keep_on_choice);
        keep_on_choice = toupper(keep_on_choice);
        if (keep_on_choice == 'N') {
            keep_on = false;
            printf(" Thank you so much for using my GPA Calculator! :)\n");
        }
    }
    return 0;
}
void run_input_mode(int class_count, float grades_list[]) {

    char course_level = '\0';
    char letter_grade = '\0';
    float grade_points = 0;
    float weight_bonus = 0;

    printf("\n Input mode is selected for the GPA Calculator!\n\n");
    for (int i = 0; i < class_count; i++) {
        printf(" What type of class is it? Enter the first letter (A for AP, H for Honors, and S for Standard): ");
        scanf(" %c", &course_level);
        course_level = toupper(course_level);
        switch (course_level) {
            case 'A':
                weight_bonus = 1;
                break;
            case 'H':
                weight_bonus = 0.5;
                break;
            case 'S':
                weight_bonus = 0;
                break;
            default:
                weight_bonus = 0;
                printf(" -_-\n Will assume Standard class for invalid input.\n");
                break;
        }
        printf("\n What are your grades in that class? Enter a letter (A, B, C, D, F): ");
        scanf(" %c", &letter_grade);
        letter_grade = toupper(letter_grade);
        switch (letter_grade) {
            case 'A':
                grade_points = 4;
                break;
            case 'B':
                grade_points = 3;
                break;
            case 'C':
                grade_points = 2;
                break;
            case 'D':
                grade_points = 1;
                break;
            case 'F':
                grade_points = 0;
                break;
            default:
                printf(" -_-\n Will assume C grade for invalid input.\n");
                grade_points = 2;
                break;
        }
        grades_list[i] = grade_points + weight_bonus;
        printf(" Grade Added!\n\n");
    }
}
void run_average_mode(int class_count, float grades_list[]) {

    float grade_points = 0;

    printf("\n Average mode is selected for the GPA Calculator!\n\n");
    for (int k = 0; k < class_count; k++) {
        printf(" Input Grade no. %d: ", k + 1);
        scanf("%f", &grade_points);
        grades_list[k] = grade_points;
        printf(" Grade Added!\n\n");
    }
}