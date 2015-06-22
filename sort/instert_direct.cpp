#include<iostream>

using namespace std;

/*
 *   Function: 
 *      	InsertSort_Direct
 *
 *   Description:
 *      	O(n^2)
 *      	-------------------
 *      	|  |  |  |  |  |  |
 *      	-------------------
 *      	 ^         ^
 *      	 |         |
 *      	 j         i
 *
 *              每次将一个待排序的记录，按其关键字大小插入到前面
 * 		已经排好序的子文件中的适当位置，直到全部记录插入
 * 		完成为止。
 * 		分类： 直接插入排序和shell排序
 *
 *   Input:
 * 		a     ---> the array needed to be sorted
 *              left  ---> the start of the array
 * 		right ---> the end of the array
 */
template<typename T>
void InsertSort_Direct(T a[], int left, int right)
{
	int i, j;
	
	for(i = left+1; i<=right; i++)
	{
		for(j = left; j<i; j++)
		{
			if(a[i] < a[j])
			{
				int temp = a[i];
				for (int k = i; k >= j+1; k--)
				{
					a[k] = a[k-1];
				}
				a[j] = temp;
				/* arr[left...j] are in sorted */
				break;
			}
		}
	}
}

//Just for test
int main()
{

	int arr[] = {0,3,33,20,55,30,20};
	int right =sizeof(arr)/sizeof(int) - 1;

	cout<<"Original array is:"<<endl;
	for (int i=0; i<=right; i++)
		cout<<"arr["<<i<<"] = "<<arr[i]<<endl;

	InsertSort_Direct(arr, 0, right);

	cout<<"sorted array is:"<<endl;
	for (int i=0; i<=right; i++)
		cout<<"arr["<<i<<"] = "<<arr[i]<<endl;

	return 0;
}
