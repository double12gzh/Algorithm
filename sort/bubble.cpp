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

	int i = left;
	int j = right;
	bool b_Flag = false;	//improve for bubble

	for (; i<right-1; i++)
	{
		b_Flag = false;

		for (; j>i; j--)
		{
			if (array[j] < array[j-1])
			{
				Swap(array[j], array[j-1]);
				b_Flag = true;
			}
		}
		
		// the array is in order and there is no need to
		// change.
		if (b_Flag == false)
			break;
	}
}

int main()
{
	int array[] = {4,2,6,9,0,23};
	int size_temp = sizeof(array)/sizeof(int);

	bubble(array, 0, size_temp-1);

	for (int i=0; i<size_temp; i++)
		cout<<"array[i] = "<<array[i]<<endl;

	return 0;
}
