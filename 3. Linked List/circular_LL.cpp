/*
** Circular Singly Linked List Implementation
** -------------------------------------------
**
** Method_Name -- Arguments Used
**
** insertEnd -- Head pointer, Data to insert
** -- Inserts Data element at the End of Circular Linked List
**
** clear -- Head pointer
** -- Deletes all nodes of Linked List
**
** scanList -- Head pointer
** -- Prints one complete rotation of whole list
*/

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

/*
** Insertion Operations
*/
void insertEnd(Node** head, int data){
	//Insert new node at the end of list
	Node* newNode = new Node(data);
	if(*head==NULL){
		*head = newNode;
		newNode->next = *head;
	}
	else{
		Node* temp = *head;
		while( temp->next != (*head) ){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = *head;
	}
}

/*
** Deletion Operations
*/
void clear(Node** head){
	Node* temp = *head;
	while(temp->next != (*head) ){
		Node* del = temp;
		temp = temp->next;
		delete del;
	}
	delete temp;
	*head = NULL;
}

/*
** Traversal Operations
*/
void scanList(Node* head){
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		Node* temp = head;
		do{
			cout<<temp->data<<" --> ";
			temp = temp->next;
		}while(temp!=head);
		cout<<" ....\n";
	}
}

/*
** Main Function
*/

int main(){
	Node *head=NULL, *end=NULL;
	insertEnd(&head,1);
	scanList(head);
	insertEnd(&head,2);
	insertEnd(&head,3);
	insertEnd(&head,4);
	insertEnd(&head,5);
	scanList(head);
	clear(&head);
	scanList(head);
	return 0;
}