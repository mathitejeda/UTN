#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED

const char * PATH_PLATOS = "datos/platos.dat";

int cantidad_platos (){
    int cant,bytes;
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p,0,SEEK_END);
    bytes = ftell(p);
    cant= bytes / sizeof(platos);
    fclose(p);
    return cant;
}

bool cargar_plato(struct platos *p){
    cout<< "ID del plato: ";
    cin>> p->ID;
    int idref=buscar_plato(p->ID);
    if (idref>=0) {
        cout<< "El plato ya existe."<<endl;
        return false;
    }
    cin.ignore();
    cout<< "Nombre: ";
    cin.getline(p->nombre, 30);
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

bool guardar_plato (struct platos reg){
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

void nuevo_plato (){
    struct platos reg;
    if (cargar_plato(&reg)){
        if (guardar_plato(reg)){
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
    pos = buscar_plato(id);
    if (pos >= 0){
        struct platos reg = leer_plato(pos);
        cout << endl;
        listar_plato(reg);
        cout<<endl;
        if (modificar_plato(&reg)){
        if (sobrescribir_plato(reg, pos)){
            cout << "plato modificado.";
        }
        else{cout << "No se modificó el plato.";}
        }
    }
    else{
        cout << "No existe el plato.";
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

int buscar_plato (int id_busqueda){
    struct platos reg;
    FILE *p;
    int i=0;
    p= fopen (PATH_PLATOS,"rb");
    if (p == NULL){ return -2;}
    while (fread (&reg,sizeof(platos),1,p)){ // al devolver un booleano sirve de referencia para los condicionales
        if (reg.ID == id_busqueda && reg.estado==true){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

bool buscar_restaurante (int id_restaurante){
    struct platos reg;
    FILE *p;
    int i=0;
    p= fopen(PATH_PLATOS,"rb");
    while (fread(&reg,sizeof(platos),1,p)){
        if (reg.ID_restaurante == id_restaurante){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

void listar_plato (struct platos show){
    if  (show.estado==true){
    cout<< "ID del plato: "<<show.ID<<endl;
    cout<< "Nombre: "<<show.nombre<<endl;
    cout << "costo de preparacion: $"<<show.costo_preparacion<<endl;
    cout<< "Valor de venta: $"<<show.valor_venta<<endl;
    cout<< "tiempo de preparacion: "<<show.tiempo_preparacion<<endl;
    cout<< "ID restaurante: "<<show.ID_restaurante<<endl;
    cout<< "Comision restaurante: "<<show.comision_restaurante<<endl;
    cout<< "ID categoria: "<<show.ID_categoria<<endl;
    }
}

void listar_por_id(int id_buscado){
    int pos = buscar_plato(id_buscado);
    if (pos >= 0){
        struct platos reg = leer_plato(pos);
        listar_plato(reg);
    }
    else{
        cout << "No existe el id buscado.";
    }
}

void listar_por_restaurante(int id_restaurante){
    struct platos reg;
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL){
        return;
    }
    if (!buscar_restaurante(id_restaurante)){
        cout<< "El restaurante no existe o no fue ingresado";
        fclose(p);
        return;
    }
    else {
    while (fread(&reg,sizeof(platos),1,p)){
        if (reg.ID_restaurante==id_restaurante)
        {
            listar_plato(reg);
            cout<<endl;
            cout<< "---------------------------------"<<endl;

        }
    }
    }
    fclose (p);
}

void listar_platos(){
    FILE *p;

    struct platos reg;

    p=fopen(PATH_PLATOS,"rb");

    if (p == NULL){return;}

    for (int i=0;i<cantidad_platos();i++)
    {
        reg=leer_plato(i);
        listar_plato(reg);
        cout<<endl;
        cout<< "---------------------------------"<<endl;
        anykey();
    }

    fclose(p);
}

void ordenar_platos(struct platos *vec, int tam){
  int i, j, pos;
  platos aux;

  for(i=0; i<tam-1; i++){
    pos = i;
    for(j= i+1; j<tam; j++){
      if (vec[j].ID < vec[pos].ID){
        pos = j;
      }
    }
    aux = vec[i];
    vec[i] = vec[pos];
    vec[pos] = aux;
  }
}

void listar_platos_dinamico (){

    int cantidad=cantidad_platos();
    if (cantidad==0){
        cout<< "No hay productos";
        return;
    }

    struct platos *vec;
    vec=(struct platos *) malloc (cantidad*sizeof(platos));
    if (vec== NULL ){
        cout << "No hay memoria para continuar";
        return;
    }
    FILE *p;
    p=fopen(PATH_PLATOS, "rb");
    if (p== NULL){
        free(vec);
        cout<< "No existe el archivo";
        return;
    }
    fread(&vec[0],sizeof(platos),cantidad,p);
    fclose(p);

    ordenar_platos(vec,cantidad);

    for (int i=0;i<cantidad;i++){
        listar_plato(vec[i]);
        cout<<endl;
        anykey();
    }
    free (vec);

}

void eliminar_plato (int id){
    int pos;
    char sel;
    pos = buscar_plato(id);
    if (pos >= 0){
        struct platos reg = leer_plato(pos);
        cout << endl;
        listar_plato(reg);
        cout << endl;
        cout<< "Seguro quiere eliminar el plato? [s/n]: ";
        cin >> sel;
        cin.ignore();
        cls();
        switch (sel)
        {
        case 's':
        case 'S':
                reg.estado=false;
                if (sobrescribir_plato(reg,pos)){
                    cout << "Plato eliminado";
                }
                else {cout<< "Ocurrio un error al eliminar el plato";}
            break;
        case 'n':
        case 'N':
            cout<< "No se eliminara el plato";
            return;
            break;        
        default:
            cout << "Opcion invalida.";
            break;
        }
    }
}
#endif // PLATOS_H_INCLUDED