#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> v;

    while(n--){
        int value;

        cin >> value;

        v.push_back(value);
    }

    //i'm just trying this sorting
    sort(v.rbegin(), v.rend());

    for_each(
        v.rbegin(), v.rend(),
        [](int i){
            cout << i << " ";
        }
    );

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

