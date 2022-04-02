#pragma once
#include <iostream>
#include <string>
#include "cPacientes.h"

using namespace std;

class cLaboratorio { //creamos class de Laboratorio
private:
	string nombre;
	int IDlaboratorio;
	int comuna;
	cPacientes* paciente1;
	cPacientes* paciente2;

public:
	cLaboratorio(string _nombre, float _idlaboratorio, int _comuna);
	~cLaboratorio();

	bool completo();
	void recibirmuestra(cPacientes* _paciente);
	void analisisdemuestra();
	void avisarpaciente();
	string to_string();
	void imprimirEnPantalla();
};