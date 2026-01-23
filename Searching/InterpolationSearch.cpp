int interpolationSearch(int arr[], int size, int target) {
	int low = 0;
	int high = size - 1;

	while (low <= high && target >= arr[low] && target <= arr[high]) {
		if (low == high) {
			if (arr[low] == target)
				return low;
			return -1;
		}

		int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));

		if (arr[pos] == target)
			return pos;
		if (arr[pos] < target)
			low = pos + 1;
		else
			high = pos - 1;
	}
}
