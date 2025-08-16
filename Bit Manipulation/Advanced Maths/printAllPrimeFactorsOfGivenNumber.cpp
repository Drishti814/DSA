#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

bool checkPrime(int num){
    if (num < 2) return false;
    int count = 0;
    for(int n = 2;n<=num;n++){
        if(num % n == 0){
            count+=1;
        }
    }
    if(count == 2){
        return true;
    }
    return false;
}

bool checkPrimeOptimal(int num){
    if (num < 2) return false;
    int count = 0;
    for(int i = 2;i<=sqrt(num);i++){
        if(num % i == 0){
            count+=1;
            if(num/i != i){
                count+=1;
            }
            if(count > 2) break;
        }
    }
    if(count == 2){
        return true;
    }
    return false;
}

//TC O(sqrt(n)*n)
//SC O(number of prime factors)
vector<int> primeFactors(int num){
    vector<int> ans;
    for(int i = 2;i<=num;i++){
        if(num % i == 0){
            if(checkPrime(i)) ans.push_back(i);
        }
    }
    return ans;
}

//better
//TC ～ O(sqrt(n)*2*sqrt(n))
//SC O(number of prime factors)
vector<int> primeFactorsBetter(int num){
    vector<int> ans;
    for(int i = 2;i*i<=num;i++){    //i<=sqrt(num) it takes more time
        if(num % i == 0){
            if(checkPrimeOptimal(i)) ans.push_back(i);
            if(num/i != i){
                if(checkPrimeOptimal(num/i)) ans.push_back(num/i);
            }
        }
    }
    if(checkPrimeOptimal(num)) ans.push_back(num);
    return ans;
}

//optimal
//TC ～ O(sqrt(n)*log(n))
//SC O(number of prime factors)
vector<int> primeFactorsOptimal(int num){
    vector<int> ans;
    for(int i = 2;i*i<=num;i++){    //i<=sqrt(num) it takes more time
        if(num % i == 0){
            ans.push_back(i);
            while(num%i==0){
                num = num/i;
            }
        }
    }
    if(num!=1) ans.push_back(num);
    return ans;
}

int main(){
    int num;
    cin >> num;
    //vector<int> ans = primeFactors(num);
    //vector<int> ans = primeFactorsBetter(num);
    vector<int> ans = primeFactorsOptimal(num);
    for(auto it: ans){
        cout << it << " ";
    }
}