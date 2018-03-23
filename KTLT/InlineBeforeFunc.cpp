#include <iostream>
#include <cmath>
using namespace std;
inline double hypothenuse (double a, double b){
	return sqrt(a*a+b*b);
}
int main(){
	double k=6, m=9;
	cout << hypothenuse (k,m)<< endl;
	cout << sqrt(k*k + m*m) <<endl;
	return 0;
}
