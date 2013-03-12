Polinom
=======

Klass Polinom(C++)
#include <cstdlib>
#include <iostream>
class Polinom
{protected:
     int deg;//степінь полінома
     double*koef; //вказівник на масив коефіцієнтів полінома
                  //koef[i] - коєфіцієнт при i-й степені,
                  //koef[0] - коєфіцієнт при нульовій степені  
 Public:
        Polinom();//онструктор без параметрів
        Polinom(int newDeg, double*newKoef);
        Polynom(const Polynom &); //копіюючий контсруктор
    ~Polynom(); //деструктор 
    int getDeg(); //функція отримання степеня полінома
    double getKoef(); //функція отримання коефіцієнта при i-ому степені
    void setKoef(double*newKoef); //функція задання коєфіцієнта при i-ому  
    void setDeg(int newDeg);              //степені, повертає степінь полінома
    Polynom operator + (const Polynom &);   //оператор суми двох поліномів
    Polynom operator = (const Polynom &);   //оператор присвоювання
    friend Polynom MultConst(double, Polynom &); //функція добутку полінома
                                     //на константу
    void InputPolynom();    //функція ввода полінома
    void OutputPolynom();   //функція вивода полінома
      };
    //конструктр без параметрів: створює поліном нульового степеня
    //з коефіцієнтом при ннульовому степені рівним нулю
    Polynom::Polynom()
    {
    deg=0;
    koef=newKoef[deg+1];
    koef[0]=0.0;
    //Конструктор з параметрами 
    //enewDeg - степінь створюваного полінома
    //newKoef - drfpsdybr yf newDeg+1 - елементний масив з коефіцієнтами
    //полінома де newKoef[i] - коефіцієнт при і-ому степені
    //  newkoef[0] - коефіцієнт при нульовому степені
    // в результаті степінь полінома буде найбільшим номером нульового елемента 
    //масива newKoef і менший або рівний newDeg(за означенням полінома
    Polynom::Polynom( int newВg, double *newKoef)
    {
    deg=0;
    for(int i=0;i<=newDeg;i++)
        if(newKoef[i]!=0) 
        deg=i;//ініціалізація змінної степеня
    koef=newKoef[i+1];
    for(i=0;i<=deg;i++)
        koef[i]=newKoef[i]; //ініціалізація масиву коефіцієнтів
}
}

using namespace std;

int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}
