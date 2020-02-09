// #include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

struct idMarks{
    int student_id;
    int marks;
};

void merge(idMarks arr[], int left, int mid, int right){
    int n1 = mid-left+1;
    int n2 = right-mid;

    idMarks arr_l[n1];
    idMarks arr_r[n2];

    for(int i=0;i<n1;i++){
        arr_l[i] = arr[left+i];
    }

    for(int i=0;i<n2;i++){
        arr_r[i] = arr[mid+1+i];
    }

    int left_index = 0;
    int right_index = 0;

    for(int i=left;i<=right;i++){
        if((left_index < n1) && (right_index <n2) && (arr_l[left_index].marks <= arr_r[right_index].marks)){
            arr[i] = arr_l[left_index];
            left_index++;
        }

        else if((left_index < n1) && (right_index <n2) && (arr_l[left_index].marks > arr_r[right_index].marks)){
            arr[i] = arr_r[right_index];
            right_index++;
        }

        else if(left_index < n1 && right_index == n2){
            arr[i] = arr_l[left_index];
            left_index++;
        }
        else if(left_index == n1 && right_index < n2){
            arr[i] = arr_r[right_index];
            right_index++;
        }
    }
}

void merge_sort(idMarks arr[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr,left,mid,right);
    }
}

list<int> fetchMarksQuery(idMarks im[], int n, int x, int y){
    list<int> output;
    for(int i=0;i<n;i++){
        if(im[i].marks>=x && im[i].marks<=y){
            output.push_back(im[i].student_id);
        }
        if(im[i].marks>y){
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

    merge_sort(im,0,n-1);

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
