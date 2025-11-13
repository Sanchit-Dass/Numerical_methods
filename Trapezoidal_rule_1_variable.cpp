#include<bits/stdc++.h>
using namespace std;

float f(float x)
{
	return (1/(16+x*x));
}

int main()
{
	int n;
	float a, b,x0,s,sum1=0;
	float h;
	cout<<"Enter the lower and the upper limit\n";
	cin>>a>>b;
	cout<<"Enter the number of subintervals\n";
	cin>>n;
	h=(b-a)/n;
	
	x0=a+h;
	
	while(x0<b)
	{
		sum1=sum1+f(x0);
		x0=x0+h;
	}
	
	s=(h/2)*(f(a)+f(b)+2*sum1);
	
	cout<<"The integral value is "<<s<<endl;
	
	
}
