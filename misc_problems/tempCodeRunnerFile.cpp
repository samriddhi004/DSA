#include <bits/stdc++.h>

using namespace std;

int binarysearch(const string& target,vector<string>& words){
    int hi = words.size();
    int lo = 0;
    
    while(hi>lo){
        int mid = lo + (hi-lo)/2;
        if(target==words[mid]){
            return mid;
        }
        else if(target>words[mid]){
            lo = mid+1;
        }
        else{
            hi=mid;
        }
    }
    return lo;
}
int main() {
    int N,Q,k;
    vector<string> words;
    vector<int> op;
    vector<pair<string,int>> wordsx;
    cin >> N >> Q;
    for(int i =0;i<N;i++){
        string word;
        cin>>word;
        words.push_back(word);
    }
    for (int i = 0; i < Q; i++) {
        string word;
        int x;
        cout << "Enter word and x:  "<<endl;
        cin >> word >>x ;
        wordsx.push_back(make_pair(word, x));
    }
    sort(words.begin(),words.end());
    for(int i=0;i<Q;i++){    
        // int pgnum=ceil((float)N/(float)wordsx[i].second);
        k=binarysearch(wordsx[i].first,words);
        if(k==-1){
            cout<<-1<<endl;
        }
        else{
            cout<<(k/wordsx[i].second)+1<<endl;
        }
    }
    return 0;
}