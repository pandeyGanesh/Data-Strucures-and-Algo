/*
** Finding Mid Point of Linked List
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
** midPoint -- Head pointer
** -- Finds and prints mid point of Linked List.
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
** Finding Mid Point of List
**
** Appraoch: We take two pointers, one slow moving and one fast moving
** fast moving pointer takes double the step of slow moving pointers
** hence, when fast moving pointer traverses N elements of LL, slow 
** moving pointer would have traversed N/2 elements, which is the mid point.
*/
void midPoint(Node* head){
	// If number of Nodes are even, it gives (N/2)+1 element as Mid
	// If number of Nodes are odd, it gives (N+1)/2 element as Mid
	Node *slowPointer = head;
	Node *fastPointer = head;
	while(fastPointer!=NULL && fastPointer->next!=NULL){
		slowPointer = slowPointer->next;
		fastPointer = fastPointer->next->next;
	}
	cout<<"Mid Point is : "<<slowPointer->data;
}

/*
** Main Function
*/

int main(){
	Node* head=NULL;
	insertEnd(&head,1);
	insertEnd(&head,2);
	insertEnd(&head,3);
	scanList(head);
	midPoint(head);
	return 0;
}