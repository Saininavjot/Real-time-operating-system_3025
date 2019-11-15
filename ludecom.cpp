#include<iostream>
using namespace std;
int main() // main function
{
    int n,i,k,j,p; // declaration of variables
    float a[10][10],l[10][10]={0},u[10][10]={0},sum,b[10],y[10]={0},x[10]={0}; // matrices are declared
    cout<<"Enter the order of matrix A! "; //print on console window
    cin>>n; // input order of matrix
    cout<<"Enter all coefficients of matrix : A"; // a matrix coefficient are entered
    for(i=1;i<=n;i++)
    {
        cout<<"\nRow "<<i<<"  "; // number of rows
        for(j=1;j<=n;j++)
            cin>>a[i][j]; // coefficient of rows
    }
    cout<<"Enter elements of b matrix"<<endl;
    for(i=1;i<=n;i++)
        cin>>b[i]; //input coefficient of b matrix
    //********** LU decomposition *****//
    for(k=1;k<=n;k++)
    {
        u[k][k]=1;
        for(i=k;i<=n;i++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[i][p]*u[p][k]; // sum is performed to get lower matrix
            l[i][k]=a[i][k]-sum;
        }

        for(j=k+1;j<=n;j++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[k][p]*u[p][j];
            u[k][j]=(a[k][j]-sum)/l[k][k]; // upper matrix
        }
    }
    //******** Displaying LU matrix**********//
    cout<<endl<<endl<<"Lower matrix is "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<l[i][j]<<"  "; //lower matrix is displayed
        cout<<endl;
    }
    cout<<endl;
    cout<<endl<<endl<<"Upper matrix is "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<u[i][j]<<"  "; // upper matrix is displayed
        cout<<endl;
    }

    //***** FINDING y; Ly=b*********//

    for(i=1;i<=n;i++)
    {                      //forward substitution method
        sum=0;
        for(p=1;p<i;p++)
        sum+=l[i][p]*y[p];
        y[i]=(b[i]-sum)/l[i][i]; // lower  matrix is used to calculate y
    }

    //********** FINDING X; UX=y***********//

    for(i=n;i>0;i--)
    {
        sum=0;
        for(p=n;p>i;p--)
            sum+=u[i][p]*x[p];
        x[i]=(y[i]-sum)/u[i][i]; // upper matrix is used to calculate x
    }
    //*********** DISPLAYING SOLUTION**************//
    cout<<endl<<"Values of x"<<endl; //
    for(i=1;i<=n;i++)
        cout<<endl<<x[i]; // displaying values of x
    return 0;
}
