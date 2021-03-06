#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

const char *PATH_PEDIDOS = "datos/pedidos.dat";

// Funciones principales

void nuevo_pedido (){
    struct pedidos nuevo;
    if (cargar_pedido(&nuevo)){
        if (guardar_pedido(nuevo)) cout<< "pedido registrado con el id: "<< nuevo.ID;
        else cout<< "No se pudo guardar el pedido.";
    }
    else cout<< "No se pudo registrar el pedido.";
}

void modificar_pedido(int id){
    int pos;
    pos = buscar_pedido(id);
    if (pos >=0){
        struct pedidos mod = leer_pedido (pos);
        listar_pedido (mod);
        cout << endl;
        cout << "Ingrese el nuevo estado para el pedido: ";
        cin  >> mod.estado;

        if (sobreescribir_pedido(mod,pos)){
            cout << "Estado modificado correctamente";
        }
        else cout << "No se pudo modificar el estado";

    }
    else cout << "No existe el pedido";
}

void listar_pedido_id (int id){
    int pos = buscar_pedido(id);
    if (pos > 0 ){
        struct pedidos listar = leer_pedido(pos);
        listar_pedido(listar);
    }
    else cout<< "No existe el id buscado. ";
}

void listar_pedidos (){

    int cantidad=cantidad_pedidos();
    if (cantidad == 0){
        cout<< "No hay pedidos";
        return;
    }

    struct pedidos *vec;
    vec=(struct pedidos *) malloc (cantidad*sizeof(pedidos));
    if (vec== NULL ){
        cout << "No hay memoria para continuar";
        return;
    }
    FILE *p;
    p=fopen(PATH_PEDIDOS, "rb");
    if (p== NULL){
        free(vec);
        cout<< "No existe el archivo";
        return;
    }
    fread(&vec[0],sizeof(pedidos),cantidad,p);
    fclose(p);

    ordenar_pedidos(vec,cantidad);

    for (int i=0;i<cantidad;i++){
        listar_pedido(vec[i]);
        cout<<endl;
    }
    free (vec);

}
// Funciones auxiliares

int buscar_pedido (int id_busqueda){
    struct pedidos search;
    FILE *p;
    int i=0;
    p= fopen (PATH_PEDIDOS,"rb");
    if (p == NULL){ return -2;}
    while (fread (&search,sizeof(pedidos),1,p)){
        if (search.ID == id_busqueda && search.estado==true){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

int cantidad_pedidos (){
    int bytes, cantidad;
    FILE * p;
    p = fopen(PATH_PEDIDOS, "rb");
    if (p == NULL) return 0;
    fseek (p,0,SEEK_END);
    bytes = ftell (p);
    cantidad = bytes / sizeof(pedidos);
    fclose (p);
    return cantidad;
}

bool cargar_pedido(struct pedidos *reg){
    reg->ID= cantidad_pedidos() + 1;
    cout << "*ID de cliente: ";
    cin >> reg->ID_cliente;
    if (buscar_cliente(reg->ID_cliente) < 0) {
        cout << "No existe el cliente";
        return false;
    }
    
    cout << "*ID del plato: ";
    cin >> reg->ID_plato;
    if (buscar_plato(reg->ID_plato) < 0){
        cout << "El plato ingresado no existe";
        return false;
    }
    
    cout << "*Cantidad: ";
    cin >> reg->cantidad;
    if (reg->cantidad<=0){
        cout << "No se puede ingresar un numero menor a cero";
        return false;
    }
    
    cout << "*Precio unitario: ";
    cin >> reg->precio_unitario;
    float valor_venta = consultar_precio (reg->ID_plato);
    if (reg->precio_unitario !=  valor_venta){
        cout << "El precio unitario no puede ser diferente al valor de venta.";
        return false;
    }

    cout << "Fecha pedido: "<<endl;
    cout << "Dia: ";
    cin >> reg->fecha_pedido.dia;
    cout << "Mes: ";
    cin >> reg->fecha_pedido.mes;
    cout << "Anio: ";
    cin >> reg->fecha_pedido.anio;

    if (!validar_fecha (reg->fecha_pedido.dia,reg->fecha_pedido.mes,reg->fecha_pedido.anio)){
        cout << "Fecha invalida";
        return false;
    }
    cout << "Valoracion: ";
    cin >> reg->valoracion;
    if (reg->valoracion < 0 || reg->valoracion >10){
        cout << "La valoracion debe ser un numero entre 0 y 10";
        return false;
    }
    reg->estado = 1;

    return true;
}

bool guardar_pedido (struct pedidos save){
    bool guardado;
    FILE *p;
    p=fopen (PATH_PEDIDOS,"ab");
    if (p==NULL) return false;
    guardado = fwrite (&save, sizeof(pedidos),1,p);
    fclose (p);
    return guardado;
}

float consultar_precio (int id){
    int pos = buscar_plato (id);
    struct platos precio = leer_plato(pos);

    return precio.valor_venta;
}

struct pedidos leer_pedido (int pos){
    struct pedidos read;
    FILE *p;
    p= fopen (PATH_PEDIDOS,"rb");
    if (p == NULL ) {
        read.ID=-1;
        return read;
        
    }
    fseek(p, pos * sizeof(pedidos),SEEK_SET);
    fread(&read, sizeof(pedidos), 1, p);
    fclose(p);
    return read;
}

void listar_pedido(struct pedidos show){
    cout << "*ID: "<< show.ID<<endl;
    cout << "*ID de cliente: "<< show.ID_cliente<<endl;
    cout << "*ID de plato: "<< show.ID_plato<<endl;
    cout << "*Precio unitario: $"<<show.precio_unitario<<endl;
    cout << "*Valoracion: "<<show.valoracion<<"/10"<<endl;
    cout << "*Pedido realizado el: "<<show.fecha_pedido.dia<<"/"<<show.fecha_pedido.mes<<"/"<<show.fecha_pedido.anio<<endl;
    cout << "*Estado: "<< show.estado<<endl;
}

bool sobreescribir_pedido (struct pedidos mod, int pos){
    bool guardado;
    FILE *p;
    p=fopen (PATH_PEDIDOS,"rb+");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(struct pedidos), SEEK_SET);
    guardado = fwrite(&mod, sizeof(struct pedidos), 1, p);
    fclose(p);
    return guardado;
}

void ordenar_pedidos(struct pedidos *vec, int tam){
  int i, j, pos;
  struct pedidos aux;

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
#endif //PEDIDOS_H_INCLUDED