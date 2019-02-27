#include<iostream>
#include<string.h>

using namespace std;

class punct{
	protected:
		int x,y,z;
		char *figura;
	public:
		punct(int,int,int,const char*);
		void afisare();
		virtual int perimetru();
		virtual int arie();
		virtual int volum();
		virtual ~punct();
};
class dreptunghi:public punct{
	protected:
		int lungime,latime;
		public:
			dreptunghi(int,int,int,const char*,int,int);
			int perimetru();
			int arie();
			int volum();
};
class cerc:public punct
{
	protected:
		int raza;
		public:
			cerc(int,int,int,const char*,int);
			int perimetru();
			int arie();
			int volum();
};

class paralelipiped:public dreptunghi{
	int inaltime;
	public:
		paralelipiped(int,int,int,const char*,int,int,int);
		int perimetru();
		int arie();
		int volum();
};

class cilindru:public cerc{
	int inaltime;
	public:
		cilindru(int,int,int,const char*,int,int);
		int perimetru();
		int arie();
		int volum();	
};
cilindru::cilindru(int x1,int y1,int z1,const char *nume,int raza,int inaltime1):cerc(x1,y1,z1,nume,raza)
{
	inaltime = inaltime1;
}
int cilindru::perimetru()
{
	return 2*3*raza;
}
int cilindru::arie()
{
	return raza*3*8;
}
int cilindru::volum()
{
	return 2*3*raza*inaltime;
}


paralelipiped::paralelipiped(int x1,int y1,int z1,const char*nume,int lung,int lat,int inalt):dreptunghi(x1,y1,z1,nume,lung,lat)
{
	inaltime = inalt;
}
int paralelipiped::perimetru()
{
	return 4*lungime+8*latime;
}
int paralelipiped::arie()
{
	return 2*latime*latime + 4*lungime*latime;
}
int paralelipiped::volum()
{
	return lungime*latime*inaltime;
}

cerc::cerc(int x1,int y1,int z1,const char*nume,int raz):punct(x1,y1,z1,nume)
{
	raza = raz;
}
int cerc::perimetru()
{
	return 2*raza*3;
}
int cerc::arie()
{
	return 3*raza*raza;
}
int cerc::volum()
{
	return 0;
}


dreptunghi::dreptunghi(int x1,int y1,int z1,const char*nume,int lung,int lat):punct(x1,y1,z1,nume)
{
	lungime = lung;
	latime = lat;
}
int dreptunghi::perimetru()
{
	return 2*(lungime+latime);
}
int dreptunghi::arie()
{
	return lungime*latime;
}
int dreptunghi::volum()
{
	return 0;
}





punct::punct(int x2,int y2,int z2,const char* nume)
{
	x = x2;
	y = y2;
	z = z2;
	figura = new char[strlen(nume) + 1];
	strcpy(figura,nume);
}
void punct::afisare(){
	cout<<"Nume figura: "<<figura<<endl;
	cout<<"Perimetru: "<<perimetru()<<endl;
	cout<<"Arie: "<<arie()<<endl;
	cout<<"Volum: "<<volum()<<endl;
}
int punct::perimetru()
{
	return 0;
}
int punct::arie()
{
	return 0;
}
int punct::volum()
{
	return 0;
}
punct::~punct()
{
	delete []figura;
}

int main(void)
{
	punct **v;
	v = new punct*[5];
	v[0] = new cerc(1,1,3,"cerc",4);
	v[1] = new paralelipiped(2,2,3,"paralelipiped",2,3,4);
	v[2] = new cerc(3,3,1,"cerc2",6);
	v[3] = new dreptunghi(0,0,0,"dreptunghi",3,4);
	v[4] = new cilindru(2,2,2,"cilindru",2,4);
	for(int i=0;i<5;i++)
		v[i]->afisare();
	return 0;
}


