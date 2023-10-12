#include <iostream>
using namespace std;
int LinearSearch(int *arr,int val){
    for(int i =0;i<sizeof(arr);i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}
int main(){
    int a[4]={1,2,3,4};
    int val= 4;
    cout<<"found at index: "<<LinearSearch(a,val);

}
