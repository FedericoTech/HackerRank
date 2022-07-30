#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, nx, q;

    cin >> n >> q;

    int *a[n];

    for(nx = 0; nx < n; nx++){
        int i, ix;
        cin >> i;

        a[nx] = new int[i];

        for(ix = 0; ix < i; ix++){
            cin >> a[nx][ix];
        }
    }

    while(q--){
        int i, j;
        cin >> i >> j;

        cout << a[i][j] << endl;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
