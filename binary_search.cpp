#include <iostream>


int bsearch(int arr[], int len, int value)
{
	int low = 0;
	int high = len - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (value == arr[mid]) {
			while (mid >= 0 && value == arr[mid-1]) {
				mid -= 1;
			}
			return mid;
		} else if (value < arr[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
	int arr[] = {1, 2, 3, 3, 3, 4, 5, 8, 8, 8, 10, 10, 10};
	int len = 13;
	int value = atoi(argv[1]);
	
	for (int i = 0; i < len; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << bsearch(arr, len, value) << std::endl;
}
