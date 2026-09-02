#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void del_node(SLL **ptr)
{
    char op;

    printf("\nDelete by:\n");
    printf("R/r : Roll number\n");
    printf("N/n : Name\n");
    printf("Enter choice: ");

    scanf(" %c", &op);

    switch (op)
    {
        case 'r':
        case 'R':
            del_by_rollno(ptr);
            break;

        case 'n':
        case 'N':
            del_by_name(ptr);
            break;

        default:
            printf("Invalid choice.\n");
    }
}

void del_by_rollno(SLL **ptr)
{
    SLL *temp = *ptr;
    SLL *prev = NULL;
    int roll;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (temp)
    {
        if (temp->rollno == roll)
        {
            if (prev == NULL)
                *ptr = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Record deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Roll number not found.\n");
}

void del_by_name(SLL **ptr)
{
    SLL *temp = *ptr;
    char name[50];
    int found = 0;
    int roll;

    printf("Enter name to delete: ");
    scanf("%49s", name);

    printf("\nMatching records:\n");

    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                   temp->rollno,
                   temp->name,
                   temp->percentage);

            found++;
        }

        temp = temp->next;
    }

    if (found == 0)
    {
        printf("Name not found.\n");
        return;
    }

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    temp = *ptr;

    while (temp)
    {
        if (temp->rollno == roll &&
            strcmp(temp->name, name) == 0)
        {
            SLL *prev = NULL;
            SLL *p = *ptr;

            while (p != temp)
            {
                prev = p;
                p = p->next;
            }

            if (prev == NULL)
                *ptr = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Record deleted successfully.\n");
            return;
        }

        temp = temp->next;
    }

    printf("Selected roll number does not match the name.\n");
}

void del_all(SLL **ptr)
{
    SLL *temp;

    while (*ptr)
    {
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }

    printf("All records deleted from memory.\n");
}
