#include <algorithm>

/*
Her iki komşu elemanı karşılaştırıyoruz. Eğer sol taraftaki eleman sağdaki
elemandan büyükse yer değiştiriyoruz. Bu işlemi dizinin sonuna kadar tekrarlıyoruz.
Dış döngüde her seferinde en büyük eleman sona yerleştiği için karşılaştırma
sayısını birer azaltıyoruz.
*/
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
}
