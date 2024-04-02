// MathLibrary.cpp
// compile with: cl /c /EHsc MathLibrary.cpp
// post-build command: lib MathLibrary.obj

// LIBRERIA C++, PROGRAMAR LAS FUNCIONES DE LA LIBRERIA, TODO EL CODIGO VA AQUI
// PARTE DE LA LIBRERIA

#include "ProjectLibrary.h"

namespace ProjectLibrary
{
	/*
	----
	Tarot Cards -- Affinity Values
	----
	0 - The Fool -> 0-260
	1 - The Magician --> 200-270
	2 - The High Priestess --> 220-290
	3 - The Empress --> 240-300 && Sex = 'F'
	4 - The Emperor --> 240-300 && Sex = 'M'
	5 - The Hierophant --> 260-310
	6 - The Lovers --> 280-330
	7 - The Chariot --> 300-350
	8 - Strength --> 300-370
	9 - The Hermit --> 320-390
	10 - Wheel of Fortune --> 330-400
	11 - Justice --> 350-420
	12 - The Hanged Man --> 360-420
	13 - Death --> 380-450
	14 - Temperance --> 400-460
	15 - The Devil --> 420-480
	16 - The Tower --> 440-490
	17 - The Star --> 451-500
	18 - The Moon --> 490-550
	19 - The Sun --> 500+
	20 - Judgement --> 500+
	21 - The World --> 500+

	Examples:
		Deberia haber entre 3 y 9 cartas por cada rango de 50 Aff (0-50 --> 3 cartas, 50-100 --> 4 cartas, 100-150 --> 2 cartas...)
		0-250 --> Fool, Magician, High Priestess, Empress/Emperor
		250-300 --> Fool, Magician, Priestess, Empress/Emperor, Hierophant, Lovers
		300-350 --> EMpress/Emperor, Hierophant, Lovers, Chariot, Strength, Hermit, WoF, Justice
		350-400 --> Chariot, Strength, Hermit, WoF, Justice, Hanged Man, Death
		400-450 --> WoF, Justice, Hanged Man, Death, Temperance, Devil, Tower
		450-500 --> Star, Moon, Sun, Judgement, World
	*/

	// TAROT FUNCTIONS & VARIABLES
	// Create an array of objects (class Tarot)
	ProjectLibrary::Tarot tarot[22];
	std::string names[] = { "The Fool", "The Magician", "The High Priestess", "The Empress", "The Emperor", "The Hierophant", "The Lovers", "The Chariot",
		"Strength", "The Hermit", "Wheel of Fortune", "Justice", "The Hanged Man", "Death", "Temperance", "The Devil", "The Tower", "The Star", "The Moon",
	"The Sun", "Judgement", "The World" };
	std::string messages[] = {
	"you'll walk a path to the unknown, with only one who truly follows you, beside your knowledge and freedom.\nI wonder, will you walk the path, or drift off the precipice?\n", // Fool
	"you know about the truths of the world. You will be able to bend obstacles to your advantage, if you truly understand that even the Heaven must be connected to Hell.\n", // Magician
	"you will be able to hold responsibility and authority over your goals once you become one with balance.\nIn doing so, you will unveil secrets, but it will be a test to your equilibrium whether you share them or not.\n", // Priestess
	"you are a kind and caring person. You will eventually hold the power to heal people's wounds, and above all, help those in need, for that is your role as Empress.\nFear not the people, for one of them will soon be your Emperor.\n", // Empress
	"you can become the base pillar for a better world if you show your confidence and authority.\nFear not the opinions of others about you, but who you are, and, at all costs, never let your qualities become flaws.\n", // Emperor
	"you stand for what you believe in.\nIt is a great trait, and you shall keep on being a consistent and righteous, strong and merciful person.\n", // Hierophant
	"you either have found the love of your life or you will soon enough.\nYou're really lucky to have found that person, be thankful for that, and never turn your back when the two of you encounter conflict or trials.\n", // Lovers
	"you're a vivacious person.\nYou will find conflict, hold no doubt to that, and you shall overcome it as long as you don't let your energy turn into anger.\n", // Chariot
	"you hold the power to overcome obstacles and pierce right through them.\nKeep that power disciplined, for it will aid you in the road to success, and keep it balanced, for it can quickly become weakness and disgrace.\n", // Strength
	"you're cautious and intelligent, prudent and perspicatious. Be wary of the places you frequent, and the acquaintances you may have, for they might become your rivals, and you might become fearful.\n", // Hermit
	"your life is just about to take a wild change, you might consider calling it a spin.\nBe ready for that moment, and don't let yourself get swept away with your previous self.\n", // Wheel
	"be true to your senses and do not back down on your ideals.\nThe righteousness of your thought is a treasure to behold, and if you don't let it go down in the form of bigotry and bias, it will gain an everlasting shine.\n", // Justice
	"you're advised to watch and inspect from a distance and stand at a neutral perspective, without judging things, but instead accepting them and acting on what is possible.\nDo as advised, and success is sure to find you.\n", // Hanged Man
	"this is a sorrow card. You may lose something precious to you in a near future, including your own self.\nThere is no other interpretation, but now that you've gained knowledge on the future loss, you can prepare to accept it.\n", // Death
	"you are a smart and organized person. May that organization flourish in you and bring you comfort, happiness and wealth, or may it wither into intolerance and rejection to others.\nWhich will be?\n", // Temperance
	"you may encounter violence and selfishness around you soon.\nIn fact, maybe this devil has already been beside you.\nWatch out for those who walk along you, and give them as they give you.\n", // Devil
	"adversity is coming your way, indeed.\nPerhaps the winds of change come with that too.\nI wonder, when those winds come, will you build walls, or will you build a windmill?\n", // Tower
	"brightness is on its way towards your life.\nLive happy and proud, for you've gained the grace to do so. Keep your ideals unchanging and always fair, and only then will you shine as bright as you can.\n", // Star
	"fear surely is present in your life.\nYou live in it. In darkness, in danger.\nYour fear is but a warning. Overcome it, and you shall see the dawn. Flee from it, and face mistakes.\n", // Moon
	"you're on your way towards happiness.\nKeep smiling and enjoy discovery, find new things and new people, and may your future be as bright as the Sun that shines on you every day.\n", // Sun
	"you will soon be given a chance, a trial.\nKeep your head up when it comes, and stand proud, for you've always done as much as you could, and it is no sin to be punished, but a deed to be rewarded.\n", // Judgement
	"you've been on a long journey, haven't you?\nRest assured, it is sure to bring success into your life, and change.\nDance over the Earth gracely, and you'll be where you're supposed to be, when you're supposed to.\n" // World
	};
	int minAffs[] = { 0, 200, 220, 240, 240, 260, 280, 300, 300, 320, 330, 350, 360, 380, 400, 420, 440, 451, 490, 500, 500, 500 };
	int maxAffs[] = { 260, 270, 290, 300, 300, 310, 330, 350, 370, 390, 400, 420, 420, 450, 460, 480, 490, 500, 550, 10000, 10000, 10000 };
	int cardCount = 0;

