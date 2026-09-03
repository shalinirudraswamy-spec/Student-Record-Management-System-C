#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void save_file(SLL *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "w");

    if (fp == NULL)
    {
        printf("File opening failed.\n");
        return;
    }

    while (ptr)
    {
        fprintf(fp, "%d %s %.2f\n",
                ptr->rollno,
                ptr->name,
                ptr->percentage);

        ptr = ptr->next;
    }

    fclose(fp);

    printf("Data saved to student.dat successfully.\n");
}

void load_file(SLL **ptr)
{
    FILE *fp;
    SLL *new_node, *last;

    fp = fopen("student.dat", "r");

    if (fp == NULL)
    {
        return;
    }

    while (1)
    {
        new_node = malloc(sizeof(SLL));

        if (new_node == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(fp);
            return;
        }

        if (fscanf(fp, "%d %s %f",
                   &new_node->rollno,
                   new_node->name,
                   &new_node->percentage) != 3)
        {
            free(new_node);
            break;
        }

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
    }

    fclose(fp);

    printf("Saved records loaded successfully.\n");
}
