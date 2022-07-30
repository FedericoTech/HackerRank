#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout << hex;  // hexadecimal base
        cout << left; // aligned to the left
        cout << showbase;
        cout << nouppercase; // formatting
        cout << (long long) A << endl; // actual printed part

        cout << dec;             //decimal base
        cout << right;             //align to the right
        cout << setw(15);         //width 15
        cout << setfill('_');    // fill with _
        cout << showpos;         // show positive sign
        cout << fixed;             //not scientific notation
        cout << setprecision(2);// formatting 2 decimals
        cout << B << endl;         // actual printed part

        cout << scientific;     //scientific notation
        cout << uppercase;      //upper case
        cout << noshowpos;         //no sign
        cout << setprecision(9);// 9 decimals
        cout << C << endl; // actual printed part

	}
	return 0;

}
