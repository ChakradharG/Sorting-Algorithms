void initArr(int* Arr1, int size, int* Arr2 = nullptr){
	if (Arr2 == nullptr){
		for (int i = 0; i < size; i++){
			Arr1[i] = 0;
		}
	}

	else {
		for (int i = 0; i < size; i++){
			Arr1[i] = Arr2[i];
		}
	}
}


void radixSort(int* arr, int size){
	int max = 0, temp;
	int* bArr = new int[size];
	int* cArr = new int[10];

	for (int i = 0; i < size; i++){
		max = (max < arr[i]) ? arr[i] : max;
	}

	for (int div = 1; max/div > 0; div *= 10){
		initArr(bArr, size);
		initArr(cArr, 10);

		for (int j = 0; j < size; j++){
			temp = (arr[j] / div) % 10;
			cArr[temp]++;
		}

		for (int j = 1; j < 10; j++){
			cArr[j] += cArr[j-1];
		}

		for (int j = size; j > 0; j--){
			temp = (arr[j-1] / div) % 10;
			bArr[--cArr[temp]] = arr[j-1];
		}

		initArr(arr, size, bArr);
	}

	delete[] bArr;
	delete[] cArr;
}
