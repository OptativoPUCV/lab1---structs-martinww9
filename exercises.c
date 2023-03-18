#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

//ejercicios de punteros y arreglos

/*
Ejercicio 1.
Programe la función void swap(int *a, int *b), la cual
intercambia los valores de las variables apuntadas por a y b.
*/
void swap(int *a, int *b) {
  int auxi = *a;
  *a = *b;
  *b = auxi;
}

/*
Ejercicio 2.
Programe la función void arrayMaxMin(int *a, int n, int *max, int *min),
la cual encuentra el máximo y el mínimo valor del arreglo a y los
almacena en las variables apuntadas por max y min.
*/
void arrayMaxMin(int *a, int n, int *max, int *min) {
    *max = a[0];
    *min = a[0];
  
    for (int i = 0; i < 10; i++)
      {
        if (a[i] > *max)
          *max = a[i]; 
        if (a[i] < *min)
          *min = a[i]; 
      }
}


/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos ingresados como parámetros y retorna un puntero 
al dato recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
   Persona * p = (Persona *) malloc(sizeof(Persona));
   //asignar valores de entrada a los campos de p
    strcpy(p->nombre, nombre);
    strcpy(p->rut, rut);
     p->edad = edad;


   return p;
}

/*
Ejercicio 4.
Considerando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int *datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector * crearVector(int n) {
    Vector *vector2 = malloc(sizeof(Vector));
  if (vector2 == NULL) return 0;
    vector2->datos = calloc(n, sizeof(int));
    vector2->capacidad = n;
    return vector2;
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor) {
        v->datos[i] = valor;
}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i) {
    return v->datos[i];
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c) {
    for(int i = 0; i < a -> capacidad; i++) {
      c -> datos[i] = a ->datos[i] + b ->datos[i];
    }
}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1+b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c){
  Vector *vectorA = crearVector( 2);
  Vector *vectorB = crearVector( 2);
  for(int i = 0; i < 2; i++)
    {
      asignarValor(vectorA, i, a1);
      asignarValor(vectorB, i, b1);
      if (i>0){
        asignarValor(vectorA, i, a2);
        asignarValor(vectorB, i, b2);
      }
    }

  sumaV(vectorA, vectorB, c);
}