	// Fills one position of the createdTarot with the corresponding card. Call it in a for-loop to fill completely
	ProjectLibrary::Tarot Tarot::createTarot() {
		ProjectLibrary::Tarot createdTarot[22];

		createdTarot[cardCount].number = cardCount;
		createdTarot[cardCount].name = names[cardCount];
		createdTarot[cardCount].message = messages[cardCount];
		createdTarot[cardCount].minAff = minAffs[cardCount];
		createdTarot[cardCount].maxAff = maxAffs[cardCount];

		cardCount += 1;
		return createdTarot[cardCount - 1];
	}

	std::tuple<std::string, std::string> Tarot::chooseCards(Tarot createdTarot[], Qualities userObj) {
		// Depending on the userObj.affinity, chooses the cards in range and shows one.
		int cardList[10], counter = 0;
		for (int i = 0; i < 22; i++)
		{
			if (userObj.affinity >= createdTarot[i].minAff && userObj.affinity <= createdTarot[i].maxAff) {
				if (createdTarot[i].number == 3 && !userObj.sex != 'F') {
					// Does nothing, prevents having Empress as Male
				}
				else if (createdTarot[i].number == 4 && userObj.sex != 'M') {
					// Does nothing, prevents having Emperor as Female
				}
				else {
					cardList[counter] = i;
					counter++;
				}

			}
		}

		std::cout << "With your affinity, there are " << counter << " cards that I could read. I'll read one of them";
		// Uncomment for debugging
		/*
		for (int i = 0; i < counter; i++)
		{
			std::cout << createdTarot[cardList[i]].name << " " << createdTarot[cardList[i]].message << "\n--\n";
		}
		*/

		ProjectLibrary::Qualities::load(3, 500);

		int card = rand() % counter;
		return std::make_tuple(createdTarot[cardList[card]].name, createdTarot[cardList[card]].message);
	}

	//--------------------------------------------------------------------------------------------------------------------------------------------------------------

		// Bool to loop in case of invalid input
	bool retry = false;

	// Funcion para repetir en caso de valor incorrecto.
	// Debe estar aqui arriba para poder funcionar en las demás funciones.
	void retryTrue() {
		retry = true;
		std::cout << "Valor incorrecto. Prueba de nuevo.\n";
	}

	//--------------------------------------------------------------------------------------------------------------------------------------------------------------

