#include <iostream>
using namespace std;


void showPopulation(int day, int susceptible, int infected, int recovered);

int main() {
	int susceptible = 80; //liczby osób
	int infected = 10;
	int recovered = 10;
	int day = 0; //numer dnia

	double infectionRate = 0.20;
	double recoveryRate = 0.10;

	showPopulation(day, susceptible, infected, recovered);
	return 0;
	
	int choice = 0;
	while (true) {
		cout << "=== Epidemic Simulator ===" << endl;
		cout << "1. Simulate next day" << endl;
		cout << "2. Change model parametres" << endl;
		cout << "3. Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;


		switch (choice) {
		case 1:
				// miejsce na obliczenie kolejnego dnia
				break;
			case 2:
				// miejsce na zmianę parametrów
				break;
			case 3:
				cout << "Koniec programu." << endl;
				break;
			default:
				cout << "Nieprawidłowa opcja! Sprobuj ponownie." << endl;
				break;

		}
	}
}
void showPopulation(int day, int susceptible, int infected, int recovered) {
	cout << "Dzien " << day << "| Podatni: " << susceptible << "| Zakazeni: "
		<< infected << "| Ozdrowiency: " << recovered << endl;
}
