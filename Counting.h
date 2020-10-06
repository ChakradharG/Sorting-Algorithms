void countingSort(int* arr, int size){
	int max = arr[0], min = arr[0];
	for (int i = 0; i < size; i++){
		max = (arr[i] > max) ? arr[i]: max;
		min = (arr[i] < min) ? arr[i]: min;
	}

	int newSize = max - min + 1;
	int* newArr = new int[newSize];
	for (int i = 0; i < newSize; i++){
		newArr[i] = 0;
	}

	for (int i = 0; i < size; i++){
		newArr[arr[i] - min]++;
	}

	int i = 0, j = 0;
	while (j < newSize){
		if (newArr[j] == 0){
			j++;
			continue;
		}
		arr[i] = j + min;
		newArr[j]--;
		i++;
	}

	delete[] newArr;
}
