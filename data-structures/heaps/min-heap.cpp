#include<iostream>
using namespace std;

int a[] = {5, 1, 13, 2, 4, 8, 23, 98};

void min_heapify(int i, int heapSize){

    int smallest = -1;
    int left = 2*i+1;
    int right = 2*i+2;

    //this step is important to break the recursion.
    //not given in CLRS
    if (left>=heapSize && right >= heapSize)
        return;
    //finding the index of smallest element
    // from root, it's left child and right child;

    if (left < heapSize && a[left]<a[i])
        smallest = left;
    else
        smallest = i;

    if(right < heapSize && a[right]<a[smallest])
        smallest = right;

    //swap the root with smallest element
    if(smallest != i && smallest!=-1){
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;

        //now calling max_heapify on the largest index again
        //only call min_heapify on the smallest index if it's changing otherwise no use
        min_heapify(smallest, heapSize);
    }



}

void build_min_heap(){

    //find the size of heap
    int arraySize = sizeof(a)/sizeof(a[0]);

    for(int i = (arraySize/2)-1; i>=0; i--){
        //call min heapify for non leaf nodes;
        min_heapify(i, arraySize);
    }
}


void display_min_heap(){

    //print the array
    for(int i =0 ; i<sizeof(a)/sizeof(a[0]); i++){
        cout<< a[i] <<" ";
    }
    cout <<endl;
}
int main(){

    cout << "Given Array :";
    display_min_heap();

    //calling build_min_heap
    build_min_heap();

    //calling display
    cout<<"Min heap array: ";
    display_min_heap();

    return 0;
}

