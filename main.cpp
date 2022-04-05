#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;



void subArraySumBruteForce_1(int *A, int n)
{
	int max = INT_MIN;
	int l = 0, r = n;			// initialize leftmost index "l" to 0 and rightmost index "r" to n
	for (int i = 0; i < n; i++) // loop for calculating all possible subarrays
		for (int j = i; j < n; j++)
		{
			int sum = 0;
			for (int k = i; k <= j; k++) // loop for calculating the sum of each subarray and store in sum
				sum += A[k];
			if (sum > max)
			{ // if the newly calculated sum is greater than max then update max
				max = sum;
				l = i;
				r = j;
			}
		}
	cout << l + 1 << " " << r + 1 << " " << max << endl;
}

void SubArraySumDP_2(int *A, int n)
{
	int T[n][n]; // T[i][j] stores the sum of elements of array from i through j.
	int max = INT_MIN;
	int l = -1, r = -1; // initialize leftmost index "l" to -1 and rightmost index "r" to -1

	for (int i = 0; i < n; i++) // loop for computing all possible subarray sums
	{
		for (int j = i; j < n; j++)
		{
			if (i == j) // if it is the same element then the sum is the element itself
			{
				T[i][i] = A[i];
				if (T[i][i] > max) // if the newly calculated sum is greater than max then update max
				{
					max = T[i][i];
					l = i;
					r = i;
				}
			}
			else // else it is the sum until previous elements and the new element
			{
				T[i][j] = T[i][j - 1] + A[j]; // implementing substructure property for Dynamic programming
				if (T[i][j] > max)			  // if the newly calculated sum is greater than max then update max
				{
					max = T[i][j];
					l = i;
					r = j;
				}
			}
		}
	}

	cout << l + 1 << " " << r + 1 << " " << max << endl;
}

int Maximum_sum(int *A, int T[], int i, int &l, int &r, int &max)
{
	if (i == 0)
	{
		return A[0];
	}
	else
	{
		if (T[i] == INT_MIN) // Checking if value of substructure is already calculated
		{
			int sum = Maximum_sum(A, T, i - 1, l, r, max) + A[i]; // Calculating solution of substructure and implementing dynamic programming with the calculated value using recursion
			if (sum > A[i])
			{
				T[i] = sum;
				if (max < T[i])
				{
					max = T[i];
					r = i;
				}
			}
			else
			{
				T[i] = A[i];
				if (max < T[i])
				{
					max = T[i];
					l = i;
					r = i;
				}
			}
		}
		else
		{
			int sum = T[i - 1] + A[i]; // implementing substructure property for Dynamic programming
			if (sum > A[i])
			{
				T[i] = sum;
				if (max < T[i])
				{
					max = T[i];
					r = i;
				}
			}
			else
			{
				T[i] = A[i];
				if (max < T[i])
				{
					max = T[i];
					l = i;
					r = i;
				}
			}
		}
	}
	return T[i];
}

void SubArraySumDP_3a(int *A, int n)
{
	int l = 0;
	int r = 0;
	int max = INT_MIN;
	int T[n]; // T[i] contains maximum sum in contiguous subarray till ith index
	for (int i = 0; i < n; i++)
	{
		T[i] = INT_MIN;
	}
	int sum = Maximum_sum(A, T, n - 1, l, r, max);

	cout << l + 1 << " " << r + 1 << " " << max << endl;
}

void SubArraySumDP_3b(int *A, int n)
{
	int T[n]; // T[i] contains maximum sum in contiguous subarray till ith index
	for (int i = 0; i < n; i++)
	{
		T[i] = A[i];
	}

	int max = T[0];
	int l = 0, r = 0;

	for (int i = 1; i < n; i++)
	{
		if (T[i] < T[i - 1] + A[i]) // implementing substructure property for Dynamic programming
		{
			T[i] = T[i - 1] + A[i];
			if (max < T[i])
			{
				max = T[i];
				r = i;
			}
		}
		else
		{
			if (max < T[i])
			{
				max = T[i];
				l = i;
				r = i;
			}
		}
	}

	cout << l + 1 << " " << r + 1 << " " << max << endl;
}

void rectangleSumBruteForce_4(int m, int n, vector<int> M[])
{

	int maxrectanglesum = INT_MIN;
	int a = -1, b = -1, c = -1, d = -1;
	int total;
//We will use 4 nested loops to fix the corners of the rectangle/submatrix
	for (int p = 0; p < m; p++)
	{
		for (int q = 0; q < n; q++)
		{
			for (int r = p; r < m; r++)
			{
				for (int s = q; s < n; s++)
				{
					total = 0;
//then we use another 2 nested loops to calculate the sum of that fixed submatrix.
					for (int i = p; i <= r; i++)
					{
						for (int j = q; j <= s; j++)
						{
							total = total + M[i][j];
						}
					}

					if (total > maxrectanglesum)
					{
						maxrectanglesum = total;
						a = p;
						b = q;
						c = r;
						d = s;
					}
				}
			}
		}
	}

	cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << " " << maxrectanglesum << endl;
}


