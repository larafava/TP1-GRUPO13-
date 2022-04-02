#include "cPacientes.h"
#include <string>
#include <iostream>

using namespace std;

cPacientes::cPacientes(string _nombre, string _apellido, int _dni, int _numerotelefono, bool _fiebre, bool _tos, bool _mocos, bool _contactoestrecho, bool _dolorcabeza, bool _dolorgarganta) {
	this->nombre = _nombre;
	this->apellido = _apellido;
	this->dni = _dni;
	this->numerotelefono = _numerotelefono;
	this->contactoestrecho = _contactoestrecho;
	this->fiebre = _fiebre;
	this->mocos = _mocos;
	this->tos = _tos;
	this->resultado = "Sin Resultado";
	this->dolorcabeza = _dolorcabeza;
	this->dolorgarganta = _dolorgarganta;
}
cPacientes::~cPacientes() {

}


string cPacientes::to_string() {//Retorna los datos del paciente en string

	return  this->nombre + " " + this->apellido + " " + std::to_string(this->dni) +
		this->resultado + " fiebre:  " + std::to_string(this->fiebre)
		+ " tos :" + std::to_string(this->tos)
		+ " mocos : " + std::to_string(this->mocos)
		+ " contacto estrecho :" + std::to_string(this->contactoestrecho)
		+ " dolor cabeza : " + std::to_string(this->dolorcabeza)
		+ " dolor garganta : " + std::to_string(this->dolorgarganta)
		+ "\n"
		;
}
void cPacientes::imprimirEnPantalla() { //Imprimo en pantalla la funcion to string
	cout << "\n";
	cout << this->to_string() + " \n";

}

void cPacientes::setresultado(string _resultado) { //hago referencia a los resultados
	this->resultado = _resultado;
}

int cPacientes::getsintomas() { //Contador de los sintomas para usarlo en el metodo analisisdemuestra
	int contador = 0;
	if (this->fiebre == true) {
		contador = contador + 1;
	}

	if (this->tos == true) {
		contador = contador + 1;
	}

	if (this->mocos == true) {
		contador = contador + 1;
	}

	if (this->contactoestrecho == true) {
		contador = contador + 1;
	}

	if (this->dolorcabeza == true) {
		contador = contador + 1;
	}

	if (this->dolorgarganta == true) {
		contador = contador + 1;
	}

	return contador;
}

string cPacientes::getresultado() { //retorna el resultado en string

	return this->resultado;

}

void cPacientes::recibirmensaje() { //imprime que el paciente recibe el mensaje
	cout << this->nombre + "recibio el mensaje \n";

}