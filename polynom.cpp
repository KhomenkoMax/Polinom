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
 
        polynom &operator=(const polynom &Object); // Ïåðåãðóçêà =
        polynom operator+(polynom &);    // Ñóìà
        polynom operator-(polynom &);    // Ð³çíèöÿ
        polynom operator*(polynom &);    // Ìíîæåííÿ
 
        // Ïåðåãðóçêà îïåðàòîðà << äëÿ âèâîäà
        friend ostream &operator<<(ostream &, polynom &);
        // Ïåðåãðóçêà îïåðàòîðà >> äëÿ ââîäà ìàòðèö³(ìàñèâó)
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
 
 
// Ïåðåãðóçêà îïåðàòîðà =
polynom& polynom::operator=(const polynom &Object)
{
    n = Object.n;
          delete []x;
    x=new double[n+1];
    for(int i=0;i<=n;)x[i++]=Object.x[i];
    return *this;
}
 
// Ïåðåãðóçêà îïåðàòîðà +
polynom polynom::operator+(polynom &fp1)
{
    polynom ret;
    ret=(n>fp1.n)?*this:fp1;
    int minind=(n>fp1.n)?fp1.n:n;
 
    for(int i=0;i<=minind;ret.x[i++]+=x[i]);
 
    return ret;
}
 
// Ïåðåãðóçêà îïåðàòîðà -
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
 
// Ïåðåãðóçêà îïåðàòîðà *
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
 
// Ïåðåãðóçêà îïåðàòîðà >>
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
 
// Ïåðåãðóçêà îïåðàòîðà <<
ostream &operator<<(ostream &fo, polynom &fp)
{
 
    for(int i=0;i<=fp.n;i+=1) fo <<"x["<<i<<"]="<<int(fp.x[i])<<endl;
    return fo;
}
 //Çíàõîäæåííÿ ³íòåãðàëó â³ä ïîë³íîìà
polynom integrate(const int koefs, const int deg)
{double mas1[100]; 
 double mas2[100];
 double mas3[100];
 int n;
for(int i=0;i<=koefs;i++)
{mas1[i]=koefs;
  mas2[i+1]=mas1[i];
  }
  for(int i=0;i<=deg;i++)
  { mas3[i]=mas2[i]/mas1[i-1];
  }
      n=deg+1;                             

  cout<<"%lf"<<mas3<<endl;
     
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
    m1.~polynom();
    m2.~polynom();
    m3.~polynom();        
}
                                        
