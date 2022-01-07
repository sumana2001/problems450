#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        if(n==1)
            cout<<"No\n";
        else{
            int count=0,index=0;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    count++;
                    index=i+1;
                }
            }
            if((count==1 && index==n) || count==0)
                cout<<"No\n";
            else
                cout<<"Yes\n";
        }
    }
    return 0;
}