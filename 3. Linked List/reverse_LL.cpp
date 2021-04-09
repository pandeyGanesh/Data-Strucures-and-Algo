/*
** Reversing the Linked List
** -------------------------------------------
** Method_Name -- Arguments Used
**
** insertEnd -- Head pointer, Data to insert
** -- Inserts Data element at the End of Linked List
**
** deleteBeg -- Head pointer
** -- Deletes First Node of Linked List
**
** scanList -- Head pointer
** -- Prints whole list
**
** reverse -- Head Pointer
** -- Reverses the Linked List.
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
	}
	else{
		Node* temp = *head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

/*
** Deletion Operations
*/
void deleteBeg(Node** head){
	if(*head!=NULL){
		Node* temp = *head;
		*head = temp->next;
		delete temp;
	}
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
		while(temp!=NULL){
			cout<<temp->data;
			temp = temp->next;
			cout<<" --> ";
		}
		cout<<"X\n";
	}
}

/*
** Reverse Operation
*/
void reverse(Node** head){
	Node *prev = NULL, *next = NULL;
	Node *curr = *head;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

/*
** Main Function
*/

int main(){
	Node* head=NULL;
	insertEnd(&head,50);
	insertEnd(&head,70);
	insertEnd(&head,80);
	insertEnd(&head,90);
	insertEnd(&head,10);
	scanList(head);
	reverse(&head);
	scanList(head);
	return 0;
}
