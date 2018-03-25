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

void insert(struct Node** head, int x, int p){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	struct Node *temp = *head;
	
	for(i=0;i<=(p-1);i++){
		temp = temp->next;
	}
	
	newNode -> data = x;
	newNode -> next = temp->next;
	temp->next = newNode;
}

void print(struct Node *node){
	while(node != NULL){
		cout<<(node -> data)<<" ";
		node = node->next;
	}
}

int main() {
	struct Node* head = NULL;
	
	push(&head, 2);
	push(&head, 3);
	print(head);
	return 0;
}