#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* initlinkedlist(node* head) {
    head = NULL;
    return head;
}

node* createnode(int d) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode != NULL) {
        newnode->data = d;
        newnode->next = NULL;
    }
    return newnode;
}

node* insertatstart(node* head, int d) {
    node* ptr = createnode(d);
    if (ptr != NULL) {
        ptr->next = head;
        head = ptr;
    }
    else {
        printf("cant append\n");
    }
    return head;
}

node* merge(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node* mergedHead;

    if (head1->data < head2->data) {
        mergedHead = head1;
        mergedHead->next = merge(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = merge(head1, head2->next);
    }

    return mergedHead;
}

node* mergesort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* secondHalf = slow->next;
    slow->next = NULL;

    head = mergesort(head);
    secondHalf = mergesort(secondHalf);

    return merge(head, secondHalf);
}

void show_list(node* head) {
    printf("My-LIST: ");
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n = 6;
    node* ll = initlinkedlist(ll);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        ll = insertatstart(ll, a);
    }
    show_list(ll);
    ll = mergesort(ll);
    show_list(ll);
    while (ll != NULL) {
        node* temp = ll;
        ll = ll->next;
        free(temp);
    }

    return 0;
}
