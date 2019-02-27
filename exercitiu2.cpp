#include<iostream>
#include<stdlib.h>

using namespace std;

class matrice{
	int n;
	char **m;
	
	public:
		matrice();
		matrice(int,char**);
		matrice(const matrice&);
		matrice &operator = (const matrice &);
		friend istream & operator>>(istream &,matrice &);
		friend ostream &operator <<(ostream &,const matrice&);
		friend bool operator ==(const matrice&,const matrice&);
		friend bool operator !=(const matrice&,const matrice&);
		~matrice();
};

matrice::matrice()
{
	this->n = 0;
	this->m = NULL;
}

matrice::matrice(int n1, char**m1)
{
	this->n = n1;
	this->m=new char*[this->n];
	for(int i=0;i<n;i++)
	{
		this->m[i]=new char[this->n];
		for(int j=0;j<i;j++)
			this->m[i][j] = '0';
		for(int j=i;j<n;j++)
			this->m[i][j] = m1[i][j];
	}	
}

matrice::matrice(const matrice& a)
{
	this->n = a.n;
	this->m = new char*[n];
	for(int i=0;i<n;i++)
	{
		this->m[i]=new char[n];
		for(int j=0;j<n;j++)
			this->m[i][j] = a.m[i][j];
	}
}

matrice& matrice :: operator = (const matrice& a)
{
	this->n = a.n;
	this->m = new char*[n];
	for(int i=0;i<n;i++)
	{
		this->m[i]=new char[n];
		for(int j=0;j<n;j++)
			this->m[i][j] = a.m[i][j];
	}
	return *this;
}

istream& operator >>(istream &a,matrice &b)
{
	cout<<"Introduceti numarul de linii si de coloane al matricei"<<endl;
	a>>b.n;
	b.m = new char*[b.n];
	for (int i=0;i<b.n;i++)
	{
		b.m[i] = new char[b.n];
		for(int j=0;j<i;j++)
			b.m[i][j] = '0';
		for(int j=i;j<b.n;j++)
		{
			cout<<"m["<<i<<"]["<<j<<"]=";
			a>>b.m[i][j];
		}
	}
	 return a;
}

matrice::~matrice()
{
	for(int i=0;i<this->n;i++)
		delete [](this->m[i]);
	delete []this->m;
}

ostream& operator <<(ostream &a,const matrice &b)
{
	for(int i=0;i<b.n;i++)
	{
		for(int j=0;j<b.n;j++)
			a<<b.m[i][j]<<" ";
		a<<endl;
	}
}

bool operator == (const matrice&a,const matrice&b)
{
	if(a.n != b.n)
		return false;
	for(int i=0;i<a.n;i++)
	{
		for(int j=i;j<a.n;j++)
			if(a.m[i][j] != b.m[i][j])
				return false;
	}
	return true;
}

bool operator != (const matrice&a,const matrice&b)
{
	if(a.n != b.n)
		return true;
	for(int i=0;i<a.n;i++)
	{
		for(int j=i;j<a.n;j++)
			if(a.m[i][j] != b.m[i][j])
				return true;
	}
	return false;
}

int main(void)
{
	char **m;
	int n;
	matrice a;
	cin>>a;
	cout<<"Introduceti numarul de elemente pentru matricea a-2a "<<endl;
	cin>>n;
	m = new char*[n];
	for(int i=0;i<n;i++)
	{
		m[i] = new char[n];
		for(int j=0;j<i;j++)
			m[i][j] = '0';
		for(int j=i;j<n;j++)
		{
			cout<<"m["<<i<<"]["<<j<<"]=";
			cin>>m[i][j];
		}	
	}
	matrice c(n,m);
	cout<<a;
	cout<<c;
	
	
	if(a == c)
		cout<<"Cele 2 matrice a si c sunt egale"<<endl;
	else cout<<"Cele 2 matrice a si c nu sunt egale"<<endl;
	
	
	matrice b(a);
	cout<<a;
	cout<<b;
	if(a == b)
		cout<<"Cele 2 matrice a si b sunt egale"<<endl;
	else cout<<"Cele 2 matrice a si b nu sunt egale"<<endl;
	return 0;
}
