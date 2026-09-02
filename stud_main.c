#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
    SLL *head = NULL;
    char ch;

    /* Load saved records */
    load_file(&head);

    while (1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all records\n");
        printf("r/R : Reverse the list\n");
        printf("e/E : Exit\n");
        printf("Enter your choice: ");

        scanf(" %c", &ch);

        switch (ch)
        {
            case 'a':
            case 'A':
                add_data(&head);
                break;

            case 'd':
            case 'D':
                del_node(&head);
                break;

            case 's':
            case 'S':
                print(head);
                break;

            case 'm':
            case 'M':
                modify_node(&head);
                break;

            case 'v':
            case 'V':
                save_file(head);
                break;

            case 't':
            case 'T':
                sort_node(head);
                break;

            case 'l':
            case 'L':
                del_all(&head);
                break;

            case 'r':
            case 'R':
                rev_links(&head);
                printf("List reversed successfully.\n");
                break;

            case 'e':
            case 'E':
            {
                char op;

                printf("\nS/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter choice: ");
                scanf(" %c", &op);

                if (op == 's' || op == 'S')
                {
                    save_file(head);
                    del_all(&head);
                    exit(0);
                }
                else if (op == 'e' || op == 'E')
                {
                    del_all(&head);
                    exit(0);
                }
                else
                {
                    printf("Invalid choice.\n");
                }

                break;
            }

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
