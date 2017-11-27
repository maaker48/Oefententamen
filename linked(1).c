#include <stdio.h>
#include <stdlib.h>

// our struct
typedef struct node
{
    int number;
    struct node* next;
} node;

void insert(int number);
void print_list();

// pointer to the head node
struct node *head = NULL;

int main (void)
{
    int array[] = {2, 3, 4, 5};
	int n = sizeof(array)/sizeof(int);

    for (int i = 0; i < n; i++) {
        insert(array[i]);
    }

    print_list();
}

void insert(int number)
{
    // build new node
    node* new_node = malloc(sizeof(node));
    //Checking if we got the memory if not we stop the programm
    if (new_node == NULL){
        printf("no space allocated");
        exit(1);
    }

    // adding in new note the number of Insert(array[i])
    new_node->number = number;
    // putting the pointer to the head
    new_node->next = head;
    // putting new_node location as new pointer head
    head = new_node;
}

// prints a linked list
void print_list()
{
    // making new temp ptr so we can move without destroying stuff
    node *ptr = head;
    printf("\n[");
    // looks if ptr is null if not we go on with printing
    while(ptr != NULL){
        printf(" %i,", ptr->number);
        // moving to next ptr in list
        ptr = ptr->next;
    }
    printf("]\n");
}
