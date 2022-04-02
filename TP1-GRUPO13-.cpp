// TP1-GRUPO13-.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "cPacientes.h"
#include "cLaboratorio.h"
#include "cCentrodetesteo.h"

int main()
{
	cPacientes* miPaciente1 = new cPacientes("Luana", "Corso", 44417808, 2915226293, true, false, true, true, false, false);
	cPacientes* miPaciente2 = new cPacientes("Pepe", "Jose", 12345234, 91444555, false, false, false, true, false, false);
	cPacientes* miPaciente3 = new cPacientes("Pepen", "Josen", 12345434, 91144555, false, false, false, true, false, false);
	cout << "Imprimo el laboratorio : \n";
	cLaboratorio* lab1 = new cLaboratorio("lab1", 1, 12);
	//imprimo el lab por pantalla
	lab1->imprimirEnPantalla();

	cCentrodetesteo* Centro1 = new cCentrodetesteo(0, 2, "Hola"); //creamos puntero dinamico de centro de testeo
	//imprimo el centro por pantalla
	cout << "Imprimo el centro por pantalla : \n";
	Centro1->imprimirEnPantalla();
	//creamos un puntero dinamico de pacientes 
	cout << "Imprimo el paciente por pantalla : \n";
	miPaciente1->imprimirEnPantalla();
	Centro1->AltaPaciente(miPaciente1);
	Centro1->AltaPaciente(miPaciente2);
	//Paciente que no puede ser dado de alta
	Centro1->AltaPaciente(miPaciente3);
	//AHora tengo que mandar al laboratorio
	Centro1->AsociarLaboratorio(lab1);
	Centro1->MandarMuestra();
	//Ahora tengo que analizar las muestras en el laboratorio
	lab1->analisisdemuestra();
	lab1->avisarpaciente();
	//Doy de baja los pacientes
	Centro1->BajaPaciente();
	cout << "\n";
	//destruyo los objetos
	delete miPaciente1;
	delete miPaciente2;
	delete miPaciente3;
	delete Centro1;
	delete lab1;


	cout << "Fin del programa . \n";
}
