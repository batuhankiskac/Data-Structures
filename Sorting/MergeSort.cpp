/*
İlk olarak, diziyi iki alt diziye bölüyoruz. Daha sonra her iki alt diziyi
tekrar tekrar bölüyoruz ta ki alt diziler tek elemanlı olana kadar. Çünkü tek elemanlı diziler
zaten sıralıdır. Daha sonra bu alt dizileri birleştirmeye başlıyoruz. İki alt diziyi L ve R adında
geçici dizilere kopyalıyoruz. Daha sonra bu iki diziyi karşılaştırarak orijinal diziye sıralı bir şekilde
yerleştiriyoruz. Tüm elemanlar yerleştirildikten sonra geçici dizileri siliyoruz.
*/
void mergesort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);

		int n1 = mid - left + 1;
		int n2 = right - mid;

		int* L = new int[n1];
		int* R = new int[n2];

		for (int i = 0; i < n1; i++)
			L[i] = arr[left + i];
		for (int j = 0; j < n2; j++)
			R[j] = arr[mid + 1 + j];

		int i = 0;
		int j = 0;
		int k = left;

		while (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				arr[k] = L[i];
				i++;
			} else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}

		delete[] L;
		delete[] R;
	}
}