		// USER FUNCTIONS & VARIABLES
		// ProjectLibrary::Qualities User; // Objeto con las keys-values de Qualities

		//Int vars for all affinities and total affinity
	int nameAffinity = 0, ageAffinity = 0, dayAffinity = 0, statusAffinity = 0, sexAffinity = 0, happyAffinity = 0;
	int totalAffinity = 0;

	//FUNCTIONS
	std::string Qualities::defineName(Qualities& userObj) {
		std::cout << "Introduce your name:\n";
		std::string inputName = "";
		std::getline(std::cin, inputName);  // En caso de que ponga un espacio, recoge tambien lo que hay despues y no peta.

		int p = inputName.find(" "); // Encuentra el espacio y lo usa para coger solo la primera palabra
		userObj.name = inputName.substr(0, p);
		std::cout << "\n";
		return userObj.name;
	}

	int Qualities::defineAge(Qualities& userObj) {
		std::string ageStr = "";
		int age = -1;
		do {
			try {
				std::cout << "Introduce your age:\n";
				std::cin >> ageStr;
				age = std::stoi(ageStr);

				if (age < 0 || age > 116) {
					retryTrue();
				}
				else {
					userObj.age = age;
					retry = false;
				}
			}
			catch (...) {
				age = -1;
				retryTrue();

			}

		} while (retry);
		std::cout << "\n";
		return userObj.age;
	}

	int Qualities::defineDay(Qualities& userObj) {
		std::string dayStr = "";
		int day = -1;

		do {
			try {
				std::cout << "Introduce the day of the month you were born:\n";
				std::cin >> dayStr;
				day = std::stoi(dayStr);

				if (day < 1 || day > 31) {
					retryTrue();
				}
				else {
					userObj.dayOfBirth = day;
					retry = false;
				}
			}
			catch (...) {
				day = -1;
				retryTrue();
			}

		} while (retry);
		std::cout << "\n";
		return userObj.dayOfBirth;
	}

	int Qualities::defineStatus(Qualities& userObj) {
		std::string statusStr = "";
		int status = 0;

		do {
			try {
				std::cout << "Are you studying, working, both or none?\n1 - Studying\n2 - Working\n3 - Both\n4 - None\n";
				std::cin >> statusStr;
				status = std::stoi(statusStr);

				if (status < 1 || status > 4) {
					retryTrue();
				}
				else {
					userObj.status = status;
					retry = false;
				}
			}
			catch (...) {
				status = 0;
				retryTrue();
			}

		} while (retry);
		std::cout << "\n";
		return userObj.status;
	}

	char Qualities::defineSex(Qualities& userObj) {
		do {
			std::string choice = "";
			std::cout << "Are you male or female?\n1 - Male\n2 - Female\n";
			std::cin >> choice;

			if (!choice._Equal("1") && !choice._Equal("2")) {
				retryTrue();
			}
			else {
				retry = false;
				if (choice._Equal("1")) {
					userObj.sex = 'M';
				}
				else {
					userObj.sex = 'F';
				}
			}

		} while (retry);
		std::cout << "\n";
		return userObj.sex;
	}

	int Qualities::defineHappiness(Qualities& userObj) {
		std::string happyStr = "";
		int happy = 0;
		do {
			try {
				std::cout << "On a scale of 1 to 10, how happy are you?\n";
				std::cin >> happyStr;
				happy = std::stoi(happyStr);

				if (happy < 1 || happy > 10) {
					retryTrue();
				}
				else {
					userObj.happiness = happy;
					retry = false;
				}
			}
			catch (...) {
				happy = 0;
				retryTrue();
			}

		} while (retry);
		std::cout << "\n";
		return userObj.happiness;
	}

	void Qualities::defineAll(Qualities& userObj) {
		Qualities::defineName(userObj);
		Qualities::defineAge(userObj);
		Qualities::defineDay(userObj);
		Qualities::defineStatus(userObj);
		Qualities::defineSex(userObj);
		Qualities::defineHappiness(userObj);
	}

	//Name Affinity Depends on Number of Vowels
	void Qualities::calcNameAff(Qualities userObj) {
		// Vowel counter and vowel array
		int vowelsCount = 0;
		char vowels[] = { 'a', 'e', 'i', 'o', 'u' };

		// Counts the vowels in the name
		for (int i = 0; i < userObj.name.length(); i++)
		{
			for (int j = 0; j < sizeof(vowels) / sizeof(char); j++) {
				if (vowels[j] == tolower(userObj.name[i])) {
					vowelsCount++;
				}
			}
		}

		// Calculate Name Affinity
		nameAffinity = (3 * vowelsCount + userObj.name.length()) * 10;

		// Print results
		std::cout << "Calculating Name Affinity";
		Qualities::load(4, 500);

		std::cout << "Name Affinity: " << nameAffinity << "\n";
		Qualities::wait();
	}

