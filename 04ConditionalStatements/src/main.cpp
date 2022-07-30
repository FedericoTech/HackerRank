/**
 * this is a non standard header that
 * includes all the STL libraries.
 * It is not portable. It only works in GCC
 */

#include <bits/stdc++.h>

using namespace std;

//declaration of the two functions
string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(
		ltrim(		//it removes the space on the left
			rtrim(	//it removes the space on the right
				n_temp	//line captured from console
			)
		)
	);

    if(n > 9){
		cout << "Greater than 9";
	} else {
		string numbers[] {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

		cout << numbers[n];
	}

    return 0;
}

//implementation of the two functions

string ltrim(const string &str) {
	//we copy the constant string into a mutable string
    string s(str);

    s.erase(		//erase characters
        s.begin(),  	//from beginning
        find_if(
			s.begin(), s.end(), //from beginning to end
			not1(				//to the first non space
				ptr_fun<int, int>(isspace) //with the function isspace
			)
		)	//to the first non space
    );

    return s;
}

string rtrim(const string &str) {
	//we copy the constant string into a mutable string
    string s(str);

    s.erase( 		//erase characters
        find_if(		//the last non space
			s.rbegin(), s.rend(), //from end to beginning
			not1(				  //to the first non space
				function<int(const int &)>( //here i'm doing the same as the above but with a lambda function.
					[](const int &c){
						return isspace(c);
					}
				)
			)
		).base(),
		s.end()
    );

    return s;
}


