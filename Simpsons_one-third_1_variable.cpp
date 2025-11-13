#include<bits/stdc++.h>
using namespace std;

float f(float x)
{
	return (1/(16+x*x));
}
int main()
{
	int n,i;
	float sum_even, sum_odd,result,a,b,h,x0;
	cout<<"Enter the upper limit"<<endl;
	cin>>b;
	cout<<"Enter the lower limit"<<endl;
	cin>>a;
	cout<<"Enter the number of intervals"<<endl;
	cin>>n;
	sum_odd=0;
	sum_even=0;
	h=(b-a)/n;
	x0=a+h;
	for(i=1;i<n;i++)
	{
		if(i%2==0)
		sum_even=sum_even+f(x0);
		
		else
		sum_odd=sum_odd+f(x0);
		
		x0=x0+h;
		
    }
		

	
	result=(h/3.0)*(f(a)+f(b)+2*sum_even+4*sum_odd);
	cout<<result;
	
}
