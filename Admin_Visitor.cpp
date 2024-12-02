#include<iostream>
#include<ctime>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include"Liveshows.cpp"
#include"snack bar.cpp"
#include"Rides.cpp"
using namespace std;
class Wonderland
{
	protected:
		static long int serial_n;
};
class fun_zone
{
	LiveShows ls;		//FRIEND CLASS
	public:
		inline void frnd_class()
		{
			ls.total;	//which is private member of LiveShows
		}
		static void zone()			//STATIC FUNCTION
		{
			int z1;
			int z2=0;
			while(z2==0)
			{
				system("cls");
				cout<<"\t\tWELCOME TO FUNZONE\n\n";
				cout<<"1. Live Shows.\n2. Snack Bar.\n3. Rides.\n4. Back.\n\tEnter : ";
				cin>>z1;
				switch(z1)
				{
					case 1:
					{
						system("cls");
						show();
						getch();
					}
					break;
					case 2:
					{
						system("cls");
						snack();
						getch();
					}
					break;
					case 3:
					{
						system("cls");
						ride();
						getch();
					}
					break;
					case 4:
					{
						z2=1;
					}
					break;
					default:
					{
						cout<<"\nWrong Input!! Try again.";
						getch();
					}
					break;
				}
								
			}
			
		}
};
class Visitors : virtual protected Wonderland
{
	protected:
		string name;
		string city;
		int age;
	public:
		inline void set_name(string n)
		{
			name=n;
		}
		inline void set_city(string c)
		{
			city=c;
		}
		template<typename T>		//TEMPLATES
		inline void set_age(T a)
		{
			age=static_cast<int>(a); //Casting
		}
		void set_serial()
		{
			long int s;
			ifstream r_sn;
			r_sn.open("serialno.txt",  ios::in);
			if(!r_sn)
			{
				s=0;	
			}
			else
			{
				r_sn>>s;
				s=s+1;
			}
			serial_n=s;
			r_sn.close();
			ofstream w_sn;
			w_sn.open("serialno.txt",  ios::out);
			w_sn<<s<<endl;
			w_sn.close();
		}
		inline int get_age()
		{
			return age;
		}
		inline string get_name()
		{
			return name;
		}
		inline string get_city()
		{
			return city;
		}
		inline long int get_serial()
		{
			return serial_n;
		}
		inline long int get_serial(long int s)
		{
			s=serial_n;
			return s;
		}
		void set_details()
		{
			int a;
			string n, c;
			cout<<"\n\tVISITOR'S DETAIL\n";
			cout<<"Enter Visitor's Name : ";
			getline(cin, n);
			fflush(stdin);
			set_name(n);
			cout<<"Enter Visitor's age : ";
			cin>>a;
			fflush(stdin);
			set_age(a);
			cout<<"Enter Visitor's City : ";
			getline(cin, c);
			fflush(stdin);
			set_city(c);
			set_serial();
			
			
   			time_t now = time(0);
   			char* dt = ctime(&now);
			ofstream d;
			d.open("VisitorData.txt", ios::app);
			d<<get_serial()<<endl;
			d<<dt;
			d<<get_name()<<endl;
			d<<get_age()<<endl;
			d<<get_city()<<endl;
			d.close();
		}
		inline void del()
		{
			remove("VisitorData.txt");
		}
		
		inline int delinc()
		{
			remove("total.txt");
		}		
		inline void deltick();	//OVERRIDING
		inline virtual void display()=0;	//PURE ABSTRACT 
};
class Finance : virtual protected Wonderland
{
	protected:
		static double total;
	public:
		
