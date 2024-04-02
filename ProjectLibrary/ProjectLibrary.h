// MathLibrary.h
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <tuple>
#pragma once

// ENCABEZADO DE LA LIBRERIA, PUBLICAR Y DEFINIR LAS FUNCIONES SIN ENSEÑAR SU CODIGO PARA USARLAS EN EL CLIENTE
// PARTE DE LA LIBRERIA

namespace ProjectLibrary
{
	class Qualities {
	public:
		std::string name = ""; // Name of the user
		int age = -1; // Age of the user
		int dayOfBirth = -1; // Day of the month of birth
		int status = -1; // Working(1), studying(2), both(3), N/A(4)
		char sex = 'N'; // User's sex (Male (M) - Female (F)) -- Char para ahorrar espacio
		int happiness = 0; // User 1-10 happiness rate
		int affinity = 0; // Returned value for a result. Depends on the values above.

		// Metodos para definir cada valor del objeto
		static std::string defineName(Qualities& userObj);
		static int defineAge(Qualities& userObj);
		static int defineDay(Qualities& userObj);
		static int defineStatus(Qualities& userObj);
		static char defineSex(Qualities& userObj);
		static int defineHappiness(Qualities& userObj);

		// Metodo que llama a todos los metodos a la vez.
		static void defineAll(Qualities& userObj);

		// Metodos para calcular afinidad
		static void calcNameAff(Qualities userObj); // Calcula afinidad basado en el nombre, usando las vocales y la longitud
		static void calcAgeAff(Qualities userObj); // Calcula afinidad basado en el primer digito de la edad
		static void calcDayAff(Qualities userObj); // Calcula afinidad basado en el ultimo digito del dia de nacimiento y de si es igual o no al primer digito de la edad
		static void calcStatusAff(Qualities userObj); // Calcula afinidad basado en estatus
		static void calcSexAff(Qualities userObj); // Calcula afinidad basado en el sexo
		static void calcHappyAff(Qualities userObj); // Calcula afinidad basado en la felicidad

		static int calcTotalAff(Qualities& userObj); // Suma todas las afinidades

		// Otros metodos y variables
		int length = 7; // El total de variables que hay, contando la afinidad

		static void printHeader(); // Printea el encabezado (titulo)
		static void printAll(Qualities userObj, int i); // Printea todos los valores del objeto
		static void wait(); // Espera un segundo y printea una nueva linea vacia
		static void load(int repeat, int milliseconds); // Printea (cantidad = repeat) puntos suspensivos con cierto delay
	};

	class Tarot {
	public:
		std::string name = ""; // Name of the Card
		int number = -1;
		std::string message = "";
		int minAff = -1;
		int maxAff = -1;

		static ProjectLibrary::Tarot createTarot();
		static std::tuple<std::string, std::string> chooseCards(Tarot createdTarot[], Qualities userObj);
	};

}