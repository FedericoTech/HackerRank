#include <utility>
#include <iostream>
using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    cout << a.size() << " " << b.size() << endl;
    cout << a + b << endl;

    swap(a[0], b[0]);

    cout << a << " " << b << endl;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}


