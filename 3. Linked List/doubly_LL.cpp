/*
** Double Linked List Implementation
** -------------------------------------------
**
** Method_Name -- Arguments Used
**
** insertEnd -- Head pointer, End pointer, Data to insert
** -- Inserts Data element at the End of Linked List
**
** clear -- Head pointer, End Pointer
** -- Deletes all nodes of Linked List
**
** scanList -- Head pointer
** -- Prints whole list
**
** scanReverse -- End pointer
** -- Prints whole list in reverse
*/

#include<iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node* prev;
	Node(int value=0){
		data = value;
		next = NULL;
		prev = NULL;
	}
};

/*
** Insertion Operations
*/
void insertEnd(Node** head, Node** end, int data){
	//Insert new node at the end of list
	Node* newNode = new Node(data);
	if(*head==NULL){
		*head = newNode;
		*end = newNode;
	}
	else{
		(*end)->next = newNode;
		newNode->prev = (*end);
		*end = newNode;
	}
}

/*
** Deletion Operations
*/
void clear(Node** head, Node** end){
	while(*head!=NULL){
		Node* temp = *head;
		*head = temp->next;
		delete temp;
	}
	*end = *head;
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

void scanReverse(Node* end){
	if(end==NULL){
		cout<<"List is empty\n";
	}
	else{
		Node* temp = end;
		while(temp!=NULL){
			cout<<temp->data << " --> ";
			temp = temp->prev;
		}
		cout<<"X\n";
	}
}

/*
** Main Function
*/

int main(){
	Node *head=NULL, *end=NULL;
	insertEnd(&head,&end,1);
	insertEnd(&head,&end,2);
	insertEnd(&head,&end,3);
	insertEnd(&head,&end,4);
	insertEnd(&head,&end,5);
	scanList(head);
	scanReverse(end);
	clear(&head,&end);
	scanList(head);
	return 0;
}