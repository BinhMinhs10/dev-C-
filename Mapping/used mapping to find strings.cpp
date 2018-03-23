#include <map>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main(){
	map <string, int> M;
	set <string> W;
	char fn[] = "input.txt";
	ifstream fi(fn);
	while(!fi.eof()){
		string s;
		getline(fi, s);
		if(s.compare("-1") == 0){
			break;
		}
		int xh = M[s];
		//cout << "xh = "<<xh<<endl;
		if(xh == 0){
			W.insert(s);
		}
		M[s]++;
	}
	fi.close();
	set <string> :: iterator it;
	for(it = W.begin(); it != W.end(); it++){
		int xh = M[*it];
		cout << *it << ": " << xh  << endl;
	}
}
