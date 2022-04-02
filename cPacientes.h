#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;

class cPacientes {
private:
	string nombre;
	string apellido;
	string resultado;
	int dni;
	int numerotelefono;
	bool fiebre;
	bool tos;
	bool mocos;
	bool contactoestrecho;
	bool dolorcabeza;
	bool dolorgarganta;

public:
	//Constructor
	cPacientes(string _nombre, string _apellido, int _dni, int _numerotelefono, bool _fiebre, bool _tos, bool _mocos, bool _contactoestrecho, bool _dolorcabeza, bool _dolorgarganta);
	//Destructor
	~cPacientes();

	//Metodos 
	string getresultado();
	string to_string();
	void imprimirEnPantalla();
	void setresultado(string _resultado);
	int getsintomas();
	void recibirmensaje();
};
