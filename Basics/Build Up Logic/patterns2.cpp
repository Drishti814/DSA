#include<iostream>
using namespace std;

void print12(int n) {
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=i; j++){
			cout << j;
		}
        for(int k = 1; k<=(n*2)-(i*2); k++){
            cout << " ";
        }
        for(int j = i; j>=1; j--){
			cout << j;
		}
		cout << endl;
	}
}

void print13(int n) {
    int num = 1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=i; j++){
			cout << num <<" ";
            num+=1;
		}
		cout << endl;
	}
}

void print14(int n) {;
	for(int i = 0; i<n; i++){
		for(char j = 'A'; j<='A'+i; j++){
			cout << j <<" ";
		}
		cout << endl;
	}
}

void print15(int n) {;
	for(int i = n; i>0; i--){
		for(char j = 'A'; j<'A'+i; j++){
			cout << j <<" ";
		}
		cout << endl;
	}
}

void print16(int n) {;
	for(int i = 0; i<n; i++){
        char ch = 'A' + i;
		for(int j = 0; j<=i; j++){
			cout << ch <<" ";
		}
		cout << endl;
	}
}

void print17(int n) {;
	for(int i = 0; i<n; i++){
		for (int x = n; x >i+1; x--){
			cout << " ";
		} 
		for(char j = 'A'; j< 'A'+i+1; j++){
			cout << j;
		}
        for(char j = 'A'+i-1; j>='A'; j--){
			cout << j;  
		}
        for (int x = n; x >i+1; x--){
			cout << " ";
		}
		cout << endl;
	}
}

void print18(int n) {;
	for(int i = 0; i<n; i++){ 
        for(char j = i; j>=0; j--){
            cout << char(65+n-j-1);
        }
        cout << endl;
    }
}

void print19(int n){
	for(int i = 0; i<n; i++){
		for(int j = n; j>i; j--){
			cout << "*";
		}
		for(int k = 0; k<= i*2 -1; k++){
			cout << " ";
		}
        for(int j = n; j>i; j--){
			cout << "*";
		}
		cout << endl;
	}
    for(int i = 1; i<=n; i++){
		for(int j = 1; j<=i; j++){
			cout << "*";
		}
        for(int k = 1; k<=(n*2)-(i*2); k++){
            cout << " ";
        }
        for(int j = i; j>=1; j--){
			cout << "*";
		}
		cout << endl;
	}
}

void print20(int n){
    for(int i = 1; i<=n; i++){
		for(int j = 1; j<=i; j++){
			cout << "*";
		}
        for(int k = 1; k<=(n*2)-(i*2); k++){
            cout << " ";
        }
        for(int j = i; j>=1; j--){
			cout << "*";
		}
		cout << endl;
	}
    for(int i = 1; i<n; i++){
		for(int j = n; j>i; j--){
			cout << "*";
		}
		for(int k = 0; k<= i*2 -1; k++){
			cout << " ";
		}
        for(int j = n; j>i; j--){
			cout << "*";
		}
		cout << endl;
	}
}

void print21(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

void print22(int n){
    for(int i = 0; i<n*2-1; i++){
        for(int j = 0; j<n*2 - 1; j++){
            int top = i;
			int bottom = n*2 - 2 - i;
			int left = j;
			int right = n*2 - 2 - j;
			cout << (n-min(min(top,bottom),min(left,right)));
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
	//print12(n);
	//print13(n);
	//print14(n);
	//print15(n);
	//print16(n);
	//print17(n);
	//print18(n);	//note
	//print19(n);
	//print20(n);
	//print21(n);
	//print22(n);	//note
}