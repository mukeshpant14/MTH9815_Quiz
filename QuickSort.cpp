#include <iostream>
#include <string>

template <typename T>
class QuickSort 
{
public:
	void sort(T* arr, int n)
	{
		quickSort(arr, 0, n - 1);
	}

	void quickSort(T* arr, int low, int high)
	{
		if (low < high)
		{
			int pi = partition(arr, low, high);

			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}

	int partition(T* arr, int low, int high)
	{
		int pivot = arr[high]; // pivot  
		int i = (low - 1); // Index of smaller element  

		for (int j = low; j < high; j++)
		{
			// If current element is smaller than the pivot  
			if (arr[j] < pivot)
			{
				i++; // increment index of smaller element  
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, high);
		return (i + 1);
	}

	void swap(T* arr, int i, int j)
	{
		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	void print(T* arr, int n)
	{
		for (int i = 0; i<n; i++)
			std::cout << arr[i] << ", ";

		std::cout << std::endl;
	}
};

void testQuickSort()
{
	int arr[] = { 45, 23, 12, 49, 5, 7, 18, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	QuickSort<int>* sort = new QuickSort<int>();
	sort->sort(arr, n);
	sort->print(arr, n);

	delete sort;
}

int main()
{
	testQuickSort();
	std::cout << "\n----------- Press Any key to quit! -------------\n" << std::endl;
	std::cin.get();

	return 0;
}
