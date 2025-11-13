#include<bits/stdc++.h>
using namespace std;

float f(float x)
{
	return (1/(16+x*x));
}
int main()
{
	int n,i;
	float sum_3, sum_rest,result,a,b,h,x0;
	cout<<"Enter the upper limit"<<endl;
	cin>>b;
	cout<<"Enter the lower limit"<<endl;
	cin>>a;
	cout<<"Enter the number of intervals"<<endl;
	cin>>n;
	sum_3=0;
	sum_rest=0;
	h=(b-a)/n;
	x0=a+h;
	for(i=1;i<n;i++)
	{
		if(i%3==0)
		sum_3=sum_3+f(x0);
		
		else
		sum_rest=sum_rest+f(x0);
		
		x0=x0+h;
		
    }
		

	
	result=(3.0*h/8.0)*(f(a)+f(b)+2*sum_3+3*sum_rest);
	cout<<result;
	
}
