#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void menu_principal()
{
cout << "MENU PRINCIPAL       "<<endl;
cout << "---------------------"<<endl;
cout << "1) PLATOS            "<<endl;
cout << "2) CLIENTES          "<<endl;
cout << "3) PEDIDOS           "<<endl;
cout << "4) REPORTES          "<<endl;
cout << "5) CONFIGURACION     "<<endl;
cout << "---------------------"<<endl;
cout << "0) SALIR DEL PROGRAMA"<<endl;
}

void Submenu_Platos (){
    
cout<<"MENU DE PLATOS"<<endl;
cout<<"---------------------------"<<endl;
cout<<"1) NUEVO PLATO"<<endl;
cout<<"2) MODIFICAR PLATO"<<endl;
cout<<"3) LISTAR PLATO POR ID"<<endl;
cout<<"4) PLATOS POR RESTAURANTE"<<endl;
cout<<"5) LISTAR TODOS LOS PLATOS"<<endl;
cout<<"6) ELIMINAR PLATO"<<endl;
cout<<"---------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;


}

#endif // MENUS_H_INCLUDED