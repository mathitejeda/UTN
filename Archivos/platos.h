#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED



void cargarplato(platos *p){
    cout<< "ID del plato: ";
    cin>> p->ID;
    cout<< "Nombre: ";
    cin>> p->nombre;
    cout << "costo de preparacion: $";
    cin >> p->costo_preparacion;
    cout<< "Valor de venta: $";
    cin>> p->valor_venta;
    cout<< "tiempo de preparacion: ";
    cin>> p->tiempo_preparacion;
    cout<< "ID restaurante: ";
    cin>> p->ID_restaurante;
    cout<< "Comision restaurante: ";
    cin>> p->comision_restaurante;
    cout<< "ID categoria: ";
    cin>> p->ID_categoria;
    p->estado = true;
}


#endif // PLATOS_H_INCLUDED