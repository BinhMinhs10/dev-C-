#include <iostream>
using namespace std;
int x=4;
int &myFunc(){
	int y = 5 + x;
	return x;
}
int main(){
	cout << "X= "<< x<<endl;
	cout << "myFunc()= "<< myFunc()<< endl;
	myFunc()=20;//nghia la x=20
	cout << "X= "<< x<<endl;
	cout << "myFunc()= "<< myFunc()<< endl;
}


