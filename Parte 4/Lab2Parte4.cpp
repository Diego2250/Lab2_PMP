/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* Autor: Diego Alejandro Morales Escobar
* Curso:       CC3086 - Programación de microprocesadores     Ciclo II - 2022
* Descripción: Suma la mitad de los numeros de un arreglo
------------------------------------------------------------------------------*/

//
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#define NTHREADS 2
using namespace std;
//create dynamic array
int size, half;
int *array=new int[size];

int* createArray(int size){
    int* array = new int[size];
    return array;
}
//fill array with random numbers
void fillArray(int* array, int size){
    for(int i=0; i<size; i++){
        array[i] = rand()%100;
    }
}
//pthread function to add numbers in the fisrt half of the array
void* addArray(void* tnumber){
    long tID = (long long)tnumber;
    int sum = 0;
    if(tID == 0){
        for(int i=0; i<half; i++){
            sum += array[i];
        }
    }
    else{
        for(int i=half; i<size; i++){
            sum += array[i];
        }
    }
    cout << "\nSuma de la mitad "<< tID+1 <<" del array: " << sum << endl;
    pthread_exit(NULL);
}

//main
int main(){
    //ask user for array size
    cout<<"Ingrese el tamaño del arreglo: ";
    size;
    cin>>size;
    //create array
    array = createArray(size);
    //fill array with random numbers
    fillArray(array, size);
    //print array
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    
    int rc; 
    pthread_t tID;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //set thread to joinable
    half = size/2;
    for(long i=0; i<NTHREADS;i++){ //create threads
        rc = pthread_create(&tID, &attr, addArray, (void*)i);
        if(rc){ //if error
            cout<<"Error al crear el hilo"<<endl;
            exit(-1);
        }

        rc=pthread_join(tID, NULL); //wait for thread to finish
        if(rc){ //if error
            cout<<"Error al unir el hilo"<<endl;
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr); //destroy thread attributes
    pthread_exit(NULL); //exit thread
    return 0;
}


