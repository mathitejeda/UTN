#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

const char *PATH_BCLIENTES = "datos/clientes.bkp";
const char *PATH_BPLATOS = "datos/platos.bkp";
const char *PATH_BPEDIDOS = "datos/pedidos.bkp";

//Funciones principales

void crear_backup()
{
    if (!emptiness_verifier())
    {
        cout << "No hay archivos. ";
        return;
    }
    struct platos platos_bkp;
    struct clientes clientes_bkp;
    struct pedidos pedidos_bkp;

    if (backup_platos(&platos_bkp) && backup_clientes(&clientes_bkp) && backup_pedidos(&pedidos_bkp)) cout << "Backup creado exitosamente!.";
    else cout << "No se pudo crear el backup";
}

void restaurar_backup()
{
    char sel;
    if (!is_a_backup_there())
    {
        cout << "No hay ningun backup creado. ";
        return;
    }
    struct platos res_platos;
    struct clientes res_clientes;
    struct pedidos res_pedidos;

    cout << "Esta accion eliminara todo lo que haya cargado luedo de crear el ultimo backup!"<<endl;
    cout<< "Desea continuar? [s/n]: ";
    cin >> sel;
    switch (sel)
    {
    case 's': case 'S':
        cls();
        if (restaurar_platos(&res_platos) && restaurar_clientes(&res_clientes) && restaurar_pedidos(&res_pedidos)) cout << "Backup recuperado exitosamente!.";
        else cout << "No se pudo recuperar el backup";
        break;
    case 'n': case 'N':
        cls();
        cout << "No se recuperara el backup.";
        break;
    default:
        cls();
        cout << "Opcion invalida.";
        break;
    }

}

//Funciones auxiliares

bool emptiness_verifier()
{
    int contador = 0;
    if (cantidad_platos() == 0)
        contador++;
    if (cantidad_clientes() == 0)
        contador++;
    if (cantidad_pedidos() == 0)
        contador++;

    if (contador == 3)
        return false;
    else
        return true;
}

bool is_a_backup_there (){
    FILE *p;

    p=fopen(PATH_BPLATOS,"rb");
    if (p == NULL) return false;
    else fclose (p);

    p=fopen(PATH_BCLIENTES,"rb");
    if (p == NULL) return false;
    else fclose (p);

    p=fopen(PATH_BPEDIDOS,"rb");
    if (p == NULL) return false;
    else fclose (p);
    
    return true;
}

bool backup_platos(struct platos *platos_bkp)
{
    bool escribio;
    int cantidad = cantidad_platos();
    platos_bkp = (struct platos *)malloc(cantidad * sizeof(platos));
    if (platos_bkp == NULL)
    {
        cout << "No hay memoria para continuar. ";
        return false;
    }
    FILE *p;

    p = fopen(PATH_PLATOS, "rb");
    fread(&platos_bkp[0], sizeof(platos), cantidad, p);
    fclose(p);
    p = fopen(PATH_BPLATOS, "wb");
    escribio = fwrite(&platos_bkp[0], sizeof(platos), cantidad, p);
    fclose(p);
    free(platos_bkp);
    return escribio;
}

bool backup_clientes(struct clientes *clientes_bkp)
{
    bool escribio;
    int cantidad = cantidad_clientes();
    FILE *p;
    clientes_bkp = (struct clientes *)malloc(cantidad * sizeof(clientes));
    if (clientes_bkp == NULL)
    {
        cout << "No hay memoria para continuar. ";
        return false;
    }
    p = fopen(PATH_CLIENTES, "rb");
    fread(&clientes_bkp[0], sizeof(clientes), cantidad, p);
    fclose(p);
    p = fopen(PATH_BCLIENTES, "wb");
    escribio = fwrite(&clientes_bkp[0], sizeof(clientes), cantidad, p);
    fclose(p);
    free(clientes_bkp);
    return escribio;
}

bool backup_pedidos (struct pedidos *pedidos_bkp){
    bool escribio;
    int cantidad = cantidad_pedidos();
    FILE *p;
    pedidos_bkp = (struct pedidos *)malloc(cantidad * sizeof(pedidos));
    if (pedidos_bkp == NULL)
    {
        cout << "No hay memoria para continuar. ";
        return false;
    }

    p = fopen(PATH_PEDIDOS, "rb");
    fread(&pedidos_bkp[0], sizeof(pedidos), cantidad, p);
    fclose(p);
    p = fopen(PATH_BPEDIDOS, "wb");
    escribio = fwrite(&pedidos_bkp[0], sizeof(pedidos), cantidad, p);
    fclose(p);
    free(pedidos_bkp);
    return escribio;
}

bool restaurar_platos (struct platos *restaurar_platos){
    bool restaurado;
    int cantidad = cantidad_platos();
    restaurar_platos = (struct platos *)malloc(cantidad * sizeof(platos));
    if (restaurar_platos == NULL)
    {
        cout << "No hay memoria para continuar. ";
        return false;
    }
    FILE *p;

    p = fopen(PATH_BPLATOS, "rb");
    fread(&restaurar_platos[0], sizeof(platos), cantidad, p);
    fclose(p);
    p = fopen(PATH_PLATOS, "wb");
    restaurado = fwrite(&restaurar_platos[0], sizeof(platos), cantidad, p);
    fclose(p);
    free(restaurar_platos);
    return restaurado;
}

bool restaurar_clientes (struct clientes *restaurar_clientes){
    bool restaurado;
    int cantidad = cantidad_clientes();
    FILE *p;
    restaurar_clientes = (struct clientes *)malloc(cantidad * sizeof(clientes));
    if (restaurar_clientes == NULL)
    {
        cout << "No hay memoria para continuar. ";
        return false;
    }
    p = fopen(PATH_BCLIENTES, "rb");
    fread(&restaurar_clientes[0], sizeof(clientes), cantidad, p);
    fclose(p);
    p = fopen(PATH_CLIENTES, "wb");
    restaurado = fwrite(&restaurar_clientes[0], sizeof(clientes), cantidad, p);
    fclose(p);
    free(restaurar_clientes);
    return restaurado;
}

bool restaurar_pedidos (struct pedidos *restaurar_pedidos){
    bool restaurado;
    int cantidad = cantidad_pedidos();
    FILE *p;
    restaurar_pedidos = (struct pedidos *)malloc(cantidad * sizeof(pedidos));
    if (restaurar_pedidos == NULL)
    {
        cout << "No hay memoria para continuar. ";
        return false;
    }

    p = fopen(PATH_BPEDIDOS, "rb");
    fread(&restaurar_pedidos[0], sizeof(pedidos), cantidad, p);
    fclose(p);
    p = fopen(PATH_PEDIDOS, "wb");
    restaurado = fwrite(&restaurar_pedidos[0], sizeof(pedidos), cantidad, p);
    fclose(p);
    free(restaurar_pedidos);
    return restaurado;
}


#endif // CONFIGURACION_H_INCLUDED