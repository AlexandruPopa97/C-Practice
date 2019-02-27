#include<iostream>

using namespace std;

class complex{
	private:
		float real;
		float imaginar;
	public:
		complex();
		complex(float,float);
		
	friend bool operator == (const complex& a,const complex&b)
	{
		if(a.real != b.real) return false;
		if(a.imaginar != b.imaginar) return false;
		return true;
	}
	friend bool operator != (const complex&a,const complex&b)
	{
		if(a.real != b.real) return true;
		if(b.imaginar != a.imaginar) return true;
		return false;
	}
	friend complex operator + (const complex&a,const complex&b)
	{
		return complex(a.real+b.real,a.imaginar+b.imaginar);
	}
	friend complex operator - (const complex&a,const complex&b)
	{
		return complex(a.real-b.real,a.imaginar-b.imaginar);
	}
	friend complex operator * (const complex&a,const complex&b)
	{
		return complex(a.real*b.real -b.imaginar*a.imaginar,a.real*b.imaginar + b.real*a.imaginar);
	}
	complex &operator += (const complex&a)
	{
		real+=a.real;
		imaginar+=a.imaginar;
		return *this;
	}
	complex &operator -= (const complex&a)
	{
		real-=a.real;
		imaginar-=a.imaginar;
		return *this;
	}
	complex &operator *= (const complex&a)
	{
		real*=a.real;
		imaginar*=a.imaginar;
		return *this;
	}
	friend ostream &operator << (ostream &dout,const complex &c)
	{
		if(c.real == 0 && c.imaginar == 0)
		{
			dout<<0<<endl;
			return dout;
		}
		else if (c.imaginar >=0 )
		{
			dout<<c.real;
			dout<<"+i*"<<c.imaginar<<endl;
			return dout;
		}
		else if (c.imaginar <0 )
		{
			dout<<c.real;
			dout<<"-i*"<<-c.imaginar<<endl;
			return dout;
		}
		return dout;
	}
	friend istream &operator >> (istream &din,complex &c)
	{
		din>>c.real>>c.imaginar;
		return din;
	}
	complex &operator = (const complex &a)
	{
		real=a.real;
		imaginar=a.imaginar;
	}
	void afisare()
	{
		cout<<real<<"+i*"<<imaginar<<endl;
	}
};

complex::complex()
{
	real = 0;
	imaginar = 0;
}

complex::complex(float re,float im)
{
	real = re;
	imaginar = im;
}

int main()
{
	complex a(1,2),b(3,-4),c(1,2),d,e,f;
	d=a+b;
	cout<<d;
	cin>>e;
	cout<<e;
	cout<<a;
	cout<<b;
	cout<<f;
	return 0;
}
