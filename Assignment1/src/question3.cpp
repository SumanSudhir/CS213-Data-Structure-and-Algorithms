#include<iostream>

using namespace std;
int chocolatePacking(int n, int v[]){
    float ppc[n];
    for(int i=0;i<n;i++){
        ppc[i] = v[i]/(i+1);
    }
    
    int price = 0;
    int count = n;
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
    int revenue[n];
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        revenue[i] = temp;
    }
    int x = chocolatePacking(n,revenue);
    cout<<x<<endl;
}
