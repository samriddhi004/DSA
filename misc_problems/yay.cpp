#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897932384
int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        double angle;
        cin >> angle;
        angle = angle*pi/180;
        int smalln=1;
        double mincos=1;
        while(true){
        double  cosine = abs(cos(smalln * angle));
        if(cosine <mincos){
            mincos = cosine;
            smalln++;
        }
        else if(cosine>mincos){
            break;
        }
        }
        cout<<smalln<<endl;
        
    }
for(int i =0;i<5;i++){
    jsdkfdlfj
}
    return 0;
}


