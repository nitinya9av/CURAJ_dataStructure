// Find the name of all students those who have score maximum marks in each subject.

#include <stdio.h>
#include <string.h>

struct student
{
    char name[50];
    int age;
    int marks[3];
};

int main()
{
    struct student s[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &s[i].age);
        printf("Enter the marks of student %d:\n", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
    }

    int max[3] = {0, 0, 0};
    char max_student[3][50];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (s[i].marks[j] > max[j])
            {
                max[j] = s[i].marks[j];
                strcpy(max_student[j], s[i].name);
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Student who scored maximum marks in subject %d: %s with %d marks\n", i + 1, max_student[i], max[i]);
    }

    return 0;
}

