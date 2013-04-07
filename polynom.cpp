#include <iostream>
#include <conio.h>
#include <math.h>
#include <malloc.h>

using namespace std;
class polynom
{
    private:
        int n;
        double *x;
    public:
        polynom();
        ~polynom();
        polynom(int n,double *x);
        double cs();
 
        polynom &operator=(const polynom &Object); //Перегрузка=
        polynom operator+(polynom &);    // Сума
        polynom operator-(polynom &);    // Різниця
        polynom operator*(polynom &);    // Добуток
		polynom integrate()
 
        // Перегрузка оператора << для вивода 
        friend ostream &operator<<(ostream &, polynom &);
        // Перегрузка оператора >> для ввода масиву
        friend istream &operator>>(istream &, polynom &);
 
};
 
polynom::polynom(int nn,double *xx)
{
    unsigned char i;
    n=nn;
    x=new double[n+1];
    for(i=0;i<=n;x[i++]=xx[i]);
}
 
polynom::polynom()
{
    double x[1]={0};
    polynom::polynom(0,x);
}
 
polynom::~polynom()
{
    delete []x;
}
 
double polynom::cs()
{
    return x[0];
}
 
 
// Перегрузка оператора =
polynom& polynom::operator=(const polynom &Object)
{
    n = Object.n;
          delete []x;
    x=new double[n+1];
    for(int i=0;i<=n;)x[i++]=Object.x[i];
    return *this;
}
 
// Перегрузкаоператора +
polynom polynom::operator+(polynom &fp1)
{
    polynom ret;
    ret=(n>fp1.n)?*this:fp1;
    int minind=(n>fp1.n)?fp1.n:n;
 
    for(int i=0;i<=minind;ret.x[i++]+=x[i]);
 
    return ret;
}
 
// Перегрузка оператора -
polynom polynom::operator-(polynom &fp1)
{
    polynom ret;
    int i;
    ret=(n>fp1.n)?*this:fp1;
    if(fp1.n>n) for(i=n;i<=ret.n;ret.x[i++]=-ret.x[i]);
    int minind=(n>fp1.n)?fp1.n:n;
 
    for(i=0;i<=minind;ret.x[i++]=x[i]-fp1.x[i]);
    return ret;
 
}
 
//Перегрузка оператора *
polynom polynom::operator*(polynom &fp1)
{
    int newindex=fp1.n+n;
    double *empty=new double[newindex+1];
    for(int i=0;i<=newindex;empty[i++]=0);
 
    polynom ret(newindex,empty);
 
    for(int i=0;i<=fp1.n;i+=1)
        for(int j=0;j<=n;j+=1) ret.x[i+j]+=fp1.x[i]*x[j];
 
    return ret;
 
}
 
// Перегрузка оператора  >>
istream &operator>>(istream &fi, polynom &fp)
{
    cout<<"n=";
    fi >> fp.n;
 
    delete []fp.x;
    fp.x=new double[fp.n+1];
    for(int i=0;i<=fp.n;)
    {
        cout<<"x["<<i<<"]=";
        fi >> fp.x[i++];
 
    }
 
    return fi;
}
 
// Перегрузка оператора <<
ostream &operator<<(ostream &fo, polynom &fp)
{
 
    for(int i=0;i<=fp.n;i+=1) fo <<"x["<<i<<"]="<<int(fp.x[i])<<endl;
    return fo;
}
 //Знаходження інтегралу від многочлена
polynom integrate(const int koefs, const int deg)
{double mas1[100]; 
 double mas2[100];
 double mas3[100];
 int n;
for(int i=0;i<=koefs;i++)
{mas1[i]=koefs[i];
  mas2[i+1]=mas1[i];
  }
  for(int i=0;i<=deg;i++)
  { mas3[i]=mas2[i]/(i-1);// /mas1[i-1];
  }
      n=deg+1;                             

  cout<<"%lf"<<mas3<<endl;
     
}

polynom polynom::integrate()
{double mas1[100]; 
 double mas2[100];
 double mas3[100];
 //int n;
for(int i=0;i<=n;i++)
{mas1[i]=x[i];
  mas2[i+1]=mas1[i];
  }
  for(int i=0;i<=n;i++)
  { mas3[i]=mas2[i]/(i-1);// /mas1[i-1];
    x[i]=mas3[i];
  }
      n++;                             

//  cout<<"%lf"<<mas3<<endl;
     
}

int main(int argc, char *argv[])
{
    double x[]={6,3,8};
 
    polynom m1(2,x);
    cout<<"Pershiy polinom:"<<endl;
    cout<<m1<<endl;
    cout<<"Vvedit drugiy polinom:"<<endl;
    polynom m2;
    cin>>m2;
    polynom m3;
    m3=m1+m2;
    cout<<endl<<"Suma m1 and m2:"<< endl<<m3<<endl;
 getch();
    m3=m1-m2;
   cout<<"Riznitsya m1 and m2:"<<endl<<m3<<endl;
    getch();
    m3=m1*m2;
    cout<<"Dobutok m1 and m2:"<<endl<<m3<<endl;
    getch();
    cout<<"Vilniy koeficient dobutku m1 ³ m2: "<<m3.cs()<<endl;
    cout<<"Integral ot  m1 :"<<endl<<m1.integrate()<<endl;
    getch();
    
	
    m1.~polynom();
    m2.~polynom();
    m3.~polynom(); 
    
system("PAUSE");
    return EXIT_SUCCESS;
}
                           
                                        
