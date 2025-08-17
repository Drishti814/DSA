#include<iostream>
#include<vector>
using namespace std;

//TC O(2k)
//SC O(1)
int maxSum(vector<int> &cards, int k){
    int n = cards.size();
    int sum = 0;
    int lSum = 0;
    int rSum = 0;
    for(int i = 0;i<k;i++){
        lSum += cards[i];
    }
    sum = lSum;
    int rindex = n-1;
    for(int i = k-1;i>=0;i--){
        lSum = lSum - cards[i];
        rSum = rSum + cards[rindex];
        rindex--;
        sum = max(lSum+rSum,sum);
    }
    return sum;
}

int main(){
    vector<int> cards = {6,2,3,4,7,2,1,7,1};
    int sum = maxSum(cards,4);
    cout << sum;
}