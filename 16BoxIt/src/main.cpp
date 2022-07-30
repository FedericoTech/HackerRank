

#include <iostream>
using namespace std;

class Box {
    int l, b, h;

public:
    Box();
    Box(int, int, int);
    Box(const Box &);

    int getLength();
    int getBreadth();
    int getHeight();

    long long CalculateVolume();

    //bool operator<(const Box&);
    friend bool operator<(const Box&, const Box&);

     //std::ostream& operator<<(std::ostream&);
    friend std::ostream& operator<<(std::ostream&, const Box&);
};

int main() {
    int n, c, l, b, h;
    Box *box = new Box();

    cin >> n;

    while(n--){
        cin >> c;
        switch(c){
            case 3:
                {
                    cin >> l >> b >> h;
                    Box box2(l, b, h);
                    if(box2 < *box){
                        cout << "Lesser" << endl;
                    } else {
                        cout << "Greater" << endl;
                    }
                }
                break;
            case 4:
                cout << box->CalculateVolume() << endl;
                break;
            case 2:
                cin >> l >> b >> h;
                box = new Box(l, b, h);
            default:
                cout << *box << endl;
        }
    }

    return 0;
}

Box::Box() {
    l = b = h = 0;
};

Box::Box(int length, int breadth, int height){
    l = length;
    b = breadth;
    h = height;
};

Box::Box(const Box &box){
    l = box.l;
    b = box.b;
    h = box.h;
};

int Box::getLength(){
    return l;
};

int Box::getBreadth(){
    return b;
};

int Box::getHeight(){
    return h;
}

long long Box::CalculateVolume(){
    return (long long)l * b * h;
}

bool operator<(const Box& box1, const Box& box2){
    return box1.l < box2.l
        || (box1.b < box2.l && box1.l == box2.l)
        || (box1.h < box2.h && box1.b == box2.b && box1.l == box2.l);
};

std::ostream& operator<<(ostream &out, const Box &box)
{
   return out << box.l << " " << box.b << " " << box.h;
};
