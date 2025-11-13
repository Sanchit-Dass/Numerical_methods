#include<bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return (x+y);
}

int main()
{
    double a,b,c,d,h,k,x0,y0,result,arr[100][100];
    double interior=0.0,edge_sum=0.0;
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
                interior=interior+arr[i][j];
        }
    }
    
       
    for(i=1;i<n;i++)
    {
     edge_sum+= arr[i][0];
    }
    
    for(i=1;i<n;i++)
    {
     edge_sum+= arr[i][m];
    }
    
  
    
    for(j=1;j<m;j++)
    {
     edge_sum+= arr[0][j];
    }
    
    for(j=1;j<m;j++)
    {
     edge_sum+= arr[n][j];
    }

 
    
    result=((h*k)/4.0)*((arr[0][0]+arr[0][m]+arr[n][0]+arr[n][m])+ 4*interior+2*edge_sum);
    
    cout<<"The value of the integral is "<<result;
    return 0;
}
