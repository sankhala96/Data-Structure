#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void push(struct Node** head, int x){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode -> data = x;
	newNode -> next = *head;
	*head = newNode;
}

void print(struct Node *node){
	while(node != NULL){
		cout<<(node -> data)<<" ";
		node = node->next;
	}
}

void swapNode(struct Node** head, int x, int y){
	
	if(x==y) return;
	
	struct Node *prevX=NULL,*currX=*head;
	while(currX && currX->data !=x){
		prevX = currX;
		currX = currX->next;
	}
	
	struct Node *prevY=NULL,*currY=*head;
	while(currY && currY->data !=y){
		prevY = currY;
		currY = currY->next;
	}
	
	if(currX==NULL || currY==NULL) return;
	
	if(prevX != NULL){
		prevX->next = currY;
	}
	else{
		*head = currY;
	}
	
	if(prevY != NULL){
		prevY->next = currX;
	}
	else{
		*head  = currX;
	}
	
	struct Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

int main() {
	struct Node* head = NULL;
	
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	print(head);
	swapNode(&head,3, 6)
	print(head);
	return 0;
}