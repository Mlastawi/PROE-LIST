#include <iostream>
#include "Lista.hpp"
#include "Wezel.hpp"

using namespace std;

int main()
{
    cout << "Poczatek programu" << endl;
    Lista<int> nowaLista( 5 );

    for( int i = 0; i < 9; i++)
        nowaLista.dodajWartosc( i );

    for( int i = 0; i < 9; i++)
        cout << "element na pozycji " <<  i << " ma wartosc " << nowaLista[i] << endl;

    cout << nowaLista.getWielkosc() << endl << endl;

    /*nowaLista.usunWezel();
    nowaLista.usunWezel();
    nowaLista.usunWezel();
    nowaLista.usunWezel();*/

    return 0;
}
