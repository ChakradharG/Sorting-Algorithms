void swap(int*, int, int);


void shellSort(int* arr, int size){
	int j, step = size/2;
	while (step > 0){
		for (int i = step; i < size; i++){
			j = i;
			while (j >= step && arr[j] < arr[j-step]){
				swap(arr, j-step, j);
				j--;
			}
		}
		step /= 2;
	}
}
