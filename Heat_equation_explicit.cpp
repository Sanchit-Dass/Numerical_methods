#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[100][100],l;
	int i,j;
	cout<<"Enter the value of lambda "<<endl;
	cin>>l;
	
	for(i=0;i<=5;i++)
	{
		a[i][0]=a[i][4]=0;
	}
	
	for(j=1;j<=3;j++)
	{
		a[0][j]=j*(4-j);
	}
	
	for(i=0;i<=4;i++)
	{
		for(j=1;j<=3;j++)
		{
			a[i+1][j]=l*a[i][j-1]+(1-2*l)*a[i][j]+l*a[i][j+1];
			
		}
	}
	
	for(i=0;i<=5;i++)
	{
		for(j=0;j<=4;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
}
