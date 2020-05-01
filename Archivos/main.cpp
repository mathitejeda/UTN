#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#include "tipos.h"
#include "prototipos.h"
#include "rlutil.h"
using namespace rlutil;
#include "platos.h"
#include "menus.h"

int main (){
    int opcion,id, id_busqueda;
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
                Submenu_Platos();
                cout<< "Seleccione una opcion: ";
                cin>> opcion;
                cin.ignore();
                switch (opcion)
                {
                case 1:
                    cls();
                    nuevo_plato();
                    anykey();
                    break;
                
                case 2:
                    cls();
                    cout<< "Ingrese el ID del plato a modificar: ";
                    cin>> id;
                    cin.ignore();
                    modificacion(id);
                    anykey();
                    break;
                case 3:
                    cls();
                    cout<< "Ingrese el ID del plato a buscar: ";
                    cin>> id_busqueda;
                    cin.ignore();
                    listar_por_id(id_busqueda);
                    anykey();
                    
                    break;

                case 4:
                        cls();
                        cout<< "Ingrese el id del restaurante a buscar: ";
                        cin>>  id_busqueda;
                        cin.ignore();
                        cls();
                        listar_por_restaurante(id_busqueda);
                        anykey();
                    break;
                
                case 5:
                    cls();
                    listar_platos();
                    cin.get();
                    break;
                case 0:
                    cls();
                    cout<< "volviendo al menu principal...";
                    msleep(1000);
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
            cls();
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

