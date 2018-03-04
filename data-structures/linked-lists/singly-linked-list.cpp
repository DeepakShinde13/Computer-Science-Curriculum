#include <iostream>
#include <malloc.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void displayList(){
    cout<<"Linked List: ";
    struct node *temp = head;
    if(head==NULL){
        return;
    }
    while(temp->next !=NULL){
        cout<< temp->data << "-->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void insertNode(int val){
    cout<<"Inserting "<< val <<"...\t";
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data= val;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;

    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    displayList();

}

void deleteNode(int val){
    cout<<"Deleting "<<val<<"...\t";
    struct node *temp = head;
    if(head==NULL){
        cout<<"Oops list is empty"<<endl;
        return;
    }
    else{
        while(temp->next != NULL){
            if(temp->next->data == val){
                struct node *node_to_be_freed = temp->next;
                temp->next = temp->next->next;
                node_to_be_freed->next = NULL;
                free(node_to_be_freed);
                break;
            }
            temp = temp->next;
        }
        if(temp->next == NULL){
            cout << "Error : Value "<< val<< " doesn't exist in Linked Listt"<<endl;
        }
    }

    displayList();
}

void searchNode(int val){
    cout<<"Searching "<<val<<"...\t";
    struct node *temp = head;
    if(head==NULL){
        cout<<"Oops list is empty"<<endl;
        return;
    }
    else{
        int count = 0;
        while(temp!= NULL){
            if(temp->data == val){
                cout<<"Success : Value "<< val << " exists at location : "<<count<<endl;
                return;
            }
            temp = temp->next;
            count += 1;
        }
        cout<<"Error : Value "<<val<<" doesn't exist in Linked List"<<endl;
    }
}
int main(){
    int a []= {1,3,4,5,6,7,8,2};

	for(int i=0; i<(sizeof(a)/sizeof(*a)); i++){

	    //Single Link List Insertion
	    insertNode(a[i]);

	}

	//deleting node in SLL
	deleteNode(4);

	//searching a node in SLL
    searchNode(8);

	return 0;
}
