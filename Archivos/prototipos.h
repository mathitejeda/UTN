#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

bool cargarplato(struct platos *);
bool guardarplato (struct platos);
void nuevoplato ();
bool modificar_plato(struct platos *);
void modificacion(int);
bool sobrescribir_plato(struct platos, int);
int buscarplato (int);
struct platos leer_plato(int);
void listarplato (struct platos);
void listarporid(int);

#endif //PROTOTIPOS_H_INCLUDED