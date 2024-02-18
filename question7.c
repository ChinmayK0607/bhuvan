#include<stdio.h>
#include<stdlib.h>

typedef struct doublenode {
    int data;
    struct doublenode* prev;
    struct doublenode* next;
} node;

node* initdll(node* head) {
    head = NULL;
    return head;
}

node* createnode(int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

node* insertatstart(int x, node* head) {
    node* newnode = createnode(x);
    if (head == NULL) {
        head = newnode;
    } else {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    return head;
}

node* insertatend(int x, node* head) {
    node* newnode = createnode(x);
    if (head == NULL) {
        head = newnode;
    } else {
        node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
    return head;
}

node* reverse(node* head) {
    node* temp = NULL;
    node* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
    }
    return head;
}

void show_dll(node* head) {
    node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int n = 3;
    node* ll = initdll(ll);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        ll = insertatend(a, ll);
    }
    printf("Original list: ");
    show_dll(ll);
    
    printf("Reversed list: ");
    show_dll(reverse(ll));

    return 0;
}
