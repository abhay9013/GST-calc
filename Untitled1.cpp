#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class item{
	private:
	int icode;
	char iname[20];
	float iprice;
	public:
	int number()
	{
		return icode;
	}
	char name()
	{
		cout<<iname;
	}
	float gst()
	{
		return iprice;
	}
};
int main()
{
	item m;
	char ch[20],ch1='y';
	fstream fil;
	float ctotal=0,stotal=0,total=0,grandtotal=0,a,c,t;
	int p;
	cout<<"Please Verify Your Authenticity.\n";
	cout<<"\nEnter Your Password:-\t";
	cin.get(ch,20);
	if(strcmp(ch,"12345")==0)
	{
	cout<<"\nWelcome To The New Era Of Tax In INDIA :) \n\n";
	cout<<"   *Goods And Services Tax(G.S.T.)*\n\n";
	do
	{
		cout<<"\n\nEnter Item Code:- \t";
		cin>>p;
		fil.open("cgst.txt",ios::in);
		/*CGST:-Central Government Goods & Service Tax.
		Collected by the Central Government on an intra-state sale.
		(Eg: transaction happening within Maharashtra).*/
		while(fil.read((char*)&m,sizeof(m)))
		{
			if(m.number()==p)
				{
					cout<<"\n\nEnter The Actual Price Of :-\t";
					m.name();
					cout<<":-\t";
					cin>>t;
					c=m.gst();
					a=(c*t)/100;
					ctotal+=a;
					break;
				}
		}
		if(m.number()!=p)
		{
			cout<<"\n\n!! Item Not Found :( !!\n";
			fil.close();
			continue;
		}
		fil.close();
		fil.open("sgst.txt",ios::in);
		/*SGST:-State Government Goods & Service Tax.
		Collected by the State Government on an intra-state sale.
		(Eg: transaction happening within Maharashtra).*/
		while(fil.read((char*)&m,sizeof(m)))
		{
			if(m.number()==p)
			{
				c=m.gst();
				a=(c*t)/100;
				stotal+=a;
			}
		}
		fil.close();
		total+=t;
		cout<<"\n\nProduct Is Added To Your List.";
		cout<<"\n\n\nWant To Add More Product In Your List.";
		cout<<"\n\n\nPress Y; Otherwise Press Any Key To Quit:-\t";
		cin>>ch1;
	}while(ch1=='y'|ch1=='Y');
	grandtotal=total+ctotal+stotal;
	cout<<"\n\nTotal Charged Amount On Product(s):-   "<<total;
	cout<<"\n\nTax Paid Tto Central Government:-    "<<ctotal;
	cout<<"\n\nTax Paid To State Government:-    "<<stotal;
	cout<<"\n\nTotal Payable Amount Of Your Bill:-   "<<grandtotal;
	cout<<"\n\nThank You :)  !!  :)  Please Visit Again  :)\n\n\n";
	}
	else
	{
		cout<<"\nPlease Enter A Valid One.";
	}
	return 0;
}

