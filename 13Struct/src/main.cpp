#include <iostream>

using namespace std;

struct student {
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {

    student st;

    cin
		>> st.age
		>> st.first_name
		>> st.last_name
		>> st.standard;

    cout
		<< st.age
		<< " " << st.first_name
		<< " " << st.last_name
		<< " " << st.standard;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
