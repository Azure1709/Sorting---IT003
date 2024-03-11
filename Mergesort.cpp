#include<bits/stdc++.h>

using namespace std;
using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

const int N = 1e6;
float A[N];

float *lfA = new float[N/2 + 1];
float *rtA = new float[N/2 + 1];

void merge(float A[], int left, int mid, int right) {
    int len_lfA = mid - left + 1;
    int len_rtA = right - mid;

    // copy array to LfA and rtA
    for(int i = 0; i < len_lfA; ++i)
        lfA[i] = A[i + left];
    for(int i = 0; i < len_rtA; ++i)
        rtA[i] = A[i + mid + 1];

    // initial index of first ans second len_A
    int lfIndex = 0,
        rtIndex = 0,
        AIndex = left;

    while (lfIndex < len_lfA && rtIndex < len_rtA) {
        if (lfA[lfIndex] <= rtA[rtIndex]) {
            A[AIndex] = lfA[lfIndex];
            ++lfIndex;
        }
        else {
            A[AIndex] = rtA[rtIndex];
            ++rtIndex;
        }
        ++AIndex;
    }


    while (lfIndex < len_lfA) {
        A[AIndex] = lfA[lfIndex];
        ++lfIndex;
        ++AIndex;
    }

    while (rtIndex < len_rtA) {
        A[AIndex] = rtA[rtIndex];
        ++rtIndex;
        ++AIndex;
    }
}

void MergeSort(float A[], int left, int right) {
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;
    MergeSort(A, left, middle);
    MergeSort(A, middle+1, right);
    merge(A, left, middle, right);
}


int main() {
	freopen("test_case.txt", "r", stdin);

    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < N; i++) cin >> A[i];

        tBegin = high_resolution_clock::now();
        MergeSort( A, 0, N - 1);
        tEnd = high_resolution_clock::now();

        exec_time = duration_cast<duration<double>>(tEnd - tBegin);

        cout << "Merge sort time_data ["<< j << "]:\t" << (int)1000 * exec_time.count() << "\tms\n";
    }
}

// lfA: Left Array
// rtA: Right Array