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
#include "clientes.h"
#include "pedidos.h"
#include "configuracion.h"
#include "menus.h"

int main (){
    int opcion,id, id_busqueda;
    bool salir;
    struct platos plato;
    struct clientes cliente;
    struct pedidos pedido;
    while (!salir)
    {
        cls();
        menu_principal();
        cout<<"Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1: // Menu de platos
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
                    listar_platos_dinamico();
                    anykey();
                    break;

                case 6:
                    cls();
                    cout << "Ingrese el id del plato que desea eliminar: ";
                    cin >> id;
                    cin.ignore();
                    eliminar_plato(id);
                    anykey();
                    break;

                case 0:
                    cls();
                    msleep(1000);
                    cout<< "volviendo al menu principal...";
                    break;
                default:
                    cls();
                    cout<< "Opcion invalida";
                    anykey();
                    break;
                }
            } // final menu de platos
            break;
        
        case 2: // Menu de clientes
            while(opcion!=0){
            cls();
            submenu_clientes();
            cout<< "Seleccione una opcion: ";
            cin>> opcion;
            cin.ignore();
            switch (opcion)
            {
            case 1:
                cls();
                nuevo_cliente();
                anykey();
                break;
            
            case 2:
                cls();
                cout<< "Ingrese el Id del cliente que desea modificar: ";
                cin>> id;
                cin.ignore();
                modificacion_cliente(id);
                anykey();
                break;

            case 3:
                cls();
                cout<< "Ingrese el id del cliente que desea visualizar: ";
                cin >> id;
                cin.ignore();
                listar_cliente_id(id);
                anykey();
                break;
            case 4:
                cls();
                listar_clientes();
                anykey();
                break;
            
            case 5:
                cls();
                cout << "Ingrese el id del cliente que desea eliminar: ";
                cin >> id;
                eliminar_cliente(id);
                anykey();
                break;
            
            case 0:
                cout << "Volviendo al menu principal";
                msleep (1000);
                break;
            
            default:
                cout << "Opcion invalida.";
                anykey();
                break;
            }
            }
            break;
        case 3: //Menu de pedidos
            while (opcion != 0){
            cls();
            submenu_pedidos();
            cout<< "Seleccione una opcion: ";
            cin>> opcion;
            cin.ignore();
            switch (opcion){
            case 1:    
                cls ();
                nuevo_pedido();
                anykey();
                break;
            
            case 2:
                cls ();
                cout<< "Ingrese el id del pedido a modificar: ";
                cin >> id;
                cin.ignore();
                modificar_pedido(id);
                anykey();
                break;

            case 3:
                cls(); 
                cout << "Ingrese el id del pedido que desea ver: ";
                cin >> id;
                listar_pedido_id(id);
                anykey();
                break;

            case 4:
                cls();
                listar_pedidos();
                anykey();
                break;

            case 0:
                cout << "Volviendo al menu principal";
                msleep (1000);
                break;
            
            default:
                cout << "Opcion invalida.";
                anykey();
                break;

            }//E O switch
            
            } 
            break;
        case 4:
            cls();
            cout << "Noting to se here.";
            anykey();
            break;

        case 5:
            while(opcion != 0){          
            cls();
            submenu_configuracion();
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion)
            {
            case 1:
                cls();
                crear_backup();
                anykey();
                break;

            case 2:
                cls();
                restaurar_backup();
                anykey();
                break;

            case 0:
                cout << "Volviendo al menu principal";
                msleep (1000);
                break;
            default:
                cls();
                cout << "Opcion invalida";
                break;
            }
            }

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

