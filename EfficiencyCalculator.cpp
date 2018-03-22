// Kemuel Maldonado Zapata
// Sept 17 - Sept 2017

#include<iostream>
#include "FibonacciModule.h"

void MainMenu();

int main ()
{

	MainMenu();
	
	return 0;
}

void MainMenu()
{
	char option;
	do
	{
		cout<<"MAIN MENU"<<endl
			<<"[1] FIBONACCI FUNCTIONS" <<endl
			<<"[0] EXIT"<<endl;
		cin >> option;
		switch(option)
		{
			case '1':
				FibonacciMenu();
				break;
			
			case '0':
				break;
			
			default:
				cout << "Invalid Option" <<endl;		
		}
		
		cout <<endl<<endl;
		
	}while(option != '0');
}
