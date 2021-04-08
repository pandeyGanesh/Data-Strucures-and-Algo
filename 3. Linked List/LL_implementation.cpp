/*
** Linked List Implementation
** -------------------------------------------
** Method_Name -- Arguments Used
**
** insertEnd -- Head pointer, Data to insert
** -- Inserts Data element at the End of Linked List
**
** insertBegin -- Head pointer, Data to insert
** -- Inserts Data element at the Beginning of Linked List
**
** insertIndex -- Head pointer, Data to insert, Index value
** -- Inserts Data element at the index position of Linked List
**
** deleteBeg -- Head pointer
** -- Deletes First Node of Linked List
**
** deleteEnd -- Head pointer
** -- Deletes Last Node of Linked List
**
** deleteValue -- Head pointer, Data to delete
** -- Deletes single instance of Data from Linked List
** 
** deleteAllValue -- Head pointer, Data to delete
** -- Delete all instances of Data from Linked List
**
** deleteIndex -- Head pointer, Index value
** -- Delete Node present at given index value from Linked List
** 
** clear -- Head pointer
** -- Clear contents of Linked List
**
** scanList -- Head pointer
** -- Prints whole list
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

void insertIndex(Node** head, int data, int index){
	Node *newNode = new Node(data);
	if(*head==NULL || index==0){
		newNode->next = *head;
		*head = newNode;
	}
	else{
		Node* prev = *head;
		while(index>1 && prev!=NULL){
			prev = prev->next;
			--index;
		}

		if(prev!=NULL){
			newNode->next = prev->next;
			prev->next = newNode;
		}
		else{
			cout<<"\nIndex provided is out of Array bounds.\n";
		}
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

void deleteEnd(Node** head){
	if(*head!=NULL){
		Node* temp = *head;
		Node* prev = NULL;
		while(temp->next != NULL){
			// Until temp reaches the last element of list
			prev = temp;
			temp = temp->next;
		}

		if(prev==NULL){
			// There exists only one element in the list.
			*head = NULL;
		}
		else{
			prev->next = NULL;
		}
		delete temp;
	}
}

void deleteValue(Node** head, int value){
	Node* curr = *head;
	if(curr->data == value){
		// If the value to delete is at head
		*head = (*head)->next;
		delete curr;
	}
	else{
		Node* prev = NULL;
		Node *next;
		while(curr!=NULL){
			next = curr->next;
			if(curr->data == value){
				prev->next = next;
				delete curr;
				break;
			}
			prev = curr;
			curr = next;
		}
	}
}

void deleteAllValue(Node** head, int value){
	Node* curr = *head;
	while(curr->data==value){
		// If the value to delete is at head
		*head = (*head)->next;
		delete curr;
		curr = *head;
	}

	Node* prev = NULL;
	Node *next;
	while(curr!=NULL){
		next = curr->next;
		if(curr->data == value){
			// current node is deleted, so previous will remain same
			// and current will move forward, as the node in between
			// no longer exists.
			prev->next = next;
			delete curr;
		}
		else{
			// If node is not delted, move ahead a node
			prev = curr;
		}
		curr = next;
	}
}

void deleteIndex(Node** head, int index){
	if(index==0 && *head!=NULL){
		Node* temp = *head;
		*head = (*head)->next;
		delete temp;
	}
	else{
		Node* prev = *head;
		while(index>1 && prev!=NULL){
			--index;
			prev = prev->next;
		}

		if(prev== NULL || prev->next==NULL){
			cout<<"\nDeletion of index is not possible.\n";
		}
		else{
			Node *temp = prev->next;
			prev->next = prev->next->next;
			delete temp;
		}
	}
}

void clear(Node** head){
	Node* next;
	while(*head!=NULL){
		next = (*head)->next;
		delete (*head);
		*head = next;
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
** Main Function
*/

int main(){
	Node* head=NULL;
	
	insertIndex(&head,50,5);
	insertIndex(&head,70,1);
	insertIndex(&head,80,2);
	insertIndex(&head,40,0);
	insertIndex(&head,40,5);
	scanList(head);
	deleteIndex(&head,1);
	deleteIndex(&head,7);
	scanList(head);
	return 0;
}
