#include <iostream>
#include <vector>

using namespace std;

bool matrix_search(vector<vector<int> > &matrix, int target)
{

	int m = matrix.size();   // the raw 
	int n = matrix[0].size();// the column

	for (int r = 0, c= n- 1; (r < m) && (c >= 0);)
	{
		if ( matrix[r][c] > target)
		{
			c--;
		}
		else if (matrix[r][c] < target)
		{
			r++;
		}
		else 
		{
			return true;
		}
	}

	return false;
}


