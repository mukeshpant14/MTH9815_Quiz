#include <iostream>

template <typename T>
class Heap
{
private:
	T **arr;
	int n;

public:
	Heap(int size) 
	{
		arr = new T*[size];
		n = 0;
	}

	void build_maxheap()
	{
		int k;
		for (k = n / 2; k >= 1; k--) {
			heapify(k, n);
		}
	}

	// max heap
	void heapify(int n, int i)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		int smallest = i;
		if (left < n && arr[left] > arr[smallest])
			smallest = left;

		if (right < n && arr[right] > arr[smallest])
			smallest = right;

		if (smallest != i)
		{
			swap(*arr, i, smallest);
			heapify(n, smallest);
		}
	}

	void add(T key)
	{
		n = n + 1;
		arr[n - 1] = &key;

		build_maxheap();
	}

	// Function to delete the root from Heap 
	void deleteRoot()
	{
		int lastElement = arr[n - 1];
		arr[0] = lastElement;

		// Decrease size of heap by 1 
		n = n - 1;

		build_maxheap();
	}

	void swap(T* arr, int i, int j)
	{
		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
};

int main() 
{
	int arr[] = { 45, 23, 12, 49, 5, 7, 18, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Heap<int> heap(10);

	std::cout << "Add node\n";
	heap.add(45);
	heap.add(23);
	heap.add(12);
	heap.add(49);
	heap.add(5);
	heap.add(7);
	heap.add(18);
	heap.add(90);

	std::cout << "Max Heap after add\n";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ",";

	std::cout << "\n----------- Press Any key to quit! -------------\n" << std::endl;
	std::cin.get();
}
