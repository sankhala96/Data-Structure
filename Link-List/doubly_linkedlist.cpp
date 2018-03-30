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

void deleteNode(struct Node** head, int x){
	struct Node *temp, *prev;
	temp = *head;
	
	if(temp != NULL && temp->data == x){
		(*head) = temp->next;
		temp -> next -> prev = NULL;
		free(temp);
		return;
	}
	
	while(temp != NULL && temp -> data !=x){
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL) return;
	
	prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	free(temp);
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
	cout<<"\n";
	
	insertAtPosition(&head, 5, 2);
	print(head);
	cout<<"\n";
	
	deleteNode(&head, 5);
	print(head);
	cout<<"\n";
	
}