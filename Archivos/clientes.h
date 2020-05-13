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
    cout<< "Ingrese el id del cliente: ";
    cin>> reg->ID;
    int refID=buscar_cliente(reg->ID);
    if (refID>=0){
        cout << "El cliente ya existe";
        return false;
    }
    cin.ignore();
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
    p=fopen("PATH_CLIENTES","ab");
    if (p==NULL) return false;
    guardado=fwrite(&reg,sizeof(platos),1,p);
    fclose(p);
    return guardado;
}

void nuevo_cliente();

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

#endif //CLIENTES_H_INCLUDED