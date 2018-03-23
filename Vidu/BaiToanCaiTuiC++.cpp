#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
int num, totalW,bk,fk,fopt;
int *value = (int*)malloc(100 * sizeof(int));
int *weight = (int*)malloc(100 * sizeof(int));
int *x = (int*)malloc(100 * sizeof(int));
int *xopt = (int*)malloc(100 * sizeof(int));
using namespace std;
void Input() {
	cout << "Enter so do vat ";
	cin >> num;
	cout << endl;
	cout << "Enter trong luong tui ";
	cin >> totalW;
	cout << endl;
	cout << "gia tri tung do vat" << endl;
	for (int i = 1; i <= num; i++) {
		cin >> value[i];
	}
	cout << "khoi luong tung do vat " << endl;
	for (int i = 1; i <= num; i++) {
		cin >> weight[i];
	}
}
void TRY(int k) {
	int tk = weight[k] > bk ? 0 : 1;
	for (int y = 0; y <= tk; y++) {
		x[k] = y;
		bk -= y*weight[k];
		fk += y*value[k];
		if (k == num) {
			if (fk > fopt) {
				fopt = fk;
				for (int i = 0; i < num; i++)
					xopt[i] = x[i];
			}
		}else TRY(k+1);
		bk+=y*weight[k];
		fk-=y*value[k];
		
	}
}
void PrintSol() {
	for (int i = 1; i <= num; i++) {
		cout << xopt[i] << " ";
	}
	cout << endl;
	cout <<"earn momeny "<< fopt;
}
int main() {
	freopen("data.txt", "r",stdin);
	Input();
	bk = totalW;
	fk = 0; fopt = -1;
	TRY(1);
	PrintSol();
	return 0;
}
