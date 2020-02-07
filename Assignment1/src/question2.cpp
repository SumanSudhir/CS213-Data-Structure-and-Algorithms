#include<bits/stdc++.h>

using namespace std;

void maximiseProfit(vector<int> v){
    int buy = v[0];
    int buy_day = 0;
    int sell = v[v.size()-1];
    int best_deal = sell-buy;

    for(int i=0;i<v.size();i++){
        int temp_buy_day,temp_sell_day;
        if(buy>v[i]){
            buy = v[i];
            temp_buy_day = i;
            sell = v[v.size()-1];
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
    vector<int> price;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        price.push_back(temp);
    }
    maximiseProfit(price);
}
