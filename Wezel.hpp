#ifndef WEZEL_H
#define WEZEL_H

#include <iostream>

using namespace std;

template <typename T>
class Wezel
{
private:
    T *wartosc; //tablica elementow typu T
    Wezel* nastepny; //wskaünik na nastepny wezel
    int wielkosc; //wielkosc tablicy
    int ostatnioDodany; //indeks ostatnio dodanego elementu
public:
    Wezel( T );
    ~Wezel();

    T getWartosc( int index ) const { return wartosc[index]; }
    void setWartosc( int index, T val ) { wartosc[index] = val; }
    int getWielkosc( ) const { return wielkosc; }
    void setWielkosc( int val ) { wielkosc = val; }
    Wezel* getNastepny() const { return nastepny; }
    void setNastepny( Wezel* val ) { nastepny = val; }


    int getOstatnioDodany() const { return ostatnioDodany; }
    void setOstatnioDodany( int war ) { ostatnioDodany = war; }
    void dodajWartosc( T );
};

template <typename T>
Wezel<T>::Wezel( T wielk ) : wielkosc(wielk), nastepny( nullptr ), ostatnioDodany(-1)
{
    wartosc = new T[wielkosc];
    for( int i = 0; i< wielkosc; i++ )
        wartosc[i] = 0;
    cout << "Utworzono element o wartosci " << wartosc << endl;
}

template <typename T>
Wezel<T>::~Wezel()
{
    delete nastepny;
    cout << "Usunieto element o wartosci " << wartosc << endl;
}

template <typename T>
void Wezel<T>::dodajWartosc( T war )
{
    ++ostatnioDodany;
    wartosc[ostatnioDodany] = war;
    cout << "element na pozycji " << ostatnioDodany << " dostal wartosc rowna " << war << endl;
}



#endif // WEZEL_H
