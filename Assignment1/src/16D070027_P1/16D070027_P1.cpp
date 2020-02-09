// #include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

struct idMarks{
    int student_id;
    int marks;
};

list<int> fetchMarksQuery(idMarks im[], int n, int x, int y){
    list<int> output;
    for(int i=0;i<n;i++){
        if(im[i].marks>=x && im[i].marks<=y){
            output.push_back(im[i].student_id);
        }
        if(im[i].marks<x){
            break;
        }
    }
    return output;
}

bool check(idMarks im1, idMarks im2){
    if(im1.marks>=im2.marks){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    idMarks im[n];
    int id;
    int marks;
    for(int i=0;i<n;i++){
        cin>>im[i].student_id;
        cin>>im[i].marks;
    }
    sort(im,im+n,check);
    int q;
    cin>>q;
    int range[q][2];
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        range[i][0] = x;
        range[i][1] = y;
    }
    cout<<endl;

    for(int i=0;i<q;i++){
        list<int> query;
        cout<<range[i][0]<<" "<<range[i][1]<<endl;
        query = fetchMarksQuery(im,n,range[i][0],range[i][1]);
        while(!query.empty()){
            cout<<query.front()<<endl;
            query.pop_front();
        }
    }
}
