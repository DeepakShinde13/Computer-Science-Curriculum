#include <iostream>
using namespace std;

//this code covers the basic insertion sort

void print_array(int a[], int n){
    for(int i = 0; i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertion_sort(int a[], int n){
    int j;
    for(j=1; j<=n; j++){
        int key = a[j];
        int i = j-1;
        while(i>=0 && a[i]>=key){
            a[i+1]=a[i];
            i-=1;
        }
        a[i+1] = key; //since i is decremented in while loop above right place to insert is i+1;
    }
    print_array(a,n);

}
int main()
{
    int a [] = {-2,-10,7,8,2,1,3,9,5};
    insertion_sort(a, sizeof(a)/sizeof(*a));
}
