#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;
class Rides
{
	public:
		int total;
	Rides()
	{	
	}
	Rides(const Rides &r)
	{
		this->total=r.total;	
	}
	void RollerCoaster()
	{
		int qty;
	    int t1=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t1=qty*200;
		cout<<"\n\nPOPCORNS TOTAL: Rs."<<t1;
		total=total+t1;
	}
	void BungeeJumping()
	{
		int qty;
	    int t2=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t2=qty*180;
		cout<<"\n\nBungee Jumping TOTAL: Rs."<<t2;
		total=total+t2;	
	}
	void HauntedHouse()
	{
		int qty;
	    int t3=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t3=qty*150;
		cout<<"\n\nHaunted House TOTAL: Rs."<<t3;
		total=total+t3;	
	}
	void JungleCruise(); 
	void arcadeGaming()
	{
		int qty;
	    int t5=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t5=qty*100;
		cout<<"\n\nArcade Games TOTAL: Rs."<<t5;
		total=total+t5;	
	}
	void Vortex()
	{
		int qty;
	    int t6=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t6=qty*200;
		cout<<"\n\nVortex TOTAL: Rs."<<t6;
		total=total+t6;	
	}		
	void SlingShot()
	{
		int qty;
	    int t7=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t7=qty*350;
		cout<<"\n\nBouncy Balls TOTAL: Rs."<<t7;
		total=total+t7;
	}
	void FerrisWheel()
	{
		int qty;
	    int t8=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t8=qty*500;
		cout<<"\n\nBouncy Balls TOTAL: Rs."<<t8;
		total=total+t8;	
	}
	void BouncyBalls()
	{
		int qty;
	    int t9=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t9=qty*230;
		cout<<"\n\nBouncy Balls TOTAL: Rs."<<t9;
		total=total+t9;
	}
	void Monorail()
	{
		int qty;
	    int t10=0;
		cout<<"\nEnter no.of tickets you want: ";
		cin>>qty;
		t10=qty*230;
		cout<<"\n\nMonorail TOTAL: Rs."<<t10;
		total=total+t10;	
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
	void operator=(int a)			//OPERATOR OVERLOADING
	{
		total=0;
	}
};
void Rides::JungleCruise() 
{
	int qty;
    int t4=0;
	cout<<"\nEnter no.of tickets you want: ";
	cin>>qty;
	t4=qty*170;
	cout<<"\n\nJungle Cruise TOTAL: Rs."<<t4;
	total=total+t4;	
}
void ride()
{
		Rides r1;
		Rides r2(r1);
		Rides r3=r1;
		r1=0;				//OPERATOR OVERLOADING
	int choice, no, i, snack[10], rides[10];
	cout<<"\t\t***RIDES***";
	cout<<"\n\n01) Roller Coaster.............. Rs.200/_\n02) Haunted House............... Rs.150/_\n03) Bungee Jumping.............. Rs.180/_";
	cout<<"\n04) Ferris Wheel................ Rs.500/_\n05) Bouncy Balls................ Rs.230/_\n06) Vortex...................... Rs.200/_\n07) Monorail.................... Rs.230/_";
	cout<<"\n08) Sling shot.................. Rs.350/_\n09) Jungle Cruise............... Rs.170/_\n10) Arcade Gaming............... Rs.100/_";
	cout<<"\n\nHow many rides would you like to take?";
	cin>>no;
	cout<<"\nEnter the code of rides you would like..\n";
	for(i=0;i<no;i++)
	{
		cout<<"\n\nRIDE "<<i+1<<": ";
		cin>>rides[i];
		if(rides[i]==1)
		{
			r1.RollerCoaster();
		}
		else if(rides[i]==2)
		{
			r1.HauntedHouse();
		}
		else if(rides[i]==3)
		{
			r1.BungeeJumping();
		}
		else if(rides[i]==4)
		{
			r1.FerrisWheel();
		}
		else if(rides[i]==5)
		{
			r1.BouncyBalls();
		}
		else if(rides[i]==6)
		{
			r1.Vortex();
		}
		else if(rides[i]==7)
		{
			r1.Monorail();
		}
		else if(rides[i]==8)
		{
			r1.SlingShot();
		}
		else if(rides[i]==9)
		{
			r1.JungleCruise();
		}
		else if(rides[i]==10)
		{
			r1.arcadeGaming();
		}
	}
	r1.get_Total_Bill();
}
