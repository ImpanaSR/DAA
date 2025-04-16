#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 1005;
int a[MAX];

void QuickSortAlgorithm(int p, int r) {
    int i, j, pivot, temp;
    if (p < r) {
        i = p;
        j = r;
        pivot = a[p];
        while (true) {
            i++;
            while (a[i] > pivot && i < r) {
                cout << "Comparing: " << a[i] << " < " << pivot << endl;
                i++;
            }
            while (a[j] < pivot) {
                cout << "Comparing: " << a[j] << " > " << pivot << endl;
                j--;
            }
            if (i < j) {
                cout << "Swapping: " << a[i] << " and " << a[j] << endl;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } else {
                break;
            }
        }
        cout << "Swapping pivot: " << a[p] << " with " << a[j] << endl;
        a[p] = a[j];
        a[j] = pivot;
        QuickSortAlgorithm(p, j - 1);
        QuickSortAlgorithm(j + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    srand(time(0));
    cout << "The array elements are: " << endl;
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    clock_t startTime = clock();
    QuickSortAlgorithm(0, n - 1);
    clock_t stopTime = clock();

    double elapsedTime = double(stopTime - startTime) / CLOCKS_PER_SEC * 1000; // milliseconds
    cout << "The time complexity for n = " << elapsedTime << " ms" << endl;

    cout << "Sorted array elements are: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
