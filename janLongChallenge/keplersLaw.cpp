#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int t, t1, t2, r1, r2;
    cin>>t;
    while(t--){
        cin>>t1>>t2>>r1>>r2;
        if(pow(t1,2)/pow(r1,3)==pow(t2,2)/pow(r2,3))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}