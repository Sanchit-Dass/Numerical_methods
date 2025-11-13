#include<bits/stdc++.h>
using namespace std;

float f(float x,float y)
{
	return (6-2*(y/x));
}
int main()
{
	int n,i;
	float h,x0,xn,y0,y;
	cout<<"Enter the initial approximation for x"<<endl;
	cin>>x0;
	cout<<"Enter the initial approximation for y"<<endl;
	cin>>y0;
	cout<<"Enter the stepsize"<<endl;
	cin>>h;
	cout<<"Enter the value of x at which the value of y is needed"<<endl;
	cin>>xn;
	n=(xn-x0)/h;
	for(i=1;i<=n;i++)
	{
		y=y0+h*f(x0,y0);
		x0=x0+h;
		y0=y;
		
    }
    cout<<y0;
		
}
