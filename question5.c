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
//assuming both the linkedlist to be of same lenght
node* concatenatell(node* head1,node*head2){
    node* list= initlinkedlist(list);
    int n = sizeofll(head1);
    for(int i=0;i<2*n;i++){

        if(i%2==0){
            node* newnode1 = head1->next;
            head1->next = list;
            list = head1;
            head1 = newnode1;
        }
        else{
            node* newnnode2 = head2->next;
            head2->next = list;
            list = head2;
            head2 = newnnode2;
        }
    }
    return list;
}
int main(){
    int n =3;
    node* ll=initlinkedlist(ll);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        ll = insertatstar(ll,a);
    }
    show_list(ll);
    node* l2=initlinkedlist(l2);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        l2 = insertatstar(l2,a);
    }
    show_list(l2);
    node* list1 = concatenatell(ll,l2);
    show_list(list1);
}
