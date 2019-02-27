#include<iostream>
#include<string.h>

using namespace std;

class Format{

	char *font;
	bool exista;
	
	public:
		Format();
		Format(const char *,bool);
		Format(Format&);
		~Format();
		friend ostream &operator << (ostream &,const Format&);
		friend istream &operator >> (istream &,Format&);
		Format &operator = (const Format &);
		char * get_font()
		{
			return font;
		}
		
};

Format::Format()
{
	font = NULL;
	exista = false;
}

Format::Format(const char *a,bool b)
{
	font = new char[strlen(a)+1];
	strcpy(font,a);
	exista = b;
}

Format::Format(Format &a)
{
	font = new char[strlen(a.font)+1];
	strcpy(font,a.font);
	exista = a.exista;
}

Format::~Format()
{
	delete []font;
}

ostream &operator <<(ostream& d,const Format& a)
{	
	d<<"Nume font:"<<a.font<<endl;
	return d;
}

Format & Format::operator = (const Format& a)
{
	this->font = new char[strlen(a.font)+1];
	strcpy(this->font,a.font);
	this->exista = a.exista;
}

istream &operator >>(istream& in,Format &a)
{
	char buffer[50];
	cout<<"Introduceti numele formatului:";
	in>>buffer;
	a.font=new char[strlen(buffer)+1];
	strcpy(a.font,buffer);
	return in;
}

class Pagina{
	char *text;
	int nr_pagina;
	Format f;
	
	public:
		Pagina():f(){
			text = NULL;
			nr_pagina = 0;
		};
		Pagina(const char*text1,int nr_pagina1,const char* font , bool a):f(font ,a)
		{
			text = new char[strlen(text1)+1];
			strcpy(text,text1);
			nr_pagina = nr_pagina1;
		}
		Pagina(Pagina& a)
		{
			text = new char [strlen(a.text) +1 ];
			strcpy(text,a.text);
			nr_pagina = a.nr_pagina;
			f = a.f;
		}
		~Pagina()
		{
			delete []text;
		}
		friend ostream &operator << (ostream& dev,const Pagina& a)
		{
			dev<<"Text:"<<a.text<<endl;
			dev<<"Numar pagina:"<<a.nr_pagina<<endl;
			dev<<a.f;
			return dev;
		}
		friend istream &operator >> (istream &dev,Pagina &a )
		{
			char buffer1[50];
			cout<<"Introduceti textul:";
			dev>>buffer1;
			a.text = new char[strlen(buffer1) + 1];
			strcpy(a.text,buffer1);
			cout<<"Introduceti numarul paginii:";
			dev>>a.nr_pagina;	
			dev>>a.f;
			return dev;
		}
		Pagina &operator =(Pagina &a)
		{
			text = new char[strlen(a.text)+1];
			strcpy(text,a.text);
			nr_pagina = a.nr_pagina;
			f = a.f;
		}
		int get_nr_pagina()
		{
			return nr_pagina;
		}
		char* get_font2()
		{
			return f.get_font();
		}
};

void sortareVector(Pagina *v,int n)
{
	Pagina aux;
	for(int i=0;i<n-1;i++)
		for(int j=i;j<n;j++)
		if(v[i].get_nr_pagina() > v[j].get_nr_pagina())
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}		
}

int main()
{
	Pagina v[4];
	for(int i=0;i<4;i++)
		cin>>v[i];
	cout<<"Vector inainte de sortare:"<<endl;
	for(int i=0;i<4;i++)
		cout<<v[i];
	sortareVector(v,4);
	
	cout<<"Vector dupa sortare:"<<endl;
	for(int i=0;i<4;i++)
		cout<<v[i];
	
	for(int i=0;i<4;i++)
		if(strcmp("Arial",v[i].get_font2()) == 0)
			cout<<v[i];
	
	return 0;
}
