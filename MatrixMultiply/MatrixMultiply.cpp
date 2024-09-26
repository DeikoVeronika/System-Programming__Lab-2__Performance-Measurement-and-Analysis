#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  

using namespace std;

// Функція для множення двох матриць
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0)); 

    // Стандартний алгоритм множення матриць O(n^3)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Функція для генерації випадкової матриці
vector<vector<int>> generateRandomMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10; // заповнюємо матрицю випадковими числами від 0 до 9
        }
    }

    return matrix;
}

// Функція для виведення матриці на екран
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // ініціалізація генератора випадкових чисел

    int n;
    cout << "Enter the matrix size: ";
    cin >> n;

    // Генерація двох випадкових матриць
    vector<vector<int>> A = generateRandomMatrix(n);
    vector<vector<int>> B = generateRandomMatrix(n);

    // Множення матриць
    vector<vector<int>> C = multiplyMatrices(A, B);

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << "Multiplication result (A * B):" << endl;
    printMatrix(C);

    return 0;
}
