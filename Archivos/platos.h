#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED

const char * PATH_PLATOS = "datos/platos.dat";

bool cargarplato(struct platos *p){
    cout<< "ID del plato: ";
    cin>> p->ID;
    int idref=buscarplato(p->ID);
    if (idref>=0) {
        cout<< "El plato ya existe."<<endl;
        return false;
    }
    cout<< "Nombre: ";
    cin>> p->nombre;
    cout << "costo de preparacion: $";
    cin >> p->costo_preparacion;
    if (p->costo_preparacion<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    cout<< "Valor de venta: $";
    cin>> p->valor_venta;
    if(p->valor_venta<p->costo_preparacion){
        cout<< "El valor de venta no puede ser menor al costo de preparacion"<<endl;
        return false;
    }
    cout<< "tiempo de preparacion: ";
    cin>> p->tiempo_preparacion;
    if (p->tiempo_preparacion<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    cout<< "ID restaurante: ";
    cin>> p->ID_restaurante;
    if (p->ID_restaurante<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    cout<< "Comision restaurante: ";
    cin>> p->comision_restaurante;
    if (p->comision_restaurante<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    cout<< "ID categoria: ";
    cin>> p->ID_categoria;
    if (p->ID_categoria<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    p->estado = true;
    cin.ignore();
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

bool modificar_plato(struct platos *mod){
    cout<< "Nombre: ";
    cin>> mod->nombre;
    cout << "costo de preparacion: $";
    cin >> mod->costo_preparacion;
    if (mod->costo_preparacion<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    cout<< "Valor de venta: $";
    cin>> mod->valor_venta;
    if(mod->valor_venta<mod->costo_preparacion){
        cout<< "El valor de venta no puede ser menor al costo de preparacion"<<endl;
        return false;
    }
    cout<< "tiempo de preparacion: ";
    cin>> mod->tiempo_preparacion;
    if (mod->tiempo_preparacion<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    cout<< "ID restaurante: ";
    cin>> mod->ID_restaurante;
    if (mod->ID_restaurante<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    cout<< "Comision restaurante: ";
    cin>> mod->comision_restaurante;
    if (mod->comision_restaurante<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    cout<< "ID categoria: ";
    cin>> mod->ID_categoria;
    if (mod->ID_categoria<0){
        cout<< "No se puede ingresar un numero negativo"<<endl;
        return false;
    }
    mod->estado = true;
    cin.ignore();
    return mod->estado;
}

void modificacion(int id){
    int pos;
    pos = buscarplato(id);
    if (pos >= 0){
        struct platos reg = leer_plato(pos);
        cout << endl;
        listarplato(reg);
        modificar_plato(&reg);
        if (sobrescribir_plato(reg, pos)){
            cout << "Producto modificado.";
        }
        else{
            cout << "No se modificó el producto.";
        }
    }
    else{
        cout << "No existe el producto.";
    }
}

bool sobrescribir_plato(struct platos reg, int pos){
    bool guardado;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, pos * sizeof(struct platos), SEEK_SET);
    guardado = fwrite(&reg, sizeof(struct platos), 1, p);
    fclose(p);
    return guardado;
}
struct platos leer_plato(int pos){
    struct platos reg;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    if (p == NULL){
        reg.ID = -1;
        return reg;
    }
    fseek(p, pos * sizeof(platos),SEEK_SET);
    fread(&reg, sizeof(platos), 1, p);
    fclose(p);
    return reg;
}

int buscarplato (int id_busqueda){
    struct platos reg;
    FILE *p;
    int i;
    p= fopen (PATH_PLATOS,"rb");
    if (p == NULL){ return -2;}
    while (fread (&reg,sizeof(platos),1,p)){ // al devolver un booleano sirve de referencia para los condicionales
        if (reg.ID == id_busqueda){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

void listarplato (struct platos show){
    cout<< "ID del plato: "<<show.ID<<endl;
    cout<< "Nombre: "<<show.nombre<<endl;
    cout << "costo de preparacion: $"<<show.costo_preparacion<<endl;
    cout<< "Valor de venta: $"<<show.valor_venta<<endl;
    cout<< "tiempo de preparacion: "<<show.tiempo_preparacion<<endl;
    cout<< "ID restaurante: "<<show.ID_restaurante<<endl;
    cout<< "Comision restaurante: "<<show.comision_restaurante<<endl;
    cout<< "ID categoria: "<<show.ID_categoria<<endl;
}

void listarporid(int id_buscado){
    int pos = buscarplato(id_buscado);
    if (pos >= 0){
        struct platos reg = leer_plato(pos);
        listarplato(reg);
        cin.get();
    }
    else{
        cout << "No existe el id buscado.";
    }
}

#endif // PLATOS_H_INCLUDED