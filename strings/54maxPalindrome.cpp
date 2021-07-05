#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int maxLength=1;
    int start=0;
    int low,high;
    for(int i=1;i<s.length();i++){
        low=i-1;
        high=i;
        while(low>=0 && high<s.length() && s[low]==s[high]){
            if(high-low+1>maxLength){
                maxLength=high-low+1;
                start=low;
            }
            low--;
            high++;
        }
        low=i-1;
        high=i+1;
        while(low>=0 && high<s.length() && s[low]==s[high]){
            if(high-low+1>maxLength){
                maxLength=high-low+1;
                start=low;
            }
            low--;
            high++;
        }
    }
    for(int i=start;i<start+maxLength;i++){
        cout<<s[i];
    }
    return 0;
}