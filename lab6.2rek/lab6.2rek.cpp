#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 10;

// ���������� ������� ��� ��������� ������
void generateArrayRecursive(int* arr, int index = 0) {
    if (index == SIZE) return;
    arr[index] = rand() % 100 + 1;
    generateArrayRecursive(arr, index + 1);
}

// ���������� ������� ��� ����������� ������� ���������� ��������
int findMinIndexRecursive(int* arr, int index = 0, int currentMinIndex = 0) {
    if (index == SIZE) return currentMinIndex;
    if (arr[index] < arr[currentMinIndex]) currentMinIndex = index;
    return findMinIndexRecursive(arr, index + 1, currentMinIndex);
}

// ���������� ������� ��� ����������� ������� ������������� ��������
int findMaxIndexRecursive(int* arr, int index = 0, int currentMaxIndex = 0) {
    if (index == SIZE) return currentMaxIndex;
    if (arr[index] > arr[currentMaxIndex]) currentMaxIndex = index;
    return findMaxIndexRecursive(arr, index + 1, currentMaxIndex);
}

// ���������� ������� ��� ��������� ������
void printArrayRecursive(int* arr, int index = 0) {
    if (index == SIZE) {
        cout << endl;
        return;
    }
    cout << arr[index] << "  ";
    printArrayRecursive(arr, index + 1);
}

// ���������� ������� ��� ����� ������������� � ���������� ��������
void swapRecursive(int* arr, int maxIndex, int minIndex, int temp = 0, int step = 0) {
    if (step == 0) temp = arr[maxIndex];
    if (step == 1) {
        arr[maxIndex] = arr[minIndex];
    }
    else if (step == 2) {
        arr[minIndex] = temp;
        return;
    }
    swapRecursive(arr, maxIndex, minIndex, temp, step + 1);
}

int main() {
    srand(time(NULL));
    int array[SIZE];

    // �������� �����
    generateArrayRecursive(array);
    cout << "Original array:\n";
    printArrayRecursive(array);

    // ��������� ������� ���������� �� ������������� ��������
    int minIndex = findMinIndexRecursive(array);
    int maxIndex = findMaxIndexRecursive(array);

    // �������� ��������� � ������������ ��������
    cout << "Min value: " << array[minIndex] << " (Index: " << minIndex << ")\n";
    cout << "Max value: " << array[maxIndex] << " (Index: " << maxIndex << ")\n";

    // ̳����� ������ ��������� �� ������������ ��������
    swapRecursive(array, maxIndex, minIndex);

    // �������� ������� �����
    cout << "\nModified array:\n";
    printArrayRecursive(array);

    return 0;
}
