// Zoo_Management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
	enum Categorie
	{
		MAMIFERE,
		PASARI,
		REPTILE,
		AMFIBIENI,
		PESTI,
		NEVERTEBRATE
	};
	enum Habitat
	{
		PADURI_TEMPERATE,
		PADURI_CONIFERE,
		PADURI_TROPICALE,
		MUNTI,
		DESERT,
		CAMPIE,
		LACURI,
		RAURI,
		MLASTINI,
		PLAJE,
		OCEANE,
		RECIFE_COLARI,
		REGIUNI_POLARE,
		ZONE_URBANE,
		PARAZITE
	};
	enum Status {
		DISPARUT,
		PERICOL_GRAV,
		PERICOL,
		VULNERABIL,
		RISC_REDUS,
		COMUNE
	};
	enum Continente {
		AMERICA_DE_NORD = 1 << 0,
		AMERICA_DE_SUD = 1 << 1,
		EUROPA = 1 << 2,
		AFRICA = 1 << 3,
		ASIA = 1 << 4,
		OCEANIA = 1 << 5,
		ANTARCTICA = 1 << 6
	};
	enum Nutritie {
		CARNIVOR,
		IERBIVOR,
		OMNIVOR
	};
	string nume;
	string denumire;
	bool disponibil;
	int id;
	int varsta;
	double lungime;
	double greutate;
	string specie;
	string descriere;
	int categorie;
	int continente;
	int nutritie;
	int habitat;
	int status;
	double cost;
	Animal(string nume, string denumire, bool disponibil, int id, int varsta, double lungime, double greutate, string specie, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, Nutritie nutritie) : nume(nume), denumire(denumire), disponibil(disponibil), id(id), varsta(varsta), lungime(lungime), greutate(greutate), specie(specie), descriere(descriere), categorie(categorie), habitat(habitat), status(status), continente(continente), nutritie(nutritie) {}
	void afiseaza() {
		cout << "ID: " << id << " | " << nume << " (" << denumire << ")\n";
		cout << "Specie: " << specie << " | Varsta: " << varsta << " ani | Greutate: " << greutate << " kg\n";
		cout << "Cost: " << cost << " lei/luna\n";
		cout << "--------------------------------------\n";
	}
	void citesteContinente() {
		continente = 0;
		string listaContinente;
		cout << "Introduceti continentele, unul pe fiecare linie. Introduceti 'STOP' la final.";
		while (listaContinente != "STOP") {
			cin >> listaContinente;
			if (listaContinente == "AMERICA_DE_NORD")
				continente |= AMERICA_DE_NORD;
			else if (listaContinente == "AMERICA_DE_SUD")
				continente |= AMERICA_DE_SUD;
			else if (listaContinente == "EUROPA")
				continente |= EUROPA;
			else if (listaContinente == "AFRICA")
				continente |= AFRICA;
			else if (listaContinente == "ASIA")
				continente |= ASIA;
			else if (listaContinente == "OCEANIA")
				continente |= OCEANIA;
			else if (listaContinente == "ANTARCTICA")
				continente |= ANTARCTICA;
			else if (listaContinente == "STOP")
				cout << "Continentele au fost introduse cu success!";
			else
				cout << "Continentul introdus este invalid! (" << listaContinente << ")\n";
		}
	}
	void adaugaAnimal() {
		cout << "Introduceti numele: ";
		cin >> nume;
		cout << "Introduceti denumirea: ";
		cin >> denumire;
		cout << "Este disponibil? (1 - Da, 0 - Nu): ";
		cin >> disponibil;
		cout << "Introduceti ID: ";
		cin >> id;
		cout << "Introduceti varsta: ";
		cin >> varsta;
		cout << "Introduceti lungimea (m): ";
		cin >> lungime;
		cout << "Introduceti greutatea (kg): ";
		cin >> greutate;
		cout << "Introduceti specia: ";
		cin >> specie;
		cout << "Introduceti descriere: ";
		cin.ignore();
		getline(cin, descriere);
		cout << "Introduceti categoria (0-Mamifere, 1-Pasari, 2-Reptile, 3-Amfibieni, 4-Pesti, 5-Nevertebrate): ";
		cin >> categorie;
		cout << "Introduceti habitatul (0-Paduri, 1-Munti, 2-Desert, 3-Ocean, 4-Urbane): ";
		cin >> habitat;
		cout << "Introduceti statusul (0-Disparut, 1-Pericol Grav, 2-Pericol, 3-Vulnerabil, 4-Risc Redus, 5-Comun): ";
		cin >> status;
		cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
		cin >> nutritie;
		citesteContinente();
		cout << "Animalul a fost adaugat cu success!";
	}
	Animal() {}
	void stergeAnimal(int ID) {
		for (int i = 0; i < nrAnimale; i++) {
			if (listaAnimale[i]->id == ID) {
				delete listaAnimale[i];
				for (int j = i; j < nrAnimale - 1; j++) {
					listaAnimale[j] = listaAnimale[j + 1];
				}
				nrAnimale--;
				cout << "Animalul a fost sters.\n";
				return;
			}
		}
		cout << "Animalul nu a fost gasit!\n";
	}
	void cautaAnimalDupaNume(string nume) {
		for (int i = 0; i < nrAnimale; i++) {
			if (listaAnimale[i]->nume == nume || listaAnimale[i]->denumire == nume) {
				listaAnimale[i]->afiseaza();
				return;
			}
		}
		cout << "Animalul nu a fost gasit!\n";
	}
	void sorteazaDupaID() {
		for (int i = 0; i < nrAnimale - 1; i++) {
			for (int j = i + 1; j < nrAnimale; j++) {
				if (listaAnimale[i]->id > listaAnimale[j]->id) {
					swap(listaAnimale[i], listaAnimale[j]);
				}
			}
		}
	}
};

