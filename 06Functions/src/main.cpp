#include <cstdio>
#include <cstdarg>
#include <algorithm>
#include <iterator>

using namespace std;

int max_of_four(const int params...);

int main() {
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int ans = max_of_four(a, b, c, d);

    printf("%d", ans);

    return 0;
}

//this is a variadic function
int max_of_four(const int params...)
{
    int num[4]{};

    va_list args; //we declare the var where we capture the params

    //we start the param capture from params into args
    va_start(args, params);

        num[0] = params; //the first element in the array is params itself

        num[1] = va_arg(args, int); //we capture the next param
        num[2] = va_arg(args, int); //we capture the next param
        num[3] = va_arg(args, int); //we capture the next param

    va_end(args); //we stop the capture.

    //now we use an algorithm to get the maximum number from the array.
    return *max_element(begin(num) , end(num));
}
