#include <stdio.h>

struct Student {
    int rollno;
    char name[50];
    float marks;
};

int main() {
    struct Student students[100];
    int count = 0;
    int choice, i;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Display Topper\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Roll No: ");
                scanf("%d", &students[count].rollno);

                printf("Enter Name: ");
                scanf("%s", students[count].name);

                printf("Enter Marks: ");
                scanf("%f", &students[count].marks);

                count++;
                printf("Student added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No students found!\n");
                } else {
                    printf("\n===== Student Records =====\n");

                    for (i = 0; i < count; i++) {
                        char grade;

                        if (students[i].marks >= 90)
                            grade = 'A';
                        else if (students[i].marks >= 75)
                            grade = 'B';
                        else if (students[i].marks >= 50)
                            grade = 'C';
                        else
                            grade = 'F';

                        printf("\nRoll No : %d\n", students[i].rollno);
                        printf("Name    : %s\n", students[i].name);
                        printf("Marks   : %.2f\n", students[i].marks);
                        printf("Grade   : %c\n", grade);
                    }
                }
                break;

            case 3: {
                int roll, found = 0;

                printf("Enter Roll No to search: ");
                scanf("%d", &roll);

                for (i = 0; i < count; i++) {
                    if (students[i].rollno == roll) {
                        printf("\nStudent Found!\n");
                        printf("Roll No : %d\n", students[i].rollno);
                        printf("Name    : %s\n", students[i].name);
                        printf("Marks   : %.2f\n", students[i].marks);

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 4: {
                int roll, found = 0;

                printf("Enter Roll No to update: ");
                scanf("%d", &roll);

                for (i = 0; i < count; i++) {
                    if (students[i].rollno == roll) {

                        printf("Enter New Name: ");
                        scanf("%s", students[i].name);

                        printf("Enter New Marks: ");
                        scanf("%f", &students[i].marks);

                        printf("Record updated successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 5: {
                int roll, found = 0;

                printf("Enter Roll No to delete: ");
                scanf("%d", &roll);

                for (i = 0; i < count; i++) {
                    if (students[i].rollno == roll) {

                        int j;
                        for (j = i; j < count - 1; j++) {
                            students[j] = students[j + 1];
                        }

                        count--;
                        found = 1;

                        printf("Student deleted successfully!\n");
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 6:
                if (count == 0) {
                    printf("No students available!\n");
                } else {
                    int topper = 0;

                    for (i = 1; i < count; i++) {
                        if (students[i].marks > students[topper].marks) {
                            topper = i;
                        }
                    }

                    printf("\n===== Topper Details =====\n");
                    printf("Roll No : %d\n", students[topper].rollno);
                    printf("Name    : %s\n", students[topper].name);
                    printf("Marks   : %.2f\n", students[topper].marks);
                }
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}