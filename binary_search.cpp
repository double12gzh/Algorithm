/* Funtion: binary_search
 *  
 * Description:
 * 		The algorithm for binary search.
 * 		the time complexity is O(logn).
 *
 * Input:
 * 		Arry -- an arrary
 * 		start -- the start of the array(depends on the user)
 * 		end -- end of the array(depends on the user)
 * 		key -- the aim value
 *
 * Return:
 * 		mid -- the position for the key in array
 * 		-1 -- FAILURE
 */

#include <iostream>
#include <string.h>

using namespace std;

int binary_search(const int *Arry, int start, int end, int key)
{
	int left = start;
	int right = end;

	while (left <= right)
	{
		int mid = (left+right)/2;

		if (key == Arry[mid])
		{
			return mid;
		}
		else if (key > Arry[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}


int main ()
{
	int num[] = {1,2,3,4,5,6,7,8};
	int key = 0;

	cout<<"before sizeof = "<<sizeof(num)/sizeof(int)<<endl;
	cout<< "please input the number between"<<0<<" and "
	<<sizeof(num)/sizeof(int)<<endl;
	cin>>key;

	int rtn = binary_search(num, 0, 7, key);
	cout<<"rtn = "<<rtn<<endl;

	return 0;
}
