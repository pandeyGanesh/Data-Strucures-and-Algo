/*
** For 2 lists of the given form
** Find the common intersecting point of the lists
** [!] The two lists need not be of same length.
** a -- b -- c -- d -- e --
** 							\
** 							 ---- f -- g -- h -- i -- X
**							/
** z -- y -- x -- w -- v -- 
**
** -------------------------------------------
**
** Method_Name -- Arguments Used
**
** insertEnd -- Head pointer, Data to insert
** -- Inserts Data element at the End of Linked List
**
** insertCommon -- Head ponter of both lists and Common data element
** -- Inserts the common node in the end of both lists
**
** deleteBeg -- Head pointer
** -- Deletes First Node of Linked List
**
** scanList -- Head pointer
** -- Prints whole list
**
** findIntersection -- Head pointer of both the lists
** -- Finds and returns the pointer to intersection of both lists.
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

void insertCommon(Node** head1, Node** head2, int data){
	Node* newNode = new Node(data);
	if(*head1==NULL){
		*head1 = newNode;
	}
	else{
		Node* temp = *head1;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}

	if(*head2==NULL){
		*head2 = newNode;
	}
	else{
		Node* temp = *head2;
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
** Finding Inresection
*/

Node* findIntersection(Node* head1, Node* head2){
	Node* temp = head1;
	int length1 = 0;
	while(temp!=NULL){
		++length1;
		temp = temp->next;
	}

	temp = head2;
	int length2 = 0;
	while(temp!=NULL){
		++length2;
		temp = temp->next;
	}

	// List 1 is longer than List 2
	if(length1 > length2){
		int difference = length1-length2;
		while(difference--){
			head1 = head1->next;
		}
	}
	// List 2 is either longer or equal in length to List 1
	else{
		int difference = length2-length1;
		while(difference--){
			head2 = head2->next;
		}
	}

	while(head1!=NULL && head2!=NULL){
		if(head1->next == head2->next){
			return head1->next;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return NULL;
}

/*
** Main Function
*/

int main(){
	Node* head1=NULL;
	insertEnd(&head1,1);
	insertEnd(&head1,2);
	insertEnd(&head1,3);

	Node* head2=NULL;
	insertEnd(&head2,10);
	insertEnd(&head2,20);
	insertEnd(&head2,30);

	insertCommon(&head1, &head2, 7);

	insertEnd(&head1,8);
	insertEnd(&head1,9);

	insertEnd(&head2,41);
	insertEnd(&head2,42);

	scanList(head1);
	scanList(head2);

	Node *intersection = findIntersection(head1, head2);
	if(intersection==NULL){
		cout<<"\nNo intersection point found.\n";
	}
	else{
		cout<<"\nIntersection at Data element \t";
		cout<<intersection->data;
	}
	return 0;
}