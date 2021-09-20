#include <iostream>
using namespace std;
#include <string>
#define SIZE 7
//Question 1
void load_array(int target[]);
void print_array(int target[]);
void rand_quick_sort(int target [], int p, int r);
int rand_partition(int target[], int p, int r);
int partition(int target[], int p, int r);
void exchange(int& a, int& b);

int main()
{
	cout << "Unsorted : ";
  print_array(intArr);
	rand_quick_sort(intArr, 0, SIZE - 1);
	cout << "Sorted : ";
	print_array(intArr);
	return 0;
}

void load_array(int target[])
{
	std::cout << "Loading Array" << std::endl;
	for (int i = 0; i < SIZE; i++)
		target[i] = rand() % 20 + 1;     // range 1 to 20
	std::cout << "Array loaded successfully." << std::endl;
} 

void print_array(int target[])
{
	for (int i = 0; i < SIZE; i++)
		cout << target[i] << " ";
	cout << endl;
}
//Randomization improves chances of even partition and nlogn running time.
void rand_quick_sort(int target[], int p, int r)
{
	if (p < r)
	{
		int q = rand_partition(target, p, r);
		rand_quick_sort(target, p, q);
		rand_quick_sort(target, q + 1, r);
	}
}
//Exchanges first element with element from a random index
int rand_partition(int target[], int p, int r)
{
	int i = rand() % (r - p) + p;
	exchange(target[p], target[i]);
	return partition(target, p, r);
}

int partition(int target[], int p, int r)
{
	int x = target[p];
	int i = p;
	int j = r;
	while (true)
	{
		while (target[j] > x)
			j--;
		while (target[i] < x)
			i++;
		if (i < j)
			exchange(target[i], target[j]);
		else
			return j;
	}
}
