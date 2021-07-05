#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2, int m, int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(s1[m-1]==s2[n-1])
        return editDistance(s1,s2,m-1,n-1);
    return 1+min(editDistance(s1,s2,m,n-1),min(editDistance(s1,s2,m-1,n),editDistance(s1,s2,m-1,n-1)));
}

int editDistanceDP(string s1,string s2, int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j==0){
                dp[i][j]=i;
            }
            else if(i==0){
                dp[i][j]=j;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
    }
    return dp[m][n];
}

int main(){
    string str1 = "sunday";
    string str2 = "saturday";
    cout<<editDistanceDP(str1,str2,str1.length(),str2.length());
    return 0;
}