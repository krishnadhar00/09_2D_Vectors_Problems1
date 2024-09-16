//  Given a square matrix, turn it by 90 degrees in clockwise directions without using any extra spaces. 
// No extra space means we cannnot use another array or matrix. 
// Approach : First row become last column and last row become first column by rotatiting 90 degree so First find the transpose and just reverse all the row so we can get the answer. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotateMatrix(vector<vector<int>> &V)
{
    int n = V.size();

    // Finding the transpose here we are using swap because we cannot made another matrix or array and loop for j is going to leass than i bcox if we have to only swap the lowermost array element or the uppermost only not the both if both will happen then it wil come to the real matrix.

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(V[i][j],V[j][i]);
        }
    }
    // Now reversing the row so that 1st column become the last and last column become the first one.
    for(int i=0;i<n;i++)
    {
        reverse(V[i].begin(),V[i].end());
    }

    return;

}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }

    rotateMatrix(vec);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

}