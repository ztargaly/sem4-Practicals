#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int row = 1;

    while(row<=n){
        int space = n -row;
        while(space){
        cout<<" ";
        space = space - 1;
    }
    int j = 1;
    while(j<=row){
        //cout<<j;
        cout<<"*";
        j = j+1;
    
    }
    int start = row - 1;
    while(start){
        //cout<<start;
        cout<<"*";
        start =start - 1;

    }
    cout<<endl;
    row = row +1;
}
}