		void tot()
		{
			double temp;
			ifstream t;
			t.open("total.txt", ios::in);
			if(!t)
			{
				temp=0;
			}
			else
			{
				t>>temp;
			}
			t.close();
			
			ofstream ot;
			ot.open("total.txt", ios::out);
			temp=total+temp;
			ot<<temp;
		}
		void admintot()
		{
			double temp;
			ifstream t;
			t.open("total.txt", ios::in);
			if(!t)
			{
				temp=0;
			}
			else
			{
				t>>temp;
			}
			t.close();
			cout<<"Total Income  : "<<temp;
		}
		~Finance()
		{
		}
};
double Finance::total=0;
long int Wonderland::serial_n=0;
class Calculation : public Visitors, public Finance
{
	protected:
		double cal;
		const double discount;
		const double price;
	public:
		Calculation() : discount(.1), price(100)
		{
		}
		void calculation()		
		{
			cout<<"\n\nTicket Price is 100 Rs.\nFree for less than 5 yrs old.";
			if(Visitors::get_age()<=4)
			{
				cal=0;
			}
			else if(Visitors::get_city()=="karachi"||Visitors::get_city()=="KARACHI"||Visitors::get_city()=="Karachi")
			{
				cal=price-(price*discount);
				cout<<"\n10% discount for Karachities!!!";
			}
			else
			{
				cal=price;
			}
			Finance::total=cal;
			cout<<"\nEntry Charges : "<<cal;
			Finance::tot();
		}
		inline virtual void view_visitor()		//VIRTUAL FUNCTION
		{
			cout<<"\n\nView Visitor\n\n";
		}
		int req_serial()
		{
			int k1, i;
			long int sn2, sn;
			char t_d[100];
			char n[100];
			char c[100];
			int a;
			ifstream vd;
			vd.open("VisitorData.txt", ios::in);
			if(vd)
			{
			cout<<"\nEnter Ticket No : ";
			cin>>sn;
			fflush(stdin);
			k1=0;
			while(k1==0)
			{
				vd>>sn2;
				vd.ignore();	
				vd.getline(t_d,100);
				vd.getline(n,100);
				vd>>a;
				vd.ignore();
				vd.getline(c,100);
				k1=vd.eof();
				if(sn==sn2)
				{
					break;
				}
					
			}
			if(sn2==sn)
			{
				system("cls");
				cout<<"\t\tVISITOR'S DATA\n";
				cout<<"\nTicket No     : "<<sn2;
				cout<<"\nDate and Time : ";
				for(i=0;i<100;i++)
				{	
					if(t_d[i]=='\0')
					{
						break;
					}
					cout<<t_d[i];
				}
				cout<<"\nName          : ";
				for(i=0;i<100;i++)
				{
					if(n[i]=='\0')
					{
						break;
					}
					cout<<n[i];
				}
				cout<<"\nAge           : "<<a;
				cout<<"\nCity          : ";
				for(i=0;i<100;i++)
				{
					if(c[i]=='\0')
					{
						break;
					}
					cout<<c[i];
				}
				cout<<"\n";
				vd.close();
				return 1;
			}
			else if(sn2!=sn)
			{
				system("cls");
				cout<<"\nNot Found";
				vd.close();
				return 0;
			}	
			}
			else
			{
				cout<<"Data Not Found.";
				vd.close();
				return 0;
			}
		}
		~Calculation()
		{
		}
			
};
class Admin : public Calculation
{
	private:
		
