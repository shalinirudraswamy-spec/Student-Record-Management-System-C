#include <stdio.h>
#include <string.h>
#include "student.h"

void modify_node(SLL **ptr)
{
    char op;

    printf("\nEnter which record to search for modification:\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter choice: ");

    scanf(" %c", &op);

    switch (op)
    {
        case 'r':
        case 'R':
            modify_by_rollno(ptr);
            break;

        case 'n':
        case 'N':
            modify_by_name(ptr);
            break;

        case 'p':
        case 'P':
            modify_by_percentage(ptr);
            break;

        default:
            printf("Invalid choice.\n");
    }
}

void modify_by_rollno(SLL **ptr)
{
    SLL *p = *ptr;
    int roll;
    float percentage;

    char name[50];

    printf("Enter roll number: ");
    scanf("%d", &roll);

    while (p)
    {
        if (p->rollno == roll)
        {
            printf("Current Name: %s\n", p->name);
            printf("Current Percentage: %.2f\n", p->percentage);

            printf("Enter new name: ");
            scanf("%49s", name);

            do
            {
                printf("Enter new percentage");
                scanf("%f", &percentage);

                if (percentage < 0 || percentage > 100)
                    printf("Invalid percentage.\n");

            } while (percentage < 0 || percentage > 100);

            strcpy(p->name, name);
            p->percentage = percentage;

            printf("Record modified successfully.\n");
            return;
        }

        p = p->next;
    }

    printf("Roll number not found.\n");
}

void modify_by_name(SLL **ptr)
{
    SLL *p = *ptr;
    char name[50];
    int found = 0;
    int roll;

    printf("Enter name: ");
    scanf("%49s", name);

    printf("\nMatching records:\n");

    while (p)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                   p->rollno,
                   p->name,
                   p->percentage);

            found++;
        }

        p = p->next;
    }

    if (found == 0)
    {
        printf("Name not found.\n");
        return;
    }

    printf("Enter roll number to modify: ");
    scanf("%d", &roll);

    p = *ptr;

    while (p)
    {
        if (p->rollno == roll &&
            strcmp(p->name, name) == 0)
        {
            char newname[50];
            float percentage;

            printf("Enter new name: ");
            scanf("%49s", newname);

            do
            {
                printf("Enter new percentage (0-100): ");
                scanf("%f", &percentage);
            }
            while (percentage < 0 || percentage > 100);

            strcpy(p->name, newname);
            p->percentage = percentage;

            printf("Record modified successfully.\n");
            return;
        }

        p = p->next;
    }

    printf("Record not found.\n");
}

void modify_by_percentage(SLL **ptr)
{
    SLL *p = *ptr;
    float percentage;
    int found = 0;
    int roll;

    printf("Enter percentage: ");
    scanf("%f", &percentage);

    printf("\nMatching records:\n");

    while (p)
    {
        if (p->percentage == percentage)
        {
            printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                   p->rollno,
                   p->name,
                   p->percentage);

            found++;
        }

        p = p->next;
    }

    if (found == 0)
    {
        printf("Percentage not found.\n");
        return;
    }

    printf("Enter roll number to modify: ");
    scanf("%d", &roll);

    p = *ptr;

    while (p)
    {
        if (p->rollno == roll &&
            p->percentage == percentage)
        {
            char newname[50];
            float newpercentage;

            printf("Enter new name: ");
            scanf("%49s", newname);

            do
            {
                printf("Enter new percentage (0-100): ");
                scanf("%f", &newpercentage);
            }
            while (newpercentage < 0 || newpercentage > 100);

            strcpy(p->name, newname);
            p->percentage = newpercentage;

            printf("Record modified successfully.\n");
            return;
        }

        p = p->next;
    }

    printf("Record not found.\n");
}
