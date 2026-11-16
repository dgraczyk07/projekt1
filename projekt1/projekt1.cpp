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
		cout << "2. Change model parameteres" << endl;
		cout << "3. Exit"<< endl;
		cout << "\nYour choice: " << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				simulateDay(day, susceptible, infected, recovered, infectionRate, recoveryRate);
				if (!checkPopulation(susceptible, infected, recovered)) {
					cout << "Error: Invalid population state! Stopping simulation." << endl;
					return 1;
				}
				break;
			case 2: {
				double newInfectionRate;
				double newRecoveryRate;

				cout << "Enter infection rate (0.0 - 1.0): ";
				cin >> newInfectionRate;
				cout << "Enter recovery rate (0.0 - 1.0): ";
				cin >> newRecoveryRate;

				if (newInfectionRate >= 0.0 && newInfectionRate <= 1.0 &&
					newRecoveryRate >= 0.0 && newRecoveryRate <= 1.0) {
					infectionRate = newInfectionRate;
					recoveryRate = newRecoveryRate;
					cout << "Parameters updated." << endl;
				}
				else {
					cout << "Invalid parameters! Rates must be between 0 and 1." << endl;
				}
				break;
			}
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

		bool checkPopulation(int susceptible, int infected, int recovered) {
			if (susceptible < 0 || infected < 0 || recovered < 0) {
				return false;
			}
			if (susceptible + infected + recovered != 100) {
				return false;
			}
			return true;
		}
	
