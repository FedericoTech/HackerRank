#include <cmath>
#include <iostream>
using namespace std;
int main() {

    //100000000 923092883 976061291 1205350525

    unsigned int
        n, //number
        i, //index
        s, //seed
        p,
        q,
        m = 1 << 31;

    cin >> n  >> s >> p >> q;

    unsigned long
        a0=s,     //first element
        a=s,    //current element
        ap=0,    //past element
        k=0;    //auxiliar element


    for(i = 0; i < n; i++){


        a=(a * p + q) % m;

        if(
            (
                a == a0 //if current element is like the first one
                || a==ap //or current element is like the one efore
            )
            && i != 0 //and different to
        ){
            k = i + 1; //we found a new number
            break;
        }
        ap=a;

    }

    //if the index reaches the max number...
    if (i==n){
        k = i; //the result is that all the numbers were different
    }

    cout << k << endl;

    return 0;
}
