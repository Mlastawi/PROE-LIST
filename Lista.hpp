#ifndef LISTA_H
#define LISTA_H
#include "Wezel.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

//wzorzec Listy zawieraj¹cej elementy typu T
template <typename T>
class Lista
{
private:
    int wielkosc; //wielkosc wezla
    Wezel<T>* pierwszy; //wskaznik na pierwszy wezel
    Wezel<T>* ostatni; //wskaznik na ostatni wezel

public:
    Lista( int );
    ~Lista();

    Wezel<T>* getPierwszy() const { return pierwszy; }
    Wezel<T>* getOstatni() const { return ostatni; }
    int getWielkosc() const { return wielkosc; }
    void setWielkosc( int val ) { wielkosc = val; }

    T& operator[]( int );

    void utworzWezel( T );
    void dodajWartosc( T );

    void ustawWartosc( int, T );
    void usunWezel( int = -1 );



    class Blad{};
    class BladOdczytu : public Blad{};
    class BladZapisu : public Blad{};
};

template <typename T>
T& Lista<T>::operator[]( int indeks )
{
    T zwracany;
    Wezel<T>* temp = pierwszy;
    zwracany = temp -> getWartosc( 0 );
    try
    {
        if( indeks < 0 )
            throw BladOdczytu();
        for( int i = 0; i < indeks; i++ )
        {
            if( temp == nullptr )
                throw BladOdczytu();
            else if( i >= temp -> getWielkosc() - 1 )
            {
                indeks -= temp -> getWielkosc();
                i -= temp -> getWielkosc();
                temp = temp -> getNastepny();
                if( temp == nullptr )
                    throw BladOdczytu();
                zwracany = temp -> getWartosc( 0 );
            }
            else
            {
                zwracany = temp -> getWartosc( i );
            }
        }
        return zwracany;
    }
    catch( BladOdczytu& nr )
    {
        cout << "Element na podanym indeksie nie istnieje. Program zakonczy prace!" << endl;
        exit(1);
    }
}

template <typename T>
Lista<T>::Lista( int war ) : wielkosc( war ), pierwszy( nullptr ), ostatni( nullptr )
{
        utworzWezel( war );
    cout << "Utworzono liste o rozmiarze " << wielkosc << endl;
}

template <typename T>
Lista<T>::~Lista()
{
    delete pierwszy;
    cout << "Usunieto liste o rozmiarze " << wielkosc << endl;
}

template <typename T>
void Lista<T>::utworzWezel( T wielk )
{

    if( pierwszy == nullptr )
    {
        pierwszy = new Wezel<T>( wielk );
        ostatni = pierwszy;
    }
    else
    {
        ostatni -> setNastepny( new Wezel<T>( wielk ) );
        ostatni = ostatni -> getNastepny();
    }
}
template <typename T>
void Lista<T>::dodajWartosc( T war )
{
    if ( ostatni -> getOstatnioDodany() >= ostatni -> getWielkosc() )
    {
        ostatni -> setNastepny( new Wezel<T>( ostatni -> getWielkosc() ) );
        ostatni = ostatni -> getNastepny();
        ostatni -> dodajWartosc( war );
    }
    else
        ostatni -> dodajWartosc( war );
}

template <typename T>
void Lista<T>::usunWezel( int index ){
    if( index == -1 || index == wielkosc )
        {
            Wezel<T>& temp = (*this)[wielkosc-2];
            Wezel<T>& temp2 = (*this)[wielkosc-1];
            delete &temp2;
            --wielkosc;
            temp.setNastepny(nullptr);
        }
    else if( index == 0)
    {
        Wezel<T>& temp = (*this)[1];
        pierwszy -> setNastepny(nullptr);
        delete pierwszy;
        --wielkosc;
        pierwszy = &temp;
    }
    else
    {
        Wezel<T>& temp = (*this)[index-1];
        Wezel<T>& temp2 = (*this)[index];

        temp.setNastepny( temp2.getNastepny() );

        temp2.setNastepny(nullptr);
        delete &temp2;

    }
}
#endif // LISTA_H
