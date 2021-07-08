//Given an array of strings dates[], the task is to sort these dates in ascending order.Each date is of the form dd/mm/yyyy.
#include<bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2){
    string sy1=s1.substr(6,4);
    string sy2=s2.substr(6,4);
    if(sy1<sy2){
        return true;
    }
    else if(sy1>sy2){
        return false;
    }
    string sm1=s1.substr(3,2);
    string sm2=s2.substr(3,2);
    if(sm1<sm2){
        return true;
    }
    else if(sm1>sm2){
        return false;
    }
    string sd1=s1.substr(0,2);
    string sd2=s2.substr(0,2);
    if(sd1<sd2){
        return true;
    }
    else if(sd1>sd2){
        return false;
    }
    return true;
}

int main(){
    int n=2;
    string dates[]={"22/08/2019","10/08/2019"};
    sort(dates,dates+n,solve);
    for(int i=0;i<n;i++){
        cout<<dates[i]<<" ";
    }
    return 0;
}