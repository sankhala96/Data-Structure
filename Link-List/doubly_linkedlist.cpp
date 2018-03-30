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

void insertAtPosition(struct Node** head, int x, int pos){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp = *head;
	
	newNode -> data = x;
	newNode -> next = NULL;
	
	for(int i=0;i<pos-2;i++){
		temp = temp->next;
	}
	
	newNode -> next = temp -> next;
	newNode -> prev = temp;
	
	temp -> next = newNode;
	
	if(newNode-> next !=NULL){
		newNode -> next -> prev = newNode;
	}
	
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
	count<<"\n";
	insertAtPosition(&head, 5, 2);
	
}