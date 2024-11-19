#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void generatedarray(int* arr);
int DefineMin(int* arr);
int DefineMax(int* arr);
void swaptest(int iMax, int iMin, int *array);
void printarray(int* array);

int const SIZE = 10;

int main() {
	int a[SIZE];

	generatedarray(a); 
	printarray(a);

	int imin = DefineMin(a);
	int imax = DefineMax(a);
	swaptest(imax, imin, a);
	printarray(a);
	return 0;
}

void generatedarray(int* arr)
{
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

}


int DefineMin(int* arr)
{
	int min = arr[0];
	int indexMin = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (min > arr[i]) {
			min = arr[i];
			indexMin = i;

		}
	}


	cout << min << endl;

	return indexMin;
}


int DefineMax(int* arr)
{
	int max = arr[0];
	int indexMax = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (max < arr[i]) {
			max = arr[i];
			indexMax = i;
		}
	}

	cout << max << endl;

	return indexMax;
}

void swaptest(int iMax, int iMin, int* array) {
	int temp = array[iMax];
	array[iMax] = array[iMin];
	array[iMin] = temp;

}

void printarray(int *array){
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}