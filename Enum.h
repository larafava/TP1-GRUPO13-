#pragma once
#include <string>


using namespace std;

using namespace std;
//creo un enum para los resultados de testeos y tambien dentro del enum esta "elem" que es el indicador de cuantos elementos existen en el enum.
enum class eResultado { Sin_resultado, Positivo, Negativo, elem };
string resultadotesteostring(eResultado resultado);