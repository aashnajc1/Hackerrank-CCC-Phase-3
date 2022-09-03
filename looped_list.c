#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

struct Node{
	int value;
	struct Node* next;
};
typedef struct Node Node;
Node links[105];

void add_link(int from, int to){
	links[from].next = &links[to];
}
void set_value(int index, int val){
	links[index].value = val;
}


//BODY BEGINS HERE
int find_loop(Node* head, int head_size){
	/***
	Your Code Here
	It must return 1 if a loop exists and zero otherwise.
	***/	
    struct Node* t= head;
    int i=0;
        while(t!=NULL)
        {
            i++;
            t= t->next;
            if(i>head_size){
                return 1;
            }
        }
    return 0;
}
//BODY ENDS HERE

//TAIL BEGINS HERE
int main(){
	int i,n,m,tmp,tmp1,tmp2;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		scanf("%d", &tmp);
		set_value(i, tmp);
	}
	for(i = 0; i < m; i++){
		scanf("%d %d", &tmp1, &tmp2);
		add_link(tmp1,tmp2);
	}
	if(find_loop(&links[0],n) == 1) printf("Loop Found");
	else printf("No Loop Found");
	return 0;
}