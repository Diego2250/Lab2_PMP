/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* Autor: Diego Alejandro Morales Escobar
* Curso:       CC3086 - Programación de microprocesadores     Ciclo II - 2022
* Descripción: Pide al usuario datos de diferentes personas y ordena los numeros CUI para luego imprimirlos
------------------------------------------------------------------------------*/

//
#include <iostream>
#include <bits/stdc++.h>
//#include <stdlib>
using namespace std;

struct estudiante{
    string nombre;
    string apellido;
    string cui;
    int ultimo_cui;
    string fecha_expiracion;
}estudiante[3];

int main(){
    //for para crear estudiantes 
    for(int i=0; i<3; i++){
        fflush(stdin);
        cout<<"Ingrese el nombre del estudiante: ";
        cin>>estudiante[i].nombre;
        cout<<"Ingrese el apellido del estudiante: ";
        cin>>estudiante[i].apellido;
        cout<<"Ingrese el CUI del estudiante: ";
        cin>>estudiante[i].cui;
        cout<<"Ingrese el ultimo numero del CUI del estudiante: ";
        cin>>estudiante[i].ultimo_cui;
        cout<<"Ingrese la fecha de expiración del CUI: ";
        cin>>estudiante[i].fecha_expiracion;

    }
    //ordenar los cui por ultimo numero de cui
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(estudiante[i].ultimo_cui<estudiante[j].ultimo_cui){
                swap(estudiante[i],estudiante[j]);
            }
        }
    }

    //mostrar los cui ordenados por ultimo numero de cui
    cout<<"\nCUI ordenados: ";
    for(int i=0; i<3; i++){
        cout<<"\nCUI: "<<estudiante[i].cui;
    }

    
    return 0;
}

