namespace util
{
	template <class T>
	void swap(T *a, T *b)
	{
		T t = *a;
		*a = *b;
		*b = t;
		int u = 0;
	}

	template <class T>
	int cmp(const void *a, const void *b) {
		double c = (*(T*)a - *(T*)b);
		return (c > 0 ? 1 : (c < 0 ? -1 : 0));
	}

	template <class T>
	void selectionSort(T* arr, int n) {
		int i, j, min_idx;

		for (i = 0; i < (n - 1); i++) {
			min_idx = i;
			for (j = (i + 1); j < n; j++) {
				if (arr[j] < arr[min_idx])
					min_idx = j;
			}
			swap(&arr[min_idx], &arr[i]);
		}
	}

	template <class T>
	void insertionSort(T* arr, int n) {
		int i, j;
		T key;
		for (i = 1; i < n; i++) {
			key = arr[i];
			j = i - 1;

			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}
}
