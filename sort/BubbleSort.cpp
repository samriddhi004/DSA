//1st loop goes n-1,then n-2,n-3,n-4,n-5
//
#include <iostream>
using namespace std;
int bubsort(int *arr,int n){
    for (int i=0;i<n;i++){
        for(int j =0;j<n-1-i;j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            } 
        }
    }
    for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int a[5]  = {5,4,3,2,1};
    bubsort(a,sizeof(a)/sizeof(a[0]));
}