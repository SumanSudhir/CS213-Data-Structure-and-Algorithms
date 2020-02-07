#include<bits/stdc++.h>

using namespace std;
int chocolatePacking(vector<int>v){
    vector<float> ppc;
    for(int i=0;i<v.size();i++){
        ppc.push_back(v[i]/(i+1));
    }

    int n = ppc.size();
    int price = 0;
    int count = v.size();
    while(count !=0){
        int max = 0;
        for(int i=0;i<n;i++){
            if(max<=ppc[i]){
                max = ppc[i];
                n = i+1;
            }
        }
        price = v[n-1]*(count/n);
        count = count%n;
    }

    return price;
}

int main(){
    int n;
    cin>>n;
    vector<int> revenue;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        revenue.push_back(temp);
    }
    int x = chocolatePacking(revenue);
    cout<<x<<endl;
}
