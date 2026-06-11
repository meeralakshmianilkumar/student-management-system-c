#include <stdio.h>

struct Student {
    int rollno;
    char name[50];
    float marks;
};


int main() {
    struct Student students[100];
    int count = 0;
    int choice;
    int i;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Roll No: ");
            scanf("%d", &students[count].rollno);

            printf("Enter Name: ");
            scanf("%s", students[count].name);

            printf("Enter Marks: ");
            scanf("%f", &students[count].marks);

            count++;
            printf("Student added successfully!\n");
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("No students found!\n");
            } else {
                printf("\nStudent Records:\n");

                for (i = 0; i < count; i++) {
                    printf("\nRoll No: %d", students[i].rollno);
                    printf("\nName: %s", students[i].name);
                    printf("\nMarks: %.2f\n", students[i].marks);
                }
            }
        }

        else if (choice == 3) {
            int roll, found = 0;

            printf("Enter Roll No to search: ");
            scanf("%d", &roll);

            for (i = 0; i < count; i++) {
                if (students[i].rollno == roll) {
                    printf("\nStudent Found!\n");
                    printf("Roll No: %d\n", students[i].rollno);
                    printf("Name: %s\n", students[i].name);
                    printf("Marks: %.2f\n", students[i].marks);

                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("Student not found!\n");
            }
        }

        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}