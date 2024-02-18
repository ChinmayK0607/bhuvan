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
    while(temp!=NULL){printf("%d ",temp->data);    temp=temp->next;}

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
node* rotatebyk(node* head,int k){
    node* curr = head;
    for(int i=0;i<k;i++){
        node* ptr = curr;
        node* newnode = curr->next;
        while(ptr->next!=NULL){
            ptr= ptr->next;
        }
        ptr->next=curr;
        curr->next=NULL;
        curr = newnode;
    }
    return curr;
}


int main(){
    int n =6;
    node* ll=initlinkedlist(ll);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        ll = insertatstar(ll,a);
    }
    show_list(ll);
    int k;
    printf("enter number");
    scanf("%d",&k);
    show_list(rotatebyk(ll,k));
}
