//hashing approach
#include<iostream>
using namespace std;

//total 256 character no size issue

int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;

    int hash[256] = {0};
    int n = s.size();
    for(int i = 0; i<n;i++){
        hash[s[i]]+=1;
    }

    while(q--){
        char c;
        cin >> c;
        cout << hash[c] << " ";
    }
}

//brute force approach
//(q*n) too much

/*
#include<iostream>
using namespace std;


int func(char c, string str){
    int count = 0;
    int n = str.size();
    for(int i=0;i < n;i++){
        if(str[i] == c){
            count+=1;
        }
    }
    return count;
}

int main(){
    string s;
    cin >> s;
    char c;
    cin >> c;
    int count = func(c,s);
    cout << count;
}
*/