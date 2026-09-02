#ifndef STUDENT_H
#define STUDENT_H

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} SLL;

// Add 
void add_data(SLL **);

// Display 
void print(SLL *);

// Delete 
void del_node(SLL **);
void del_by_rollno(SLL **);
void del_by_name(SLL **);

//Modify 
void modify_node(SLL **);
void modify_by_rollno(SLL **);
void modify_by_name(SLL **);
void modify_by_percentage(SLL **);

// Sort 
void sort_node(SLL *);
void sort_by_name(SLL *);
void sort_by_percentage(SLL *);

// Other operations 
int get_rollno(SLL *);
int count_node(SLL *);
void del_all(SLL **);
void rev_links(SLL **);

 //File handling
void save_file(SLL *);
void load_file(SLL **);
 #endif

#endif
