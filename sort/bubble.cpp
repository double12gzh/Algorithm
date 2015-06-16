#include<iostream>

using namespace std;

template<typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// The improved bubble sort
void bubble(int array[], int left, int right)
{
	assert(left >= 0 && right >= left);

	int i = left;
	int j = right;
	bool b_Flag = false;	//improve for bubble

	for (; i<right-1; i++)
	{
		for (; j>i; j--)
		{
			if (array[j] < array[j-1])
			{
				Swap(array[j], array[j-1]);
				b_Flag = true;
			}
		}
		
		if (b_Flag == false)
			break;
	}
}
