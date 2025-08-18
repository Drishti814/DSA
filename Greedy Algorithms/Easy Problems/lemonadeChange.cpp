#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//TC O(N)
//SC O(1)
bool lemonadeChange(vector<int> &money){
    int five = 0;
    int ten = 0;
    int twenty = 0;
    for(int i = 0;i<money.size();i++){
        if(money[i]==5){
            five++;
        }
        else if(money[i]==10){
            if(five){
                five--;
                ten++;
            } 
            else return false;
        }
        else{
            if(five && ten){
                ten--;
                five--;
                twenty++;
            }
            else if(five>=3){
                five = five-3;
                twenty++;
            }
            else return false;
        }
    }
    return true;
}

int main(){
    vector<int> money = {5,5,5,10,20};
    int ans = lemonadeChange(money);
    cout << ans;
}