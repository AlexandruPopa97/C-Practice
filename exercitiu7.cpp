#include<iostream>
#include<string.h>

using namespace std;

class persoana{
	protected:
		char *nume;
	public:
		virtual void afisare() = 0;
		virtual int get_venit() = 0;
		virtual ~persoana();
		persoana();
		persoana(const char*);
		persoana(const persoana &);
		persoana &operator=(const persoana &);
};
persoana &persoana::operator =(const persoana &a)
{
	delete []nume;
	nume = new char[strlen(a.nume) + 1];
	strcpy(nume,a.nume);
} 
persoana::persoana()
{
	nume = NULL;
}
persoana::~persoana()
{
	delete []nume;
}
persoana::persoana(const char *n)
{
	nume = new char[strlen(n) + 1];
	strcpy(nume,n);
}
persoana::persoana(const persoana& a)
{
	nume = new char[strlen(a.nume) + 1];
	strcpy(nume,a.nume);
}



class student:public virtual persoana
{
	protected:
	int media;
	int bursa;
	public:
		student(int,const char*);
		student();
		student(const student &);
		void afisare();
		int get_venit();
		int get_media();
		student &operator = (const student &);
		~student();
		
};
student &student::operator=(const student&a)
{
	delete []nume;
	nume = new char[strlen(a.nume) + 1];
	strcpy(nume,a.nume);
	media = a.media;
	bursa = a.bursa;
}

int student::get_media()
{
	return media;
}
void student::afisare()
{
	cout<<"Nume: "<<nume<<endl;
	cout<<"Media: "<<media<<endl;
	cout<<"Bursa: "<<bursa<<endl;
}
int student::get_venit()
{
	return bursa;
}

student::~student()
{
}
student::student()
{
	media = 0;
	bursa = 0;
}
student::student(int a,const char*n):persoana(n)
{
	media = a;
	if(a>8.5)
		bursa = 700;
	else
		bursa = 0;
}
student::student(const student&a):persoana(a)
{
	media = a.media;
	bursa = a.bursa;
}


class angajat:public virtual persoana
{
	protected:
	int salariu;
	public:
		angajat();
		angajat(int,const char*);
		angajat(const angajat &);
		void afisare();
		int get_venit();
		angajat &operator=(const angajat&);
		~angajat();
};
angajat &angajat::operator=(const angajat&a)
{
	delete []nume;
	nume = new char[strlen(a.nume) + 1];
	strcpy(nume,a.nume);
	salariu = a.salariu;
}
angajat::angajat()
{
	salariu = 0;
}
angajat::angajat(int a,const char *n):persoana(n)
{
	salariu = a;
}
angajat::angajat(const angajat &a):persoana(a)
{
	salariu = a.salariu;
}
angajat::~angajat()
{
}
void angajat::afisare()
{
	cout<<"Nume: "<<nume<<endl;
	cout<<"Salariu: "<<salariu<<endl;
}
int angajat::get_venit()
{
	return salariu;
}

class student_angajat:public student,public angajat
{
	public:
		student_angajat();
		student_angajat(int,int,const char*);
		student_angajat(const student_angajat &);
		~student_angajat();
		void afisare();
		int get_venit();
		student_angajat &operator = (const student_angajat&);	
};
student_angajat &student_angajat::operator=(const student_angajat &a)
{
	delete []nume;
	nume = new char[strlen(a.nume) + 1];
	strcpy(nume,a.nume);
	salariu = a.salariu;
	bursa = a.bursa;
	media = a.media;
}
student_angajat::student_angajat()
{
}
student_angajat::student_angajat(int a,int b,const char*n):student(a,n),persoana(n),angajat(b,n)
{
}
student_angajat::student_angajat(const student_angajat &a):student(a),angajat(a),persoana(a)
{
}
student_angajat::~student_angajat()
{
}
void student_angajat::afisare()
{
	cout<<"Nume: "<<nume<<endl;
	cout<<"Salariu: "<<angajat::get_venit()<<endl;
	cout<<"Medie: "<<student::get_media()<<endl;
	cout<<"Bursa: "<<student::get_venit()<<endl;
}
int student_angajat::get_venit()
{
	return student::get_venit() + angajat::get_venit();
}

void sortare(persoana *v[],int n)
{
	persoana *aux;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(v[i]->get_venit() < v[j]->get_venit())
			{
				aux = v[i];
				v[i] = v[j]; 
				v[j] = aux;
			}
}

int main(void)
{
	persoana *v[5];
	v[0] = new student_angajat(9,3000,"Andrei");
	v[1] = new angajat(2500,"Ionel");
	v[2] = new student(6,"Mircea");
	v[3] = new angajat(3400,"Vasile");
	v[4] = new student_angajat(10,2600,"Beraru");
	cout<<"-----INAINTE DE SORTARE-----"<<endl;
	for(int i=0;i<5;i++)
	{
		v[i] ->afisare();
		cout<<endl;
	}
	sortare(v,5);
	cout<<"------DUPA SORTARE-------"<<endl;
	for(int i=0;i<5;i++)
	{
		v[i] ->afisare();
		cout<<endl;
	}
	
	cout<<"Cei care au venit mai mare de 3000"<<endl;
	for(int i=0;i<5;i++)
		if(v[i]->get_venit() >3000)
		{
			v[i] ->afisare();
			cout<<endl;
		}
	return 0;
}
