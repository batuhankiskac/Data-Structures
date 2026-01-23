
// Linear Search algoritması (iteratif)
// Sıralı veya sırasız bir dizide aranan elemanın indeksini döndürür, yoksa -1 döner.
int linearSearch(int arr[], int size, int target) {
	for (int i = 0; i < size; ++i) {
		// Her elemanı sırayla kontrol et
		if (arr[i] == target)
			return i;
	}
	// Bulunamazsa -1 döndür
	return -1;
}

// Linear Search algoritması (recursive, tail recursion)
// Sıralı veya sırasız bir dizide aranan elemanın indeksini döndürür, yoksa -1 döner.
int linearSearchRecursive(int arr[], int size, int target, int index = 0) {
	// Dizi sonuna gelindiyse -1 döndür
	if (index >= size)
		return -1;
	// Eleman bulunduysa indeksini döndür
	if (arr[index] == target)
		return index;
	// Sonraki eleman için fonksiyonu tekrar çağır
	return linearSearchRecursive(arr, size, target, index + 1);
}
