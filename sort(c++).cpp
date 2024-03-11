#include<bits/stdc++.h>

using namespace std;
using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

const int N = 1e6;
float A[N];



int main() {
	freopen("test_case.txt", "r", stdin);

    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < N; i++) cin >> A[i];

        tBegin = high_resolution_clock::now();
        sort(A, A + N);
        tEnd = high_resolution_clock::now();

        exec_time = duration_cast<duration<double>>(tEnd - tBegin);

        cout << "Sort (c++) time_data ["<< j << "]:\t" << (int)1000 * exec_time.count() << "\t ms\n" << endl;
    }
}
