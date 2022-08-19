/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* Autor: Diego Alejandro Morales Escobar
* Curso:       CC3086 - Programación de microprocesadores     Ciclo II - 2022
* Descripción: Calcula la distancia en base a la velocidad y tiempo
------------------------------------------------------------------------------*/

#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
# include <unistd.h>
int velocidad;
int tiempo;
int distancia;
int contador = 10;
using namespace std;

void* funcion_tiempo(void *tnumber){
    long tID = (long long)tnumber;
    for (int i = 0; i < contador; i++)
    {
        tiempo = tiempo + 1;
        cout << "Tiempo: " << tiempo << " Segundos\n" << endl;
        sleep(1);
    }
    
    pthread_exit(NULL);
}

void* funcion_distancia(void *tnumber){
    long tID = (long long)tnumber;
    for (int i = 0; i < contador; i++)
    {
        distancia = velocidad * tiempo;
        //imprimir el tiempo en segundos y la distancia en metros 
        cout<<"En "<<tiempo<<" segundos, la distancia es de "<<distancia<<" metros\n"<<endl;
        sleep(1);
    }
    
    pthread_exit(NULL);

}

void* checkDistancia(void *tnumber){
    long tID = (long long)tnumber;
    int diez=0, treinta=0, sesenta=0; 
    for (int i = 0; i < contador; i++)
    {
        if (distancia>=10 && distancia<30 && diez==0)
        {
            cout<<"\nSe ha recorrido una distancia de 10 metros\n"<<endl;
            diez = 1;
        }
        else if (distancia>=30 && distancia<60 && treinta==0)
        {
            cout<<"\nSe ha recorrido una distancia de 30 metros\n"<<endl;
            treinta = 1;
        }
        else if(distancia>=60 && sesenta==0)
        {
            cout<<"\nSe ha recorrido una distancia de 60 metros\n"<<endl;
            sesenta = 1;
        }
        sleep(1);
        
    }
    
    pthread_exit(NULL);
}
//main
int main(){
    cout<<"Ingrese el valor de a velocidad (m/s): \n";
    velocidad;
    cin>>velocidad;
    int rc;
    long i=0;
    pthread_t tID;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //set thread to joinable
    rc=pthread_create(&tID, &attr, funcion_tiempo, (void*)i);
    if(rc){ //if error
        cout<<"Error al crear el hilo"<<endl;
        exit(-1);
    }
    rc=pthread_create(&tID, &attr, funcion_distancia, (void*)i);
    if(rc){ //if error
        cout<<"Error al crear el hilo"<<endl;
        exit(-1);
    }
    rc=pthread_create(&tID, &attr, checkDistancia, (void*)i);
    if(rc){ //if error
        cout<<"Error al crear el hilo"<<endl;
        exit(-1);
    }
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
    return 0;
}
