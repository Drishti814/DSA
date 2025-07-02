#include<iostream>
using namespace std;

int main(){
    int marks;
    cin >> marks;
    if (marks>=90){
        cout << "Grade A" << endl;
    }
    else if (marks>=70){    //(marks>=70 && marks<90)needed if we use if instead of else if
        cout << "Grade B" << endl;
    }
    else if (marks>=50){
         cout << "Grade C" << endl;
    }
    else if (marks>=35){
        cout << "Grade D" << endl;
    }
    else{
        cout << "Fail" << endl;
    }
 }

 //else statement is not mandatory