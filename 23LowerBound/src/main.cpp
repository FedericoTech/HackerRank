
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n, value;

    cin >> n;

    vector<int> v(n);

    while(n--){
        cin >> value;
        v[v.size() - n] = value;
    }

    cin >> n;

    while(n--){

        cin >> value;

        int index = lower_bound(v.begin(), v.end(), value) - v.begin();

        if(v[index] == value){
        	cout << "Yes ";
        } else {
        	cout << "No ";
        }

        cout << index + 1 << endl;
    }

    return 0;
}