Animal* listaAnimale[100];
int nrAnimale = 0;
Animal* cautaAnimalDupaID(int ID) {
	for (int i = 0; i < nrAnimale; i++) {
		if (listaAnimale[i]->id == ID) {
			return listaAnimale[i];
		}
	}
	return nullptr;
}
void afisareToateAnimalele() {
	cout << "\nAnimalele de la Zoo!\n";
	for (int i = 0; i < nrAnimale; i++) {
		listaAnimale[i]->afiseaza();
	}
	cout << "\n";
}
class Mamifer : public Animal {
public:
	string tipMamifer;
	string specie;
	string nume;
};
class Pasare : public Animal {
public:
	string tipPasare;
	string specie;
	enum migratie {
		MIGRATOARE,
		SEMIMIGRATOARE,
		NEMIGRATOARE,
		NOMADA
	};
};
class Reptila : public Animal {
public:
	string tipReptila;
	string specie;
};
int main()
{
	listaAnimale[nrAnimale++] = new Animal("Leu", "Regele Junglei", true, 1, 10, 2.5, 190, Animal::MAMIFERE, Animal::PADURI_TROPICALE, Animal::VULNERABIL, Animal::CARNIVOR);
	listaAnimale[nrAnimale++] = new Animal("Tigru", "Tigrul Bengal", true, 2, 8, 3.0, 220, Animal::MAMIFERE, Animal::DESERT, Animal::VULNERABIL, Animal::CARNIVOR);

	int optiune;
	do {
		cout << "\n1. Vezi animale\n2. Adauga animal\n3. Sterge animal\n4. Cauta dupa nume\n5. Iesire\nOptiune: ";
		cin >> optiune;
		Animal tempAnimal("", "", true, 0, 0, 0.0, 0.0, "", "", Animal::MAMIFERE, Animal::PADURI_TROPICALE, Animal::COMUNE, Animal::AFRICA, Animal::CARNIVOR);
		switch (optiune) {
		case 1: afisareToateAnimalele(); break;
		case 2: tempAnimal.adaugaAnimal(); break;
		case 3: { int id; cout << "ID: "; cin >> id; tempAnimal.stergeAnimal(id); break; }
		case 4: { string nume; cout << "Nume: "; cin >> nume; tempAnimal.cautaAnimalDupaNume(nume); break; }
		}
	} while (optiune != 5);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
