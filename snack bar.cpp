#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;
class Snackbar
{
	static int total;
	public:
		string item;
		int choice;
		int t2,t3,t4,t5,t6,t7,t8,t9,t10;
	Snackbar()
	{
	}
	static void popcorn()
	{
		int t1;
		int qt;
	    t1=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t1=qt*20;
		cout<<"\n\nPOPCORNS TOTAL: Rs."<<t1;
		total=total+t1;
	}
	void icecream()
	{
		int qt; 
		t2=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t2=qt*80;
		cout<<"\n\nICE-CREAM TOTAL: Rs."<<t2;
		total=total+t2;
	}
	void beverage()
	{
		char choice;
		cout<<"BEVERAGES INCLUDE: \n\na) Tea.\nb) Coffee.\nc)Cold drink.";
		cout<<"\n\nEnter the code of beverage you would like..\n";
		cin>>choice;
		int qt; 
		t3=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t3=qt*40;
		cout<<"\n\nBEVERAGE TOTAL: Rs."<<t3;
		total=total+t3;
	}
	void golgappay()
	{
		int qt; 
		t4=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t4=qt*70;
		cout<<"\n\nGOL GAPPAY TOTAL: Rs."<<t4;
		total=total+t4;
	}
	void chaat()
	{
		int qt; 
		t5=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t5=qt*70;
		cout<<"\n\nCHAAT TOTAL: Rs."<<t5;
		total=total+t5;
	}
	void pizzafries()
	{
		int qt; 
		t6=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t6=qt*120;
		cout<<"\n\nPIZZA FRIES TOTAL: Rs."<<t6;
		total=total+t6;
	}
	void burger()
	{
		int qt;
		t7=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t7=qt*190;
		cout<<"\n\nBURGERS TOTAL: Rs."<<t7;
		total=total+t7;
	}
	void wraps()
	{
		int qt; 
		t8=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t8=qt*170;
		cout<<"\n\nCHICKEN WRAPS TOTAL: Rs."<<t8;
		total=total+t8;
	}
	void fishchips()
	{
		int qt;
		t9=0;
		cout<<"\nEnter quantity: ";
		cin>>qt;
		t9=qt*200;
		cout<<"\n\nFISH AND CHIPS TOTAL: Rs."<<t9;
		total=total+t9;
	}
	void cupcake()
	{
		int *qt;
		qt=new int;		//NEW 
		t10=0;
		cout<<"\nEnter quantity: ";
		cin>>*qt;
		t10=(*qt)*90;
		cout<<"\n\nCUPCAKE TOTAL: Rs."<<t10;
		total=total+t10;
		delete qt;		//DELETE
	}
	void get_Total_Bill()
	{
			int temp;
			ifstream t1;
			t1.open("total.txt", ios::in);
			if(!t1)
			{
				temp=0;
			}
			else
			{
				t1>>temp;
			}
			t1.close();
			
			ofstream ot1;
			ot1.open("total.txt", ios::out);
			temp=total+temp;
			ot1<<temp;
			ot1.close();
		cout<<"\n\nTOTAL BILL: Rs."<<total;
	}
};
int Snackbar::total=0;
void snack()
{
	Snackbar s1;
	int choice, no, i, snack[10];
	system("color 70");
	cout<<"\t\t***SNACK BAR***\n\n01) Popcorn................ Rs.20/_\n02) Beverages.............. Rs.40/_\n03) Ice-cream.............. Rs.80/_";
	cout<<"\n04) Gol Gappay............. Rs.70/_\n05) Chana Chaat............ Rs.70/_\n06) Pizza Fries............ Rs.120/_\n07) Burger................. Rs.190/_";
	cout<<"\n08) Fish and Chips......... Rs.200/_\n09) Chicken Wraps.......... Rs.170/_\n10) Cupcakes............... Rs.90/_";
	cout<<"\n\nHow many items would you like to have?";
	cin>>no;
	cout<<"\nEnter the code of items you would like..\n";
	for(i=0;i<no;i++)
	{
		cout<<"\n\nITEM "<<i+1<<": ";
		cin>>snack[i];
		if(snack[i]==1)
		{
			s1.popcorn();
		}
		else if(snack[i]==2)
		{
			s1.beverage();
		}
		else if(snack[i]==3)
		{
			s1.icecream();
		}
		else if(snack[i]==4)
		{
			s1.golgappay();
		}
		else if(snack[i]==5)
		{
			s1.chaat();
		}
		else if(snack[i]==6)
		{
			s1.pizzafries();
		}
		else if(snack[i]==7)
		{
			s1.burger();
		}
		else if(snack[i]==8)
		{
			s1.fishchips();
		}
		else if(snack[i]==9)
		{
			s1.wraps();
		}
		else if(snack[i]==10)
		{
			s1.cupcake();
		}
	}
	s1.get_Total_Bill();
	
}
