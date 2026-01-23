
// Interpolation Search algoritması
// Sıralı bir dizide aranan elemanın indeksini döndürür, yoksa -1 döner.
// Arama, aranan değerin dizideki konumunu tahmin ederek daha hızlı bulmayı amaçlar.
int interpolationSearch(int arr[], int size, int target) {
	int low = 0;
	int high = size - 1;

	// Aranan değer, dizinin sınırları içindeyse ve low <= high ise devam et
	while (low <= high && target >= arr[low] && target <= arr[high]) {
		// Eğer aralıkta tek bir eleman kaldıysa kontrol et
		if (low == high) {
			if (arr[low] == target)
				return low;
			return -1;
		}

		// Pozisyonu tahmin et: lineer dağılım varsayımı ile
		int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));

		// Aranan değer bulunduysa
		if (arr[pos] == target)
			return pos;
		// Aranan değer pozisyondan büyükse, aramayı sağ tarafa kaydır
		if (arr[pos] < target)
			low = pos + 1;
		// Aranan değer pozisyondan küçükse, aramayı sol tarafa kaydır
		else
			high = pos - 1;
	}
	// Değer bulunamazsa -1 döndür
	return -1;
}
