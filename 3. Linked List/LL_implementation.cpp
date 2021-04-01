#include<iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int value=0){
		data = value;
		next = NULL;
	}
};

void insertEnd(Node** head, int data){
	//Insert new node at the end of list
	Node* newNode = new Node(data);
	if(*head==NULL){
		*head = newNode;
	}
	else{
		Node* temp = *head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void insertBegin(Node** head, int data){
	Node *newNode = new Node(data);
	if(*head==NULL){
		*head = newNode;
	}
	else{
		newNode->next = *head;
		*head = newNode;
	}
}

/*
void insertIndex(Node** head, int data, int index){
	Node* temp = *head;
	while(index>0 && temp!=NULL){
		temp = temp->next;
		--index;
	}
}*/

void scanList(Node* head){
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		Node* temp = head;
		while(temp!=NULL){
			cout<<temp->data;
			temp = temp->next;
			cout<<" --> ";
		}
		cout<<"X\n";
	}
}

int main(){
    Node* head=NULL;// = new Node(5);
    insertEnd(&head, 2);
    insertEnd(&head, 5);
    insertEnd(&head, 7);
    insertEnd(&head, 1);
    scanList(head);
	insertBegin(&head,20);
	scanList(head);
	insertBegin(&head,70);
	scanList(head);
    return 0;
}
