#include<bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return (x+y);
}

int main()
{
    double a,b,c,d,h,k,x0,y0,result,arr[100][100];
    double odd_odd_interior=0.0, odd_even_interior=0.0, even_even_interior=0.0,edge_odd=0.0, edge_even=0.0;
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
        	if(i%2!=0 && j%2!=0)
        	{
        		odd_odd_interior+=arr[i][j];
			}
			
			else if(i%2==0 && j%2==0)
			{
                even_even_interior+=arr[i][j];
            }
            else
            {
            	odd_even_interior+=arr[i][j];
			}
        }
    }
    
       
    for(i=1;i<n;i++)
    {
    	if(i%2==0)
    	{
    		edge_even+=arr[i][0];
    		edge_even+=arr[i][m];
		}
		else
		{
			edge_odd+=arr[i][0];
			edge_odd+=arr[i][m];
		}
     
    }
    
   for(i=1;i<m;i++)
    {
    	if(i%2==0)
    	{
    		edge_even+=arr[0][i];
    		edge_even+=arr[n][i];
		}
		else
		{
			edge_odd+=arr[0][i];
			edge_odd+=arr[n][i];
		}
     
    }
 
    
    result=((h*k)/9.0)*((arr[0][0]+arr[0][m]+arr[n][0]+arr[n][m])+ 4*(edge_odd) + 2*(edge_even) + 16*(odd_odd_interior) + 8*(odd_even_interior) + 4*(even_even_interior));
    cout<<"The value of the integral is "<<result;
    return 0;
}
