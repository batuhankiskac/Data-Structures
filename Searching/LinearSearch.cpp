
// Linear Search iterative versiyon
int linearSearch(int arr[], int size, int target) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == target)
			return i;
	}
	return -1;
}

// Linear Search recursive versiyon (tail recursion bu arada)
int linearSearchRecursive(int arr[], int size, int target, int index = 0) {
	if (index >= size)
		return -1;
	if (arr[index] == target)
		return index;
	return linearSearchRecursive(arr, size, target, index + 1);
}
