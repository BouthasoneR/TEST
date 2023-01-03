#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct list
{ 
    int item;
    struct list *next;
}
list;

void reverse_list(list **l)
{ 
    list *temp = NULL;
    list *prev = NULL;
    list *current = (*l);
    
    while(current != NULL) 
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    
    (*l) = prev;
}

void printnodes(list *head) 
{ 
    while(head != NULL) 
    {
        cout << head->item <<" ";
        head = head->next;
    }
}

void push(list **l, int item) 
{ 
    list *node;
    node = (list *)malloc(sizeof(list));
    node->item = item;
    node->next = (*l);
    (*l) = node;
}


int main() 
{ 
    list *head = NULL;
    
    push(&head, 100);
    push(&head, 80);
    push(&head, 60);
    push(&head, 40);
    push(&head, 20);
    
    cout << "Original" << endl;
    printnodes(head);
    
    cout << "\n\nReversed"<<endl;
    reverse_list(&head);
    printnodes(head);

    return 0;
}

