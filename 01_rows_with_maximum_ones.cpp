// Rows with maximum number of ones.
// Given a boolean 2D array, where each row is sorted.Find the row with the maximum number of one's.
// Alternative approach to solve this question is searching the row with leftmost ones.
// What happens in leftmost ones is that from last we search the 1 till it present and then in the next row we search the one of left side of above row if 1 exists then leftmost one changes to second row and if not then first row is the leftmost one row.

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// Another approach to solve this question.
int leftMostOnes(vector<vector<int>>&V)
{
    int leftMostOne = -1;
    int leftMostIndex = -1;
    int j = V[0].size()-1;

    // finding leftmost ones in 0th row.
    while(j>=0 && V[0][j]==1)
    {
        leftMostOne = j;
        leftMostIndex = 0;
        j--;
    }

    // Check in rest of the rows if we can find a one left to the leftmost one 
    for(int i=1;i<V.size();i++)
    {
        while(j>=0 && V[i][j]==1) 
        {
            leftMostOne = j;
            leftMostIndex = i;
            j--;
        }
    }
    return leftMostIndex;
}

int maximumOnesRow(vector<vector<int>> &V)
{
    int maxNumberOnes = INT_MIN;
    int maxRowIndex = -1;
    int column = V[0].size();

    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            if(V[i][j]==1)
            {
                int numberOfOnes = column - j;
                if(numberOfOnes > maxNumberOnes)
                {
                    maxNumberOnes = numberOfOnes;
                    maxRowIndex = i;
                }
                break;
            }
        }
    }
    return maxRowIndex;

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }

    // int result = maximumOnesRow(vec);
    int ans = leftMostOnes(vec);
    // cout<<result<<" ";
    cout<<ans<<" ";
}