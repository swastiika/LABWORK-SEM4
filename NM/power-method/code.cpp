#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double tolerance, max_val;
    const int maxIterations = 1000;
    
    // Read size of matrix
    cout << "Enter size of matrix: ";
    cin >> n;
    
    // Dynamically allocate memory
    double A[n][n],x[n],temp[n];
       // Read matrix A
    cout << "Enter matrix elements:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    
    // Read initial guess vector
    cout << "Enter initial guess vector:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    // Read tolerance
    cout << "Enter tolerance: ";
    cin >> tolerance;
    
    double lambda_old = 0;
    double lambda_new = 0;
    
    // Main iteration loop
    for(int iter = 0; iter < maxIterations; iter++) {
        // Matrix-vector multiplication
        for(int i = 0; i < n; i++) {
            temp[i] = 0;
            for(int j = 0; j < n; j++) {
                temp[i] += A[i][j] * x[j];
            }
        }
        
        // Find maximum absolute value
        max_val = 0;
        for(int i = 0; i < n; i++) {
            if(abs(temp[i]) > max_val) {
                max_val = abs(temp[i]);
            }
        }
        
        // Normalize vector
        for(int i = 0; i < n; i++) {
            temp[i] = temp[i] / max_val;
        }
        
        lambda_new = max_val;
        
        // Check convergence
        if(abs(lambda_new - lambda_old) < tolerance) {
            break;
        }
        
        lambda_old = lambda_new;
        
        // Update vector
        for(int i = 0; i < n; i++) {
            x[i] = temp[i];
        }
    }
    
    // Print results
    cout << "\nDominant eigenvalue: " << lambda_new << endl;
    cout << "Eigenvector: ";
    for(int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    
    return 0;
}