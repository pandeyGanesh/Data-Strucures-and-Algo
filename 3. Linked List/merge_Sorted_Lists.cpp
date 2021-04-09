/*
** Merge two sorted Linked Lists
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
** merge -- Takes pointers to head of List 1 and List 2
** -- Returns head pointer to new Merged List
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
** Merge two Sorted Linked Lists
**
** Appraoch: We take two pointers, one slow moving and one fast moving
** fast moving pointer takes double the step of slow moving pointers
** hence, when fast moving pointer traverses N elements of LL, slow 
** moving pointer would have traversed N/2 elements, which is the mid point.
*/
Node* merge(Node* head1, Node* head2){
	Node *finalHead = NULL, *lastNode;
	if(head1->data < head2->data){
		finalHead = head1;
		head1 = head1->next;
	}
	else{
		finalHead = head2;
		head2 = head2->next;
	}
	lastNode = finalHead;
	while(head1!=NULL && head2!=NULL){
		if(head1->data < head2->data){
			lastNode->next = head1;
			lastNode = lastNode->next;
			head1 = head1->next;
		}
		else{
			lastNode->next = head2;
			lastNode = lastNode->next;
			head2 = head2->next;
		}
	}

	if(head1 != NULL){
		lastNode->next = head1;
	}
	if(head2 != NULL){
		lastNode->next = head2;
	}

	return finalHead;
}

/*
** Main Function
*/

int main(){
	Node* head1=NULL;
	insertEnd(&head1,1);
	insertEnd(&head1,3);
	insertEnd(&head1,7);
	insertEnd(&head1,9);
	insertEnd(&head1,12);
	scanList(head1);

	Node* head2=NULL;
	insertEnd(&head2,4);
	insertEnd(&head2,8);
	insertEnd(&head2,9);
	insertEnd(&head2,10);
	insertEnd(&head2,13);
	insertEnd(&head2,15);
	scanList(head2);

	Node* newList = merge(head1, head2);
	scanList(newList);
	return 0;
}