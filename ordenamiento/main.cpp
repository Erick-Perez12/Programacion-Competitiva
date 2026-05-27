#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Metricas {
    long long operaciones = 0;
    long long memoria = 0; 
};

vector<int> generarArreglo(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    return arr;
}

void bubbleSort(vector<int>& arr, Metricas& m) {
    int n = arr.size();
    m.memoria = sizeof(int) * n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            m.operaciones++; 
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.operaciones += 3; 
            }
        }
    }
}

void merge(vector<int>& arr, int left, int mid, int right, Metricas& m) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    m.memoria += (n1 + n2) * sizeof(int);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        m.operaciones++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, Metricas& m) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, m);
        mergeSort(arr, mid + 1, right, m);
        merge(arr, left, mid, right, m);
    }
}

int partition(vector<int>& arr, int low, int high, Metricas& m) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        m.operaciones++;

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            m.operaciones += 3;
        }
    }
    swap(arr[i + 1], arr[high]);
    m.operaciones += 3;
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, Metricas& m) {
    m.memoria += sizeof(int) * 3;
    if (low < high) {
        int pi = partition(arr, low, high, m);
        quickSort(arr, low, pi - 1, m);
        quickSort(arr, pi + 1, high, m);
    }
}

template <typename Func>
void ejecutarYMedir(
    string nombre,
    vector<int> arr,
    Func algoritmo
) {
    Metricas m;
    auto inicio = high_resolution_clock::now();
    algoritmo(arr, m);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(fin - inicio);

    cout << "----------------------------------\n";
    cout << nombre << endl;
    cout << "Tiempo: " << duracion.count() << " us\n";
    cout << "Operaciones: " << m.operaciones << endl;
    cout << "Memoria aproximada: " << m.memoria / 1024.0 << " KB\n";
}

int main() {
    srand(time(0));
    vector<int> tamanios = {100, 1000, 10000};
    for (int n : tamanios) {

        cout << "\n----------------------------------\n";
        cout << n << " ELEMENTOS\n";
        vector<int> original = generarArreglo(n);

        ejecutarYMedir(
            "Bubble Sort",
            original,
            [](vector<int>& arr, Metricas& m) {
                bubbleSort(arr, m);
            }
        );

        ejecutarYMedir(
            "Merge Sort",
            original,
            [](vector<int>& arr, Metricas& m) {
                mergeSort(arr, 0, arr.size() - 1, m);
            }
        );

        ejecutarYMedir(
            "Quick Sort",
            original,
            [](vector<int>& arr, Metricas& m) {
                quickSort(arr, 0, arr.size() - 1, m);
            }
        );
    }

    return 0;
}