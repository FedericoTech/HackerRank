
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {

    int score1;
    int score2;
    int score3;
    int score4;
    int score5;

public:
    void input()
    {
        cin >> score1 >> score2 >> score3 >> score4 >> score5;
    }

    int calculateTotalScore();
};

int Student::calculateTotalScore()
{
    return score1 + score2 + score3 + score4 + score5;
}

int main() {

    int n;

    cin >> n;

    vector<Student> students(n);

    for_each(
        students.begin(), students.end(),
        [](auto &student){
            student.input();
        }
    );

    int kristen = students[0].calculateTotalScore();

    cout << count_if(
        students.begin()+1, students.end(),
        [kristen](auto student){
            return kristen < student.calculateTotalScore();
        }
    );

    return 0;
}