	public:
		void view_visitor()
		{
			system("cls");
			long int sn2, sn;
			int i, j, k1;
			char t_d[100];
			char n[100];
			char c[100];
			int a;
			
			cout<<"\t\tVisitor's Record\n\nPRESS 1 : To find details of particular visitor.";
			cout<<"\nPRESS 2 : To find the details of all Visitors.\n";
			j=0;
			while(j==0)
			{
				cout<<"\tENTER (1 or 2): ";
				cin>>i;
				fflush(stdin);
				if(i==1)
				{
					j=1;
					system("cls");
					req_serial();
				}
				else if(i==2)
				{
					j=1;	
					system("cls");
					ifstream vd2;
					vd2.open("VisitorData.txt", ios::in);
					if(vd2)
					{
					k1=0;
					cout<<"\t\tVISITOR'S DATA\n";
					while(1)
					{
						vd2>>sn2;
						vd2.ignore();
						vd2.getline(t_d,100);
						vd2.getline(n,100);
						vd2>>a;
						vd2.ignore();
						vd2.getline(c,100);
						k1=vd2.eof();
						if(k1==1)
						{
							break;
						}
						cout<<"\nTicket No     : "<<sn2;
						cout<<"\nDate and Time : ";
						for(i=0;i<100;i++)
						{
							if(t_d[i]=='\0')
							{
								break;
							}
							cout<<t_d[i];
						}
						cout<<"\nName          : ";
						for(i=0;i<100;i++)
						{
							if(n[i]=='\0')
							{
								break;
							}
							cout<<n[i];
						}
						cout<<"\nAge           : "<<a;
						cout<<"\nCity          : ";
						for(i=0;i<100;i++)
						{
							if(c[i]=='\0')
							{
								break;
							}
							cout<<c[i];
						}
						cout<<"\n";
					}
					
					vd2.close();
					}
					else
					{
						cout<<"\n Data Not Found.";
						vd2.close();
					}
					
				}
				else
				{
					j=0;
					cout<<"Wrong Input. Please try again.\n";
				}
			}
		}
		inline void deltick()
		{
			remove("serialno.txt");
		}
		void display()
		{
			cout<<"\n\tDISPLAY VISITOR'S DETAIL";
			cout<<"\nTicket no     : "<<get_serial();
			cout<<"\nName          : "<<get_name();
			cout<<"\nAge           : "<<get_age();
			cout<<"\nCity          : "<<get_city();
		}
		inline int req_serial()
		{
			Calculation::req_serial();		//OVERRIDING
		}
		
};
int admin_visitor()
{
	int c1, c2, c3, c4, choice;
	system("color 70");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\tAMUSEMENT PARK MANAGEMENT SYSTEM";
	getch();
	fun_zone z;
	Admin c;
	Calculation *ptr;	//LATE BINDING
	ptr=&c;				//UPCASTING
	Admin *ptr2;
	ptr2=(Admin*)(ptr);		//DOWNCASTING
	
	while(1)
	{
		system("cls");
		cout<<"\t\tWELCOME TO PORTAL\n\n";
		cout<<"1. Visitor\n2. Admin \n3. Exit\n\n	Select : ";
		c1=0;
		while(c1==0)
		{
		cin>>choice;
		fflush(stdin);
		switch(choice)
		{
			case 1:
			{	
				c3=0;
				c1=1;
				while(c3==0)
				{
					system("cls");
					cout<<"\t\tVISITORS\n\n";
					cout<<"1. To Enter WonderLand.\n2. FunZone.\n3. Back\n\t Enter : ";
					cin>>c2;
					fflush(stdin);
					switch(c2)
					{
						case 1:
						{
							system("cls");
							c.set_details();
							c.display();
							c.calculation();
							getch();
						}
						break;
						case 2:
						{
							system("cls");
							cout<<"\t\tFUNZONE\n\n";
							c4=c.req_serial();
							if(c4==0)
							{
								cout<<"\nPlease Enter WonderLand first.";
								getch();
							}
							else
							{
								fun_zone::zone();
							}
						}
						break;
						case 3:
						{
							c3=1;
						}
						break;
						default:
						{
							cout<<"\n\tWrong Input!! Try again.";
							getch();
						}
						break;
					
					}
				}
			}
			break;
			case 2:	//to view admin
			{
				string a,b;
				a="ooplab123";
				cout<<"\t\tEnter password :\n";
				cin>>b;
				if (a==b)
				{
				c3=0;
				c1=1;
				while(c3==0)
				{
					system("cls");
					cout<<"\t\tADMIN\n\n";
					cout<<"1. View Visitor Details.\n2. View Total Income.\n3. Delete all Visitor Details.\n";
					cout<<"4. Delete Income Details.";
					cout<<"\n5. Delete Ticket Number, Visitor & Income Details\n6. Back\n\t Enter : ";
					cin>>c2;
					fflush(stdin);
					switch(c2)
					{
						case 1:
						{
							system("cls");
							ptr2->view_visitor();
							getch();
						}
						break;
						case 2:
						{
							system("cls");
							c.admintot();
							getch();
						}
						break;
						case 3:
						{
							system("cls");
							c.del();
							cout<<"Visitor Details deleted successfully.";
							getch();
						}
						break;
						case 4:
						{
							system("cls");
							c.delinc();
							cout<<"Income Details deleted successfully.";
							getch();
						}
						break;
						case 5:
						{
							system("cls");
							c.del();
							c.delinc();
							c.deltick();
							cout<<"Visitor & Income Details deleted successfully.";
							cout<<"\nTicket Number cleared successfully.";
							getch();
						}
						break;
						case 6:
						{
							c3=1;
						}
						break;
						default:
						{
							cout<<"\n\tWrong Input!! Try again.";
							getch();
						}
						break;
					
					}
				}
			}
			else {
				cout<<"\twrong password\t\tSECURITY ALERTED\n"; 
			}
		}
			
			break;
			case 3:
			{
				system("cls");
				cout<<"\nTHANKS FOR COMING!!";
				getch();
				return 0;
			}
			break;
			default:
			{
				try				//EXCEPTION HANDLING
				{
					if(choice>0&&choice<4)
					{
					}
					else
					{
						throw choice;
					}
				}
				catch(int choice)
				{
					c1=0;
					cout<<"Wrong Input! Enter again : ";
				}
			}
			break;
		
		}
	}
	
	cout<<endl<<endl;
	system("pause");
	return 0;
}}
