#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    int n, i;

    cin >> n;

    i = n+1;

    int a[n];

    while(--i){
        cin >> a[i-1];
    }

    for_each(
        a, a + n,
        [](int i){
            cout << i << " ";
        }
    );

    return 0;
}
