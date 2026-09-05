#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int get_rollno(SLL *ptr)
{
    int n = 1;
    SLL *temp;

    while (1)
    {
        temp = ptr;

        while (temp)
        {
            if (temp->rollno == n)
                break;

            temp = temp->next;
        }

        if (temp == NULL)
            return n;

        n++;
    }
}

void add_data(SLL **ptr)
{
    SLL *new_node, *last;
    float percentage;

    new_node = malloc(sizeof(SLL));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->rollno = get_rollno(*ptr);

    printf("Roll No = %d\n", new_node->rollno);

    printf("Enter name: ");
    scanf("%s", new_node->name);

    do
    {
        printf("Enter percentage (0-100): ");
        scanf("%f", &percentage);

        if (percentage < 0 || percentage > 100)
            printf("Invalid percentage.\n");

    } while (percentage < 0 || percentage > 100);

    new_node->percentage = percentage;
    new_node->next = NULL;

    if (*ptr == NULL)
    {
        *ptr = new_node;
    }
    else
    {
        last = *ptr;

        while (last->next)
            last = last->next;

        last->next = new_node;
    }

    printf("Student record added successfully.\n");
}
