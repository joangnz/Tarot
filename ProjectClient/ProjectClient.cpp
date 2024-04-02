// MathClient.cpp
// compile with: cl /EHsc MathClient.cpp /link MathLibrary.lib

// CLIENTE USADO, AQUI SOLO SE LLAMA A LAS FUNCIONES DE LA LIBRERIA
// ESTE ES EL CLIENTE EJECUTABLE

/*
- Un programa que, mediante tu nombre, edad, etc… adivine el futuro o cómo es el usuario.
*/

#include "ProjectLibrary.h"

int main()
{
	// Randomizer
	srand(time(NULL));

	// Crea un objeto con key-values y metodos de la clase Qualities
	ProjectLibrary::Qualities User;

	//Crea una array de objetos con key-values y metodos de la clase Tarot
	ProjectLibrary::Tarot TarotCards[22];
	for (int i = 0; i < 22; i++)
	{
		TarotCards[i] = ProjectLibrary::Tarot::createTarot();
	}

	// Printeo el header
	ProjectLibrary::Qualities::printHeader();

	// Defino todos los valores de los campos
	ProjectLibrary::Qualities::defineAll(User);

	// Limpio la consola y printeo todos los valores
	system("cls");
	ProjectLibrary::Qualities::printHeader();
	ProjectLibrary::Qualities::printAll(User, 0);

	// Calculo la afinidad de cada dato del usuario
	ProjectLibrary::Qualities::calcTotalAff(User);
	system("pause");

	// Limpia la consola y te muestra las cartas del tarot.
	system("cls");
	ProjectLibrary::Qualities::printHeader();
	ProjectLibrary::Qualities::printAll(User, 1);
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	std::string cardName, cardMessage;
	std::tie(cardName, cardMessage) = ProjectLibrary::Tarot::chooseCards(TarotCards, User);
	ProjectLibrary::Qualities::wait();
	std::cout << cardName << ", " << cardMessage;

	return 0;
}