#include<iostream>
using namespace std;

int a[] = {5, 1, 13, 2};

void max_heapify(int i, int heapSize){


    int largest = -1;
    int left = 2*i+1;
    int right = 2*i+2;

    //this step is important to break the recursion.
    //not given in CLRS
    if (left>=heapSize && right >= heapSize)
        return;
    //finding the index of largest element
    // from root, it's left child and right child;

    if (left < heapSize && a[left]>a[i])
        largest = left;
    else
        largest = i;

    if(right < heapSize && a[right]>a[largest])
        largest = right;

    //swap the root with largest element
    if(largest != i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        //now calling max_heapify on the largest index again
        //call only when largest is changing
        max_heapify(largest, heapSize);

    }


}

void build_max_heap(){

    //find the size of heap
    int arraySize = sizeof(a)/sizeof(a[0]);

    for(int i = (arraySize/2)-1; i>=0; i--){
        //call max heapify for non leaf nodes;
        max_heapify(i, arraySize);
    }
}


void sadfa(){

    //print the array
    for(int i =0 ; i<sizeof(a)/sizeof(a[0]); i++){
        cout<< a[i] <<" ";
    }
    cout <<endl;
}
int main(){

    cout << "Given Array :";
    display_max_heap();

    //calling build_max_heap
    build_max_heap();

    //calling display
    cout<<"Max heap array: ";
    display_max_heap();

    return 0;
}
