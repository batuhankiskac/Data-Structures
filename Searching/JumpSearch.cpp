#include <cmath>
#include <algorithm>

// Jump Search algoritması
// Sıralı bir dizide aranan elemanın indeksini döndürür, yoksa -1 döner.
// Dizi bloklara ayrılır ve blok atlayarak arama yapılır, ardından lineer arama ile bulunur.
int jumpSearch(int arr[], int size, int target) {
	if (size == 0)
		return -1;

	int jumpStep = sqrt(size); // Atlanacak blok boyutu
	int prev = 0;
	int step = jumpStep;

	// Hedef değerin olabileceği bloğu bul
	while (arr[std::min(step, size) - 1] < target) {
		prev = step;
		step += jumpStep;
		if (prev >= size)
			return -1;
	}

	// Bloğun içinde lineer arama yap
	while (arr[prev] < target) {
		prev++;
		if (prev == std::min(step, size))
			return -1;
	}

	// Değer bulunduysa indeksini döndür
	if (arr[prev] == target)
		return prev;

	// Bulunamazsa -1 döndür
	return -1;
}
