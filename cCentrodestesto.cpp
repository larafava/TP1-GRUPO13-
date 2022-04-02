#include "cCentrodetesteo.h"
#include "cLaboratorio.h"
#include "cPacientes.h"

using namespace std;

cCentrodetesteo::cCentrodetesteo(int _IDcentro, int _comuna, string _nombre)
{
	this->nombre = _nombre;
	this->IDcentro = _IDcentro;
	this->comuna = _comuna;
	this->paciente1 = NULL;
	this->paciente2 = NULL;
	this->laboratorio = NULL;


}

cCentrodetesteo::~cCentrodetesteo()
{
}

bool cCentrodetesteo::completo() {//Devuelve true si el centro de testeo esta completo y false si no lo esta
	bool toR = true;
	if (this->paciente1 == NULL || this->paciente2 == NULL) {
		toR = false;
	}
	return toR;
}


void cCentrodetesteo::AsociarLaboratorio(cLaboratorio* _laboratorio)//Recibe el laboratorio al cual se va a ver asociado el centro de testeo
{
	this->laboratorio = _laboratorio;
}

void cCentrodetesteo::BajaPaciente() {

	if (this->paciente1 != NULL) { //Primero verifico que exista paciente
		if (!(this->paciente1->getresultado().compare("Sin Resultado") == 0)) {
			this->paciente1 = NULL;
			cout << "Paciente dado de baja \n";

		}

		if (!(this->paciente2->getresultado().compare("Sin Resultado") == 0)) {
			this->paciente2 = NULL;
			cout << "Paciente dado de baja \n";


		}

	}
}

string cCentrodetesteo::to_string() { //Retorna los datos del centro de testeo en string
	return this->nombre + " " + std::to_string(this->IDcentro) + " " + std::to_string(this->comuna);
}

void cCentrodetesteo::imprimirEnPantalla() { //Imprime en pantalla la funcion to string
	cout << this->to_string() + "\n";
}


void cCentrodetesteo::AltaPaciente(cPacientes* _paciente)//Recibo un paciente y verifico que haya espacio para atenderlo
{
	if (this->paciente1 == NULL) {
		this->paciente1 = _paciente;
	}
	else if (paciente2 == NULL) {
		this->paciente2 = _paciente;
	}
	else
		cout << "No se pudo dar de alta al paciente, ocupado \n";
}

void cCentrodetesteo::MandarMuestra() {//mando la muestra al laboratorio
	if (this->paciente1 != NULL && this->laboratorio != NULL) //Primero verifico que exista el paciente y el laboratorio
	{
		this->laboratorio->recibirmuestra(this->paciente1);
	
	}
	if (this->paciente2 != NULL && this->laboratorio != NULL)
	{
		this->laboratorio->recibirmuestra(this->paciente2);
	}
}