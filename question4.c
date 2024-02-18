#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}node;
node* initlinkedlist(node* head){
    head = NULL;
    return head;
}
node* createnode(int d){
    node* newnode = (node *)malloc(sizeof(node));
    if(newnode!= NULL){
        newnode->data = d;
        newnode->next = NULL;
    }
    return newnode;
}
node* insertatstar(node* head,int d){
    node* ptr;
    ptr = createnode(d);
    if(ptr!=NULL){
        ptr->next = head;
        head = ptr;
    }
    else{
        printf("cant append\n");
    }
    return head;
}
node* insertatend(node* head,int d){
    node* ptr = head;
    node* newnode = createnode(d);
    if(head==NULL){
        head = newnode;
    }
    else{
        while(ptr!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = NULL;
    }
    return head;
}
node* deleteatstart(node* head){

    if(head!=NULL){
        node* newnode;
        if(head!=NULL){
            newnode = head;
            head = head->next;
            free(newnode);
            newnode = NULL;
        }
    }
    return head;
}
void show_list(node *head){
    printf("My-LIST: ");
    node * temp=head;
    while(temp!=NULL){printf("%d -> ",temp->data);    temp=temp->next;}

}
int sizeofll(node* head){
    int i=0;
    while(head!=NULL){
        head = head->next;
        i++;

    }
    printf("%d",i);

    return i;
}
typedef struct nodepair
{   
    node* node1;
    node* node2;
}pair;
pair alternate(node* head) {
    pair nodes;
    //int n = sizeofll(head); // Call sizeofll function to get the number of nodes
    node* lista = NULL; // Initialize lista as an empty linked list
    node* listb = NULL; // Initialize listb as an empty linked list
    node* search = head;
    int i=0;
    while (search!=NULL) {
        node* newnode = search;  
        node* ptr = search->next;  
        if (i % 2 == 0) {
            // Insert the node into list a
            newnode->next = lista;
            lista = newnode;
        } else {
            // Insert the node into list b
            newnode->next = listb;
            listb = newnode;
        }
        i++;
        search = ptr;
    }
    nodes.node1 = lista;
    nodes.node2 = listb;
    return nodes;
}

int main(){
    int n =5;
    node* ll=initlinkedlist(ll);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        ll = insertatstar(ll,a);
    }
    show_list(ll);
    pair altnode = alternate(ll);
    show_list(altnode.node1);
    show_list(altnode.node2);
}
