#include<iostream>
using namespace std;

int main(){
    //1D array
    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    cout << arr[4] << endl;

    //2D array
    int arr1[3][6];
    arr1[2][4]=10;
    cout << arr1[2][4] << endl << arr1[2][2] << endl ;

    //strings
    string s = "drishti";
    cout << s[6] << endl;
    int len = s.size();
    s[len-1] = 'y';
    cout << s[len-1];
 }
