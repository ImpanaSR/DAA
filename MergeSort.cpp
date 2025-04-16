#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 1005;
int a[MAX];

void Merge(int low, int mid, int high) {
    int b[MAX];
    int i = low, h = low, j = mid + 1;

    while (h <= mid && j <= high) {
        if (a[h] < a[j]) {
            b[i++] = a[h++];
        } else {
            b[i++] = a[j++];
        }
    }

    if (h > mid) {
        for (int k = j; k <= high; k++) {
            b[i++] = a[k];
        }
    } else {
        for (int k = h; k <= mid; k++) {
            b[i++] = a[k];
        }
    }

    for (int k = low; k <= high; k++) {
        a[k] = b[k];
    }
}

void MergeSortAlgorithm(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSortAlgorithm(low, mid);
        MergeSortAlgorithm(mid + 1, high);
        Merge(low, mid, high);
    }
}

int main() {
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }

    cout << "The array elements are: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    clock_t startTime = clock();
    MergeSortAlgorithm(0, n - 1);
    clock_t stopTime = clock();

    double elapsedTime = double(stopTime - startTime) / CLOCKS_PER_SEC * 1000;
    cout << "Time complexity (ms) for n = " << n << " is: " << elapsedTime << " ms" << endl;

    cout << "Sorted array elements are: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
