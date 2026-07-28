# include <stdio.h>

double average(int score[]);

int main(void) {
    int i;
    char name[64];
    int score[5];
    char grade;
    char *status;
    double avg;
    
    printf("Enter student name: ");
    fscanf(stdin, "%63[^\n]", name);

    printf("Enter your 5 scores:\n");
    for (i = 0; i < 5; i++) {
        printf("Enter your next score:\n");
        fscanf(stdin, "%d", &score[i]);
        if (score[i] < 1 || score[i] > 100) {
            printf("Invalid input. Try again.\n");
            i--;
            continue;
        }
    }
   avg = average(score);
    
    switch ((int)(avg / 10)) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default :
            grade = 'F';
    }
    if (grade >= 'A' && grade <= 'D') {
        status = "Passing";
    } else {
        status = "Failing";
    }

    printf("= Grade Report =\n");
    printf("Student: %s\n", name);
    printf("Scores: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", score[i]);
    }
    printf("\n");
    printf("Average: %.2f\n", avg);
    printf("Grade: %c\n", grade);
    printf("Status: %s\n", status);
        
    return 0;
}

double average(int score[]) {
    int i;
    int total = 0;
    for (i = 0; i < 5; i++) {
        total += score[i];
    }
    return total / 5.0;
}