#include <cstdio>
using namespace std;

int main() {

    int i;
    long int li;
    char c;
    float f;
    double d;

    scanf(
        "%d %ld %c %f %lf",
        &i, &li, &c, &f, &d
    );

    printf(
        "%d\n%li\n%c\n%.3f\n%.9lf",
        i,
        li,
        c,
        f,
        d
    );

    return 0;
}
