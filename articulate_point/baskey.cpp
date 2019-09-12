#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

void satvik (int a[1]) {
    a[0] = 2;
    a[1] = 3;
}

int main() {
    int a[2];
    satvik (a);
    cout << a[0] << " " << a[1] << "\n";

    return 0;
}