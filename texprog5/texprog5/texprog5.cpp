#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
#include <ctime>
#include <Windows.h>
using namespace std;

void Gen(int size, int**matrix) {
    for (int u = 0; u < size; u++){
        for (int v = 0, k = 0; v < u+1; v++) {
            matrix[u][v] = rand() % 2;
            if (u == v) {
                while (matrix[u][v] == 1) {
                    matrix[u][v] = rand() % 3;
                }
            }
            if (k == 4) {
                matrix[u][v] = 0;
            }
            if ((matrix[u][v] == 1) || (matrix[u][v] == 2)) {
                k++;
            }
            matrix[v][u] = matrix[u][v];
        }
    }
}

void GenUser(int size, int** matrix) {
    for (int u = 0; u < size; u++) {
        for (int v = 0, k = 0; v < size; v++) {
            cin >> matrix[u][v];
            if (k == 4) {
                matrix[u][v] = 0;
            }
            if (u == v) {
                while (matrix[u][v] == 1) {
                    cin >> matrix[u][v];
                }
            }
            if ((matrix[u][v] == 1) || (matrix[u][v] == 2)) {
                k++;
            }
        }
        cout << endl;
    }
}

void seeM(int size, int** matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int size, v=1;
    cout << "введите размер" << endl;
    cin >> size;
    queue<int> Queue;
    int* G = new int[size];
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    cout << "генерация(1-да)?" << endl;
    cin >> v;
    if (v==1) {
        Gen(size, matrix);
    }
    else { 
        cout << "введите матрицу смежности(1, 2 или 0, по строчкам)" << endl;
        GenUser(size, matrix); }
    cout << endl;
    seeM(size, matrix);
    cout << endl;
    for (int i = 0; i < size; i++) {
        G[i] = 0;
    }
    Queue.push(0);
    while (!Queue.empty()) {
        int node = Queue.front();
        Queue.pop();
        G[node] = 2;
        for (int j = 0; j < size; j++)
        {
            if (matrix[node][j] == 1 && G[j] == 0)
            {
                Queue.push(j);
                G[j] = 1;
            }
        }
        cout << node + 1 << endl;
    }
    cin.get();
    return 0;
}