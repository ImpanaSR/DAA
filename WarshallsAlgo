#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 100;  // You can increase this if needed
int a[MAX][MAX];
int n;

void getClosure() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1 || (a[i][k] == 1 && a[k][j] == 1)) {
                    a[i][j] = 1;
                }
            }
        }
    }
}

void PrintMatrix() {
    cout << "Transitive closure matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    
    cout << "Enter number of nodes: ";
    cin >> n;

    // Generate random adjacency matrix
    cout << "Initial adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 2;  // 0 or 1
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    getClosure();
    PrintMatrix();

    return 0;
}
