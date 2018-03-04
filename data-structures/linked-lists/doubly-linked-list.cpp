
#include <iostream>
using namespace std;
#include <malloc.h>


struct nodeDLL{
    int data;
    struct nodeDLL *next;
    struct nodeDLL *prev;
};

struct nodeDLL *headDLL = NULL;

void reverseTraversalDLL(){
    cout<<"Doubly Linked List Reverse Traversal: ";

    struct nodeDLL *temp = headDLL;
    if(headDLL == NULL){
        cout<<"DLL is empty...";
        return;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }

        while(temp!= headDLL){
            cout<<temp->data<<"-->";
            temp = temp->prev;
        }
        cout<<temp->data<<"\n";
    }
}
void displayDoublyLinkedList(){
    cout<<"Doubly Linked List: ";
    struct nodeDLL *temp = headDLL;
    if(headDLL==NULL){
        return;
    }
    while(temp->next !=NULL){
        cout<< temp->data << "-->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
void searchNodeDLL(int val){
    cout<<"Searching "<<val<<"...\t";
    struct nodeDLL *temp = headDLL;
    if(headDLL == NULL){
        cout<<"Oops list is empty"<<endl;
        return;
    }
    else{
        int count = 0;
        while(temp!= NULL){
            if(temp->data == val){
                cout<<"Success : Value "<<val<<" exists at index : "<<count<<endl;
                return;
            }
            temp = temp->next;
            count += 1;
        }
        cout<<"Error : Value "<<val<<" doesn't exist in Linked List"<<endl;
    }
}

void deleteNodeDLL(int val){
    cout<<"Deleting "<<val<<"...\t";
    struct nodeDLL *temp = headDLL;
    if(headDLL == NULL){
        cout<<"Oops list is empty"<<endl;
        return;
    }
    else{
        while(temp->next != NULL){
            if(temp->next->data == val){
                struct nodeDLL *node_to_be_freed = temp->next;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                node_to_be_freed->next = NULL;
                node_to_be_freed->prev = NULL;
                free(node_to_be_freed);
                break;
            }
            temp = temp->next;
        }
        if(temp->next == NULL){
            cout << "Error : Value "<< val<<" doesn't exist in Linked Listt"<<endl;
        }
    }

    displayDoublyLinkedList();
}

void insertNodeInDLL(int val){
    cout<<"Inserting in doubly linked list "<<val<<"...\t";
    struct nodeDLL *new_node = (struct nodeDLL*) malloc(sizeof(struct nodeDLL));
    new_node->data= val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(headDLL == NULL){
        headDLL = new_node;

    }
    else{
        struct nodeDLL *temp = headDLL;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    displayDoublyLinkedList();
}


int main() {
	// your code goes here
	int a []= {1,3,4,5,6,7,8,2};

	for(int i=0; i<(sizeof(a)/sizeof(*a)); i++){

	    //Double Link List Insertion
	    insertNodeInDLL(a[i]);


	}

	//Reverse Traversal of DLL
	reverseTraversalDLL();

	//deleting node in DLL
	deleteNodeDLL(4);

	//Searching a node in DLL
	searchNodeDLL(8);

	return 0;
}
