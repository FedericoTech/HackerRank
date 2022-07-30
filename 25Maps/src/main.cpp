#include <iostream>
#include <map>

using namespace std;


int main() {
	int n, q, m;
	string name;

	cin >> n;

	map<string, int> mks;

	while(n--){
		cin >> q >> name;

		switch(q){
			case 1: //insert
				cin >> m;
				if(mks.count(name)){
					mks[name] += m;
				} else {
					mks.insert(make_pair(name, m));
				}
				break;
			case 2: //delete
				mks.erase(name);
				break;
			case 3: //is present
				if(mks.count(name)){
					cout << mks[name] << endl;
				} else {
					cout << 0 << endl;
				}
				break;
		}

	}

    return 0;
}
