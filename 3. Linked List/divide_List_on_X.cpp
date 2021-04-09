/*
** Re-arrange a Linked List such that all values less than X
** comes before all nodes greater than or equal to X.
** [!] Preserve the order of elements.
**
** For list: 1 7 3 9 2 5 8 4		X = 5
** Output: 1 3 2 4 7 9 5 8
** Explanation:
** 1,3,2,4 } all elements less than X are before
** 7,9,5,8 } all elements greater than equal to X
** and the order of elements is preserved.
** -------------------------------------------
** 
** divide -- Takes head pointer of list and value of X
** -- returns head pointer to rearranged list.
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
*/
Node* divide(Node* head, int X){
	Node *beforeX = new Node();
	Node *afterX = new Node();
	Node *headBefore = beforeX;
	Node *headAfter = afterX;

	while( head!=NULL ){
		if(head->data < X){
			beforeX->next = head;
			beforeX = beforeX->next;
		}
		else{
			afterX->next = head;
			afterX = afterX->next;
		}
		head = head->next;
	}
	Node *temp = headAfter;
	headAfter = headAfter->next;
	delete temp;
	temp = headBefore;
	headBefore = headBefore->next;
	delete temp;

	beforeX->next = headAfter;
	afterX->next = NULL;
	return headBefore;
}

/*
** Main Function
*/

int main(){
	Node* head=NULL;
	insertEnd(&head,1);
	insertEnd(&head,7);
	insertEnd(&head,9);
	insertEnd(&head,3);
	insertEnd(&head,5);
	insertEnd(&head,3);
	insertEnd(&head,8);
	insertEnd(&head,12);
	scanList(head);

	Node* newList = divide(head,5);
	scanList(newList);
	return 0;
}