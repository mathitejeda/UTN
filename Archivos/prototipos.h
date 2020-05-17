#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
//Para las funciones "platos"
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

//Para las funciones "clientes"
bool validar_mail (const char*);
bool validar_fecha (int , int ,int);
bool cargar_cliente (struct clientes*);
bool guardar_cliente(struct clientes);
void nuevo_cliente();
bool modificar_cliente (struct clientes);
bool sobreescribir_cliente (struct clientes);
void modificacion_cliente (int);
void listar_cliente_id (int);
void listar_clientes ();
void eliminar_cliente (int);
void listar_cliente (struct clientes);
int buscar_cliente(int);
struct clientes leer_cliente(int);
int cantidad_clientes();
void ordenar_clientes (struct clientes*, int);

// para las funciones de pedidos
//principales
void nuevo_pedido();
void modificar_pedido(int);
//auxiliares
int buscar_pedido(int);
int cantidad_pedidos();
bool cargar_pedido(struct pedidos *);
bool guardar_pedido (struct pedidos);
float consultar_precio (int);
struct pedidos leer_pedido (int);
void listar_pedido(struct pedidos show);
bool sobreescribir_pedido( struct pedidos, int);

#endif //PROTOTIPOS_H_INCLUDED