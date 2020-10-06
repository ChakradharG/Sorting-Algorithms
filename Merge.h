void swap(int*, int, int);


void merge(int* arr, int beg, int mid, int end){
	int s1 = mid - beg, s2 = end - mid;
	int* tArr1 = new int[s1];
	int* tArr2 = new int[s2];

	for (int i = beg; i < mid; i++){
		tArr1[i-beg] = arr[i];
	}

	for (int i = mid; i < end; i++){
		tArr2[i-mid] = arr[i];
	}
	
	int i = 0, j = 0, k = 0;
	while (k < s1 + s2){
		if (j == s2){
			arr[beg+k] = tArr1[i];
			i++;
		}
		else if (i == s1){
			arr[beg+k] = tArr2[j];
			j++;
		}
		else if (tArr1[i] <= tArr2[j]){
			arr[beg+k] = tArr1[i];
			i++;
		}
		else if (tArr1[i] > tArr2[j]){
			arr[beg+k] = tArr2[j];
			j++;
		}

		k++;
	}

	delete[] tArr1;
	delete[] tArr2;
}


void mergeSort(int* arr, int beg, int end){
	if ((beg + 1) < end){
		int mid = (beg + end) / 2;
		
		mergeSort(arr, beg, mid);
		mergeSort(arr, mid, end);
		merge(arr, beg, mid, end);
	}

}
