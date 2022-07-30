#include <iostream>
#include <set>

using namespace std;


int main() {
	int n, q, v;

	cin >> n;

	set<int> s;

	while(n--){
		cin >> q >> v;

		switch(q){
			case 1: //insert
				s.insert(v);
				break;
			case 2: //delete
				s.erase(v);
				break;
			case 3: //is present
				if(s.count(v)){
					cout << "Yes" << endl;
				} else {
					cout << "No" << endl;
				}
				break;
		}

	}

    return 0;
}
