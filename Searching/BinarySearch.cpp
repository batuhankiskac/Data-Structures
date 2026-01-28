// Binary Search algoritması (iteratif)
// Sıralı bir dizide aranan elemanın indeksini döndürür, yoksa -1 döner.
int binarySearch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	int mid = left + (right - left) / 2;

	// Arama aralığı geçerli olduğu sürece devam et
	while (left <= right) {
		// Ortadaki eleman aranan değer mi?
		if (arr[mid] == target)
			return mid;
		// Aranan değer ortadakinden büyükse sağa kay
		else if (arr[mid] < target)
			left = mid + 1;
		// Aranan değer ortadakinden küçükse sola kay
		else
			right = mid - 1;
		// Yeni ortayı hesapla
		mid = (left + right) / 2;
	}
	// Bulunamazsa -1 döndür
	return -1;
}


// Binary Search algoritması (recursive)
// Sıralı bir dizide aranan elemanın indeksini döndürür, yoksa -1 döner.
int binarySearchRecursive(int arr[], int left, int right, int target) {
	// Arama aralığı geçersizse -1 döndür
	if (left > right)
		return -1;

	int mid = left + (right - left) / 2;
	// Ortadaki eleman aranan değer mi?
	if (arr[mid] == target)
		return mid;
	// Aranan değer ortadakinden büyükse sağa kay
	else if (arr[mid] < target)
		return binarySearchRecursive(arr, mid + 1, right, target);
	// Aranan değer ortadakinden küçükse sola kay
	else
		return binarySearchRecursive(arr, left, mid - 1, target);
}
