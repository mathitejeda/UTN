#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

bool cargar_plato(struct platos *);
bool guardar_plato (struct platos);
void nuevo_plato ();
bool modificar_plato(struct platos *);
void modificacion(int);
bool sobrescribir_plato(struct platos, int);
int buscar_plato (int);
struct platos leer_plato(int);
void listar_plato (struct platos);
void listar_por_id(int);

#endif //PROTOTIPOS_H_INCLUDED