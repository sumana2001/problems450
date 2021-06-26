#include<bits/stdc++.h>
using namespace std;

int multiply(int x, int res[], int size)
{
    int carry = 0; 
    for (int i=0; i<size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10; 
        carry  = prod/10;   
    }
    while (carry)
    {
        res[size] = carry%10;
        carry = carry/10;
        size++;
    }
    return size;
}

void factorial(int n){
    int res[500];
    res[0] = 1;
    int size = 1;
    for (int i=2; i<=n; i++)
        size = multiply(i, res, size);
    for(int i=size-1;i>=0;i--){
        cout<<res[i];
    }
}

int main(){
    int n=100;
    //correct ans=93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
    factorial(n);
    return 0;
}