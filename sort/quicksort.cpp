//assuming partition always at middle ie best case :so time complexity is O(nlogn)
// => n/2^k=1 so, k= log_base2_(n) 
// worst case is if the array is already sorted
#include <bits/stdc++.h>
using namespace std;
int partition(int l,int h,vector<int> a){
    int pivot = a[l];
    int i=l;int j=h;

    while(i<j){
    do{
        i++;
    }while(a[i]<=pivot);
    do{
        j--;    
    }while(a[j]>pivot);
    if(i<j){
        swap(a[i],a[j]);
    }
    }
    swap(a[l],a[j]);
    return j;
}
void quicksort(int l,int h,vector<int> a){

    if(l<h){
        int j = partition(l,h,a);
        quicksort(l,j,a);
        quicksort(j+1,h,a);
    }

}
int main(){
    vector<int> a ={1,5,2,4,3};
    quicksort(0,a.size()-1,a);
    cout<<"Sorted "<<" ";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}