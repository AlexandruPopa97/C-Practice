#include<iostream>
#include<string.h>
using namespace std;

class produs
{
	protected:
		char *marca;
		int pret;
	public:
		produs();
		produs(const char *,int);
		produs(produs &);
		virtual ~produs();
		virtual void afisare();
		virtual double get_volum();
};
produs::produs()
{
	marca = NULL;
	pret = 0;
}
produs::produs(const char *c,int p)
{
	marca = new char[strlen(c) + 1];
	strcpy(marca,c);
	pret = p;
}
produs::produs(produs &a)
{
	marca = new char[strlen(a.marca) + 1];
	strcpy(marca,a.marca);
	pret = a.pret;
}
produs::~produs()
{
	delete []marca;
}
void produs::afisare()
{
	cout<<"Marca: "<<marca<<endl;
	cout<<"Pret: "<<pret<<endl;
	cout<<"Volum: "<<0<<endl;
}
double produs::get_volum()
{
	return 0;
}


class frigider:public virtual produs
{
	protected:
		double volum;
		bool defrost;
	public:
		frigider();
		frigider(const char*,int,double,bool);
		frigider(frigider &);
		~frigider();
		void afisare();
		double get_volum();
};
frigider::frigider()
{
	volum = 0;
	defrost = false;
}
frigider::frigider(const char *c,int p,double v,bool d):produs(c,p)
{
	volum = v;
	defrost = d;
}
frigider::frigider(frigider& a):produs(a)
{
	volum = a.volum;
	defrost = a.defrost;
}
frigider::~frigider()
{
}
void frigider::afisare()
{
	cout<<"Marca: "<<marca<<endl;
	cout<<"Pret: "<<pret<<endl;
	cout<<"Volum: "<<volum<<endl;
	cout<<"Defrost: "<<defrost<<endl;
}
double frigider::get_volum()
{
	return volum;
}

class lada_frigorifica:public virtual produs
{
	protected:
		double dim[3];
		char *detalii_consum;
	public:
		lada_frigorifica();
		lada_frigorifica(const char*,int,double d[3],const char*);
		lada_frigorifica(lada_frigorifica&);
		~lada_frigorifica();
		void afisare();
		double get_volum();	
};
lada_frigorifica::lada_frigorifica():produs()
{
	dim[0] = 0;
	dim[1] = 0;
	dim[2] = 0;
	detalii_consum = NULL;
}
lada_frigorifica::lada_frigorifica(const char*c,int p,double d[3],const char *detalii):produs(c,p)
{
	dim[0] = d[0];
	dim[1] = d[1];
	dim[2] = d[2];
	detalii_consum = new char[strlen(detalii) + 1];
	strcpy(detalii_consum,detalii);
}
lada_frigorifica::lada_frigorifica(lada_frigorifica &a):produs(a)
{
	dim[0] = a.dim[0];
	dim[1] = a.dim[1];
	dim[2] = a.dim[2];
	detalii_consum = new char [strlen(a.detalii_consum) + 1];
	strcpy(detalii_consum,a.detalii_consum);
}
lada_frigorifica::~lada_frigorifica()
{
	delete []detalii_consum;
}
double lada_frigorifica::get_volum()
{
	return dim[0] * dim[1] * dim[2];
}
void lada_frigorifica::afisare()
{
	cout<<"Marca: "<<marca<<endl;
	cout<<"Pret: "<<pret<<endl;
	cout<<"Dimensiuni: "<<dim[0]<<" "<<dim[1]<<" "<<dim[2]<<endl;
	cout<<"Volum: "<<dim[0] * dim[1] * dim[2]<<endl;
	cout<<"Detalii consum: "<<detalii_consum<<endl;
}

class combina_frigorifica:public frigider,public lada_frigorifica
{
	char *info_suplimentare;
	public:
		combina_frigorifica();
		combina_frigorifica(const char*,int,bool,double d[3],const char*,const char*);
		combina_frigorifica(combina_frigorifica&);
		~combina_frigorifica();
		void afisare();
		double get_volum();	
};

combina_frigorifica::combina_frigorifica():frigider(),lada_frigorifica()
{
	info_suplimentare = NULL;
}
combina_frigorifica::combina_frigorifica(const char* m,int p,bool de, double d[3],const char *c,const char*i):lada_frigorifica(m,p,d,c),produs(m,p)
{
	defrost = de;
	info_suplimentare = new char[strlen(i) + 1];
	strcpy(info_suplimentare,i);
	volum = dim[0] * dim[1] * dim[2];
}
combina_frigorifica::combina_frigorifica(combina_frigorifica &a):lada_frigorifica(a),produs(a)
{
	defrost = a.defrost;
	info_suplimentare = new char[strlen(a.info_suplimentare) + 1];
	strcpy(info_suplimentare,a.info_suplimentare);
	volum = a.volum;
}
combina_frigorifica::~combina_frigorifica()
{
	delete []info_suplimentare;
}
void combina_frigorifica::afisare()
{
	cout<<"Marca: "<<marca<<endl;
	cout<<"Pret: "<<pret<<endl;
	cout<<"Dimensiuni: "<<dim[0]<<" "<<dim[1]<<" "<<dim[2]<<endl;
	cout<<"Detalii consum: "<<detalii_consum<<endl;
	cout<<"Volum: "<<volum<<endl;
	cout<<"Defrost: "<<defrost<<endl;
	cout<<"Informatii suplimentare: "<<info_suplimentare<<endl;
}
double combina_frigorifica::get_volum()
{
	return volum;
}

void sortare(produs *v[],int n)
{
	produs *aux;
	for(int i=0;i<5;i++)
		for(int j=i;j<5;j++)
		{
			if(v[i]->get_volum() < v[j]->get_volum())
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
}

int main()
{
	double d1[]={1.5,2,3},d2[]={3,4,5};
	produs *v[5];
	v[0] = new produs("Arctic",2500);
	v[1] = new lada_frigorifica("Samsung",1250,d1,"Consuma putin");
	v[2] = new combina_frigorifica("Arctic",1500,true,d2,"Consuma mult","Nu bate nu trocane");
	v[3] = new frigider("Hp",900,40,true);
	v[4] = new frigider("Apple",4900,30,false);
	cout<<"-----Vector inainte de sortare-----"<<endl;
	for(int i=0;i<5;i++)
	{
		v[i]->afisare();
		cout<<endl;
	}
	sortare(v,5);
	cout<<"-----Vector dupa sortare in functie de volum-----"<<endl;
	for(int i=0;i<5;i++)
	{
		v[i]->afisare();
		cout<<endl;
	}
	return 0;
}
