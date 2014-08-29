#include <iostream>
#include <fstream>
#include <string>
//Para los que se quedaron pegados con el struct,
//yo piendo que no les va a entrar, pero igual deberían saber usarlos.
using namespace std;
struct alumno
{
	string nombre;
	int seccion;
	float controles[5];
	float tareas[5];
	float solemne1;
	float solemne2;
	float examen;
	float nota_final;
};

float calc_promedio(float x[], int tam)
{
	float min = x[0];
	float suma = 0;
	for (int i = 0; i < tam; ++i)
	{
		if(x[i]< min)
		{
			min = x[i];
			suma+=x[i];
		}
	}
	return (suma - min)/(tam - 1.0);
}

void calc_nota_final(struct alumno *x)
{
	//Para usar el puntero al alumno, hay dos formas de hacerlo.
	//1.- De forma dinamica: x->nombre.
	//2.- De forma estatica: (*x).nombre.
	//Lo hare de forma estatica esta vez.

	float NP = calc_promedio((*x).controles, 5)*0.2 + 
				calc_promedio((*x).tareas, 5)*0.2 + 
				(((*x).solemne1 + (*x).solemne2)/2)*0.6;

	(*x).nota_final = NP*0.7 + ((*x).examen)*0.3;
}

int main() 
{
	ifstream archivo;
	archivo.open("alumno.txt");
	alumno aux;
	alumno *alumnos = new alumno[15];
	for (int i = 0; i < 15; ++i)
	{
		alumnos[i] = aux;
	}
	int i = 0;
	if( archivo.is_open())
	{
		while (!archivo.eof() && i<15) 
		{
			archivo>>(alumnos[i]).nombre
			>>(alumnos[i]).controles[0]
			>>(alumnos[i]).controles[1]
			>>(alumnos[i]).controles[2]
			>>(alumnos[i]).controles[3]
			>>(alumnos[i]).controles[4]
			>>(alumnos[i]).tareas[0]
			>>(alumnos[i]).tareas[1]
			>>(alumnos[i]).tareas[2]
			>>(alumnos[i]).tareas[3]
			>>(alumnos[i]).tareas[4]
			>>(alumnos[i]).solemne1
			>>(alumnos[i]).solemne2
			>>(alumnos[i]).examen;
			calc_nota_final(&alumnos[i]);
		if(alumnos[i].nota_final > 4.0)
		{
			cout<<alumnos[i].nombre<<" aprueba"<<endl;
		}
		else
			cout<<alumnos[i].nombre<<" no aprueba"<<endl;
		i++;
		}
	}


}