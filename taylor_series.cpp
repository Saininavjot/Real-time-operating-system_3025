/*
 * taylor_series.cpp
 *
 *  Created on: Sep 23, 2019
 *      Author: User
 */
#include <iostream> //header file to include input & output stream
#include <math.h> //math header file from library is included
using namespace std; //using standard library namespace
int main() // main function
{
float x = 10, sum = 1, term = 1, temp = 0; //float type variables are declared and initialized
int i = 0; // int type i is declared and initialized to 0
while (temp != sum) // while loop to check temp is not equal to sum and if true then execute loop
{
i++;  // increment i by 1
term = term * x / i; // calculate sum terms of taylor's series
temp = sum; //temp is initialized with sum value
sum = sum + term; // all terms in taylor series are added
cout<< "Term number:"<<i <<endl; // display number of terms in series is i
cout<< "value of "<<i<<" sum term:"<<term<<endl; //display terms of taylor series
cout<< "Sum of taylor series with "<<i<<" terms is:"<<sum<<endl; //display sum of series
}
cout<<"exact value = "<< exp((double)x); //display exact value
return 0; // return 0 to exit
} // end of main function

/*Mathematices of embedded system*/
//code for taylors series
