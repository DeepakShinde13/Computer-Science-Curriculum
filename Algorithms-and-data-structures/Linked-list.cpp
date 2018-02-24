#include <iostream>
#include <malloc.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void displayLinkedList(){
    cout<<"Link List : ";
    struct node *temp = head;
    if(head == NULL){
        return;
    }
    while(temp->next != NULL ){
        cout<<temp->data << "-->";
        temp = temp->next;
    }
    cout << temp->data << endl;

}
void insertNode(int val){

    cout<<"Inserting... "<<val<< "\t";
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;

    if ( head == NULL){
        head = new_node;
    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }


    //displaying the list
    displayLinkedList();
}
void deleteNode(int val){
    cout << "Deleting... " << val <<"\t";
    struct node *temp = head;
    if (head == NULL){
        cout<<"Oops.. List is empty"<<endl;
        return;
    }

    while(temp->next!= NULL){
        if(temp->next->data == val){
            struct node *node_to_be_removed = temp->next;
            temp->next = node_to_be_removed->next;
            node_to_be_removed = NULL;
            free(node_to_be_removed);
            displayLinkedList();
            return;
        }
        temp = temp->next;
    }

    cout<<"Error! "<<val<<" doesn't exist in the list"<<endl;
}

void searchNode(int val){
    cout<<"Searching "<< val <<"\t";

    struct node *temp = head;
    if (head == NULL){
        cout<<"Oops.. List is empty"<<endl;
        return;
    }

    int count = 0;
    while(temp->next!= NULL){
        if(temp->next->data == val){
            cout << "Success! "<< val<<" found at index "<<count <<endl;
            return;
        }
        temp = temp->next;
        count+=1;
    }

    cout<<"Error! "<<val<<" doesn't exist in the list"<<endl;

    }

int main(){
    int a[] = {7, 2, 5, 6, 73, 4, 25, 26};
    for(int i=0; i< sizeof(a)/sizeof(*a);i++){
        //inserting a node;
        insertNode(a[i]);
    }
    //deleting a node;
    deleteNode(2);
    deleteNode(100);

    //searching a node
    searchNode(73);
    searchNode(200);
    return 0;
}