	//Age Affinity Depends on First Digit
	void Qualities::calcAgeAff(Qualities userObj) {
		//Get the first digit of the age
		std::string ageStr = std::to_string(userObj.age);
		int firstDigit = 0;

		if (ageStr.length() == 1) {
			firstDigit = std::stoi(ageStr);
		}
		else if (ageStr.length() == 2) {
			firstDigit = stoi(ageStr) / 10;
		}
		else if (ageStr.length() == 3) {
			firstDigit = stoi(ageStr) / 100;
			firstDigit += 10;
		}

		// Calculate the Age Affinity
		ageAffinity = firstDigit * 30;

		// Print results
		std::cout << "Calculating Age Affinity";
		Qualities::load(4, 500);

		std::cout << "Age Affinity: " << ageAffinity << "\n";
		Qualities::wait();
	}

	//Day Affinity Depends on Last Digit & Coincidence with Age First Digit
	void Qualities::calcDayAff(Qualities userObj) {
		// Calculate Day Affinity based on the last digit * 10
		dayAffinity = (userObj.dayOfBirth % 10) * 10;

		if (userObj.dayOfBirth % 10 == ageAffinity / 30) { // If the last digit of DoB == the first digit of the age (ageAffinity = firstDigit * 30)
			dayAffinity += 50;
		}

		std::cout << "Calculating Day Affinity";
		Qualities::load(4, 500);

		std::cout << "Day Affinity: " << dayAffinity << "\n";
		Qualities::wait();
	}

	//Status Affinity Depends on Status Choice, 1 lowest, 4 highest
	void Qualities::calcStatusAff(Qualities userObj) {
		if (userObj.status == 1) {
			statusAffinity = 0;
		}
		else if (userObj.status == 2) {
			statusAffinity = 30;
		}
		else if (userObj.status == 3) {
			statusAffinity = 70;
		}
		else { // userObj.status == 4
			statusAffinity = 100;
		}

		std::cout << "Calculating Status Affinity";
		Qualities::load(4, 500);

		std::cout << "Status Affinity: " << statusAffinity << "\n";
		Qualities::wait();
	}

	//Sex Affinity = 30 IF Male, = 50 IF Female
	void Qualities::calcSexAff(Qualities userObj) {
		if (userObj.sex == 'M') {
			sexAffinity = 30;
		}
		else {
			sexAffinity = 50;
		}

		std::cout << "Calculating Sex Affinity";
		Qualities::load(4, 500);

		std::cout << "Sex Affinity: " << sexAffinity << "\n";
		Qualities::wait();
	}

	//Happy Affinity = Happiness * 10
	void Qualities::calcHappyAff(Qualities userObj) {
		happyAffinity = userObj.happiness * 10;

		std::cout << "Calculating Happiness Affinity";
		Qualities::load(4, 500);

		std::cout << "Happiness Affinity: " << happyAffinity << "\n";
		Qualities::wait();
	}

	//SUM ALL AFFINITIES
	int Qualities::calcTotalAff(Qualities& userObj) {
		calcNameAff(userObj);
		calcAgeAff(userObj);
		calcDayAff(userObj);
		calcStatusAff(userObj);
		calcSexAff(userObj);
		calcHappyAff(userObj);

		totalAffinity = nameAffinity + ageAffinity + dayAffinity + statusAffinity + sexAffinity + happyAffinity;
		userObj.affinity = totalAffinity;

		std::cout << "Calculating Total Affinity";
		Qualities::load(4, 500);

		std::cout << "Total Affinity: " << userObj.affinity;
		Qualities::wait();

		return totalAffinity; // User.affinity = User.calcTotalAff(User);
	}

	void Qualities::printHeader() {
		std::cout
			<< "\t--------------\n\tTAROT GUESSER\n\t--------------\n\n";
	}

	void Qualities::printAll(Qualities userObj, int i) {
		std::cout << "Name: " << userObj.name << "\n" << "Age: " << userObj.age << "\n"
			<< "Day of Birth: " << userObj.dayOfBirth << "\n" << "Status: " << userObj.status << "\n"
			<< "Sex: " << userObj.sex << "\n" << "Happiness: " << userObj.happiness;
		if (i > 0) {
			std::cout << "\n" << "Affinity: " << userObj.affinity;
		}
		std::cout << "\n\n";
	}

	void Qualities::wait() {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "\n";
	}

	void Qualities::load(int repeat, int milliseconds) {
		for (int i = 0; i < repeat; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
			std::cout << " .";
		}

		std::cout << "\n";
	}
}