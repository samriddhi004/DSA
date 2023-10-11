//half the array until you get to your value
// run time = O(logN)
// [lo,hi)
// array gotta be sorted 
#include <iostream>
using namespace std;
int BinarySearch(int *arr, int val){
    int low = 0;
    int v;
    int high = sizeof(arr);
    int m = low +(high-low)/2;
    while(low<high){
        m =low +(high-low)/2;
        v= arr[m];
        if (v == val){
            return m;
        }
        else if(val>v){
            low = m+1;

        }
        else{
            high = m;
        }
        }
    return -1;
    }

int main(){
    int a[7]={1,2,3,4,5,6,7};
    int value = 3;
    cout<<"value found at index: "<<BinarySearch(a,value);
    return 0;
}