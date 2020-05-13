#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct fecha
{
    int dia,mes,anio;
};

struct platos
{
 unsigned int ID, tiempo_preparacion,ID_restaurante, comision_restaurante,ID_categoria;
 char nombre[30];
 float costo_preparacion,valor_venta;
 bool estado;
};

struct clientes
{
    int ID;
    int CP;
    char apellidos[50], nombres[50], mail[50], domicilio[100];
    fecha fecha_nacimiento;
    bool estado;
};



#endif // TIPOS_H_INCLUDED