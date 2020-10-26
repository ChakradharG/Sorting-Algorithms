void swap(int*, int, int);


void bubbleSort(int* arr, int size){
	bool done = false;
	for (int i = 0; i < size; i++){
		done = true;
		for (int j = i; j < size; j++){
			if (arr[i] > arr[j]){
				done = false;
				swap(arr, i, j);
			}
		}
		if (done){
			break;
		}
	}
}
