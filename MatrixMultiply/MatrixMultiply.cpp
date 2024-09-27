#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

vector<vector<int>> generateRandomMatrix(int n, int seed) {
    vector<vector<int>> matrix(n, vector<int>(n));

    srand(seed);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10000; 
        }
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the matrix size: ";
    cin >> n;

    static vector<vector<int>> A, B; 
    static int count = 0; 

    if (count % 2 == 0) {
        A = generateRandomMatrix(n, 3);
        B = generateRandomMatrix(n, 4);
    }

    count++; 

    vector<vector<int>> C = multiplyMatrices(A, B);

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << "Multiplication result (A * B):" << endl;
    printMatrix(C);

    return 0;
}
