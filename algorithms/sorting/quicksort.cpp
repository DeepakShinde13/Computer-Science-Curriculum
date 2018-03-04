#include<iostream>
using namespace std;

void print_array(int a[], int n){
    for(int i = 0; i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int partition_array(int *a, int p, int r){
    int pivot = a[r];
    int i=p-1;
    for(int j=p; j<=r-1;j++){
        if(a[j]<=pivot){
            i+=1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quick_sort(int *a, int p, int r){
    if(p<r){
        int q = partition_array(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}

int main(){
    int a [] = {-2,-10,7,8,2,1,3,9,5};
    quick_sort(a,0, (sizeof(a)/sizeof(*a))-1);
    print_array(a,(sizeof(a)/sizeof(*a)));
    return 0;
}
