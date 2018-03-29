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

void insertAtEnd(struct Node** head, int x){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode -> data = x;
	newNode -> next = NULL;
	
	struct Node *last = *head;
	while(last->next != NULL){
		last = last -> next;
	}
	
	last -> next = newNode;
	
	newNode -> prev = last;
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
	insertAtEnd(&head, 4);
	print(head);
	
}