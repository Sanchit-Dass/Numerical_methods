#include<bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return (1/(x*x+y*y));
}

int main()
{
    double a,b,c,d,h,k,x0,y0,result,arr[100][100];
    double both_mul_3_interior=0.0, no_mul_3_interior=0.0, Mul_nomul_interior=0.0,edge_mul3=0.0, edge_nomul3=0.0;
    int i,j,n,m;
    cout<<"Enter the lower and the upper limit of x"<<endl;
    cin>>a>>b;
    cout<<"Enter the lower and the upper limit of y"<<endl;
    cin>>c>>d;
    cout<<"Enter the step size of x and y respectively"<<endl;
    cin>>h>>k;
    n=int((b-a)/h);
    m=int((d-c)/k);
    x0=a;
    y0=c;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            arr[i][j]=f(x0,y0);
            y0=y0+k;
        }
            x0=x0+h;
            y0=c;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
        	if(i%3==0 && j%3==0)
        	{
        		both_mul_3_interior+=arr[i][j];
			}
			
			else if(i%3!=0 && j%3!=0)
			{
                no_mul_3_interior+=arr[i][j];
            }
            else
            {
            	Mul_nomul_interior+=arr[i][j];
			}
        }
    }
    
       
    for(i=1;i<n;i++)
    {
    	if(i%3==0)
    	{
    		edge_mul3+=arr[i][0];
    		edge_mul3+=arr[i][m];
		}
		else
		{
			edge_nomul3+=arr[i][0];
			edge_nomul3+=arr[i][m];
		}
     
    }
    
   for(i=1;i<m;i++)
    {
    	if(i%3==0)
    	{
    		edge_mul3+=arr[0][i];
    		edge_mul3+=arr[n][i];
		}
		else
		{
			edge_nomul3+=arr[0][i];
			edge_nomul3+=arr[n][i];
		}
     
    }
 
    
    result=((9.0*h*k)/64.0)*((arr[0][0]+arr[0][m]+arr[n][0]+arr[n][m])+ 2*(edge_mul3) + 3*(edge_nomul3) + 4*(both_mul_3_interior) + 6*(Mul_nomul_interior) + 9*(no_mul_3_interior));
    cout<<"The value of the integral is "<<result;
    return 0;
}
