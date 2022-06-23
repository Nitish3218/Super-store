#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
using namespace std;
class super
{
	public:
		string i_no,i_name,i_date;
		float i_price,i_quantity,i_tax,i_dis,i_net;
		int menu=1;
		int control_panel();
		int bill_report();
		int Edit();
		int show_details();
};
super::control_panel()
{
	system("cls");
	cout<<"\t\t\t Super Market Billing\n\t\t\t=======================\n\n\n";
	cout<<"\t\t\t1.Bill Report\n\n";
	cout<<"\t\t\t2.Add/Remove/Edit Item\n\n";
	cout<<"\t\t\t3.Show Item Details\n\n";
	cout<<"\t\t\t4.Exit\n\n";
	
}
super::bill_report()
{
	string iino,iiname,iidate;
	int iinet;
	system("cls");
	fstream file;
	cout<<"Item No: ";
	cin>>iino;
	cout<<"Name of the item: ";
	cin>>iiname;
	cout<<"Manufacturing Date(dd-mm-yy): ";
	cin>>iidate;
	cout<<"Net Amount: ";
	cin>>iinet;
	file.open("super.txt",ios::in);
	if(!file) cout<<"file openning error";
	else
	{		
		cout<<"\t\t\t********************************************\n\t\t\t\t\tDETAILS\n\t\t\t********************************************";
		file>>i_no>>i_name>>i_date>>i_price>>i_quantity>>i_tax>>i_dis>>i_net;
		while(!file.eof())
		{
			if(iino==i_no && iiname==i_name && iidate==i_date)
			{
				cout<<"\n\nPRICE\t:\t"<<i_price;
				cout<<"\n\nQUANTITY\t:\t"<<i_quantity;
				cout<<"\n\nTAX\t:\t"<<i_tax;
				cout<<"\n\nDISCOUNT\t:\t"<<i_dis;
				cout<<"\n\nNET\t:\tRs."<<i_net;
				
			}
			file>>i_no>>i_name>>i_date>>i_price>>i_quantity>>i_tax>>i_dis>>i_net;
		}
	}
}
super::Edit()
{
	d:
	system("cls");
	int chose;
	fstream file;
	cout<<"\t\t\tBill Editor\n\t\t\t===========\n\n";
	cout<<"\t\t\t1.Add Item Details\n\n";
	cout<<"\t\t\t2.Edit Item Details\n\n";
	cout<<"\t\t\t3.Delete Item Details\n\n";
	cout<<"\t\t\t4.Back to main menu\n\n";
	cout<<"Enter Required Option: ";
	cin>>chose;
	switch(chose)
	{
		case 1:
			{
				int a,b,c;
				string iinum;
				file.open("super.txt",ios::app|ios::out|ios::in);
				file>>iinum;
				cout<<"Item No: ";
				cin>>i_no;
				cout<<"Name of the item: ";
				cin>>i_name;
				cout<<"Manufacturing Date(dd-mm-yy): ";
				cin>>i_date;
				cout<<"Price: ";
				cin>>i_price;
				cout<<"Quantity: ";
				cin>>i_quantity;
				cout<<"Tax Percent: ";
				cin>>i_tax;
				cout<<"Discount Percent: ";
				cin>>i_dis;
				a=i_price*i_quantity;
				b=a+(a*i_tax/100);
				c=b-(b*i_dis/100);
				i_net=c;
				if(!file) cout<<"file openning error..........";
				else
				{
					
					if(iinum==i_no) cout<<"\nItem no already Exist.....";
					else
					{
						file<<i_no<<"\t"<<i_name<<"\t"<<i_date<<"\t"<<i_price<<"\t"<<i_quantity<<"\t"<<i_tax<<"\t"<<i_dis<<"\t"<<i_net<<"\n";
						cout<<"\n\t\t\tItem Added succesfully\n\n";
					}
				}
			}
		break;
		case 2:
			{
				string iino,iiname,iidate,ino,iname,idate;
				int iinet,iprice,iquantity,itax,idis,net,count=0,a,b;
				system("cls");
				fstream file;
				fstream file1;
				cout<<"\t\t\tCurrent Details are\n";
				file.open("super.txt",ios::in);
				file1.open("super1.txt",ios::out|ios::app);
				if(!file) cout<<"file openning error.........";
				else
				{
					cout<<"Item No: ";
					cin>>iino;
					cout<<"Name of the item: ";
					cin>>iiname;
					cout<<"Manufacturing Date(dd-mm-yy): ";
					cin>>iidate;
					cout<<"Net Amount: ";
					cin>>iinet;
					file>>i_no>>i_name>>i_date>>i_price>>i_quantity>>i_tax>>i_dis>>i_net;
					while(!file.eof())
					{
						if(iino==i_no && iiname==i_name && iidate==i_date)
						{
							cout<<"\t\t\tEnter New Details\n";
							cout<<"Name of the item: ";
							cin>>iname;
							cout<<"Manufacturing Date(dd-mm-yy): ";
							cin>>idate;
							cout<<"Price: ";
							cin>>iprice;
							cout<<"Quantity: ";
							cin>>iquantity;
							cout<<"Tax Percent: ";
							cin>>itax;
							cout<<"Discount Percent: ";
							cin>>idis;
							a=iprice*iquantity;
							b=a+(a*itax/100);
							net=b-(b*idis/100);
							file1<<i_no<<"\t"<<iname<<"\t"<<idate<<"\t"<<iprice<<"\t"<<iquantity<<"\t"<<itax<<"\t"<<idis<<"\t"<<net<<"\n";
							cout<<"Item Detials editted successfully";
							count++;
						}
						else
						file1<<i_no<<"\t"<<i_name<<"\t"<<i_date<<"\t"<<i_price<<"\t"<<i_quantity<<"\t"<<i_tax<<"\t"<<i_dis<<"\t"<<i_net<<"\n";
						file>>i_no>>i_name>>i_date>>i_price>>i_quantity>>i_tax>>i_dis>>i_net;
					} 
					
					if(count==0)
					{
						string key;
						cout<<"item not found\n";
						cout<<"Back To menu...\nPRESS ANY KEY...........";
						cin>>key;
						goto d;
					}
					

				}
				file.close();
				file1.close();
				remove("super.txt");
				rename("super1.txt","super.txt");
				
			}
		case 3:
		{
			 	string iino;
				int count=0;
				system("cls");
				fstream file;
				fstream file1;
				cout<<"\t\t\tDelete Item\n";
				file.open("super.txt",ios::in);
				file1.open("super1.txt",ios::out|ios::app);
				if(!file) cout<<"file openning error.........";
				else
				{
					cout<<"Enter the Item No to be deleted: ";
					cin>>iino;
					file>>i_no;
					while(!file.eof())
					{
						if(iino==i_no)
						{
							cout<<"Item deleted successfully\n";
							count++;
						}
						else
						file1<<i_no<<"\t"<<i_name<<"\t"<<i_date<<"\t"<<i_price<<"\t"<<i_quantity<<"\t"<<i_tax<<"\t"<<i_dis<<"\t"<<i_net<<"\n";
						file>>i_no;
					} 
					
					if(count==0)
					{
						cout<<"Item not found\n";
						
					}
					

				}
				file.close();
				file1.close();
				remove("super.txt");
				rename("super1.txt","super.txt");
				
		}
		case 4:
		{
			menu=0;
		}	
	}
	
}
super::show_details()
{
	int co=0;
	system("cls");
	string iino;
	cout<<"Enter the Item no: ";
	cin>>iino;
	cout<<"\t\t\tDETAILS OF PRODUCT\n";
	fstream file;
	file.open("super.txt",ios::in);
	file>>i_no>>i_name>>i_date>>i_price>>i_quantity>>i_tax>>i_dis>>i_net;
	while(!file.eof())
	{
		if(iino==i_no)
		{
			co=1;
			cout<<"\nItem no: "<<i_no;
			cout<<"\nName of the item: "<<i_name;
			cout<<"\nManufacturing Date(dd-mm-yy): "<<i_date;
			cout<<"\nPrice: "<<i_price;
			cout<<"\nQuantity: "<<i_quantity;
			cout<<"\nTax Percent: "<<i_tax;
			cout<<"\nDiscount Percent: "<<i_dis;
			cout<<"\nNet :"<<i_net;
		}
		file>>i_no>>i_name>>i_date>>i_price>>i_quantity>>i_tax>>i_dis>>i_net;
	}
	if(co==0) cout<<"Item not found.....";

	
}
int main()
{
	x:
	int choice;
	super s;
	s.control_panel();
	cout<<"Please Enter Required Option : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			s.bill_report();
			break;
		case 2:
			s.Edit();
			if(s.menu==0)
			goto x;
			break;
		case 3:
			s.show_details();
			break;
		case 4:
			break;
		default:
			cout<<"Invalid Choice";
	}
	
}