#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;
class LiveShows
{
	friend class fun_zone;	//FRIEND CLASS
	private:
		int total;
	public:
	LiveShows()
	{
		total=0;	
	}
	LiveShows(int n) : total(n)
	{
	}
	void Doctor_Strange()
	{
		total=750;
		get_total();
		cout<<"\nTOTAL AMOUNT: Rs."<<total;	
	}
	void Batman()
	{
		total=750;
		get_total();
		cout<<"\nTOTAL AMOUNT: Rs."<<total;	
	}
	void Spiderman()
	{
		total=750;
		get_total();
		cout<<"\nTOTAL AMOUNT: Rs."<<total;	
	}
	void Lionking()
	{
		total=550;
		get_total();
		cout<<"\nTOTAL AMOUNT: Rs."<<total;	
	}
	void Cinderella()
	{
		total=550;
		get_total();
		cout<<"\nTOTAL AMOUNT: Rs."<<total;	
	}
	friend void aladdin(LiveShows obj);
			
	void get_total()
	{	int temp;
		ifstream t3;
		t3.open("total.txt", ios::in);
		if(!t3)
		{
			temp=0;
		}
		else
		{
			t3>>temp;
		}
		t3.close();
		ofstream ot3;
		ot3.open("total.txt", ios::out);
		temp=total+temp;
		ot3<<temp;
		ot3.close();
	}
};
void aladdin(LiveShows l1)
	{
		l1.total=550;
		l1.get_total();
		cout<<"\nTOTAL AMOUNT: Rs."<<l1.total;	
}
void show()
{
	LiveShows l1(0);
	const LiveShows l2;
	char ch;
	int c;
	cout<<"\t\t***LIVE SHOWS***\n\nWhich one would you like to watch?\n\n 1.....Family shows.\n 2.....Children shows.";
	cin>>c;
	switch(c)
	{
		case 1:
			{
				cout<<"\n->FAMILY SHOWS(Rs. 750 each): \n\t\t\t     a)Doctor Strange.\n\t\t\t     b)Batman.";
				cout<<"\n\t\t\t     c)Spiderman.";
				cout<<"\n\nEnter the code of show you would like..\n";
				cin>>ch;
				if(ch=='a')
				{
					l1.Doctor_Strange();
				}
				else if(ch=='b')
				{
					l1.Batman();
				}
				else if(ch=='c')
				{
					l1.Spiderman();
				}
				break;
			}
		case 2:
		{
			cout<<"\n->CHILDREN SHOWS(Rs. 550 each): \n\t\t\t     a)Lion King.\n\t\t\t     b)Cindrella.";
			cout<<"\n\t\t\t     c)Aladdin.";
			cout<<"\n\nEnter the code of show you would like..\n";
			cin>>ch;
			if(ch=='a')
			{
				l1.Lionking();
			}
			else if(ch=='b')
			{
				l1.Cinderella();
			}
			else if(ch=='c')
			{
				aladdin(l1);
			}	
			break;
		}
			
	}		
}
