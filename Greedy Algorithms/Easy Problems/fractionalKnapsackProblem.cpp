#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool comparison(Item &a, Item&b){
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;
    return r1 > r2;
}

//TC O(NlogN + N)
//SC O(1)
 double fractionalKnapsack(Item arr[], int n, int w){
    sort(arr,arr+n,comparison);
    double totalValue = 0;
    for(int i = 0;i<n;i++){
        if(arr[i].weight<=w){
            totalValue += arr[i].value;
            w -= arr[i].weight;
        }
        else{
            totalValue += ((double) arr[i].value / (double) arr[i].weight)*(double)(w);
            break;
        }
    }
    return totalValue;
}

int main(){
    int n = 4;
    int weight = 90;
    vector<Item> arr = {{100,20},{60,10},{100,50},{200,50}};
    double ans = fractionalKnapsack(arr.data(), n, weight);
    cout << ans;

} 