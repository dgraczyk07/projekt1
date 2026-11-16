#include <iostream>
#include <cmath>
using namespace std;

void showPopulation(int day, int susceptible, int infected, int recovered, int total);
void simulateDay(int& day, int& susceptible, int& infected, int& recovered, double infectionRate, double recoveryRate);
bool checkPopulation(int susceptible, int infected, int recovered);

int main() {
	int susceptible = 80; //liczba osób podatnych
	int infected = 10; //l. osób zakażonych
	int recovered = 10; //l. ozdrowieńców
	int day = 0; //numer dnia
	int total = 100; //suma/liczba populacji

	double infectionRate = 0.20;
	double recoveryRate = 0.10;

	int choice = 0;
	while (true) {
		showPopulation(day, susceptible, infected, recovered, total);
		cout << "\n=== Epidemic Simulator ===" << endl;
		cout << "1. Simulate next day" << endl;
		cout << "2. Change model parametres" << endl;
		cout << "3. Exit"<< endl;
		cout << "\nYour choice: " << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				simulateDay(day, susceptible, infected, recovered, infectionRate, recoveryRate);
				break;
			case 2:
				// miejsce na zmianę parametrów
				break;
			case 3:
				cout << "End of program." << endl;
				return 0;
			default:
				cout << "Invalid option. Please try again." << endl;
				break;

		}
	}
	return 0;
}
void showPopulation(int day, int susceptible, int infected, int recovered, int total) {
	cout << "Day " << day << "| Susceptible: " << susceptible << "| Infected: "
		<< infected << "| Recovered: " << recovered << "| Total: " << total << endl;
}
void simulateDay(int& day, int& susceptible, int& infected, int& recovered, double infectionRate, double recoveryRate) {
		int initialInfected = infected; //zapamiętuje liczbę zakażonych na początku dnia

		int newInfections = static_cast<int>(floor(initialInfected * infectionRate));
		int newRecoveries = static_cast<int>(floor(initialInfected * recoveryRate)); //oblicza nowe zakażenia i nowe ozdrowienia (zaokrąglone w dół)

		if (newInfections > susceptible) {
			newInfections = susceptible;
		} //ogranicza nowe zakażenia do liczby osób podatnych

		if (newRecoveries > initialInfected) {
			newRecoveries = initialInfected;
		}//ogranicza nowe ozdrowienia do liczby osób zakażonych

		susceptible = susceptible - newInfections;
		infected = infected + newInfections - newRecoveries;
		recovered = recovered + newRecoveries;//aktualizacja wszystkich grup

		day++; //kolejny dzień.
	}
