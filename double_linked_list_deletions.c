//-------------------- head of the code ------------------------

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define in(x) scanf(" %d", &x);
#define LinkedListNode LinkedListNode
typedef struct LinkedListNode LinkedListNode;
struct LinkedListNode {
	int val;
	struct LinkedListNode* next;
	struct LinkedListNode* prev;
};


//-------------------- body of the code ------------------------


LinkedListNode* insertAtBeginning(LinkedListNode* head, int val) {
 struct LinkedListNode *ptr = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
 //struct LinkedListNode *ptr1 = head;
    ptr->val = val;
    ptr->prev=NULL;
    ptr->next = head;
    
    if(head)
    {
    head->prev=ptr;
    }
    head=ptr;
    return head;
}
LinkedListNode* insertAtEnd(LinkedListNode* head, int val) {
struct LinkedListNode *ptr = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    struct LinkedListNode *t = head;
    ptr->val = val;
        ptr->next = NULL;
    if(!head)
    {
        return insertAtBeginning(head, val);
    }
    while(t->next)
    {
        t=t->next; 
    }
        t->next=ptr;
        ptr->prev = t;
    
   return head;
}
LinkedListNode* insertAtPosition(LinkedListNode* head, int val, int pos) {
struct LinkedListNode* newnode=(struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    newnode->val=val;
    if(head==NULL&&pos==1)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else if(pos==1)
    {
        head = insertAtBeginning(head,val);
    }
    else
    {
        struct LinkedListNode* previous = head;
        while(pos>2)
        {
            previous=previous->next;
            pos--;
        }
        if(previous->next==NULL)
            head = insertAtEnd(head,val);
        else
        {
        previous->next->prev=newnode;
        newnode->next=previous->next;
        newnode->prev=previous;
        previous->next=newnode;
        }
    }
    return head;
}
LinkedListNode* deleteAtBeginning(LinkedListNode* head) 
{
   struct LinkedListNode *ptr = head;
    if(head==NULL)
    {
        return NULL;
    }
   else if(head->next == NULL)
   {
        free(ptr);
       head = NULL;
    }
    else
    {
        ptr->next->prev = NULL;
        head = ptr->next;
        free(ptr);
    }
    return head;
}
LinkedListNode* deleteAtEnd(LinkedListNode* head) 
{
   struct LinkedListNode *ptr = head;
    if(head==NULL)
    {
       return NULL;
   }    
   else if(head->next==NULL)
   {
       free(ptr);
       head = NULL;
   }
    else
    {
        while(ptr->next)
        {
            ptr=ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
    return head;
}
LinkedListNode* deleteAtPosition(LinkedListNode* head, int pos) 
{
    if(head==NULL)
    {
        return NULL;
    }
    else if(pos==1)
    {
        head = deleteAtBeginning(head);
    }
    else
    {
        struct LinkedListNode* previous = head;
        while(pos>2)
        {
            previous=previous->next;
            pos--;
        }
        if(previous->next->next==NULL)
        {
            head=deleteAtEnd(head);
        }
        else
        {
            struct LinkedListNode* todelete = previous->next;
            previous->next=todelete->next;
            todelete->next->prev=previous;
            free(todelete);
        }
    }
    return head;
}
//-------------------- tail of the code ------------------------


int rng(int lim) {
	if (lim == 0) return 0;
	return rand()%lim;
}
int a[1005], sz = 0;
void insertt(int val, int pos) {
	if (pos < 0) return;
	if (pos > sz + 1) return;
	sz += 1;
	for (int i = sz; i > pos; i--)
		a[i] = a[i - 1];
	a[pos] = val;
}
void erasee(int pos) {
	if (pos > sz) return;
	if (pos < 1) return;
	sz--;
	for (int i = pos; i <= sz; i++)
		a[i] = a[i + 1];
}
int check(LinkedListNode* head) {
	if (head == NULL && sz == 0) return 1;
	if (head == NULL || sz == 0) return 0;
	LinkedListNode* node = head;
	for (int i = 1; i <= sz; i++) {
		if (node == NULL) return 0;
		if (node->val != a[i]) return 0;
		node = node->next;
	}	
	if (node != NULL) return 0;

	node = head;
	while (node->next)
		node = node->next;

	for (int i = sz; i >= 1; i--) {
		if (node == NULL) return 0;
		if (node->val != a[i]) return 0;
		node = node->prev;
	}
	if (node != NULL) return 0;
	return 1;
}
int main() {
	srand(time(NULL));
	int t, n; in(t); in(n);
	while (t--) {
		LinkedListNode* head = NULL;
		sz = 0;
		for (int i = 0; i < n; i++) {
			int type = rng(6);
			if (type == 0) {
				int val = rng(1000);
				head = insertAtBeginning(head, val);
				insertt(val, 1);
				if (!check(head)) {
					printf("incorrect insertAtBeginning");
					return 0;
				}
			}

			if (type == 1) {
				int val = rng(1000);
				head = insertAtEnd(head, val);
				insertt(val, sz + 1);
				if (!check(head)) {
					printf("incorrect insertAtEnd");
					return 0;
				}
			}

			if (type == 2) {
				int val = rng(1000);
				int pos = rng(sz + 1) + 1;
				head = insertAtPosition(head, val, pos);
				insertt(val, pos);
				if (!check(head)) {
					printf("incorrect insertAtPosition");
					return 0;
				}
			}

			if (type == 3) {
				head = deleteAtBeginning(head);
				erasee(1);
				if (!check(head)) {
					printf("incorrect deleteAtBeginning");
					return 0;
				}
			}

			if (type == 4) {
				head = deleteAtEnd(head);
				erasee(sz);
				if (!check(head)) {
					printf("incorrect deleteAtEnd");
					return 0;
				}
			}

			if (type == 5) {
				int pos = rng(sz)+1;
				head = deleteAtPosition(head, pos);
				erasee(pos);
				if (!check(head)) {
					printf("incorrect deleteAtPosition");
					return 0;
				}
			}
		}
	}
	printf("correct");
}