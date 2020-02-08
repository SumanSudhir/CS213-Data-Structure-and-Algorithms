#include<iostream>

using namespace std;

void maximiseProfit(int n, int v[]){
    int buy = v[0];
    int buy_day = 0;
    int sell = v[n-1];
    int best_deal = sell-buy;

    for(int i=0;i<n;i++){
        int temp_buy_day,temp_sell_day;
        if(buy>v[i]){
            buy = v[i];
            temp_buy_day = i;
            sell = v[n-1];
        }
        if( i > temp_buy_day && sell<v[i]){
            sell = v[i];
            temp_sell_day = i;
        }
        if((sell-buy) > best_deal){
            buy_day = temp_buy_day;
            best_deal = sell-buy;
        }
    }
    cout<<best_deal<<endl;
    cout<<buy_day+1<<endl;
}

int main(){
    int n;
    cin>>n;
    int price[n];
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        price[i] = temp;
    }
    maximiseProfit(n,price);
}
