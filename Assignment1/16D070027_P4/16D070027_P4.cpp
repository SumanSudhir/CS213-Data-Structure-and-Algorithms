#include<iostream>

using namespace std;

int *alternateSorting(int v1[],int l,int v2[],int r){

    int n = l + r;
    int p = 0;
    int q = 0;
    // cout<<v1.size()<<endl;
    int* output = new int[n];;

    for(int i=0;i<n;i++){
        if(p<l && q<r && v1[p] <= v2[q]){
            output[i] = v1[p];
            p++;
        }
        else if(p<l && q<r && v1[p] > v2[q]){
            output[i] = v2[q];
            q++;
        }
        else if(p==l && q<r){
            output[i] = v2[q];
            q++;
        }
        else if(q==r && p<l){
            output[i] = v1[p];
            p++;
        }
    }

    return output;
}

int main(){
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    int l =0;
    int r = 0;
    int temp;
    bool flag = true;

    for(int i=0;i<n;i++){
        cin>>temp;
        if(i==0){
            arr1[l] = temp;
            l++;
        }
        else if(flag == true && temp>=arr1[i-1]){
            arr1[l] = temp;
            l++;
        }
        else{
            arr2[r] = temp;
            r++;
            flag = false;
        }
    }

    int* result = alternateSorting(arr1,l,arr2,r);

    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
