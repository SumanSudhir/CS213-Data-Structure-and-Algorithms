#include<bits/stdc++.h>

using namespace std;

int *alternateSorting(int v1[],int l,int v2[],int r){

    int n = l + r;
    int p = 0;
    int q = 0;
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
    int n,k;
    cin>>n>>k;
    int temp;
    int arr[n*k];

    for(int j=0;j<n;j++){
        cin>>temp;
        arr[j] = temp;
    }

    for(int i=1;i<k;i++){
        int arr1[n];
        for(int j=0;j<n;j++){
            cin>>temp;
            arr1[j] = temp;
        }
        int* result = alternateSorting(arr,i*n,arr1,n);

        for(int m=0;m<(i+1)*n;m++){
            arr[m] = result[m];
        }
    }

    for(int i=0;i<k*n;i++){
        cout<<arr[i]<<" ";
    }
}
