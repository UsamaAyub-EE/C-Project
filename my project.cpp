#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>

using namespace std;
class sweet
{
	//hello 
	private:
		char* name;
		char* flavour;
		int price,amount;
	public:
		sweet();
		sweet(int,int,char*,char*);
		~sweet();
		int sell(int,int);
		int getprice();
		int getamount();
		char* getname();
		char* getflavour();
		void setprice(int);
		void setamount(int);
		void setname(char*);
		void setflavour(char*);
		void addsweet();
		void addice();
		void addcake();
		void showsweet();
		void showice();
		void showcake();
		int searchsweet();
		int searchcake();
		int searchice();
		void updatesweet();
		void updatecake();
		void updateice();
		void buysweet();
		void buyice();
		void buycake();
		void deletesweet();
		void deleteice();
		void deletecake();
};
sweet::sweet()
{
	price=0;
	amount=0;
	name="\0";
	flavour="\0";
}
sweet::sweet(int p,int a,char* n,char* f)
{
	setprice(p);
	setamount(a);
	setname(n);
	setflavour(f);
}
sweet::~sweet()
{
	delete[] name,flavour;
	price=0;
	amount=0;
}
int sweet::sell(int a,int b)
{
	if(a<0)
	{
		cout<<"Invalid entry of amount for buying sweet.\n";
		return b;
	}
	if(a>b)
	{
		cout<<"Sweet not available in requested amount.\n";
		return b;
	}
	else
	return b-a;
}
void sweet::setprice(int p)
{
	if(p<0)
	{
		cout<<"Price entered for sweet was invalid.The default price will be set.";
		price=0;
	}
	else if(p>=1000)
	{
		cout<<"Price entered for sweet was invalid.The default price will be set.";
		price=0;
	}
	else
	price=p;
}
void sweet::setamount(int a)
{
	if(a<0)
	{
		cout<<"Amount entered for sweet was invalid.The default amount will be set.";
		amount=0;
	}
	else if(a>=100)
	{
		cout<<"Amount entered for sweet was invalid.The default amount will be set.";
		amount=0;
	}
	else 
	amount=a;
}
void sweet::setname(char* n)
{
	name=new char[strlen(n)+1];
	strcpy(name,n);
	name[0]=toupper(name[0]);
}
void sweet::setflavour(char* f)
{
	flavour=new char[strlen(f)+1];
	strcpy(flavour,f);
	flavour[0]=toupper(flavour[0]);
}
int sweet::getamount()
{
	return amount;
}
int sweet::getprice()
{
	return price;
}
char* sweet::getflavour()
{
	return flavour;
}
char* sweet::getname()
{
	return name;
}
void sweet::addsweet()
{
	ofstream file;
	file.open("sweet.txt",ios::app);
	file<<"\nName of sweet is "<<name<<" ";
	file<<"\nPrice is "<<price<<" Rs. per kg";
	file<<"\nAmount is "<<amount<<" kg,";
	file.close();
}
void sweet::addice()
{
	ofstream file;
	file.open("ice.txt",ios::app);
	file<<"\nName of ice cream is "<<name<<" ";
	file<<"\nFlavour is "<<flavour<<" ";
	file<<"\nPrice is "<<price<<" Rs.";
	file<<"\nAmount is "<<amount<<",";
	file.close();
}
void sweet::addcake()
{
	ofstream file;
	file.open("cake.txt",ios::app);
	file<<"\nName is "<<name<<" ";
	file<<"\nPrice is "<<price<<" Rs.";
	file<<"\nAmount is "<<amount<<",";
	file.close();
}
int sweet::searchsweet()
{
	char sen[25],ch;
	int k=0,i,t;
	i=strlen(name)+1;
	ifstream fin;
	fin.open("sweet.txt",ios::in);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	if(t==0)
	{
			cout<<"Name of sweet is "<<name;
			while(ch!=',')
			{
				cout<<ch;
				fin.get(ch);
			}
			fin.close();
			return 0;
	}
	else
	{
		cout<<"Sweet does not exist in storage.\n";
		fin.close();
		return 1;
	}
}
int sweet::searchice()
{
	char sen[25],ch;
	int k=0,i,t,j;
	i=strlen(name)+1;
	j=strlen(flavour)+1;
	ifstream fin;
	fin.open("ice.txt",ios::in);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	if(t==0)
	{
		while(!fin.eof())
		{
			k=0;
			fin.get(ch);
			while(ch!=' '&&k<=j)
			{
				sen[k]=ch;
				k++;
				fin.get(ch);
			}
		sen[k]='\0';
		t=strcmp(sen,flavour);
		if(t==0)
		break;
	}
	if(t==0)
	{
		cout<<"Name of ice cream is "<<name;
		cout<<"\nFlavour of ice cream is "<<flavour;
		while(ch!=',')
			{
				cout<<ch;
				fin.get(ch);
			}
		fin.close();
		return 0;
	}
	}
	else
	{
		cout<<"Ice cream does not exist in storage.\n";
		fin.close();
		return 1;
	}
}
int sweet::searchcake()
{
	char sen[25],ch;
	int k=0,i,t;
	i=strlen(name)+1;
	ifstream fin;
	fin.open("cake.txt",ios::in);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	if(t==0)
	{
			cout<<"Name of cake is "<<name;
			while(ch!=',')
			{
				cout<<ch;
				fin.get(ch);
			}
			fin.close();
			return 0;
	}
	else
	{
		cout<<"Cake does not exist in storage.\n";
		fin.close();
		return 1;
	}
}
void sweet::updatesweet()
{
	char sen[25],ch;
	int k=0,i,t,nol=0,temp=0;
	i=strlen(name)+1;
	ifstream fin;
	ofstream fout;
	fout.open("temporary.txt",ios::out);
	fin.open("sweet.txt",ios::in);
	fin.seekg(0,ios::beg);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	++nol;
	fin.seekg(0,ios::beg);
	fin.get(ch);
	while(!fin.eof())
	{
		if(ch=='\n')
		++temp;
		if(temp!=nol)
		{
			fout<<ch;
		}
		else
		{
			temp++;
			fout<<"\nPrice is "<<price<<" Rs. per kg";
			fout<<"\nAmount is "<<amount<<" kg,\n";
			while(ch!=',')
			fin.get(ch);
			++temp;
			fin.get(ch);
		}
		fin.get(ch);
	}
	fin.close();
	fout.close();
	remove("sweet.txt");
	rename("temporary.txt","sweet.txt");
}
void sweet::updatecake()
{
	char sen[25],ch;
	int k=0,i,t,nol=0,temp=0;
	i=strlen(name)+1;
	ifstream fin;
	ofstream fout;
	fout.open("temporary.txt",ios::out);
	fin.open("cake.txt",ios::in);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	++nol;
	fin.seekg(0,ios::beg);
	fin.get(ch);
	while(!fin.eof())
	{
		if(ch=='\n')
		++temp;
		if(temp!=nol)
		{
			fout<<ch;
		}
		else
		{
			temp++;
			fout<<"\nPrice is "<<price<<" Rs.";
			fout<<"\nAmount is "<<amount<<",\n";
			while(ch!=',')
			fin.get(ch);
			++temp;
			fin.get(ch);
		}
		fin.get(ch);
	}
	fin.close();
	fout.close();
	remove("cake.txt");
	rename("temporary.txt","cake.txt");
}
void sweet::updateice()
{
	char sen[25],ch;
	int k=0,i,t,j,nol=0,temp=0;
	i=strlen(name)+1;
	j=strlen(flavour)+1;
	ifstream fin;
	ofstream fout;
	fin.open("ice.txt",ios::in);
	fout.open("temporary.txt",ios::out);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=j)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,flavour);
		if(t==0)
		break;
	}
	++nol;
	fin.seekg(0,ios::beg);
	fin.get(ch);
	while(!fin.eof())
	{
		if(ch=='\n')
		++temp;
		if(temp!=nol)
		{
			fout<<ch;
		}
		else
		{
			temp++;
			fout<<"\nPrice is "<<price<<" Rs.";
			fout<<"\nAmount is "<<amount<<",\n";
			while(ch!=',')
			fin.get(ch);
			++temp;
			fin.get(ch);
		}
		fin.get(ch);
	}
	fin.close();
	fout.close();
	remove("ice.txt");
	rename("temporary.txt","ice.txt");
}
void sweet::buysweet()
{
	char sen[25],ch;
	int k=0,i,t,nol=0,l=0,p,q,r,pr,amt;
	i=strlen(name)+1;
	ifstream fin;
	ofstream fout;
	fin.open("sweet.txt",ios::in);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	++nol;
	while(1)
	{
		if(ch>='0'&&ch<='9')
		break;
		fin.get(ch);
	}
	p=ch-'0';
	l++;
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		q=ch-'0';
		l++;
	}
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		r=ch-'0';
		l++;
		fin.get(ch);
	}
	if(l==3)
	pr=p*100+q*10+r;
	else if(l==2)
	pr=p*10+r;
	else
	pr=r;
	price=pr;
	while(1)
	{
		if(ch>='0'&&ch<='9')
		break;
		fin.get(ch);
	}
	l=0;
	p=ch-'0';
	l++;
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		q=ch-'0';
		l++;
	}
	if(l==2)
	amt=p*10+q;
	else
	amt=p;
	cout<<"\nEnter how much sweet you want to buy:\n";
	cin>>p;
	fin.close();
	amount=sell(p,amt);
	if(amount==amt)
	cout<<"Sweet can not be bought.\n";
	else
	cout<<"Price of "<<p<<" kg of sweet is "<<p*price<<" Rs.\n";
	sweet s(price,amount,name," ");
	s.updatesweet();
}
void sweet::buycake()
{
	char sen[25],ch;
	int k=0,i,t,nol=0,l=0,p,q,r,pr,amt;
	i=strlen(name)+1;
	ifstream fin;
	ofstream fout;
	fin.open("cake.txt",ios::in);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	++nol;
	while(1)
	{
		if(ch>='0'&&ch<='9')
		break;
		fin.get(ch);
	}
	p=ch-'0';
	l++;
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		q=ch-'0';
		l++;
	}
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		r=ch-'0';
		l++;
		fin.get(ch);
	}
	if(l==3)
	pr=p*100+q*10+r;
	else if(l==2)
	pr=p*10+r;
	else
	pr=r;
	price=pr;
	while(1)
	{
		if(ch>='0'&&ch<='9')
		break;
		fin.get(ch);
	}
	l=0;
	p=ch-'0';
	l++;
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		q=ch-'0';
		l++;
	}
	if(l==2)
	amt=p*10+q;
	else
	amt=p;
	cout<<"\nEnter how many cakes you want to buy:\n";
	cin>>p;
	fin.close();
	amount=sell(p,amt);
	if(amount==amt)
	cout<<"Cake can not be bought.\n";
	else
	cout<<"Price of "<<p<<" cakes is "<<p*price<<" Rs.\n";
	sweet s(price,amount,name," ");
	s.updatecake();
}
void sweet::buyice()
{
	char sen[25],ch;
	int k=0,i,t,j,nol=0,temp=0,p,q,r,pr,l=0,amt;
	i=strlen(name)+1;
	j=strlen(flavour)+1;
	ifstream fin;
	fin.open("ice.txt",ios::in);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
		while(!fin.eof())
		{
			k=0;
			fin.get(ch);
			while(ch!=' '&&k<=j)
			{
				sen[k]=ch;
				k++;
				if(ch=='\n')
				++nol;
				fin.get(ch);
			}
		sen[k]='\0';
		t=strcmp(sen,flavour);
		if(t==0)
		break;
	}
	++nol;
	while(1)
	{
		if(ch>='0'&&ch<='9')
		break;
		fin.get(ch);
	}
	p=ch-'0';
	l++;
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		q=ch-'0';
		l++;
	}
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		r=ch-'0';
		l++;
		fin.get(ch);
	}
	if(l==3)
	pr=p*100+q*10+r;
	else if(l==2)
	pr=p*10+r;
	else
	pr=r;
	price=pr;
	while(1)
	{
		if(ch>='0'&&ch<='9')
		break;
		fin.get(ch);
	}
	l=0;
	p=ch-'0';
	l++;
	fin.get(ch);
	if(ch>='0'&&ch<='9')
	{
		q=ch-'0';
		l++;
	}
	if(l==2)
	amt=p*10+q;
	else
	amt=p;
	cout<<"\nEnter how many ice creams you want to buy:\n";
	cin>>p;
	fin.close();
	amount=sell(p,amt);
	if(amount==amt)
	cout<<"Ice cream can not be bought.\n";
	else
	cout<<"Price of "<<p<<" ice creams is "<<p*price<<" Rs.\n";
	sweet s(price,amount,name,flavour);
	s.updateice();
}
void sweet::showsweet()
{
	char ch;
	ifstream fin;
	fin.open("sweet.txt",ios::in);
	while(!fin.eof())
	{
		fin.get(ch);
		cout<<ch;
	}
	cout<<"\n";
	fin.close();
}
void sweet::showcake()
{
	char ch;
	ifstream fin;
	fin.open("cake.txt",ios::in);
	while(!fin.eof())
	{
		fin.get(ch);
		cout<<ch;
	}
	cout<<"\n";
	fin.close();
}
void sweet::showice()
{
	char ch;
	ifstream fin;
	fin.open("ice.txt",ios::in);
	while(!fin.eof())
	{
		fin.get(ch);
		cout<<ch;
	}
	cout<<"\n";
	fin.close();
}
void sweet::deletesweet()
{
	char sen[25],ch;
	int k=0,i,t,nol=0,temp=0;
	i=strlen(name)+1;
	ifstream fin;
	ofstream fout;
	fout.open("temporary.txt",ios::out);
	fin.open("sweet.txt",ios::in);
	fin.seekg(0,ios::beg);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	fin.seekg(0,ios::beg);
	fin.get(ch);
	while(!fin.eof())
	{
		if(ch=='\n')
		++temp;
		if(temp!=nol)
		{
			fout<<ch;
		}
		else
		{
			temp++;
			while(ch!=',')
			fin.get(ch);
			++temp;
		}
		fin.get(ch);
	}
	fin.close();
	fout.close();
	remove("sweet.txt");
	rename("temporary.txt","sweet.txt");
}
void sweet::deletecake()
{
	char sen[25],ch;
	int k=0,i,t,nol=0,temp=0;
	i=strlen(name)+1;
	ifstream fin;
	ofstream fout;
	fout.open("temporary.txt",ios::out);
	fin.open("cake.txt",ios::in);
	fin.seekg(0,ios::beg);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	fin.seekg(0,ios::beg);
	fin.get(ch);
	while(!fin.eof())
	{
		if(ch=='\n')
		++temp;
		if(temp!=nol)
		{
			fout<<ch;
		}
		else
		{
			temp++;
			while(ch!=',')
			fin.get(ch);
			++temp;
		}
		fin.get(ch);
	}
	fin.close();
	fout.close();
	remove("cake.txt");
	rename("temporary.txt","cake.txt");
}
void sweet::deleteice()
{
	char sen[25],ch;
	int k=0,i,t,j,nol=0,temp=0;
	i=strlen(name)+1;
	j=strlen(flavour)+1;
	ifstream fin;
	ofstream fout;
	fin.open("ice.txt",ios::in);
	fout.open("temporary.txt",ios::out);
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=i)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,name);
		if(t==0)
		break;
	}
	while(!fin.eof())
	{
		k=0;
		fin.get(ch);
		while(ch!=' '&&k<=j)
		{
			sen[k]=ch;
			k++;
			if(ch=='\n')
			++nol;
			fin.get(ch);
		}
		sen[k]='\0';
		t=strcmp(sen,flavour);
		if(t==0)
		break;
	}
	--nol;
	fin.seekg(0,ios::beg);
	fin.get(ch);
	while(!fin.eof())
	{
		if(ch=='\n')
		++temp;
		if(temp!=nol)
		{
			fout<<ch;
		}
		else
		{
			temp++;
			while(ch!=',')
			fin.get(ch);
			++temp;
		}
		fin.get(ch);
	}
	fin.close();
	fout.close();
	remove("ice.txt");
	rename("temporary.txt","ice.txt");
}
int main()
{
	int key=1;
	cout<<"**This project is for sweets management system.**\n";
	cout<<"***It has been made entirely by Usama Ayub***\n";
	while(key==1){
	char n[25],f[25],ch='y';
	int choice1,choice2,p,a,num;
	cout<<"What do you want to do.You can:\n";
	cout<<"1:Add a sweet\n";
	cout<<"2:Search for a sweet\n";
	cout<<"3:Buy a sweet\n";
	cout<<"4:Update the price or amount of a sweet\n";
	cout<<"5:Delete a sweet\n";
	cout<<"Enter the corresponding number for your action:\n";
	cin>>choice1;
	if(choice1==1)
	{
		cout<<"Which sweet do you want to add.You can add:\n";
		cout<<"1:Sweet\n2:Ice cream\n3:Cake\n";
		cout<<"Enter the corresponding number for your action:\n";
		cin>>choice2;
		if(choice2==1)
		{
			while(ch=='y'||ch=='Y'){
			cout<<"Enter name of your sweet:\n";
			cin>>n;
			sweet s(0,0,n," ");
			num=s.searchsweet();
			if(num==0)
			{
				cout<<"\nThis sweet already exists.Try another sweet.\n";
				continue;
			}
			cout<<"Enter price of your sweet:\n";
			cin>>p;
			cout<<"Enter amount of your sweet:\n";
			cin>>a;
			sweet s1(p,a,n," ");
			s1.addsweet();
			cout<<"The sweet was successfully added.";
			cout<<"Do you want to add another sweet.\n";
			cout<<"Enter y if yes.Otherwise press any key.\n";
			cin>>ch;
			}
		}
		if(choice2==2)
		{
			while(ch=='y'||ch=='Y'){
			cout<<"Enter name of your ice cream:\n";
			cin>>n;
			cout<<"Enter flavour of your ice cream:\n";
			cin>>f;
			sweet s(0,0,n,f);
			num=s.searchice();
			if(num==0)
			{
				cout<<"\nThis ice cream already exists.Try another ice cream.\n";
				continue;
			}
			cout<<"Enter price of your ice cream:\n";
			cin>>p;
			cout<<"Enter amount of your ice cream:\n";
			cin>>a;
			sweet s1(p,a,n,f);
			s1.addice();
			cout<<"The ice cream was successfully added.";
			cout<<"Do you want to add another ice cream.\n";
			cout<<"Enter y if yes.Otherwise press any key.\n";
			cin>>ch;
			}
		}
		if(choice2==3)
		{
			while(ch=='y'||ch=='Y'){
			cout<<"Enter name of your cake:\n";
			cin>>n;
			cin>>f;
			strcat(n,f);
			sweet s(0,0,n," ");
			num=s.searchcake();
			if(num==0)
			{
				cout<<"\nThis cake already exists.Try another cake.\n";
				continue;
			}
			cout<<"Enter price of your cake:\n";
			cin>>p;
			cout<<"Enter amount of your cake:\n";
			cin>>a;
			sweet s1(p,a,n," ");
			s1.addcake();
			cout<<"The cake was successfully added.";
			cout<<"Do you want to add another cake.\n";
			cout<<"Enter y if yes.Otherwise press any key.\n";
			cin>>ch;
			}
		}
	}
	if(choice1==2)
	{
		cout<<"Enter which sweet you want to search for.You can search for:\n";
		cout<<"1:Sweet\n2:Cake\n3:Ice cream\n";
		cout<<"Enter the corresponding number for your choice\n";
		cin>>choice2;
		if(choice2==1)
		{
			cout<<"Enter the name of the sweet\n";
			cin>>n;
			sweet s(0,0,n," ");
			p=s.searchsweet();
		}
		if(choice2==2)
		{
			cout<<"Enter the name of the cake\n";
			cin>>n;
			cin>>f;
			strcat(n,f);
			sweet s(0,0,n," ");
			p=s.searchcake();
		}
		if(choice2==3)
		{
			cout<<"Enter the name of your ice cream\n";
			cin>>n;
			cout<<"Enter the flavour of your ice cream\n";
			cin>>f;
			sweet s(0,0,n,f);
			p=s.searchice();
		}
	}
	if(choice1==3)
	{
		cout<<"Enter which type of sweet you want to buy.\n";
		cout<<"You can buy:\n";
		cout<<"1-Sweet\n2-Cake\n3-Ice cream\n";
		cout<<"Enter the corresponding number for your action\n";
		cin>>choice2;
		if(choice2==1)
		{
			cout<<"Do you want to see all available sweets?\n";
			cout<<"Enter y if yes.Else enter any key.\n";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				cout<<"All available sweets are as under:\n";
				sweet s2(0,0," "," ");
				s2.showsweet();
			}
			cout<<"Enter name of sweet you want to buy:\n";
			cin>>n;
			sweet s(0,0,n," ");
			num=s.searchsweet();
			if(num!=0)
			{
				cout<<"As this sweet does not exist in storage";
				cout<<", so you can't buy this sweet.\n";
			}
			else
			{
				s.buysweet();
			}
		}
		if(choice2==2)
		{
			cout<<"Do you want to see all available cakes?\n";
			cout<<"Enter y if yes.Else enter any key.\n";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				cout<<"All available cakes are as under:\n";
				sweet s2(0,0," "," ");
				s2.showcake();
			}
			cout<<"Enter name of cake you want to buy:\n";
			cin>>n;
			cin>>f;
			strcat(n,f);
			sweet s(0,0,n," ");
			num=s.searchcake();
			if(num!=0)
			{
				cout<<"As this cake does not exist in storage";
				cout<<", so you can't buy this cake.\n";
			}
			else
			{
				s.buycake();
			}
		}
		if(choice2==3)
		{
			cout<<"Do you want to see all available ice creams?\n";
			cout<<"Enter y if yes.Else enter any key.\n";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				cout<<"All available ice creams are as under:\n";
				sweet s2(0,0," "," ");
				s2.showice();
			}
			cout<<"Enter name of ice cream you want to buy:\n";
			cin>>n;
			cout<<"Enter flavour of ice cream.\n";
			cin>>f;
			sweet s(0,0,n,f);
			num=s.searchice();
			if(num!=0)
			{
				cout<<"As this ice cream does not exist in storage";
				cout<<", so you can't buy this ice cream.\n";
			}
			else
			{
				s.buyice();
			}
		}
	}
	if(choice1==4)
	{
		cout<<"You can change the price and amount of the following sweets:\n";
		cout<<"1-Sweet\n2-Cake\n3-Ice cream\n";
		cout<<"Enter the corresponding number for your action\n";
		cin>>choice2;
		if(choice2==1)
		{
			cout<<"Enter the sweet whose amount and price you wish to change\n";
			cin>>n;
			sweet s(0,0,n," ");
			num=s.searchsweet();
			if(num!=0)
			{
				cout<<"As this sweet does not exist in storage,so you";
				cout<<" cannot change its amount or price.\n";
			}
			else
			{
				cout<<"\nEnter the new price of sweet\n";
				cin>>p;
				cout<<"Enter the new amount of sweet\n";
				cin>>a;
				sweet s1(p,a,n," ");
				s1.updatesweet();
				cout<<"The update was successful.\n";
			}
		}
		if(choice2==2)
		{
			cout<<"Enter the cake whose price and amount you want to change.\n";
			cin>>n;
			cin>>f;
			strcat(n,f);
			sweet s(0,0,n," ");
			num=s.searchcake();
			if(num!=0)
			{
				cout<<"As this cake does not exist in storage,so you";
				cout<<" cannot change its amount or price.\n";
			}
			else
			{
				cout<<"\nEnter the new price of cake\n";
				cin>>p;
				cout<<"Enter the new amount of cake\n";
				cin>>a;
				sweet s1(p,a,n," ");
				s1.updatecake();
				cout<<"The update was successful.\n";
			}
		}
		if(choice2==3)
		{
			cout<<"Enter the ice cream whose price and amount you want to change.\n";
			cin>>n;
			cout<<"Enter the flavour of ice cream.\n";
			cin>>f;
			sweet s(0,0,n,f);
			num=s.searchice();
			if(num!=0)
			{
				cout<<"As this ice cream does not exist in storage,so you";
				cout<<" cannot change its amount or price.\n";
			}
			else
			{
				cout<<"\nEnter the new price of ice cream\n";
				cin>>p;
				cout<<"Enter the new amount of ice cream\n";
				cin>>a;
				sweet s1(p,a,n,f);
				s1.updateice();
				cout<<"The update was successful.\n";
			}
		}
	}
	if(choice1==5)
	{
		cout<<"Enter which type of sweet you want to delete.\n";
		cout<<"1-Sweet\n2-Cake\n3-Ice cream\n";
		cout<<"Enter the corresponding number for your action\n";
		cin>>choice2;
		if(choice2==1)
		{
			cout<<"Enter the name of the sweet you want to delete\n";
			cin>>n;
			sweet s(0,0,n," ");
			num=s.searchsweet();
			if(num!=0)
			{
				cout<<"As this sweet does not exist in storage,";
				cout<<"So you cannot delete it.\n";
			}
			else
			{
				s.deletesweet();
				cout<<"\nThis sweet was successfully deleted!\n";
			}
		}
		if(choice2==2)
		{
			cout<<"Enter the name of the cake you want to delete\n";
			cin>>n;
			cin>>f;
			strcat(n,f);
			sweet s(0,0,n," ");
			num=s.searchcake();
			if(num!=0)
			{
				cout<<"As this cake does not exist in storage,";
				cout<<"So you cannot delete it.\n";
			}
			else
			{
				s.deletecake();
				cout<<"\nThis cake was successfully deleted!\n";
			}
		}
		if(choice2==3)
		{
			cout<<"Enter the name of the ice cream you want to delete\n";
			cin>>n;
			cout<<"Enter the flavour of ice cream:\n";
			cin>>f;
			sweet s(0,0,n,f);
			num=s.searchice();
			if(num!=0)
			{
				cout<<"As this ice cream does not exist in storage,";
				cout<<"So you cannot delete it.\n";
			}
			else
			{
				s.deleteice();
				cout<<"\nThis ice cream was successfully deleted!\n";
			}
		}
	}
	cout<<"\nEnter 1 if you wish to do something else. Else enter any key\n";
	cin>>key;
	}
	return 0;
}
