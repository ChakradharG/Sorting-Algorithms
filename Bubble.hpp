void swap(int*, int, int);


void bubbleSort(int* arr, int size){
	bool done;

	for (int i = 0; i < size-1; i++){
		done = true;
		for (int j = size-1; j > i; j--){
			if (arr[j] < arr[j-1]){
				done = false;
				swap(arr, j, j-1);
			}
		}
		if (done){
			break;
		}
	}
}
