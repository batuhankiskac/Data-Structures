int binarySearch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	int mid = (left + right) / 2;

	while (left <= right) {
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
		mid = (left + right) / 2;
	}
}

int binarySearchRecursive(int arr[], int left, int right, int target) {
	if (left > right)
		return -1;

	int mid = (left + right) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] < target)
		binarySearchRecursive(arr, mid + 1, right, target);
	else if (arr[mid] > target)
		binarySearchRecursive(arr, left, mid - 1, target);
}
