#include <stdio.h>
#include <string.h>
#include "student.h"

int count_node(SLL *ptr)
{
    int count = 0;

    while (ptr)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

void sort_node(SLL *ptr)
{
    char op;

    if (ptr == NULL)
    {
        printf("No records to sort.\n");
        return;
    }

    printf("\nSort by:\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter choice: ");

    scanf(" %c", &op);

    switch (op)
    {
        case 'n':
        case 'N':
            sort_by_name(ptr);
            break;

        case 'p':
        case 'P':
            sort_by_percentage(ptr);
            break;

        default:
            printf("Invalid choice.\n");
    }
}

void sort_by_name(SLL *p)
{
    SLL *p1, *p2;
    int count, i, j;

    count = count_node(p);

    for (i = 0; i < count - 1; i++)
    {
        p1 = p;
        p2 = p->next;

        for (j = 0; j < count - 1 - i; j++)
        {
            if (strcmp(p1->name, p2->name) > 0)
            {
                int roll;
                float percentage;
                char name[50];

                roll = p1->rollno;
                strcpy(name, p1->name);
                percentage = p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = roll;
                strcpy(p2->name, name);
                p2->percentage = percentage;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    printf("Sorted by name successfully.\n");
}

void sort_by_percentage(SLL *p)
{
    SLL *p1, *p2;
    int count, i, j;

    count = count_node(p);

    for (i = 0; i < count - 1; i++)
    {
        p1 = p;
        p2 = p->next;

        for (j = 0; j < count - 1 - i; j++)
        {
            /* Descending order */
            if (p1->percentage < p2->percentage)
            {
                int roll;
                float percentage;
                char name[50];

                roll = p1->rollno;
                strcpy(name, p1->name);
                percentage = p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = roll;
                strcpy(p2->name, name);
                p2->percentage = percentage;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    printf("Sorted by percentage successfully.\n");
}
