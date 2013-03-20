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
 
        polynom &operator=(const polynom &Object); // Перегрузка =
        polynom operator+(polynom &);    // Сума
        polynom operator-(polynom &);    // Різниця
        polynom operator*(polynom &);    // Множення
 
        // Перегрузка оператора << для вивода
        friend ostream &operator<<(ostream &, polynom &);
        // Перегрузка оператора >> для ввода матриці(масиву)
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
 
// Перегрузка оператора +
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
 
// Перегрузка оператора *
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
 
// Перегрузка оператора >>
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
    cout<<"Vilniy koeficient dobutku m1 і m2: "<<m3.cs()<<endl;
    m1.~polynom();
    m2.~polynom();
    m3.~polynom();        
}
