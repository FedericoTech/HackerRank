#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
	stringstream iss(s);
	stringstream ss;

	std::tm t = {};

	iss >> get_time(&t, "%I:%M:%S%p"); //%p doesn't work

	if(t.tm_hour == 12){
		t.tm_hour -= 12;
	}

	if(s.compare(s.length() - 2, 2, "PM") == 0){
		t.tm_hour += 12;
	}

	ss << put_time(&t, "%H:%M:%S");

	return ss.str();

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
