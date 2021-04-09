/*
** Check if given Linked List is palindrome
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
** mid -- Takes pointers to head
** -- Returns pointer to mid element
**
** palidrome -- Takes a pointer to head and a pointer to mid element
** -- Checks if the List is palindrome or not
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
** Find mid of the Linked List
** Returns a pointer that points to the first element
** of the second half list.
*/
Node* mid(Node* head){
	Node* begin = new Node();
	begin->next = head;
	Node* slowPointer = begin;
	Node* fastPointer = begin;
	while(fastPointer!=NULL && fastPointer->next!=NULL){
		slowPointer = slowPointer->next;
		fastPointer = fastPointer->next->next;
	}
	return slowPointer;
}

/*
** Checks if given List is palindrome
** -------------------------------------------
** Partition the original list into two lists and 
** reverse the second half of list.
** Then check if the second half is equal to the first half.
*/
void palidrome(Node* head, Node* midHead){
	Node* otherHalf = midHead->next;
	midHead->next = NULL;

	// Reverse second List
	Node *prev = NULL, *curr = otherHalf, *next = NULL;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	otherHalf = prev;

	// Check palindrome
	bool isPalindrome = true;
	while(head!=NULL && otherHalf!=NULL){
		if(head->data != otherHalf->data){
			isPalindrome = false;
			break;
		}
		head = head->next;
		otherHalf = otherHalf->next;
	}

	if(otherHalf==NULL){
		if(head!=NULL && head->next!=NULL){
			isPalindrome = false;
		}
	}

	if(isPalindrome)
		cout<<"Given List is a Palindrome\n";
	else
		cout<<"Given List is not a Palindrome\n";
}

/*
** Main Function
*/

int main(){
	Node* head1=NULL;
	insertEnd(&head1,1);
	insertEnd(&head1,3);
	insertEnd(&head1,7);
	insertEnd(&head1,7);
	insertEnd(&head1,3);
	insertEnd(&head1,1);
	Node* midPointer = mid(head1);
	palidrome(head1, midPointer);

	Node* head2=NULL;
	insertEnd(&head2,1);
	insertEnd(&head2,3);
	insertEnd(&head2,7);
	insertEnd(&head2,3);
	insertEnd(&head2,1);
	midPointer = mid(head2);
	palidrome(head2, midPointer);

	Node* head3=NULL;
	insertEnd(&head3,1);
	insertEnd(&head3,3);
	insertEnd(&head3,7);
	insertEnd(&head3,9);
	insertEnd(&head3,12);
	midPointer = mid(head3);
	palidrome(head3, midPointer);
	return 0;
}