int maximum_subarray_sum(vector<int> &A, int &begin, int &last, int n) // Using maxsubarray problem in task 3b(Implementation of Kadane's DP algorithm for 1D array)
{
	int max_sum = A[0];
	int total = A[0];
	begin = 0;
	last = 0;

	for (int i = 0; i < n; i++)
	{
		if (A[i] < total + A[i]) // implementing substructure property for Dynamic programming
		{
			total = total + A[i];
			if (max_sum < total)
			{
				max_sum = total;
				last = i;
			}
		}
		else
		{
			total = A[i];
			if (max_sum < total)
			{
				max_sum = total;
				begin = i;
				last = i;
			}
		}
	}

	return max_sum;
}

void rectangleSumDP_5(int m, int n, vector<int> matrix[])
{
	int totalSum = INT_MIN;
	int a, b, c, d;

	int l, r, i, j;
	int sum, start, end;

	for (l = 0; l < n; l++)
	{

		for (r = l; r < n; r++)
		{

			vector<int> temp(m, 0);  // Initialize all elements of temp as 0
			for (i = 0; i < m; i++)
			{
				for (j = l; j <= r; j++)
				{
					temp[i] = temp[i] + matrix[i][j];  // Calculate sum between current left(l) and right(r) for every row 'i
				}
			}
/*Find the maximum sum subarray in temp[].The function below also sets values of start and finish.
So 'sum' is sum of rectangle between (start, left) and (finish, right) which is the maximum sum with boundary columns strictly as left and right.*/

			sum = maximum_subarray_sum(temp, start, end, m); //using dynamic programming Algorithm3(Problem 1)

			if (sum > totalSum)// Compare sum with max_total so far with,If sum is more, then update maxSum and other output values
			{
				totalSum = sum;
				a = l;
				b = r;
				c = start;
				d = end;
			}
		}
	}

	cout << c + 1 << " " << a + 1 << " " << d + 1 << " " << b + 1 << " " << totalSum << endl; // Print final values
}


void rectangleSumDP_6(int m, int n, vector<int> matrix[])
{
	int max_total = INT_MIN;
	int a, b, c, d;

	int l, r, i;
	int sum, start, end;

	for (l = 0; l < n; l++)
	{

		vector<int> temp(m, 0);  // Initialize all elements of temp as 0

		for (r = l; r < n; r++)
		{

			for (i = 0; i < m; i++)
				temp[i] = temp[i] + matrix[i][r];  // Calculate sum between current left and right for every row 'i

// Find the maximum sum subarray in temp[].The function below also sets values of start and finish.
//So 'sum' is sum of rectangle between (start, left) and (finish, right) which is the maximum sum with boundary columns strictly as left and right.
			
sum = maximum_subarray_sum(temp, start, end, m);    //using dynamic programming Algorithm3(Problem 1)

			if (sum > max_total) // Compare sum with max_total so far with,If sum is more, then update maxSum and other output values
			{
				max_total = sum;
				a = l;
				b = r;
				c = start;
				d = end;
			}
		}
	}

	cout << c + 1 << " " << a + 1 << " " << d + 1 << " " << b + 1 << " " << max_total << endl;  // Print final values
}


int main(int argc, char *argv[])
{
    int m,n;
    if (argv[1][0] == '1')
    {
        cout << "Task 1" << endl;
        cin >> n;
        int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
subArraySumBruteForce_1(A,n);
    }
    else
    if (argv[1][0] == '2')
    {
        cout << "Task 2" << endl;
         cin >> n;
        int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
        SubArraySumDP_2(A,n);
    }
    else
    if (argv[1][0] == '3')
    {
        if (argv[1][1] == 'a')
        {
            cout << "Task 3a" << endl;
             cin >> n;
        int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
            SubArraySumDP_3a(A,n);
        }

        if (argv[1][1] == 'b')
        {
            cout << "Task 3b" << endl;
             cin >> n;
        int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
            SubArraySumDP_3b(A,n);
        }
    }
    else
    if (argv[1][0] == '4')
    {
        cout << "Task 4" << endl;
        int row,col;
    cin>>row>>col;
    vector<int> M[row];
    for(int i=0;i<row;i++){
        M[i].assign(col,0);
     for(int j=0;j<col;j++){
        cin>>M[i][j];
    }
    }
        rectangleSumBruteForce_4(row,col,M);
    }
    else
    if (argv[1][0] == '5')
    {
        cout << "Task 5" << endl;
        int row,col;
    cin>>row>>col;
    vector<int> M[row];
    for(int i=0;i<row;i++){
        M[i].assign(col,0);
     for(int j=0;j<col;j++){
        cin>>M[i][j];
    }
    }
        rectangleSumDP_5(row,col,M);
    }
    else
    if (argv[1][0] == '6')
    {
        cout << "Task 6" << endl;
        int row,col;
    cin>>row>>col;
    vector<int> M[row];
    for(int i=0;i<row;i++){
        M[i].assign(col,0);
     for(int j=0;j<col;j++){
        cin>>M[i][j];
    }
    }
        rectangleSumDP_6(row,col,M);
    }
    return 0;
}