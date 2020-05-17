#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <regex>
const char * PATH_CLIENTES = "datos/clientes.dat";
bool validar_mail(const char *mail){
    const regex pattern 
    ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

     return regex_match(mail, pattern);

}

bool validar_fecha (int dia, int mes, int anio){
    if (mes>=1 && mes <= 12){
    switch (mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (dia >= 1 && dia <= 31) return true;
            else return false;
            break;
        case 2: 
            if (anio%4==0 && anio%100!=0){
                if (dia>=1 && dia <=27) return true;
                else return false;
            }
            else if (dia >=1 && dia <=29) return true;
            else return false;
            break;
        case 4: case 6: case 9: case 11:
        if (dia >=1 && dia <=30) return true;
        else return false;
        break;
    }
    }
    else return false;
}

bool cargar_cliente(struct clientes *reg){
    reg->ID=cantidad_clientes()+1;
    cout<< "Nombre(s): ";
    cin.getline(reg->nombres,50);
    cout<< "Apellido(s): ";
    cin.getline(reg->apellidos,50);
    cout<< "mail: ";
    cin.getline(reg->mail,50);
    if(!validar_mail(reg->mail)){
        cout<< "mail invalido";
        return false;
    }
    cout<< "Domicilio: ";
    cin.getline(reg->domicilio,100);
    cout<< "CP: ";
    cin>>reg->CP;
    if (reg->CP<1000 || reg->CP>9999) {
        cout<< "Codigo postal invalido.";
        return false;
    }
    cout<< "Fecha de nacimiento: "<<endl;
    cout<< "Dia: ";
    cin>>reg->fecha_nacimiento.dia;
    cout<< "Mes: ";
    cin>>reg->fecha_nacimiento.mes;
    cout<< "Anio: ";
    cin>>reg->fecha_nacimiento.anio;
    if (!validar_fecha(reg->fecha_nacimiento.dia,reg->fecha_nacimiento.mes,reg->fecha_nacimiento.anio)){
        cout<< "Fecha invalida.";
        return false;
    }
    reg->estado=true;
    cin.ignore();
    return reg->estado;
}

bool guardar_cliente (struct clientes reg){
    bool guardado;
    FILE *p;
    p=fopen(PATH_CLIENTES,"ab");
    if (p==NULL) return false;
    guardado=fwrite(&reg,sizeof(platos),1,p);
    fclose(p);
    return guardado;
}

void nuevo_cliente(){
    struct clientes nuevo;
    if (cargar_cliente(&nuevo)){
        if (guardar_cliente(nuevo)) cout<< "Cliente cargado con exito";
        else cout<< "No se pudo guardar el cliente.";
    }
    cout<< "No se pudo cargar el cliente.";
}

bool modificar_cliente (struct clientes *mod){
    cout<< "Nombre(s): ";
    cin.getline(mod->nombres,50);
    cout<< "Apellido(s): ";
    cin.getline(mod->apellidos,50);
    cout<< "mail: ";
    cin.getline(mod->mail,50);
    if(!validar_mail(mod->mail)){
        cout<< "mail invalido";
        return false;
    }
    cout<< "Domicilio: ";
    cin.getline(mod->domicilio,100);
    cout<< "CP: ";
    cin>>mod->CP;
    if (mod->CP<1000 || mod->CP>9999) {
        cout<< "Codigo postal invalido.";
        return false;
    }
    cout<< "Fecha de nacimiento: "<<endl;
    cout<< "Dia: ";
    cin>>mod->fecha_nacimiento.dia;
    cout<< "Mes: ";
    cin>>mod->fecha_nacimiento.mes;
    cout<< "Anio: ";
    cin>>mod->fecha_nacimiento.anio;
    if (!validar_fecha(mod->fecha_nacimiento.dia,mod->fecha_nacimiento.mes,mod->fecha_nacimiento.anio)){
        cout<< "Fecha invalida.";
        return false;
    }
    mod->estado=true;
    cin.ignore();
    return mod->estado;
}

bool sobreescribir_cliente (struct clientes mod,int pos){
    bool sobreescrito;
    FILE *p;
    p=fopen("PATH_CLIENTES","rb+");
    if (p==NULL) return false;
    fseek(p, pos * sizeof(struct clientes), SEEK_SET);
    sobreescrito = fwrite (&mod,sizeof(clientes),1,p);
    fclose (p);
    return sobreescrito;
}

