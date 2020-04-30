#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "tipos.h"
#include "prototipos.h"
#include "rlutil.h"
using namespace rlutil;
#include "platos.h"
#include "menus.h"

int main (){
    int opcion;
    bool salir;
    struct platos plato;
    while (!salir)
    {
        cls();
        menu_principal();
        cout<<"Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            while(opcion!=0){
                cls();
                SubmenuPlatos();
                cout<< "Seleccione una opcion: ";
                cin>> opcion;
                cin.ignore();
                switch (opcion)
                {
                case 1:
                    cls();
                    nuevoplato();
                    anykey();
                    break;
                
                case 2:
                    break;
                case 3:
                    cls();
                    int id;
                    cout<< "Ingrese el ID del plato a buscar: ";
                    cin>> id;
                    listarporid(id);
                    anykey();
                    
                    break;
                case 0:
                    cls();
                    cout<< "volviendo al menu principal...";
                    msleep(500);
                    break;
                default:
                    cls();
                    cout<< "Opcion invalida";
                    anykey();
                    break;
                }
            } // final menu de platos
            break;
        case 0:
            cls();
            salir=true;
            cout<< "Programa finalizado.";
            anykey();
            break;
        default:
            cls();
            cout<< "La opcion ingresada no es valida.";
            anykey();
            break;
        }

    }
    return 0;
}

