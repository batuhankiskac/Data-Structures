#include <algorithm>

/*
Cocktail Shaker Sort, Bubble Sort'un geliştirilmiş bir versiyonudur.
Bu algoritma, diziyi iki yönlü olarak sıralar: önce soldan sağa, sonra sağdan sola.
Çünkü bubble sortta büyük elemanlar en sağa tek turda giderken, küçük elemanlar
en sola doğru yavaş ilerler. Bu nedenle, cocktail shaker sort her iki yönde de geçiş yaparak
küçük elemanların da hızlıca en sola yerleşmesini sağlar.
*/
void cocktailShakerSort(int arr[], int n) {
	int start = 0;
	int end = n - 1;

	// Dizinin başından sonuna ve sonundan başına doğru sıralama yapıyoruz.
	while (start < end) {
		// Soldan sağa geçiş
		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1])
				std::swap(arr[i], arr[i + 1]);
		}
		end--;
		// Sağdan sola geçiş
		for (int i = end; i > start; --i) {
			if (arr[i] < arr[i - 1])
				std::swap(arr[i], arr[i - 1]);
		}
		start--;
	}
}
