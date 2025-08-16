#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int num;
    cin >> num;
    //O(n)
    for(int n = 1;n<=num;n++){
        if(num % n == 0){
            //cout << n << " ";
        }
    }

    //overall - O(nlogn+sqrt(n) but factors in sqrt(n) time)
    //O(sqrt(n))
    vector<int> ls;
    for(int i = 1;i*i<=num;i++){    //i<=sqrt(num) it takes more time
        if(num % i == 0){
            ls.push_back(i);
            if(num/i != i){
            ls.push_back(num/i);
        }
        }
    }
    //O(nlogn)-where n=number of factors
    sort(ls.begin(),ls.end());
        for(auto it : ls){
            cout << it << endl;
        } 
    
}

