#include"cLaboratorio.h"
#include "cPacientes.h"
#include <string.h>


using namespace std;


cLaboratorio::cLaboratorio(string _nombre, float _idlaboratorio, int _comuna)
{
	this->nombre = _nombre;
	this->IDlaboratorio = _idlaboratorio;
	this->comuna = _comuna;
	this->paciente1 = NULL;
	this->paciente2 = NULL;

}
cLaboratorio::~cLaboratorio() {};
bool cLaboratorio::completo() { //Devuelve true si el laboratorio esta completo y false si no lo esta
	bool toR = true;
	if (this->paciente1 == NULL || this->paciente2 == NULL) {
		toR = false;
	}
	return toR;
}
void cLaboratorio::analisisdemuestra() { //Determina si el paciente tiene covid, si tiene mas de dos sintomas el testeo es positivo y si tiene menos de dos sintomas el testeo es negativo
	if (this->paciente1 != NULL) {//primero verifico que exista el paciente
		if (this->paciente1->getsintomas() > 2)
			this->paciente1->setresultado("Positivo");
		else
			this->paciente1->setresultado("Negativo");
	}
	if (this->paciente2 != NULL) {
		if (this->paciente2->getsintomas() > 2)
			this->paciente2->setresultado("Positivo");
		else
			this->paciente2->setresultado("Negativo");
	}

}

string cLaboratorio::to_string() {  //Retorna los datos del laboratorio en string
	return this->nombre + " " + std::to_string(this->IDlaboratorio) + " " + std::to_string(this->comuna);
}

void cLaboratorio::imprimirEnPantalla() { //Imprimo en pantalla la funcion to string
	cout << this->to_string() + "\n";
}

void cLaboratorio::recibirmuestra(cPacientes* _paciente) //Recibo las muestras de los pacientes desde el centro de testeo
{
	cout << "muestra recibida \n";
	if (this->paciente1 == NULL) {
		this->paciente1 = _paciente;
	}
	else if (paciente2 == NULL) {
		this->paciente2 = _paciente;
	}
	else
		cout << "No se pudo analizar la muestra \n"; //Si son distintos de NULL, no se logra analizar la muestra
}





void cLaboratorio::avisarpaciente() {  //Avisa al paciente por mensaje el resultado del testeo y si no hay error se logra mandar el mensaje

	cout << " \n";

	if (this->paciente1 != NULL) {//primero verifico que exista el paciente
		if (!(this->paciente1->getresultado().compare("Sin Resultado") == 0)) {
			this->paciente1->recibirmensaje();
			cout << "el resultado del paciente es : ";
			cout << this->paciente1->getresultado();
			cout << "Se logro mandar el mensaje  \n";
			this->paciente1 = NULL;

		}
		cout << "el resultado del paciente 2 es : ";
		cout << this->paciente2->getresultado();
		if (!(this->paciente2->getresultado().compare("Sin Resultado") == 0)) {
			this->paciente2->recibirmensaje();
			cout << "Se logro mandar el mensaje  \n";
			this->paciente2 = NULL;

		}



	}

}