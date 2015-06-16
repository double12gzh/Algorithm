#include<iostream>

using namespace std;

template<typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int bubble(int array[], int left, int right)
{
	int i = left;
	int j = right;
	bool b_Flag = FALSE;

	for (; i<n-1; i++)
	{
		for (; j>i; j--)
		{
			if (array[j] < array[j-1])
			{
				Swap(array[j], array[j-1]);
				b_Flag = TRUE;
			}
		}
		
		if (b_Flag == FALSE)
			break;
	}
	
	return 0;  
}
