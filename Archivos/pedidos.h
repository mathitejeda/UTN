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
    cout<< "No se pudo registrar el pedido.";
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

    cout << "Fecha pedido: ";
    cout << "Dia: ";
    cin >> reg->fecha_pedido.dia;
    cout << "Mes: ";
    cin >> reg->fecha_pedido.mes;
    cout << "Año: ";
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

#endif //PEDIDOS_H_INCLUDED