#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// funciones malloc y memcpy
// se quiere introducir un nuevo entero en el arreglo de tipo
// int a[2] = {20,30}.
// para esto, tengo que reservar dinamicamente memoria, asignando el espacio de
// un entero.
void *generic_insert(void *arr, unsigned arr_size, unsigned idx,
                     void *data_to_ins, unsigned sizeval) {
  void *new_arr = malloc((arr_size) + sizeval);

  // en caso de no tener espacio en memoria.
  if (!new_arr)
    return NULL;

  // idx  nos ayuda para saber a partir de cual indice es que haremos la
  // expansion e insercion del dato.

  memcpy(new_arr, arr, idx);
  memcpy(new_arr + idx, data_to_ins, sizeval);
  memcpy(new_arr + idx + sizeval, arr + idx, arr_size - 1);

  return new_arr;
}

// TODO: generic_delete
void *generic_delete(void *arr, unsigned arr_size, unsigned idx,
                     unsigned sizeval) {
  void *new_arr = malloc(arr_size - sizeval);

  if (!new_arr)
    return NULL;

  memcpy(new_arr, arr, idx);

  memcpy(new_arr + idx, arr + idx + sizeval, arr_size - idx - sizeval);

  free(arr);

  return new_arr;
}
