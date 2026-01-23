#include <vector>
#include <algorithm>

/*
   Fibonacci Search
   Mantık: Diziyi sürekli Fibonacci oranlarında (yaklaşık 1/3 ve 2/3) bölmek.
   Değişkenler:
	 fibM   : Diziyi kapsayan ana Fibonacci sayısı (F_m)
	 fibMM1 : Bir önceki (F_m-1) - "Middle Minus 1"
	 fibMM2 : İki önceki (F_m-2) - "Middle Minus 2"
*/

int fibonacciSearch(const std::vector<int>& arr, int x) {
	int n = arr.size();
	if (n == 0) return -1;

	// 1. ADIM: Diziyi kapsayacak en küçük Fibonacci sayısını bul
	int fibMM2 = 0; // (m-2)'nci Fibonacci
	int fibMM1 = 1; // (m-1)'inci Fibonacci
	int fibM = fibMM2 + fibMM1; // m'inci Fibonacci

	// n'den büyük veya eşit en küçük Fibonacci sayısını bulana kadar ilerle
	while (fibM < n) {
		fibMM2 = fibMM1;
		fibMM1 = fibM;
		fibM = fibMM2 + fibMM1;
	}

	// 'offset', elimine edilen sol kısmın son indeksini tutar.
	// Başlangıçta hiçbir şey elimine edilmediği için -1'dir.
	int offset = -1;

	// 2. ADIM: fibM 1'den büyük olduğu sürece döngüye gir
	while (fibM > 1) {
		// Kontrol edilecek indeks (i)
		// offset + fibMM2: Yani eldeki aralığın yaklaşık 1/3'lük (altın oran) kısmı.
		// min(..., n-1): Dizi sınırını aşmamak için güvenlik.
		int i = std::min(offset + fibMM2, n - 1);

		// A) Eğer aranan değer, bu indeksteki değerden BÜYÜKSE
		// Demek ki aranan sayı SAĞ tarafta (daha ileride).
		if (arr[i] < x) {
			// Fibonacci sayılarını 1 adım küçült (shift 1 down)
			fibM = fibMM1;
			fibMM1 = fibMM2;
			fibMM2 = fibM - fibMM1;

			// Başlangıç noktamızı (offset) şimdiki indekse taşı
			offset = i;
		}

		// B) Eğer aranan değer, bu indeksteki değerden KÜÇÜKSE
		// Demek ki aranan sayı SOL tarafta.
		else if (arr[i] > x) {
			// Fibonacci sayılarını 2 adım küçült (shift 2 down)
			// Neden 2 adım? Çünkü sol parça (fibMM2), sağ parçadan (fibMM1) daha küçüktür.
			fibM = fibMM2;
			fibMM1 = fibMM1 - fibMM2;
			fibMM2 = fibM - fibMM1;
		}

		// C) Eşitse bulduk demektir
		else {
			return i;
		}
	}

	// 3. ADIM: Son kontrol
	// Fibonacci mantığı bazen son elemanı kaçırabilir,
	// özellikle fibMM1 1 olduğunda son bir kontrol gerekebilir.
	if (fibMM1 && offset + 1 < n && arr[offset + 1] == x) {
		return offset + 1;
	}

	return -1;
}
