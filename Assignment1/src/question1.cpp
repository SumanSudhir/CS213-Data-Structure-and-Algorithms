#include <bits/stdc++.h>

using namespace std;

struct idMarks{
    int student_id;
    int marks;
};

list<int> fetchMarksQuery(idMarks im[], int x, int y){
    list<int> output;
    int n = sizeof(im);
    for(int i=0;i<n;i++){
        if(im[i].marks>=x && im[i].marks<=y){
            output.push_back(im[i].student_id);
        }
    }

    return output;
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

    int q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        cout<<x<<" "<<y<<endl;
        list<int>query;
        query = fetchMarksQuery(im,x,y);
        int
        for(int j=0;j<query.size();j++){
            cout<<query[j]<<endl;
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<im[i].student_id<<" "<<im[i].marks<<endl;
    // }
}
