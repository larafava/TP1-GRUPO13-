#pragma once
#include <iostream>
#include <string>
class cPacientes;
class cLaboratorio;


using namespace std;

class cCentrodetesteo {
private:
	int IDcentro;
	int comuna;
	string nombre;
	cPacientes* paciente1;
	cPacientes* paciente2;
	cLaboratorio* laboratorio;



public:
	//Constructor
	cCentrodetesteo(int _IDcentro1, int _comuna1, string _nombre1);
	//Destructor
	~cCentrodetesteo();

	//Metodos
	void AsociarLaboratorio(cLaboratorio* _laboratorio);
	void AltaPaciente(cPacientes* _paciente);
	void MandarMuestra();
	void BajaPaciente();
	bool completo();
	string to_string();
	void imprimirEnPantalla();
};