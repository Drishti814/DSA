#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//TC O(N)
//SC O(1)
bool jumpGame(vector<int> &jump){
    int maxIndex = 0;
    for(int i = 0;i<jump.size();i++){
        if(i>maxIndex) return false;
        maxIndex = max(maxIndex,i+jump[i]);
        if(maxIndex>=jump.size()) break;
    }
    return true;
}

int main(){
    vector<int> jump = {1,2,4,1,1,0,2,5};
    bool ans = jumpGame(jump);
    cout << ans;
}
