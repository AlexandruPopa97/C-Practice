#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Prod{
	protected:
		char cod[4];
		int pret;
	public:
		Prod();
		Prod(const char [4],int);
		virtual void afisare();
		virtual int get_pret();
		virtual void citire();
		virtual ~Prod();	
};
Prod::~Prod()
{
}
class Prod_A:public Prod
{
		char *descriere;
		int data_exp[3];
	public:
		Prod_A();
		Prod_A(const char*,int [3],const char [4],int);
		Prod_A(Prod_A &);
		Prod_A &operator=(const Prod_A &);
		~Prod_A();
		void afisare();
		int get_pret();
};
class Pachet_promo:public Prod{
	Prod_A *v;
	int nr_prod;
	int reducere;
	public:
	 	Pachet_promo();
	 	Pachet_promo(Prod_A *,int,int,const char[4],int);
	 	Pachet_promo(Pachet_promo &);
	 	Pachet_promo &operator=(const Pachet_promo&);
	 	void afisare();
	 	int get_pret();
	 	~Pachet_promo();
};


void Prod::citire()
{
	cout<<"Introduceti cod(4):";
	cin>>cod;
	fflush(stdin);
	cout<<"Introduceti pret:";
	cin>>pret;
}

Pachet_promo::~Pachet_promo()
{
	delete []v;
}
Pachet_promo::Pachet_promo()
{
	v = NULL;
	nr_prod = 0;
	reducere = 0;
}
Pachet_promo::Pachet_promo(Prod_A *x,int nr,int red,const char a[4],int b):Prod(a,b)
{
	nr_prod = nr;
	reducere = red;
	v =	(Prod_A*)malloc(sizeof(Prod_A) * nr_prod);
	for(int i=0;i<nr_prod;i++)
		v[i] = x[i];
}
Pachet_promo::Pachet_promo(Pachet_promo& a)
{
	nr_prod = a.nr_prod;
	reducere = a.reducere;
	v = (Prod_A*)malloc(sizeof(Prod_A) * nr_prod);
	for(int i=0;i<nr_prod;i++)
		v[i] = a.v[i];
}
Pachet_promo & Pachet_promo::operator=(const Pachet_promo &a)
{
	nr_prod = a.nr_prod;
	reducere = a.reducere;
	delete []v;
	v = (Prod_A*)malloc(sizeof(Prod_A) * nr_prod);
	for(int i=0;i<nr_prod;i++)
		v[i] = a.v[i];
}
void Pachet_promo::afisare()
{
	cout<<"Cod promo:"<<cod<<endl;
	cout<<"Pret pachet: "<<pret<<endl;
	cout<<"Numar produse: "<<nr_prod<<endl;
	cout<<"Reducere: "<<reducere<<endl;
}
int Pachet_promo::get_pret()
{
	return pret-reducere*pret/100;
}

Prod::Prod()
{
	strcpy(cod,"NULL");
	pret = 0;
}
Prod::Prod(const char a[4],int b)
{
	strcpy(cod,a);
	pret = b;
}
void Prod::afisare()
{
	cout<<"Cod produs:"<<cod<<endl;
	cout<<"Pret produs: "<<pret<<endl;
}
int Prod::get_pret()
{
	return pret;
}

Prod_A::Prod_A()
{
	descriere = NULL;
	data_exp[0] = 0;	
	data_exp[1] = 0;
	data_exp[2] = 0;
}
Prod_A::Prod_A(const char *desc,int v[3],const char a[4],int b):Prod(a,b)
{
	descriere = new char[strlen(desc) + 1];
	strcpy(descriere,desc);
	for(int i=0;i<3;i++)
		data_exp[i] = v[i];
}
Prod_A::Prod_A(Prod_A &a)
{
	strcpy(cod,a.cod);
	pret = a.pret;
	descriere = new char[strlen(a.descriere) + 1];
	strcpy(descriere,a.descriere);
	for(int i=0;i<3;i++)
		data_exp[i] = a.data_exp[i];
}
Prod_A::~Prod_A()
{
	delete []descriere;
}
Prod_A &Prod_A:: operator=(const Prod_A& a)
{
	strcpy(cod,a.cod);
	pret = a.pret;
	descriere = new char[strlen(a.descriere) + 1];
	strcpy(descriere,a.descriere);
	for(int i=0;i<3;i++)
		data_exp[i] = a.data_exp[i];
}
void Prod_A::afisare()
{
	cout<<"Cod produs:"<<cod<<endl;
	cout<<"Pret produs: "<<pret<<endl;
	cout<<"Descriere: "<<descriere<<endl;
	cout<<"Data expirarii: "<<data_exp[0]<<data_exp[1]<<data_exp[2]<<endl;
}
int Prod_A::get_pret()
{
	return pret;
}


void sortare(Prod **v,int n)
{
	Prod *aux;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(v[i]->get_pret() < v[j]->get_pret())
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
}

int main(void)
{
	Prod *v[4];
	int a[]={1,2,3};
	v[0] = new Prod_A("descriere_0",a,"abc",125);
	
	Prod_A q[2];
	Prod_A x("descriere_v0",a,"qaz",100),y("desciere_v1",a,"qwe",250);
	q[0] = x;
	q[1] = y;
	
	v[1] = new Pachet_promo(q,2,80,"pro",350);
	v[2] = new Prod_A("descriere_2",a,"asd",500);
	v[3] = new Prod_A("desciere_3",a,"qqq",50);
	
	sortare(v,4);
	
	for(int i=0;i<4;i++)
	{
		v[i]->afisare();
		cout<<endl;
	}
	return 0;
}
