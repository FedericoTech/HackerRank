
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> numbers;

    while(n--){
        int value;
        cin >> value;

        numbers.push_back(value);
    }

    cin >> n;

    numbers.erase(numbers.begin() + n -1);

    int first, last;

    cin >> first >> last;

    numbers.erase(
        numbers.begin() + first -1,
        numbers.begin() + last -1
    );

    cout << numbers.size() << endl;

    for_each(
    		numbers.begin(), numbers.end(),
		[](int i){
			cout << i << " ";
		}
	);

    return 0;
}
