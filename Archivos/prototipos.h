#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
int cantidad_platos();
bool cargar_plato(struct platos *);
bool guardar_plato (struct platos);
void nuevo_plato ();
bool modificar_plato(struct platos *);
void modificacion(int);
bool sobrescribir_plato(struct platos, int);
int buscar_plato (int);
bool buscar_restaurante (int);
struct platos leer_plato(int);
void listar_plato (struct platos);
void listar_por_id(int);
void listar_por_restaurante(int);
void listar_platos();
void eliminar_plato();
void ordenar_platos(platos,int);
void listar_platos_dinamico();

#endif //PROTOTIPOS_H_INCLUDED