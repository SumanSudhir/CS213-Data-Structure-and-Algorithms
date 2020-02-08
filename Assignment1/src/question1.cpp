#include<iostream>
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
    }
    return output;
}
//
// void merge(imMarks im,int l,int m,int r){
//
//     for(int i=0;i<n;i++){
//
//     }
// }
//
// idMarks sortStruct(idMarks im[], int l,int n){
//     if(n>l){
//         int m = (l+n)/2;
//         sortStruct(im,l,m);
//         sortStruct(im, m+1,n);
//         merge(im,l,m,r);
//     }
// }

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
