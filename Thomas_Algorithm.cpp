#include<iostream>
using namespace std;
int main()
{
	int n,i;
	float a[100], b[100], c[100], d[100], x[100], alpha[100], beta[100];
	cout<<"Enter the number of equations/number of variables\n";
	cin>>n;
	cout<<"Enter of values of the principle diagonals\n";
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	
	cout<<"Enter of values of the sub-diagonals\n";
	for(i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter of values of the super-diagonals\n";
	for(i=1;i<=n-1;i++)
	{
		cin>>c[i];
	}
	
	cout<<"Enter of values of the right hand side elements\n";
	for(i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	
	alpha[1]=b[1];
	for(i=2;i<=n;i++)
	{
		alpha[i]=b[i]-(a[i]*c[i-1])/alpha[i-1];
	}
	
	beta[1]=d[1]/b[1];
	
	for(i=2;i<=n;i++)
	{
		beta[i]=(d[i]-a[i]*beta[i-1])/alpha[i];
	}
	
	x[n]=beta[n];
	for(i=n-1;i>=1;i--)
	{
		x[i]=beta[i]-(c[i]*x[i+1])/alpha[i];
	}
	
	cout<<"The Solution for the system of linear equation is: \n";
	
	for(i=1;i<=n;i++)
	{
		cout<<x[i]<<" ";
	}
		
}
