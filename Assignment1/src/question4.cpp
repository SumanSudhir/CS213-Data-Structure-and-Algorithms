#include<bits/stdc++.h>

using namespace std;

vector<int> alternateSorting( vector<int>v1, vector<int>v2){
    int n = v1.size() + v2.size();
    int p = 0;
    int q = 0;
    // cout<<v1.size()<<endl;
    vector<int> output;
    for(int i=0;i<n;i++){
        if(p<v1.size() && q<v2.size() && v1[p] <= v2[q]){
            output.push_back(v1[p]);
            p++;
        }
        else if(p<v1.size() && q<v2.size() && v1[p] > v2[q]){
            output.push_back(v2[q]);
            q++;
        }
        else if(p==v1.size() && q<v2.size()){
            output.push_back(v2[q]);
            q++;
        }
        else if(q==v2.size() && p<v1.size()){
            output.push_back(v1[p]);
            p++;
        }
    }
    return output;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr1, arr2;
    int temp;
    bool flag = true;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(i==0){
            arr1.push_back(temp);
        }
        else if(flag == true && temp>=arr1[i-1]){
            arr1.push_back(temp);
        }
        else{
            arr2.push_back(temp);
            flag = false;
        }
    }

    vector<int> result = alternateSorting(arr1, arr2);
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
