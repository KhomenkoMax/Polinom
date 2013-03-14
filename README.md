
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

#define MAX_P_LENGTH 5

class polynom
{
private:
double a[MAX_P_LENGTH];

public:
polynom() { for(int i=0;i<MAX_P_LENGTH;i++) a[i]=0.0; }


polynom(const polynom & p) {for(int i=0;i<MAX_P_LENGTH;i++) a[i]=p.a[i];}


double operator()(double x);
friend polynom operator+(polynom a, polynom b);
friend polynom operator-(polynom a, polynom b);
friend polynom operator+(polynom a, double d);
friend polynom operator+(double d, polynom a);
friend polynom operator*(polynom a, double d);
friend polynom operator*(double d, polynom a);
friend ostream& operator<<(ostream&o, polynom p);
friend istream& operator>>(istream&s, polynom&p);
};

double polynom::operator()(double x)
{
double mnozh=1;
double sum=a[MAX_P_LENGTH-1];
for (int i=MAX_P_LENGTH-2;i>=0;i--)
{
sum+=mnozh*a[i];
mnozh*=x;
}
return sum;
}


polynom operator+(polynom a, polynom b)
{
polynom p;
for(int i=0;i<MAX_P_LENGTH;i++)
p.a[i]=a.a[i]+b.a[i];
return p;
}

polynom operator-(polynom a, polynom b)
{
polynom p;
for(int i=0;i<MAX_P_LENGTH;i++)
p.a[i]=a.a[i]-b.a[i];
return p;
}

polynom operator+(polynom a, double d)
{
polynom p;
for(int i=0;i<MAX_P_LENGTH;i++)
p.a[i]=a.a[i]+d;
return p;
}

polynom operator+(double d, polynom a)
{
polynom p;
for(int i=0;i<MAX_P_LENGTH;i++)
p.a[i]=a.a[i]+d;
return p;
}

polynom operator*(polynom a, double d)
{
polynom p;
for(int i=0;i<MAX_P_LENGTH;i++)
p.a[i]=a.a[i]*d;
return p;
}

polynom operator*(double d, polynom a)
{
polynom p;
for(int i=0;i<MAX_P_LENGTH;i++)
p.a[i]=a.a[i]*d;
return p;
}

ostream& operator<<(ostream&o, polynom p)
{
bool first_el=true;
for(int i=MAX_P_LENGTH-1;i>0;i--)
if (p.a[i]!=0.0) 
{
if (!first_el) o<<"\t+ "; else first_el=false;

if (p.a[i]!=1.0) o<<p.a[i];


if(i>1) o<<"x^"<<i;
else o<<"x";
}

if (!first_el) o<<"\t+ ";
o<<p.a[0];

return o;
}

istream& operator>>(istream&s, polynom&p)
{
for(int i=0;i<MAX_P_LENGTH;i++)
{
cout<<"a["<<i<<"]=";
s>>p.a[i];
}
return s;
}


int main()
{
int n;
double x=1.0;
polynom* m;

polynom**m = new polynom*[i];


for(int i=0;i<4;i++) 
{ 
m[i] = new polynom ((rand()%1000)/100.0); 
}

polynom a,b;
double d;

cout<<"\n‚a:";
cin>>a;
cout<<"‚d (double):";
cin>>d;

cout<<"\n\n‚a:\n"<<a;
cout<<"\n * "<<d<<" =";
b=a*d;
cout<<"\n"<<b;
cout<<"\n + "<<d<<" =";
b=b+d;
cout<<"\n"<<b;
cout<<"\n - \n"<<a<<" =";
b=b-a;
cout<<"\n"<<b;

cout<<"\n‚n :";
cin>>n;
m = new polynom[n];

cout<<"\n‚¢¥¤¨â¥ x:";
cin>>x;

while(x!=0.0){
  if (x==0.0) break;
  for(int i=0;i<n;i++)
  {

    cout<<"\np"<<i<<" = "<<m[i]<<" = "<<m[i](x);

    if(m[i](x) >= m[i](x+0.001) && m[i](x) >= m[i](x-0.001)) // max
       cout<<"\tmax: "<<m[i];
     		
    if(m[i](x) <= m[i](x+0.001) && m[i](x) <= m[i](x-0.001)) // min
       cout<<"\tmin: "<<m[i];
  }
  cout<<"\n‚¢¥¤¨â¥ x:";
  cin>>x;
};

} // end of main