void modificacion_cliente (int id){
    int pos;
    pos = buscar_cliente(id);
    if (pos >= 0){
        struct clientes mod = leer_cliente(pos);
        cout << endl;
        listar_cliente(mod);
        cout<<endl;
        if (modificar_cliente(&mod)){

        if (sobreescribir_cliente(mod, pos)) cout << "Cliente modificado.";

        else cout << "No se modificó el cliente.";

        }
    }
    else cout << "No existe el cliente.";
}

void listar_cliente_id (int id){
    int pos = buscar_cliente(id);
    if (pos >=0){
        struct clientes listar=leer_cliente(pos);
        listar_cliente(listar);
    }
    else cout << "No Existe el id buscado";
}

void listar_clientes (){
 
    int cantidad=cantidad_clientes();
    if (cantidad==0){
        cout<< "No hay clientes";
        return;
    }

    struct clientes *listar;
    listar=(struct clientes *) malloc (cantidad*sizeof(clientes));
    if (listar== NULL ){
        cout << "No hay memoria para continuar";
        return;
    }
    FILE *p;
    p=fopen(PATH_CLIENTES, "rb");
    if (p== NULL){
        free(listar);
        cout<< "No existe el archivo";
        return;
    }
    fread(&listar[0],sizeof(clientes),cantidad,p);
    fclose(p);

    ordenar_clientes(listar,cantidad);

    for (int i=0;i<cantidad;i++){
        listar_cliente(listar[i]);
        cout<<endl;
    }
    free (listar);

}

void eliminar_cliente (int id){
    char sel;
    int pos = buscar_cliente(id);
    if (pos >= 0){
        struct clientes reg = leer_cliente(pos);
        cout << endl;
        listar_cliente(reg);
        cout << endl;
        cout<< "Seguro quiere eliminar al cliente? [s/n]: ";
        cin >> sel;
        cin.ignore();
        cls();
        switch (sel)
        {
        case 's':
        case 'S':
                reg.estado=false;
                if (sobreescribir_cliente(reg,pos)){
                    cout << "cliente eliminado";
                }
                else {cout<< "Ocurrio un error al eliminar al cliente";}
            break;
        case 'n':
        case 'N':
            cout<< "No se eliminara el cliente";
            return;
            break;        
        default:
            cout << "Opcion invalida.";
            break;
        }
    }
}

void listar_cliente (struct clientes show){
    cout << "#ID "<<show.ID<<":"<< show.nombres << " " << show.apellidos<<endl;
    cout << "*Fecha de nacimiento: "<<show.fecha_nacimiento.dia<<"/"<<show.fecha_nacimiento.mes<<"/"<<show.fecha_nacimiento.anio<<endl;
    cout << "*Domicilio: " << show.domicilio <<endl;
    cout << "*Codigo postal: "<< show.CP<<endl;
    cout << "*Email: "<<show.mail;

}

int buscar_cliente (int id_busqueda){
    struct clientes reg;
    FILE *p;
    int i=0;
    p= fopen (PATH_CLIENTES,"rb");
    if (p == NULL){ return -2;}
    while (fread (&reg,sizeof(clientes),1,p)){
        if (reg.ID == id_busqueda && reg.estado==true){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

struct clientes leer_cliente(int pos){
    struct clientes reg;
    FILE *p;
    p = fopen(PATH_CLIENTES, "rb");
    if (p == NULL){
        reg.ID = -1;
        return reg;
    }
    fseek(p, pos * sizeof(clientes),SEEK_SET);
    fread(&reg, sizeof(clientes), 1, p);
    fclose(p);
    return reg;
}

int cantidad_clientes(){
    int cant, bytes;
    FILE *p;
    fopen(PATH_CLIENTES,"rb");
    if (p == NULL) return 0;
    fseek (p, 0, SEEK_END);
    bytes = ftell(p);
    cant = bytes/sizeof(clientes);
    fclose (p);
    return cant;
}

void ordenar_clientes (struct clientes *vec, int tam){
    int i, j, pos;
    struct clientes aux;

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

#endif //CLIENTES_H_INCLUDED