#include <cmath>
#include <algorithm>

int jumpSearch(int arr[], int size, int target) {
	if (size == 0)
		return -1;

	int jumpStep = sqrt(size);
	int prev = 0;
	int step = jumpStep;

	while (arr[std::min(step, size) - 1] < target) {
		prev = step;
		step += jumpStep;
		if (prev >= size)
			return -1;
	}

	while (arr[prev] < target) {
		prev++;
		if (prev == std::min(step, size))
			return -1;
	}

	if (arr[prev] == target)
		return prev;

	return -1;
}
