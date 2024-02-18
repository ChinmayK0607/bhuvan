#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* initlinkedlist(node *head) {
    head = NULL;
    return head;
}

node* createnode(int d) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode != NULL) {
        newnode->data = d;
        newnode->next = NULL;
    }
    return newnode;
}

node* insertatstart(node *head, node*temp) {
    node *ptr;
    ptr = temp;
    if (ptr != NULL) {
        ptr->next = head;
        head = ptr;
    }
    else {
        printf("Memory allocation failed.\n");
    }
    return head;
}

node* show_list(node *head) {
    printf("My-LIST: ");
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
node* insertatstart1(node *head, int d) {
    node *ptr;
    ptr = createnode(d);
    if (ptr != NULL) {
        ptr->next = head;
        head = ptr;
    }
    else {
        printf("Memory allocation failed.\n");
    }
    return head;
}

node* insertatmin(node* head,node* newnode){
    node* temp = head;
    int d = newnode->data;
    if(head->data >=d){
        head = insertatstart(head,newnode);
    }
    else{
        while(temp->next->data < d){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

node* sortedconcatenation(node *main, node *head) {
    if (main == NULL)
        return head;

    node* newnode = head;
    while (newnode != NULL) {
        node* ptr = newnode->next;
        node* nptr = newnode;   
        main = insertatmin(main,nptr);
        newnode = ptr;
    }
    return main;
}
int main() {
    node *ll = initlinkedlist(ll);
    int n=5, data;
    printf("Enter elements for the first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        ll = insertatstart1(ll, data);
    }
    show_list(ll);
    node *l2 = initlinkedlist(l2);
    printf("Enter elements for the second list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        l2 = insertatstart1(l2, data);
    }
    show_list(l2);
    ll = sortedconcatenation(ll, l2);
    printf("Sorted concatenated list: ");
    show_list(ll);
    return 0;
}
