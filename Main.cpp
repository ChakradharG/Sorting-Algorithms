#include <iostream>
#include <time.h>
#include <chrono>
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Shell.h"
#include "Merge.h"
#include "Heap.h"
#include "Quick.h"
#include "Counting.h"
#include "Radix.h"
using namespace std;


void swap(int* arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


void dispArr(int* arr, int size){
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}


void validate(int* arr, int size){
	//To check whether an algorithm works or not
	bool flag = true;
	for (int i = 0; i < size-1; i++){
		if (arr[i] > arr[i+1]){
			flag = false;
			break;
		}
	}
	cout << "\n" << flag;
}


int main(){
	srand(time(0));
	int size, ch;
	float max;
	cout << "Size of the array: ";
	cin >> size;
	cout << "Range of possible values in the array: ";
	cin >> max;
	cout << "\nWhich algorithm do you want to use?\n"
			"1. Bubble Sort \t\t2. Selection Sort\n"
			"3. Insertion Sort \t4. Shell Sort\n"
			"5. Merge Sort \t\t6. Heap Sort\n"
			"7. Quick Sort \t\t8. Counting Sort\n"
			"9. Radix Sort\n";
	cin >> ch;

	int* arr = new int[size];
	for (int i = 0; i < size; i++){
		arr[i] = (int) rand()*(max/RAND_MAX);
	}

	cout << "\nUnsorted Array: ";
	dispArr(arr, size);

	auto start = chrono::high_resolution_clock::now();
	switch (ch){
		case 1: bubbleSort(arr, size); break;
		case 2: selectionSort(arr, size); break;
		case 3: insertionSort(arr, size); break;
		case 4: shellSort(arr, size); break;
		case 5: mergeSort(arr, 0, size); break;
		case 6: heapSort(arr, size); break;
		case 7: quickSort(arr, 0, size); break;
		case 8: countingSort(arr, size); break;
		case 9: radixSort(arr, size); break;
		default: cout << "\nWrong input.\n"; break;
	}
	auto end = chrono::high_resolution_clock::now();

	cout << "Sorted Array: ";
	dispArr(arr, size);

	chrono::duration <float> dur = end - start;
	float durMS = dur.count() * 1000;
	cout << "\nTime Elapsed: " << durMS << " ms";

	// validate(arr, size);

	delete[] arr;
}
