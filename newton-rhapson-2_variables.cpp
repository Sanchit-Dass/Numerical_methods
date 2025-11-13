#include<bits/stdc++.h>
using namespace std;

float f(float x, float y)
{
	return (x*x+y*y-4);
}

float g(float x, float y)
{
	return (x-y);
}

float fx(float x, float y)
{
	return (2*x);
}

float fy(float x, float y)
{
	return (2*y);
}

float gx(float x, float y)
{
	return (1);
}

float gy(float x, float y)
{
	return (-1);
}

float D(float x, float y)
{
	return(fx(x,y)*gy(x,y)-gx(x,y)*fy(x,y));
}

float Dx(float x, float y)
{
	return(f(x,y)*gy(x,y)-g(x,y)*fy(x,y));
}

float Dy(float x, float y)
{
	return(fx(x,y)*g(x,y)-gx(x,y)*f(x,y));
}

int main()
{
	float x0,y0,epsilon,h,k,x1,y1;
	
	cout<<"Enter the initial guess"<<endl;
	cin>>x0>>y0;
	cout<<"Enter the tolerance error"<<endl;
	cin>>epsilon;
	
	
	h=-Dx(x0,y0)/D(x0,y0);
	k=-Dy(x0,y0)/D(x0,y0);
	x1=x0+h;
	y1=y0+k;
	
	while(abs(x1-x0)>epsilon || abs(y1-y0)>epsilon)
	{
		x0=x1;
		y0=y1;
		
		h=-Dx(x0,y0)/D(x0,y0);
	    k=-Dy(x0,y0)/D(x0,y0);
	    x1=x0+h;
      	y1=y0+k;
		
	}
	
	cout<<"The roots of the equation are: "<<x1<<","<<y1;
	
	
	
}
