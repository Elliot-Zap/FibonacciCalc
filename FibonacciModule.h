// Kemuel Maldonado Zapata
// Sept 17 - Sept 18 2017

#ifndef FIBONACCI_MODULE
#define FIBONACCI_MODULE

#include<iostream>
#include<cmath>

using namespace std;

double GoldenRatio = (1+sqrt(5))/2;
double Psi = -1/GoldenRatio;


/*
0 	FibonacciMenu();
1	PrintFibonacci(maxPosition);
2	FibonacciAtPosition(int number)
3	MaxPosibleFibonacci(maxNum)
4	AllSumFibonnaci(MaxNum);
5	EvenSumFibonacci(MaxNum);
6	OddSumFinonacci(MaxNum);	
*/


//1//
void PrintFibonacci(int minPosition,int maxPosition)
{

	
	if(minPosition == maxPosition)
	{
		long long num= pow(GoldenRatio, double(maxPosition))/sqrt(5) + 0.5;
		cout << num << endl; 	
			
	}
	else if(minPosition > maxPosition)
		cout << "Invalid Entry"<<endl;
	else
	{
		long long num= pow(GoldenRatio, double(minPosition))/sqrt(5) + 0.5;
		cout << num << " ";
		return PrintFibonacci(minPosition +1,maxPosition);
	}
		
}

//2//
void FibonacciAtPosition(int position)
{
	//F(n) = floor( phi^n / sqrt(5) + 0.5)
	
	long long num = pow(GoldenRatio, double(position))/sqrt(5) + 0.5;
	
	cout << "F("<< position<<") = "<< num <<endl;
}

//3//
void MaxPossibleFibonacci(int maxNumber)
{
	long long k = ((log(maxNumber + 0.5) + 0.5*log(5))/log(GoldenRatio));
	long long num = pow(GoldenRatio, double(k))/sqrt(5) + 0.5;
	
	
	cout << "Biggest possible number under "<<maxNumber<<" is F("<<k<<") = "<< num <<endl;
}
//4//
void AllSumFibonacci(int maxNumber)
{
	long long k = ((log(maxNumber + 0.5) + 0.5*log(5))/log(GoldenRatio));
	
    unsigned long long sum = ((pow(GoldenRatio,double(k)) * (1+GoldenRatio)) 	+ (-1*pow(GoldenRatio,double(k))*(GoldenRatio - 2)))/( 2*sqrt(5) );
    
    cout << "The  sum of all fibonacci numbers less or equal to "<< maxNumber<<endl
		 << sum <<endl;
}

//5//
void EvenSumFibonacci(int maxNumber)
{
	/* You can find the sum of all even fibonacci numbers by using this closed form expression
	
	F(n) = (Phi^n - Psi^n ) / sqrt(5) 
	
	Phi = Golden Ratio = (1+sqrt(5))/2 ~= 1.61803...
	Psi = -1/Phi
	
	Since in the fibonacci sequence all even numbers are every 3 numbers we can turn it into this:
	F(n) = (Phi^(3n) - Psi^(3n) ) / sqrt(5)
	
	Sum (Phi^(3n) - Psi^(3n) ) / sqrt(5), n = 1 to k 
	
	k = ((log(maxNumber + 0.5) + 0.5*log(5))/log(GoldenRatio))/3
	^- this tells us how many times the loop will run
	
	And since this sum is part of the geometric series it can be "simplified" as such:
	
	sum = 1/(2*sqrt(5)) (phi^3k * (1+(phi)/(1+phi^3) + (-phi)^-3k (phi - 2) 
	
	while a bit long it greatly reduces excecution time vs. running a lot of loops (hopefully...)
	
	*/
	
	

	long long k = ((log(maxNumber + 0.5) + 0.5*log(5))/log(GoldenRatio))/3 ;
    unsigned long long sum = ((pow(GoldenRatio,3.0*k) * (1+GoldenRatio)) 	+ (-1*pow(GoldenRatio, -3.0 * k)*(GoldenRatio - 2)))/( 2*sqrt(5) );
    
    
    cout << "The  sum of all even fibonacci numbers less or equal to "<< maxNumber<<endl
		 << sum <<endl;
    
}

//6//
void OddSumFibonacci(int maxNumber)
{
	//AllSum
	long long Allk = ((log(maxNumber + 0.5) + 0.5*log(5))/log(GoldenRatio));
	unsigned long long allSum = ((pow(GoldenRatio,double(Allk)) * (1+GoldenRatio)) 	+ (-1*pow(GoldenRatio,double(Allk))*(GoldenRatio - 2)))/( 2*sqrt(5) );
    
    //EvenSum
	long long evenk = ((log(maxNumber + 0.5) + 0.5*log(5))/log(GoldenRatio))/3 ;
    unsigned long long evenSum = ((pow(GoldenRatio,3.0*evenk) * (1+GoldenRatio)) 	+ (-1*pow(GoldenRatio, -3.0 * evenk)*(GoldenRatio - 2)))/( 2*sqrt(5));
	
	cout << "The  sum of all odd fibonacci numbers less or equal to "<< maxNumber<<endl
		 << allSum - evenSum <<endl;
	
}

//0//
void FibonacciMenu()
{
	char option;
	do
	{
		cout<<"FIBONACCI FUNCTIONS MENUS"<<endl
			<<"[1] Print Fibonacci Sequence"<<endl
			<<"[2] Find Fibonacci Number at Position"<<endl
			<<"[3] Find Maximum Possible Fibonacci"<<endl
			<<"[4] Sum of all Fibonacci Numbers"<<endl
			<<"[5] Sum of all Even Fibonacci Numbers"<<endl
			<<"[6] Sum of all Odd Fibonacci Numbers"<<endl
			<<"[0] Return to Main Menu"<<endl;
			
		cin >> option;
		
		switch(option)
		{
			int endPos;
			int maxNum;
			
			case '1': // Print
				
				
				cout << "By how many numbers would you like your sequence to have?"<<endl; 
				cin >> endPos;
				
				PrintFibonacci(1,endPos);				
				
				break;
			
			case '2': //F(N)
				
				cout << "Insert Position of Fibonacci Number : ";
				cin >> endPos;
				
				FibonacciAtPosition(endPos);
				break;
			
			case '3'://MaxFib
				
				cout << "Insert a number please"<<endl;
				cin >> maxNum;
				
				MaxPossibleFibonacci(maxNum);
				break;
			
			case '4'://FibSum
				
				cout << "Insert a number please"<<endl;
				cin >> maxNum;
				
				AllSumFibonacci(maxNum);
				break;
			
			case '5'://EvenFibSum
				cout << "Insert a number please"<<endl;
				cin >> maxNum;
				
				EvenSumFibonacci(maxNum);
				break;
			
			case '6'://OddFibSum
				cout << "Insert a number please"<<endl;
				cin >> maxNum;
				
				OddSumFibonacci(maxNum);
				break;
			
			case '0':
				break;
			
			default:
				cout << "Invalid Option" <<endl;
		}
		
		cout <<endl<<endl;
		
	}while(option != '0');
}




#endif
