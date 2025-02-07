#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;

    // Dynamically allocate augmented matrix
    float aug[n][2 * n];

    // Input the matrix and initialize the augmented matrix
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> aug[i][j];
        }
        for (int j = n; j < 2 * n; j++) {
            aug[i][j] = (i == (j - n)) ? 1 : 0; // Add identity matrix
        }
    }
    
    // Perform Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Check for singularity
        if (aug[i][i] == 0) {
            cout << "Mathematical Error: Matrix is singular." << endl;
            return 0;
        }

        // Normalize the pivot row
        float pivot = aug[i][i];
        for (int j = 0; j < 2 * n; j++) {
            aug[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = aug[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    aug[k][j] -= factor * aug[i][j];
                }
            }
        }
    }

    // Extract and print the inverse matrix
    cout << "The inverse matrix is:" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            cout << aug[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}