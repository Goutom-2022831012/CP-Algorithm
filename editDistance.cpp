#include<bits/stdc++.h>
using namespace std ; 

int editDistance(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> str(n+1 , vector<int> (m+1));
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if( i == 0 )
            str[i][j]= j ;
           else if( j == 0 )
            str[i][j] = i ;
           else if( s1[i-1] == s2[j-1]){
                str[i][j] = str[i-1][j-1];                                   
           }
           else str[i][j] = min({str[i-1][j] , str[i][j-1] , str[i-1][j-1]}) +1 ;

        }
    }
    return str[n][m];
}
int main(){
    string s1;
    string s2;
    cin >> s1 >> s2 ;
    cout << editDistance(s1,s2);
    return 0 ;
}