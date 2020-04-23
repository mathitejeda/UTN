#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "tipos.h"
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"
#include "menus.h"

int main (){
    int opcion;
    while (opcion!=0)
    {
        cls();
        menu_principal();
        cout<<"Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            break;
        case 0:
            cls();
            cout<< "Programa finalizado.";
            getkey();
            break;
        default:
            cls();
            cout<< "La opcion ingresada no es valida.";
            getkey();
            break;
        }

    }
    return 0;
}

