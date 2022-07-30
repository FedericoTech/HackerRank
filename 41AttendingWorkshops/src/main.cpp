#include<bits/stdc++.h>

using namespace std;

#define initialize(a, b, c) (Available_Workshops::init(a, b, c))

#define CalculateMaxWorkshops(a) (Available_Workshops::calc(a))


struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;

    vector<Workshop> ws;

public:
    static Available_Workshops* init(int[], int[], int);

    static int calc(Available_Workshops*);
};

Available_Workshops * Available_Workshops::init(int start_time[], int duration[], int n){
    Available_Workshops* aw = new Available_Workshops();

    while(n--){
        Workshop ws;
        ws.duration = duration[n];
        ws.start_time = start_time[n];
        ws.end_time = start_time[n] + duration[n];
        aw->ws.push_back(ws);
    }

    return aw;
}

int Available_Workshops::calc(Available_Workshops* aw){

    sort(
        aw->ws.begin(), aw->ws.end(),
        [](Workshop ws1, Workshop ws2){
            return ws1.end_time - ws2.end_time > 0;
        }
    );


    int total{0};

    while (aw->ws.size()) {
        ++total;
        int end_time = aw->ws.back().end_time;
        bool overlap{true};
        while (aw->ws.size() && overlap) {
            aw->ws.pop_back();
            if (aw->ws.back().start_time >= end_time) {
                overlap = false;
            }
        }
    }

    return total;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
