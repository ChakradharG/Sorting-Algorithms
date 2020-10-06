void swap(int*, int, int);


void heapify(int* arr, int size){
	int cur, par;
	for (int i = 1; i < size; i++){
		cur = i;
		par = (cur - 1) / 2;

		while (par >= 0){
			if (arr[par] < arr[cur]){
				swap(arr, cur, par);
				cur = par;
				par = (cur - 1) / 2;
			}
			else {
				break;
			}
		}
	}
}


void delMax(int* arr, int len){
	swap(arr, 0, len);
	bool f = true;

	int cur = 0, lCh = 2 * cur + 1, rCh = 2 * cur + 2;
	while (lCh < len && rCh < len){
		if (arr[cur] < arr[lCh] || arr[cur] < arr[rCh]){
			if (arr[lCh] > arr[rCh]){
				swap(arr, cur, lCh);
				cur = lCh;
			}
			else {
				swap(arr, cur, rCh);
				cur = rCh;	
			}

			lCh = 2 * cur + 1;
			rCh = 2 * cur + 2;
		}
		else {
			f = false;
			break;
		}
	}
	//For the last leaf node when the array is even in size
	if (f && lCh < len){
		if (arr[cur] < arr[lCh]){
			swap(arr, cur, lCh);
		}
	}
}


void heapSort(int* arr, int size){
	heapify(arr, size);

	for (int i = size-1; i > 0; i--){
		delMax(arr, i);
	}
}
