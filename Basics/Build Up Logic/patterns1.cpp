#include<iostream>
using namespace std;


void print1(int n){
    for(int i = 0; i <n; i++){
        for(int j = 0; j <n ; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void print2(int n) {
	for(int i = 0; i<n; i++){
		for(int j = 0; j<=i; j++){
			cout << "* ";
		}
		cout << endl;
	}
}

void print3(int n) {
	for(int i = 0; i<n; i++){
		for(int j = 0; j<=i; j++){
			cout << j+1;
		}
		cout << endl;
	}
}

void print4(int n) {
	for(int i = 0; i<n; i++){
		for(int j = 0; j<=i; j++){
			cout << i+1;
		}
		cout << endl;
	}
}

void print5(int n) {
	for(int i = 0; i<n; i++){
		for(int j = n; j>i; j--){
			cout << "* ";
		}
		cout << endl;
	}
}

void print6(int n) {
	for(int i = n; i>0; i--){
		for(int j = 0; j<i; j++){
			cout << j;
		}
		cout << endl;
	}
}

void print7(int n) {
	for(int i = 0; i<n; i++){
		for (int x = n; x >i+1; x--){
			cout << " ";
		}
		for(int j = 0; j< (i*2+1); j++){
			cout << "*";
		}
		cout << endl;
	}
}

void print8(int n) {
	for(int i = n; i>0; i--){
		for(int x = n;x>=i+1;x--){
			cout <<" ";
		}
		for(int j = 0; j<i*2-1; j++){
			cout << "*";
		}
		cout << endl;
	}
}

void print9(int n) {
	for(int i = 0; i<n; i++){
		for (int x = n; x >i+1; x--){
			cout << " ";
		}
		for(int j = 0; j< (i*2+1); j++){
			cout << "*";
		}
		cout << endl;
	}
	for(int i = n; i>0; i--){
		for(int x = n;x>=i+1;x--){
			cout <<" ";
		}
		for(int j = 0; j<i*2-1; j++){
			cout << "*";
		}
		cout << endl;
	}
}

void print10(int n) {
	for(int i = 0; i<n; i++){
		for(int j = 0; j<=i; j++){
			cout << "*";
		}
		cout << endl;
	}
	for(int i = 0; i<n; i++){
		for(int j = n-1; j>i; j--){
			cout << "*";
		}
		cout << endl;
	}
}

void print11(int n) {
	for(int i = 0; i<n; i++){
		for(int j = 0; j<=i; j++){
			if ((i-j)%2==0){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		cout << endl;
	}
}

int main(){
    int n;
    cin >> n;
    //print1(n);
    //print2(n);
    //print3(n);
    //print4(n);
    //print5(n);
	//print6(n);
	//print7(n);
	//print8(n);
	//print9(n);
	//print10(n);
	//print11(n);
}