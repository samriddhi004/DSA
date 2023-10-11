// given the two crystal balls that will break if dropped
// from high enough distance, determine the exact spot
// in which it will break in the most optimized way.

#include <iostream>
#include <math.h>
using namespace std;
int search(int *arr,int bheight){
    int rn=0,i,lim = sqrt(bheight);
    while(rn<bheight){
        rn+= lim;
        if(arr[rn]){
            for(i=rn;i>0;i--){
                if(!(arr[i])){
                return i+1;
                
                }
            }
        
       } 
    }
return -1; 
}
int main(){
    int a[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout<<"critical point found at: "<<search(a,sizeof(a)/sizeof(a[0]));
    return 0;
}