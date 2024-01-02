#include <bits/stdc++.h>
using namespace std;

    void merge(vector<int>& a,int l,int mid,int h){
        int i =l;int j=mid+1;int k=l;
        vector<int>c(h+1);
        while(i<=mid && j<=h)
         {
            if(a[i]<=a[j])
            {
            c[k++]=a[i++];
            }
            else
            c[k++]=a[j++];
        }
        for(;i<=mid;i++){  
            c[k++]=a[i]; 
        }
        for(;j<=h;j++){
            c[k++]=a[j];
        }
        for (int x = l; x <= h; x++) 
        {
        a[x] = c[x];
        }

        
    }
    void mergesor(vector<int>& a,int l, int h){
        if(l<h){
            int mid = (l+h) /2;
            mergesor(a,l,mid);
            mergesor(a,mid+1,h);
            merge(a,l,mid,h);

        }
    }
int main(){
    vector<int> a ={5,3,2,8,4,9,0};
    cout<<"unsorted list: "<<endl;
    for(int i =0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    mergesor(a,0,a.size()-1);
    cout<<endl<<endl<<"sorted list: "<<endl;
    for(int i =0;i<a.size();i++){
        cout<<a[i]<<" ";
    }

}