#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;
void insert(int data){
    struct node *t = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(!head){
    head=newnode;
    return;
    }
    t=head;
    while(t->next){
        t = t->next;
    }
    t->next = newnode;
}
void delete()
{
    if(head){
        //struct node* ptr = head;
        head = head->next;
        //free(ptr);
    }
}
void print() {
   struct node *t = head;
    while(t){
        printf("%d", t->data);   
    if(t->next!=NULL)
    {
        printf("->");
    }
    t = t->next;
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,val;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &val);
        insert(val);
    }
    int k;
    scanf("%d", &k);
    while(k--){
    delete();
    }
    print();
    return 0;
}

