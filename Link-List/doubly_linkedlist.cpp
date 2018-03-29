#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next,*prev;
};

void insertAtFront(struct Node** head, int x){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode -> data = x;
	newNode -> next = *head;
	newNode -> prev = NULL;
	
	if(*head !=NULL){
		(*head) -> prev = newNode;
	}
	
	*head = newNode;
	
}

void print(struct Node* head){
	while(head != NULL){
		cout<<(head->data)<<" ";
		
		head = head->next;
	}
}

int main(){
	struct Node *head = NULL;
	
	insertAtFront(&head, 1);
	insertAtFront(&head, 2);
	insertAtFront(&head, 3);
	
	print(head);
	
}