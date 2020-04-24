#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct platos
{
 int ID, tiempo_preparacion,ID_restaurante, comision_restaurante,ID_categoria;
 char nombre[30];
 float costo_preparacion,valor_venta;
 bool estado;
};


#endif // TIPOS_H_INCLUDED