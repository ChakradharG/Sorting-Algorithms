void swap(int*, int, int);


void quickSort(int* arr, int beg, int end){
	if (end-beg < 2){
		return;
	}

	int y = beg + 1;
	for (int g = beg+1; g < end; g++){
		if (arr[g] < arr[beg]){
			swap(arr, y, g);
			y++;
		}
	}
	swap(arr, beg, y-1);
	quickSort(arr, beg, y);
	quickSort(arr, y, end);
}
