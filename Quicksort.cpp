#include<bits/stdc++.h>

using namespace std;
using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

const int N = 1e6;
float A[N];

void Quick_Sort(int low, int high){
    int pivot = low + (high-low)/2;
    int left = low,   right = high;
    do{
        while (A[left] < A[pivot]) ++left;
        while (A[right] > A[pivot]) --right;

        if(left <= right){
            float tmp = A[left]; A[left] = A[right]; A[right] = tmp;
            ++left; --right;
        }
    }while(left <= right);
    if(low < right) Quick_Sort(low, right);
    if(left < high) Quick_Sort(left, high);

}

int main() {
	freopen("test_case.txt", "r", stdin);

    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < N; i++) cin >> A[i];

        tBegin = high_resolution_clock::now();
        Quick_Sort(0, N-1);
        tEnd = high_resolution_clock::now();

        exec_time = duration_cast<duration<double>>(tEnd - tBegin);

        cout << "Quick sort time_data ["<< j << "]:\t" << (int)1000 * exec_time.count() << "\tms\n";
    }
}
