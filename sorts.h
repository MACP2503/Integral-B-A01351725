#ifndef SORTS_H
#define SORTS_H
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

template<class T>
class Sorts {
private:
    void swap(vector<T> &, int, int);
    void copyArray(vector<T> &, vector<T> &, int, int);
    void mergeArray(vector<T> &, vector<T> &, int, int, int);
    void mergeSplit(vector<T> &, vector<T> &, int, int);
    int auxiliar(vector<T>, int, int, int);

public:
    void ordenaSeleccion(vector<T> &v);
    void ordenaBurbuja(vector<T> &v);
    void ordenaMerge(vector<T> &v);
    int busqSecuencial(const vector<T> &v, int target);
    int busqBinaria(const vector<T> &v, int target);
};

template<class T>
void Sorts<T>::swap(vector<T> &vector, int i, int j) {
    T aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
}

template<class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
    for (int i = low; i <= high; ++i) {
        A[i] = B[i];
    }
}

template<class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        while (j <= high) {
            B[k++] = A[j];
            j++;
        }
    } else {
        while (i <= mid) {
            B[k++] = A[i];
            i++;
        }
    }
}

template<class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
    if ((high - low) < 1) return;
    int mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

template<class T>
void Sorts<T>::ordenaSeleccion(vector<T> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(v, i, min);
        }
    }
}

template<class T>
void Sorts<T>::ordenaBurbuja(vector<T> &v) {
    for (int i = v.size() - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
            }
        }
    }
}

template<class T>
void Sorts<T>::ordenaMerge(vector<T> &v) {
    vector<T> temporal(v.size());
    mergeSplit(v, temporal, 0, v.size() - 1);
}

template<class T>
int Sorts<T>::auxiliar(vector<T> vec, int low, int high, int target) {
    if (low < high) {
        int mid = (high + low) / 2;
        if (target == vec[mid]) {
            return mid;
        } else if (target < vec[mid]) {
            return auxiliar(vec, low, mid - 1, target);
        } else if (target > vec[mid]) {
            return auxiliar(vec, mid + 1, high, target);
        }
    }
    return -1;
}

template<class T>
int Sorts<T>::busqSecuencial(const vector<T> &v, int target) {
    vector<T> vec(v);
    for (int i = 0; i < vec.size(); ++i) {
        if (target == vec[i]) {
            return i;
        }
    }
    return -1;
}

template<class T>
int Sorts<T>::busqBinaria(const vector<T> &v, int target) {
    vector<T> vec(v);
    return auxiliar(vec, 0, vec.size() - 1, target);
}

#endif // SORTS_H
