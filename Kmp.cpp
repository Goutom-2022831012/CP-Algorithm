#include<bits/stdc++.h>
using namespace std ; 

vector<int> getlps(string st){
    int l = st.length();
    vector<int> lps(l,0);
    int i = 1 ; 
    int j = 0 ;
    while(i<l){
        if(st[i] = st[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return lps;
}
void KMP(string text , string pattern , vector<int> lps ){
    int l = text.length();
    int m  = pattern.length();
    int i= 0;
    int j = 0;
    while(i<l){
        if(text[i]==pattern[j]){
            i++;
            j++;
            if(j==m){
                cout<<i-j;
                j = lps[j-1];
            }
        }
        else{
            if(i<l && text[i]!=text[j]){
             if(j!=0){
                j = lps[j-1];
            }
            else {
                 i++;
            }
            }
            else i++;
        }
    }
}
int main(){
    string pattern ;cin>>pattern;
    string text ; cin>> text;
    vector<int> lps = getlps(pattern);
    KMP(text,pattern,lps);
    return 0;
}