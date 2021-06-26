#include<bits/stdc++.h>
using namespace std;

void findCommon(int a1[], int a2[], int a3[], int n1,int n2, int n3){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2 && k<n3){
        if(a1[i]==a2[j] && a2[j]==a3[k])
        {
            cout<<a1[i]<<" ";
            i++;
            j++;
            k++;
        }
        else if(a1[i]<a2[j])
            i++;
        else if(a2[j]<a3[k])
            j++;
        else
            k++;
    }
}

void findCommonSTL(int a1[], int a2[], int a3[], int n1,int n2, int n3){
    map<int,int> m1;
    map<int,int> m2;
    map<int,int> m3;

    for(int i=0;i<n1;i++)
        m1[a1[i]]++;
    for(int i=0;i<n2;i++)
        m2[a2[i]]++;
    for(int i=0;i<n3;i++)
        m3[a3[i]]++;

    for(int i=0;i<n1;i++){
        if(m1[a1[i]]>0 && m2[a1[i]]>0 && m3[a1[i]]>0)
            cout<<a1[i]<<" ";
        m1[a1[i]]=0;   
    }
}

int main(){
    int a1[] = {1, 5, 10, 20, 40, 80};
    int a2[] = {6, 7, 20, 80, 100};
    int a3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int n2 = sizeof(a2)/sizeof(a2[0]);
    int n3 = sizeof(a3)/sizeof(a3[0]);
 
    cout << "Common Elements are ";
    findCommonSTL(a1, a2, a3, n1, n2, n3);
    return 0;
}