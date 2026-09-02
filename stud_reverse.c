#include "student.h"

void rev_links(SLL **ptr)
{
    SLL *prev = NULL;
    SLL *cur = *ptr;
    SLL *next;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *ptr = prev;
}
