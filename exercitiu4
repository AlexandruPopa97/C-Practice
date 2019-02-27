#include<iostream>
#include<string.h>

using namespace std;

class persoana{
	protected:
		char *nume;
		int varsta;
	public:
		persoana();
		persoana(const char *,int);
		persoana(const persoana &);
		~persoana();
		persoana &operator = (const persoana &);
		void afisare();
		
};
class angajat:public persoana{
	protected:
		double salariu;
	public:
		angajat();
		angajat(const char* n,int v,double s);
		angajat(const angajat &);
		angajat &operator = (const angajat &);
		void afisare();
};
class angajat_part_time:public angajat{
	int nr_ore;
	char *detalii;
	public:
		angajat_part_time();
		angajat_part_time(const char*,int,double,int nr,const char*);
		angajat_part_time(const angajat_part_time&);
		~angajat_part_time();
		angajat_part_time &operator = (const angajat_part_time&);
		void afisare();
		void citire_angajat_part_time();
		int get_nr_ore();
		int get_salariu();
		int get_varsta();
		void afisare_detalii();
};

void angajat_part_time::afisare_detalii()
{
	cout<<detalii<<endl;
}
int angajat_part_time::get_salariu()
{
	return salariu;
}

int angajat_part_time::get_varsta()
{
	return varsta;
}
int angajat_part_time::get_nr_ore()
{
	return nr_ore;
}
void angajat_part_time::citire_angajat_part_time()
{
	fflush(stdin);
	char buffer[50];
	cout<<"Introduceti numele:";
	//getline(cin,buffer,50);
	cin>>buffer;
	nume = new char[strlen(buffer) + 1];
	strcpy(nume,buffer);
	cout<<"Introduceti varsta:";cin>>varsta;
	cout<<"Introduceti salariul:";cin>>salariu;
	cout<<"Introduceti numarul de ore:";cin>>nr_ore;
	cout<<"Introduceti detaliile:";fflush(stdin);cin>>buffer;
	detalii = new char[strlen(buffer) + 1];
	strcpy(detalii,buffer);
}

angajat_part_time::angajat_part_time(const angajat_part_time &a):angajat(a)
{
	nr_ore = a.nr_ore;
	detalii = new char[strlen(a.detalii) + 1];
	strcpy(detalii,a.detalii);	
}
angajat_part_time &angajat_part_time::operator =(const angajat_part_time& a)
{
	angajat::operator = (a);
	nr_ore = a.nr_ore;
	delete []detalii;
	detalii = new char[strlen(a.detalii) + 1];
	strcpy(detalii,a.detalii);
}
angajat_part_time::~angajat_part_time()
{
	delete []detalii;
}

void angajat_part_time::afisare()
{
	if(nume != NULL)
	{
		angajat::afisare();
		cout<<"Numar ore:"<<nr_ore<<endl;
		cout<<"Detalii:"<<detalii<<endl;
	}
	else cout<<"Obiect gol"<<endl;
}
angajat_part_time::angajat_part_time():angajat()
{
	nr_ore = 0;
	detalii = NULL;
}
angajat_part_time::angajat_part_time(const char*n,int v,double s, int nr,const char*d):angajat(n,v,s)
{
	nr_ore = nr;
	detalii = new char[strlen(d) + 1];
	strcpy(detalii,d);
}

angajat &angajat:: operator = (const angajat & a)
{
	persoana::operator = (a);
	salariu = a.salariu;
}



persoana::persoana()
{
	nume = NULL;
	varsta = 0;
}
persoana::persoana(const char *n,int v)
{
	nume = new char[strlen(n) + 1];
	strcpy(nume,n);
	varsta = v;
}
persoana::persoana(const persoana &a)
{
	nume = new char[strlen(a.nume) + 1];
	strcpy(nume,a.nume);
	varsta = a.varsta;
}
persoana::~persoana()
{
	delete []nume;
}
void persoana::afisare()
{
	if(nume != NULL)
	{
		cout<<"Nume:"<<nume<<endl;
		cout<<"Varsta:"<<varsta<<endl;
	}
	else cout<<"Obiect gol"<<endl;
}
persoana &persoana::operator = (const persoana &a)
{
	delete []nume;
	nume = new char[strlen(a.nume) + 1];
	strcpy(nume,a.nume);
	varsta = a.varsta;
}

angajat::angajat():persoana()
{
	salariu = 0;
}
void angajat::afisare()
{
	if(nume != NULL)
	{
		persoana::afisare();
		cout<<"Salariu:"<<salariu<<endl;
	}
	else cout<<"Obiect gol"<<endl;
}
angajat::angajat(const char* n,int v,double s):persoana(n,v)
{
	salariu = s;
}
angajat::angajat(const angajat &a):persoana(a)
{
	salariu = a.salariu;
}

void sortare_angajati(angajat_part_time *v,int n)
{
	angajat_part_time aux;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(v[i].get_nr_ore() < v[j].get_nr_ore())
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
}

int main(void)
{
	angajat_part_time v[3];
	for(int i=0;i<3;i++)
		v[i].citire_angajat_part_time();
	cout<<"Afiseaza angajati inainte de sortare:"<<endl	;
	for(int i=0;i<3;i++)
		v[i].afisare();
	sortare_angajati(v,3);
	cout<<"Afiseaza angajati dupa sortare:"<<endl;
	for(int i=0;i<3;i++)
		v[i].afisare();
	
	cout<<"Afiseaza angajati cu salariu mai mare de 1000 si varsta 20:"<<endl;
	for(int i=0;i<3;i++)
	if( v[i].get_salariu() > 1000 && v[i].get_varsta() == 20)
		v[i].afisare_detalii();
	return 0;
}
