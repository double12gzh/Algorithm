#include<iostream>

/* Function: shell_insert()
 *
 * Dscription:
 * 	     可以看成是分组插入，主要的一点就是要
 * 	     知道分组的增量是多少.
 * 	     e.g:
 * 	     arr[] = {49,38,65,97,76,13,27,49,55,4}
 * 	     49  38  65  97 76  13  27  49  55  4
 * 	    - 49                 13                -
 * 	    | |__________________|                 |
 * 	    |    38                 27             |
 *          |    |__________________|              |
 * 	    |        65                 49         |
 * 	    |        |__________________|          |
 * 	    |   	 97                 55     |
 *          |    	 |__________________|      |
 *          |		     76                 4  |
 *          |		     |__________________|  |
 *          -                                      -
 * 	     一趟排序的结果：
 * 		13 27 49 55 4 49 38 65 97 76
 */
using namespace std;

void Swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template<typename T>
void shell_sort(T arr[])
{
	int num_arr = sizeof(arr)/sizeof(T);
	int group, i, j;

	for (group = num_arr/2; group > 0; group /= 2)
	{
		for (i = group; i < num_arr; i++)
		{
			for (j = i - group; j >= 0; j -= group)
			{
				if (arr[j] > arr[j+group])
				{
					Swap(arr, j, j+group);
				}
			}
		}
	}

}

int main()
{
	int arr[] = {6,2,4,1,5};
	int num_arr = sizeof(arr)/sizeof(int);

	cout<<"The orig array is :"<<endl;
	for (int i=0; i<num_arr; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	//test shell_sort function
	shell_sort(arr);

	cout<<"The ordered array is :"<<endl;
	for (int i=0; i<num_arr; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
