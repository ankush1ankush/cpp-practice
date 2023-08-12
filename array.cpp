#include<bits\stdc++.h>
using namespace std;
/*void printarr(int m,int n,int arr[][n]){
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    int arr[][5]={{1,2,3},{4,5}};
    printarr(2,5,arr);
}*/
void print(int m, int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", arr[i][j]);
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
    print(m, n, arr);
    return 0;
}