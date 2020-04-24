#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

bool cargarplato(struct platos *);
bool guardarplato (struct platos);
void nuevoplato ();
int buscarplato (int);
struct platos leer_plato(int);
void listarplato (struct platos);
void listarporid(int);

#endif //PROTOTIPOS_H_INCLUDED