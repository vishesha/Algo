#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

void subArraySumBruteForce_1(int *A, int n){
	int sum;
	int maximumsum = INT_MIN;
	int start = -1, end = -1;

	for (int i = 0; i < n; i++) // iterating through each element in array considering it as left index for maxsum
	{
		for (int j = i; j < n; j++) // iterating through each element from i in array considering it as right index for maxsum
		{
			sum = 0;
			for (int k = i; k <= j; k++) // iterating through each element from i to j to calculate sum
			{
				sum = sum + A[k];
			}

			if (sum > maximumsum) // checking if current sum is greater than existing maximum sum and updating values
			{
				maximumsum = sum;
				start = i;
				end = j;
			}
		}
	}

	cout << start + 1 << " " << end + 1 << " " << maximumsum << endl;
}

void SubArraySumDP_2(int *A,int n)
{
	int sum;

	int S[n][n]; // S[i][j] is considered as sum of elements of array from i to j indexes

	int maximumsum = INT_MIN;
	int start = -1, end = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
			{
				S[i][i] = A[i];
				if (S[i][i] > maximumsum)
				{
					maximumsum = S[i][i];
					start = i;
					end = i;
				}
			}
			else
			{
				S[i][j] = S[i][j - 1] + A[j]; // implementing substructure property for Dynamic programming
				if (S[i][j] > maximumsum)
				{
					maximumsum = S[i][j];
					start = i;
					end = j;
				}
			}
		}
	}

	cout << start + 1 << " " << end + 1 << " " << maximumsum << endl;
}


int Maximum_sum(int *A, int S[], int i, int &start, int &end, int &maximumsum)
{
	if (i == 0)
	{
		return A[0];
	}
	else
	{
		if (S[i] == INT_MIN) // Checking if value of substructure is already calculated
		{
			int sum = Maximum_sum(A, S, i - 1, start, end, maximumsum) + A[i]; // Calculating solution of substructure and implementing dynamic programming with the calculated value
			if (sum > A[i])
			{
				S[i] = sum;
				if (maximumsum < S[i])
				{
					maximumsum = S[i];
					end = i;
				}
			}
			else
			{
				S[i] = A[i];
				if (maximumsum < S[i])
				{
					maximumsum = S[i];
					start = i;
					end = i;
				}
			}
		}
		else
		{
			int sum = S[i - 1] + A[i]; // implementing substructure property for Dynamic programming
			if (sum > A[i])
			{
				S[i] = sum;
				if (maximumsum < S[i])
				{
					maximumsum = S[i];
					end = i;
				}
			}
			else
			{
				S[i] = A[i];
				if (maximumsum < S[i])
				{
					maximumsum = S[i];
					start = i;
					end = i;
				}
			}
		}
	}
	return S[i];
}


void SubArraySumDP_3a(int *A, int n)  {
int start = 0;
	int end = 0;
	int maximumsum = INT_MIN;
	int S[n]; // S[i] contains maximum sum in contiguous subarray till ith index
	for (int i = 0; i < n; i++)
	{
		S[i] = INT_MIN;
	}
	int sum = Maximum_sum(A, S, n - 1, start, end, maximumsum);

	cout << start + 1 << " " << end + 1 << " " << maximumsum << endl;
}




void SubArraySumDP_3b(int *A, int n)  {
  int S[n]; // S[i] contains maximum sum in contiguous subarray till ith index
	for (int i = 0; i < n; i++)
	{
		S[i] = A[i];
	}

	int maximumsum = S[0];
	int start = 0, end = 0;

	for (int i = 1; i < n; i++)
	{
		if (S[i] < S[i - 1] + A[i]) // implementing substructure property for Dynamic programming
		{
			S[i] = S[i - 1] + A[i];
			if (maximumsum < S[i])
			{
				maximumsum = S[i];
				end = i;
			}
		}
		else
		{
			if (maximumsum < S[i])
			{
				maximumsum = S[i];
				start = i;
				end = i;
			}
		}
	}

	cout << start + 1 << " " << end + 1 << " " << maximumsum << endl;
}

void rectangleSumBruteForce_4(int m, int n, vector<int> M[])
{

	int maximumsum = INT_MIN;
	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	int sum;

	for (int p = 0; p < m; p++)
	{
		for (int q = 0; q < n; q++)
		{
			for (int r = p; r < m; r++)
			{
				for (int s = q; s < n; s++)
				{
					sum = 0;
					for (int i = p; i <= r; i++)
					{
						for (int j = q; j <= s; j++)
						{
							sum = sum + M[i][j];
						}
					}

					if (sum > maximumsum)
					{
						maximumsum = sum;
						x1 = p;
						y1 = q;
						x2 = r;
						y2 = s;
					}
				}
			}
		}
	}

	cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << " " << maximumsum << endl;
}


int maxsubarray(vector<int> &A, int &start, int &end, int n) // Using maxsubarray problem in task 3b
{
	int maximumsum = A[0];
	int currentmaximum = A[0];
	start = 0;
	end = 0;

	for (int i = 0; i < n; i++)
	{
		if (A[i] < currentmaximum + A[i]) // implementing substructure property for Dynamic programming
		{
			currentmaximum = currentmaximum + A[i];
			if (maximumsum < currentmaximum)
			{
				maximumsum = currentmaximum;
				end = i;
			}
		}
		else
		{
			currentmaximum = A[i];
			if (maximumsum < currentmaximum)
			{
				maximumsum = currentmaximum;
				start = i;
				end = i;
			}
		}
	}

	return maximumsum;
}

void rectangleSumDP_5(int m, int n, vector<int> matrix[])
{
	int maxSum = INT_MIN;
	int Left, Right, Top, Bottom;

	int currentleft, currentright, i, j;
	int sum, start, end;

	for (currentleft = 0; currentleft < n; currentleft++)
	{

		for (currentright = currentleft; currentright < n; currentright++)
		{

			vector<int> temp(m, 0);
			for (i = 0; i < m; i++)
			{
				for (j = currentleft; j <= currentright; j++)
				{
					temp[i] = temp[i] + matrix[i][j];
				}
			}

			sum = maxsubarray(temp, start, end, m);

			if (sum > maxSum)
			{
				maxSum = sum;
				Left = currentleft;
				Right = currentright;
				Top = start;
				Bottom = end;
			}
		}
	}

	cout << Top + 1 << " " << Left + 1 << " " << Bottom + 1 << " " << Right + 1 << " " << maxSum << endl;
}


void rectangleSumDP_6(int m, int n, vector<int> matrix[])
{
	int maxSum = INT_MIN;
	int Left, Right, Top, Bottom;

	int currentleft, currentright, i;
	int sum, start, end;

	for (currentleft = 0; currentleft < n; currentleft++)
	{

		vector<int> temp(m, 0);

		for (currentright = currentleft; currentright < n; currentright++)
		{

			for (i = 0; i < m; i++)
				temp[i] = temp[i] + matrix[i][currentright];

			sum = maxsubarray(temp, start, end, m);

			if (sum > maxSum)
			{
				maxSum = sum;
				Left = currentleft;
				Right = currentright;
				Top = start;
				Bottom = end;
			}
		}
	}

	cout << Top + 1 << " " << Left + 1 << " " << Bottom + 1 << " " << Right + 1 << " " << maxSum << endl;
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