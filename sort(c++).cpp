#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int limit = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();

    freopen("test_case.txt", "r ", stdin);
    float *A = new float[limit];

    for (int j = 1; j <= 5; j++){
        for (int i = 0; i < limit; i++)         cin >> A[i];


    auto begin = high_resolution_clock :: now();
    sort(A, A + limit);

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds> (end - begin);

    cout << "sort (c++) time_data ["<< j << "]:\t" <<  duration.count() << "\tms\n";
    }
   return 0;

}
