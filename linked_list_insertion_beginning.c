#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*head =NULL;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
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
    print();
    return 0;
}
