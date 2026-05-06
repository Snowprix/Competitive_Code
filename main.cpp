#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct SortResult {
    string name;
    long long steps;
    long long duration_ns;
};

vector<int> generateRandomArray(int n, int min_val, int max_val) {
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min_val, max_val);
    for (int i = 0; i < n; ++i) arr[i] = dis(gen);
    return arr;
}

void bubbleSort(vector<int>& arr, long long& steps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            steps++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                steps++;
            }
        }
    }
}

void selectionSort(vector<int>& arr, long long& steps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            steps++;
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
        steps++;
    }
}

void insertionSort(vector<int>& arr, long long& steps) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        steps++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            steps += 2;
        }
        arr[j + 1] = key;
    }
}

void quickSort(vector<int>& arr, int low, int high, long long& steps) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            steps++;
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                steps++;
            }
        }
        swap(arr[i + 1], arr[high]);
        steps++;
        int pi = i + 1;
        quickSort(arr, low, pi - 1, steps);
        quickSort(arr, pi + 1, high, steps);
    }
}

int main() {
    int n, min_val, max_val;

    cout << "Cantidad de numeros a generar: "; cin >> n;
    cout << "Rango minimo: "; cin >> min_val;
    cout << "Rango maximo: "; cin >> max_val;

    vector<int> original_arr = generateRandomArray(n, min_val, max_val);

    cout << "\nArray generado:\n[ ";
    for (int x : original_arr) cout << x << " ";
    cout << "]\n";

    vector<SortResult> results;
    auto run_sort = [&](string name, auto func) {
        vector<int> temp_arr = original_arr;
        long long steps = 0;

        auto start = high_resolution_clock::now();
        func(temp_arr, steps);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end - start);
        results.push_back({name, steps, duration.count()});
    };

    run_sort("Bubble Sort", [](vector<int>& a, long long& s) { bubbleSort(a, s); });
    run_sort("Selection Sort", [](vector<int>& a, long long& s) { selectionSort(a, s); });
    run_sort("Insertion Sort", [](vector<int>& a, long long& s) { insertionSort(a, s); });
    run_sort("Quick Sort", [](vector<int>& a, long long& s) { quickSort(a, 0, a.size() - 1, s); });

    sort(results.begin(), results.end(), [](const SortResult& a, const SortResult& b) {
        return a.duration_ns < b.duration_ns;
    });

    cout << "\nResultados comparativos (Ordenados por tiempo):\n";
    cout << "----------------------------------------------------------------------\n";
    cout << left << setw(10) << "Posicion" << setw(20) << "Algoritmo" << setw(20) << "Pasos" << "Tiempo (ns)" << endl;
    cout << "----------------------------------------------------------------------\n";

    for (int i = 0; i < results.size(); ++i) {
        cout << left << setw(10) << (to_string(i + 1) + "o")
             << setw(20) << results[i].name
             << setw(20) << results[i].steps
             << results[i].duration_ns << " ns" << endl;
    }

    return 0;
}
