#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    string numbers[] {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int f, t;

    cin >> f >> t;

    if(f < 10){

        for_each(
            numbers + f, numbers + (t > 9 ? 9 : t) + 1,
            [](string s){
                cout << s << endl;
            }
        );
    }

    if(t > 9){
        for(f = 10; f <= t; f++){
            cout << (f % 2 ? "odd" : "even") << endl;
        }
    }


    // Complete the code.
    return 0;
}



