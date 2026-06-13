#include <stdio.h>

struct Student {
    int rollno;
    char name[50];
    float marks;
};

void saveToFile(struct Student students[], int count)
{
    FILE *fp = fopen("students.dat", "wb");

    if (fp == NULL) {
        printf("Error saving file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(students, sizeof(struct Student), count, fp);

    fclose(fp);
}

int loadFromFile(struct Student students[])
{
    FILE *fp = fopen("students.dat", "rb");

    int count = 0;

    if (fp == NULL)
        return 0;

    fread(&count, sizeof(int), 1, fp);
    fread(students, sizeof(struct Student), count, fp);

    fclose(fp);

    return count;
}

char calculateGrade(float marks)
{
    if (marks >= 90)
        return 'A';
    else if (marks >= 75)
        return 'B';
    else if (marks >= 50)
        return 'C';
    else
        return 'F';
}

int main()
{
    struct Student students[100];
    int count;
    int choice, i;

    count = loadFromFile(students);

    while (1)
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Display Topper\n");
        printf("7. Total Students\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Student limit reached!\n");
                    break;
                }

                printf("Enter Roll No: ");
                scanf("%d", &students[count].rollno);

                printf("Enter Name: ");
                scanf("%s", students[count].name);

                printf("Enter Marks: ");
                scanf("%f", &students[count].marks);

                count++;

                saveToFile(students, count);

                printf("Student added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No students found!\n");
                }
                else
                {
                    printf("\n===== STUDENT RECORDS =====\n");
                    printf("Total Students: %d\n", count);

                    for (i = 0; i < count; i++)
                    {
                        printf("\nRoll No : %d\n", students[i].rollno);
                        printf("Name    : %s\n", students[i].name);
                        printf("Marks   : %.2f\n", students[i].marks);
                        printf("Grade   : %c\n",
                               calculateGrade(students[i].marks));
                    }
                }
                break;

            case 3:
            {
                int roll;
                int found = 0;

                printf("Enter Roll No to search: ");
                scanf("%d", &roll);

                for (i = 0; i < count; i++)
                {
                    if (students[i].rollno == roll)
                    {
                        printf("\nStudent Found!\n");
                        printf("Roll No : %d\n", students[i].rollno);
                        printf("Name    : %s\n", students[i].name);
                        printf("Marks   : %.2f\n", students[i].marks);
                        printf("Grade   : %c\n",
                               calculateGrade(students[i].marks));

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 4:
            {
                int roll;
                int found = 0;

                printf("Enter Roll No to update: ");
                scanf("%d", &roll);

                for (i = 0; i < count; i++)
                {
                    if (students[i].rollno == roll)
                    {
                        printf("Enter New Name: ");
                        scanf("%s", students[i].name);

                        printf("Enter New Marks: ");
                        scanf("%f", &students[i].marks);

                        saveToFile(students, count);

                        printf("Record updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 5:
            {
                int roll;
                int found = 0;

                printf("Enter Roll No to delete: ");
                scanf("%d", &roll);

                for (i = 0; i < count; i++)
                {
                    if (students[i].rollno == roll)
                    {
                        int j;

                        for (j = i; j < count - 1; j++)
                        {
                            students[j] = students[j + 1];
                        }

                        count--;

                        saveToFile(students, count);

                        printf("Student deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 6:
                if (count == 0)
                {
                    printf("No students available!\n");
                }
                else
                {
                    int topper = 0;

                    for (i = 1; i < count; i++)
                    {
                        if (students[i].marks >
                            students[topper].marks)
                        {
                            topper = i;
                        }
                    }

                    printf("\n===== TOPPER DETAILS =====\n");
                    printf("Roll No : %d\n",
                           students[topper].rollno);
                    printf("Name    : %s\n",
                           students[topper].name);
                    printf("Marks   : %.2f\n",
                           students[topper].marks);
                    printf("Grade   : %c\n",
                           calculateGrade(students[topper].marks));
                }
                break;

            case 7:
                printf("Total Students = %d\n", count);
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}