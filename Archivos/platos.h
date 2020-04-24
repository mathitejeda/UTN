#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED

const char * PATH_PLATOS = "datos/platos.dat";

bool cargarplato(struct platos *p){
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
    
    return p->estado;
}

bool guardarplato (struct platos reg){
    bool guardado;
    FILE *p;
    p=fopen(PATH_PLATOS, "ab");
    if (p == NULL){
        return false;
    }
    guardado = fwrite (&reg, sizeof(platos),1,p);
    fclose(p);
    return guardado;
}
void nuevoplato (){
    struct platos reg;
    if (cargarplato(&reg)){
        if (guardarplato(reg)){
            cout << "Plato guardado correctamente";
        }
        else {cout << "No se pudo guardar el plato en el archivo.";}
    }
    else {cout << "No se pudo guardar el plato";}
}

#endif // PLATOS_H_INCLUDED