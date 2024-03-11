#include<bits/stdc++.h>

using namespace std;
using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

const int N = 1e6;
float A[N];

void heapify(float A[], int N, int i)
{

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < N && A[left] > A[largest])
		largest = left;

	if (right < N && A[right] > A[largest])
		largest = right;

	if (largest != i) {
		swap(A[i], A[largest]);

		heapify(A, N, largest);
	}
}

void heapSort(float A[], int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(A, N, i);

	for (int i = N - 1; i > 0; i--) {

		swap(A[0], A[i]);

		heapify(A, i, 0);
	}
}

int main() {
	freopen("test_case.txt", "r", stdin);

    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < N; i++) cin >> A[i];

        tBegin = high_resolution_clock::now();
        heapSort(A, N);
        tEnd = high_resolution_clock::now();

        exec_time = duration_cast<duration<double>>(tEnd - tBegin);

        cout << "Heap sort time_data ["<< j << "]:\t" << (int)1000 * exec_time.count() << "\tms\n";
    }
}
