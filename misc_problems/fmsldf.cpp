#include<iostream>
using namespace std;

int happyornot(int num){
   int m = num;
    int sum = 0;
    int max= 50;
    while (m != 1 && max> 0) {
        sum = 0;
        while (m > 0) {
            int last = m % 10;
            sum += last * last;
            m = m / 10;
        }
        m = sum;
        max--;

    }
    if(m==1){
        return 1;
    }
    return 0;
    }

int main()
{
    int count=0;
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        count =count + happyornot(i);
    }
    cout<<count;
    return 0;
}