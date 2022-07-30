#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> parseInts(string str) {

	string sn;
	vector<int> num;
	stringstream ss(str);

	while(getline(ss, sn, ',')){
		stringstream ss2(sn);
		num.push_back(stoi(sn));
	}

	return num;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(unsigned int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
