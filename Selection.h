void swap(int*, int, int);


void selectionSort(int* arr, int size){
	int sel;

	for (int i = 0; i < size-1; i++){
		sel = i + 1;
		for (int j = i; j < size; j++){
			if (arr[j] < arr[sel]){
				sel = j;
			}
		}
		swap(arr, i, sel);
	}
}
