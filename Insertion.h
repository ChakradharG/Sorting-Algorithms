void swap(int*, int, int);


void insertionSort(int* arr, int size){
	int j;
	for (int i = 1; i < size; i++){
		j = i;
		while (j > 0 && arr[j] < arr[j-1]){
			swap(arr, j-1, j);
			j--;
		}
	}
}
