#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Person {
protected:
	string name;
	int age;
public:
	virtual void getdata()=0;
	virtual void putdata()=0;
	virtual ~Person(){};
};


class Professor : public Person
{
	int publications = 0;
	int id = 0;
	static int cur_id;

public:
	Professor(){
		id = ++cur_id;
	}

	void getdata(){
		cin >> name >> age >> publications;
	}

	void putdata(){
		cout
			<< name
			<< " " << age
			<< " " << publications
			<< " " << id << endl;
	}
};

int Professor::cur_id = 0;

class Student : public Person
{
	int marks[6];
	int id = 0;
	static int cur_id;
public:
	Student(){
		id = ++cur_id;
	}

	void getdata() {
		cin >> name >> age;

		for_each(
			begin(marks), end(marks),
			[](auto &i){
				cin >> i;
			}
		);
	}

	void putdata(){
		cout << name << " "
			<< age << " "
			<< accumulate(
					begin(marks), end(marks),
					0
			) << " "
			<< id << endl;
	}
};

int Student::cur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
