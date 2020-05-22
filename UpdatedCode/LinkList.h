#ifndef SOURCE_LINKLIST_H
#define SOURCE_LINKLIST_H

#include <stdlib.h>
/*___________center of table linked list___________*/
int tiles_in_center = 0;
class Node
{
public:
    char data;
    Node *next;
    Node *prev;
};

class LinkList {
public:
    /*___________pushing into linked list___________*/
   static  void push(Node** head_ref, int new_data)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));

        new_node->data = new_data;

        new_node->next = (*head_ref);
        new_node->prev = NULL;

        if ((*head_ref) != NULL)
            (*head_ref)->prev = new_node;

        (*head_ref) = new_node;
    }

/*___________delete node at given position___________*/
    static void deleteNode(Node** head_ref, Node* del)
    {
        if (*head_ref == NULL || del == NULL)
        {
            return;
        }

        if (*head_ref == del)
        {
            *head_ref = del->next;
        }

        if (del->next != NULL)
        {
            del->next->prev = del->prev;
        }

        if (del->prev != NULL)
        {
            del->prev->next = del->next;
        }

        free(del);
    }

/*___________delete node at given position___________*/
    static void remove_node(Node** head_center_table, int n)
    {
        if (*head_center_table == NULL || n <= 0)
        {
            return;
        }
        Node* current = *head_center_table;

        for (int i = 1; current != NULL && i < n; i++)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            return;
        }

        deleteNode(head_center_table, current);
    }
};

#endif //SOURCE_LINKLIST_H
