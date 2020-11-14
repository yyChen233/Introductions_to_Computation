#include <iostream>
using namespace std;
int main()
{ int row,col;
int time=0;
cin>>row>>col;
int array[110][110];
for(int i = 0 ; i < row ; i++)
{
for(int j = 0 ; j < col ; j++)
{
cin>>array[i][j];
}
}
for(int n = 0 ;; n++) { for (int i = n ; i < col-n ; i++) { cout<<array[n][i]<<'\n'; time++; }
if(time==row*col)break; for (int j=n+1 ; j < row-n ; j++) { cout<<array[j][col-n-1]<<'\n'; time++; }
if(time==row*col)break; for (int i=col-2-n ; i >= n ; i--) { cout<<array[row-n-1][i]<<'\n'; time++; }
if(time==row*col)break; for (int j=row-2-n ; j>n ; j--) { cout<<array[j][n]<<'\n'; time++; }
if(time==row*col)break; }
return 0; }
