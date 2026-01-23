/*
Normal hayatta kendimizi bir kart destesiyle sıralama yaparken düşünelim.
Elimize bir kart alırız ve bu kartı elimizdeki sıralı kartların arasına
doğru pozisyona yerleştiririz. Sonra bir kart daha alırız ve aynı işlemi
tekrarlarız. Tüm kartlar bitene kadar bu işlemi devam ettiririz.
*/
void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;

		// Sol taraftaki elemanları key'den büyük olduğu sürece bir sağa kaydırıyoruz.
		while (j >= 0 && arr[j] > key)
			arr[j + 1] = arr[j--];
		// Key'in doğru pozisyonuna yerleştiriyoruz.
		arr[j + 1] = key;
	}
}
