/*
** For given linked list
** 1 -- 2 -- 3 -- 4 -- 5 
** Reorder it such that
** 1 -- 5 -- 2 -- 4 -- 3
** -------------------------------------------
** Approach:
** We partition the list in 2 sub-lists, diving from the mid
** We reverse the second sub-list
** Then we Link the two lists as, first of L1 points to first of L2
** first of L2 poitns to second of L1 and so on.
** -------------------------------------------
**
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
** Finding Mid point of Linked List
*/
Node* findMid(Node* head){
	Node* temp = new Node();
	temp->next = head;

	Node* slow = temp;
	Node* fast = temp;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	temp = slow->next;
	slow->next = NULL;
	return temp;
}

/*
** Reverse the Linked List
*/
void reverse(Node** head){
	Node* prev = NULL;
	Node* curr = *head;
	Node* next = NULL;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

/*
** Reordering the two lists
*/
Node* reorder(Node* head1, Node* head2){
	// Size of first list is always greater than or equal to list 2
	Node* finalHead = head1;
	Node* curr1 = head1;
	Node* curr2 = head2;
	bool changeFirst = true;
	while(head1!=NULL || head2!=NULL){
		if(changeFirst){
			curr1 = head1->next;
			head1->next = curr2;
			head1 = curr1;
			changeFirst = false;
		}
		else{
			curr2= head2->next;
			head2->next = curr1;
			head2 = curr2;
			changeFirst = true;
		}
	}
	return finalHead;
}

/*
** Main Function
*/

int main(){
	Node* head1=NULL;
	insertEnd(&head1,1);
	insertEnd(&head1,2);
	insertEnd(&head1,3);
	insertEnd(&head1,4);
	insertEnd(&head1,5);
	insertEnd(&head1,6);
	scanList(head1);
	Node* afterMid = findMid(head1);
	reverse(&afterMid);
	Node* finalList = reorder(head1, afterMid);
	scanList(finalList);
	return 0;
}