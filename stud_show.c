#include <stdio.h>
#include "student.h"

void print(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("%d %s %f\n",
           "Roll No", "Name", "Percentage");
    printf("---------------------------------------------\n");

    while (ptr)
    {
        printf("%d %s %f\n",
               ptr->rollno,
               ptr->name,
               ptr->percentage);

        ptr = ptr->next;
    }

    printf("---------------------------------------------\n");
}
