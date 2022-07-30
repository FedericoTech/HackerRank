
#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> dq;

    //we go walk the array
    for (int i=0; i < n; i++){

        //if the deque still empty...
        if (dq.empty()){
            //we insert the first index
            dq.push_back(i);
        }

        //if the front is behind the subs ample...
        if (dq.front() <= (i - k)){
            //we remove the front
            dq.pop_front();
        }

        // if the new element is bigger than the last
        while (!dq.empty() && arr[i] >= arr[dq.back()]){
            //we get rid of the last
            dq.pop_back();
        }

        //push the new
        dq.push_back(i);

        // print out only when the first window is completed
        if (i >= (k - 1)){
            cout << arr[dq.front()] << " ";
        }
    }
    cout << endl;
}

int main(){

	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

