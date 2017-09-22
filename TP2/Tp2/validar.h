#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



#endif // VALIDAR_H_INCLUDED



void myFgets(char* buffer, int limite ,FILE* archivo);

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombre(char* buffer);
int val_validarFloat(char* buffer);
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);
int val_getInt(int* destino, char* mensaje,char* mensajeError,int intentos);
int val_validarEdad(int* destino, int edad_A_Validar, int intentos);
int val_validarDni(int* destino, int dni_A_Validar, int intentos);
