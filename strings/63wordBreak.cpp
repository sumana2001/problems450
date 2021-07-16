#include<bits/stdc++.h>
using namespace std;

bool dictContains(string s){
    string dictionary[]={"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
    int n=sizeof(dictionary)/sizeof(dictionary[0]);
    for(int i=0;i<n;i++){
        if(dictionary[i].compare(s)==0)
            return true;
    }
    return false;
}

bool wordBreak(string s){
    int n=s.size();
    if(n==0)
        return true;
    bool wb[n+1];
    memset(wb,false,sizeof(wb));
    for(int i=1;i<=n;i++){
        if(wb[i]==false && dictContains(s.substr(0,i)))
            wb[i]=true;
        if(wb[i]==true){
            if(i==n)
                return true;
            for(int j=i+1;j<=n;j++){
                if(wb[j]==false && dictContains(s.substr(i,j-1)))
                    wb[j]=true;
                if(j==n && wb[j]==true)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}