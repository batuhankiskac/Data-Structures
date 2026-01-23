#include <algorithm>

/*
Sol taraftaki ilk elemanı pivot olarak alıyoruz. Daha sonra sağ taraftaki elemanlarla
karşılaştırarak en küçüğünü buluyoruz. En küçük elemanı pivot ile yer değiştiriyoruz.
Bu işlemi dizinin sonuna kadar tekrarlıyoruz.
*/
void selectionSort(int arr[], int n) {
	int min;

	for (int pivot = 0; pivot < n - 1; ++pivot) {
		min = pivot;
		for (int j = pivot + 1; j < n; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		std::swap(arr[pivot], arr[min]);
	}
}
