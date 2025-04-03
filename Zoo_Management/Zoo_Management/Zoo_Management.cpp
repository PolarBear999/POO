// Zoo_Management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
    static Animal* listaAnimale[100];
    static int nrAnimale;
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
        RECIFE_CORALI,
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
    string nume;
    string specie;
    bool disponibil;
    int id;
    int varsta;
    double lungime;
    double greutate;
    string descriere;
    int categorie;
    int continente;
    int habitat;
    int status;
    double cost;
    string continentele;
    Animal(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, double cost) : nume(nume), specie(specie), disponibil(disponibil), id(id), varsta(varsta), lungime(lungime), greutate(greutate), descriere(descriere), categorie(categorie), habitat(habitat), status(status), continente(continente), cost(cost) {}
    void afiseaza() {
        afiseazaContinente();
        cout << "ID: " << id << " | " << nume << " (" << specie << ")\n";
        cout << "Specie: " << specie << " | Varsta: " << varsta << " ani | Greutate: " << greutate << " kg\n";
        cout << "Lungime: " << lungime << " m | Cost: " << cost << " lei/luna\n";
        cout << "Habitat: " << habitat << " | Continente: " << continentele << " | Status: " << status << "\n";
        cout << "Descriere: " << descriere << endl;
        cout << "Disponibil: " << (disponibil ? "Da" : "Nu") << endl;
        cout << "--------------------------------------\n";
    }
    void citesteContinente() {
        continente = 0;
        string listaContinente;
        cout << "Introduceti continentele, unul pe fiecare linie. Introduceti 'STOP' la final:\n";
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
                cout << "Continentele au fost introduse cu success!\n";
            else
                cout << "Continentul introdus este invalid! (" << listaContinente << ")\n";
        }
    }
    void afiseazaContinente() {
        if (continente & AMERICA_DE_NORD) continentele += "America de Nord ";
        if (continente & AMERICA_DE_SUD) continentele += "America de Sud ";
        if (continente & EUROPA) continentele += "Europa ";
        if (continente & AFRICA) continentele += "Africa ";
        if (continente & ASIA) continentele += "Asia ";
        if (continente & OCEANIA) continentele += "Oceania ";
        if (continente & ANTARCTICA) continentele += "Antarctica ";
    }
    void adaugaAnimal();
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
            if (listaAnimale[i]->nume == nume || listaAnimale[i]->nume == nume) {
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
    void AnimalDisponibil(string tip) {
        for (int i = 0; i < nrAnimale; i++) {
            if (listaAnimale[i]->specie == tip) {
                cout << "Animalul este " << (listaAnimale[i]->disponibil ? "Disponibil" : "Indisponibil") << " pentru vizita.\n";
                if (listaAnimale[i]->disponibil) cout << "Pretul pentru vizita este de " << listaAnimale[i]->cost << "lei.\n";
            }
        }
    }
    Animal* cautaAnimalDupaID(int ID) {
        for (int i = 0; i < nrAnimale; i++) {
            if (listaAnimale[i]->id == ID) {
                return listaAnimale[i];
            }
        }
        return nullptr;
    }
    static void afisareToateAnimalele() {
        cout << "\nAnimalele de la Zoo!\n";
        for (int i = 0; i < nrAnimale; i++) {
            listaAnimale[i]->afiseaza();
        }
        cout << "\n";
    }
};
class Mamifer : public Animal {
public:
    enum Nutritie {
        CARNIVOR,
        IERBIVOR,
        OMNIVOR
    };
    int nutritie;
    double pret;
    Mamifer(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(pret) {}
};
class Pasare : public Animal {
public:
    enum Migratie {
        MIGRATOARE,
        SEMIMIGRATOARE,
        NEMIGRATOARE,
        NOMADA
    };
    enum Nutritie {
        CARNIVOR,
        IERBIVOR,
        OMNIVOR
    };
    int nutritie, migratie;
    double pret;
    Pasare(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, Migratie migratie) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(pret), migratie(migratie) {}
};
class Reptila : public Animal {
public:
    enum Nutritie {
        CARNIVOR,
        IERBIVOR,
        OMNIVOR
    };
    int nutritie;
    double pret;
    bool veninos;
    Reptila(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, bool veninos) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(pret), veninos(veninos) {}

};
class Amfibian : public Animal {
public:
    enum Nutritie {
        CARNIVOR,
        IERBIVOR,
        OMNIVOR
    };
    int nutritie;
    double pret;
    bool acvatic;
    Amfibian(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, bool acvatic) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(pret), acvatic(acvatic) {}
};
class Peste : public Animal {
public:
    string specie;
    enum Nutritie {
        CARNIVOR,
        IERBIVOR,
        OMNIVOR
    };
    int nutritie, adancimeMax;
    double pret;
    Peste(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, int adancimeMax) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(pret), adancimeMax(adancimeMax) {}
};
class Nevertebrata : public Animal {
public:
    string specie;
    enum Nutritie {
        CARNIVOR,
        IERBIVOR,
        OMNIVOR
    };
    int nutritie;
    double pret;
    Nevertebrata(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(pret) {}
};
Animal* Animal::listaAnimale[100];
int Animal::nrAnimale;
void Animal::adaugaAnimal() {
    {
        int tipAnimal;
        cout << "Alege tipul animalului (0 - Mamifer, 1 - Pasare, 2 - Reptila, 3 - Amfibian, 4 - Peste, 5 - Nevertebrata): ";
        cin >> tipAnimal;
        cout << "Introduceti numele: ";
        cin >> nume;
        cout << "Introduceti specia: ";
        cin >> specie;
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
        cout << "Introduceti descriere: ";
        cin.ignore();
        getline(cin, descriere);
        cout << "Introduceti categoria (0-Mamifere, 1-Pasari, 2-Reptile, 3-Amfibieni, 4-Pesti, 5-Nevertebrate): ";
        cin >> categorie;
        cout << "Introduceti habitatul (0-Paduri Temperate, 1-Paduri Conifere,2-Paduri_Tropicale,3-Munti,4-Desert,5-Campie,6-Lacuri,7-Rauri,8-Mlastini,9-Plaje,10-Oceane,11-Recife Corali,12-Regiuni Polare,13-Zone Urbane, 14-Parazite): ";
        cin >> habitat;
        cout << "Introduceti statusul (0-Disparut, 1-Pericol Grav, 2-Pericol, 3-Vulnerabil, 4-Risc Redus, 5-Comun): ";
        cin >> status;
        cout << "Introduceti cost aproximativ lunar pentru mentenanta, intretinere si mancare (lei): ";
        cin >> cost;
        citesteContinente();
        switch (tipAnimal) {
        case 0: {
            int nutritie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            Mamifer* newMamifer = new Mamifer(nume, specie, true, nrAnimale + 1, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Mamifer::Nutritie(nutritie), 100.0);
            listaAnimale[nrAnimale++] = newMamifer;
            break;
        }
        case 1: {
            int nutritie, migratie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            cout << "Introduceti tipul de migratie (0-Migratoare, 1-Semi-migratoare,2-Nemigratoare,3-Nomada)";
            cin >> migratie;
            Pasare* newPasare = new Pasare(nume, specie, true, nrAnimale + 1, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Pasare::Nutritie(nutritie), 75.0, Pasare::Migratie(migratie));
            listaAnimale[nrAnimale++] = newPasare;
            break;
        }
        case 2: {
            bool veninos;
            cout << "Este veninos? (1 - Da, 0 - Nu): ";
            cin >> veninos;
            int nutritie;
            Reptila* newReptila = new Reptila(nume, specie, true, nrAnimale + 1, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Reptila::Nutritie(nutritie), veninos, 50.0);
            listaAnimale[nrAnimale++] = newReptila;
            break;
        }
        case 3: {
            bool acvatic;
            cout << "Poate trai in apa? (1 - Da, 0 - Nu): ";
            cin >> acvatic;
            int nutritie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            Amfibian* newAmfibian = new Amfibian(nume, specie, true, nrAnimale + 1, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Amfibian::Nutritie(nutritie), acvatic, 25.0);
            listaAnimale[nrAnimale++] = newAmfibian;
            break;
        }
        case 4: {
            int adancimeMax;
            cout << "Introduceti adancimea maxima la care se gaseste:  ";
            cin >> adancimeMax;
            int nutritie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            Peste* newPeste = new Peste(nume, specie, true, nrAnimale + 1, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Peste::Nutritie(nutritie), adancimeMax, 25.0);
            listaAnimale[nrAnimale++] = newPeste;
            break;
        }
        case 5: {
            int nutritie;
            Nevertebrata* newNevertebrata = new Nevertebrata(nume, specie, true, nrAnimale + 1, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Nevertebrata::Nutritie(nutritie), 0.0);
            listaAnimale[nrAnimale++] = newNevertebrata;
            break;
        }
        default:
            cout << "Optiune invalida!" << endl;
            return;
        }
        cout << "Animalul a fost adaugat cu success!";
        listaAnimale[nrAnimale - 1]->stergeAnimal(nrAnimale);
    }
}
int main()
{
    //Animal::listaAnimale[Animal::nrAnimale++] = new Animal("Simba", "Leu", true, 1, 10, 2.5, 190, "Leu", "Leul este regele junglei.", Animal::MAMIFERE, Animal::CAMPIE, Animal::VULNERABIL, Animal::AFRICA | Animal::EUROPA, Mamifer::CARNIVOR);
    //Animal::listaAnimale[Animal::nrAnimale++] = new Animal("Sherekan", "Tigru Alb Manzian", false, 2, 8, 3.0, 220, "Tigru Alb Manzian", "Tigrul alb manzian este foarte rar!", Animal::MAMIFERE, Animal::DESERT, Animal::VULNERABIL, Animal::AFRICA, Animal::CARNIVOR);

    int optiune;
    Animal::listaAnimale[Animal::nrAnimale++] = new Animal("Simba", "Leu", true, 0, 10, 2, 190, "Leul este regele junglei.", Animal::MAMIFERE, Animal::CAMPIE, Animal::VULNERABIL, Animal::AFRICA | Animal::EUROPA, 0);
    do {
        cout << "\n1. Vezi animale\n2. Adauga animal\n3. Sterge animal\n4. Cauta dupa nume\n5. Iesire\nOptiune: ";
        cin >> optiune;
        switch (optiune) {
        case 1: Animal::afisareToateAnimalele(); break;
        case 2: Animal::listaAnimale[0]->adaugaAnimal(); break;
        case 3: { int id; cout << "ID: "; cin >> id; Animal::listaAnimale[0]->stergeAnimal(id); break; }
        case 4: { string nume; cout << "Nume: "; cin >> nume; Animal::listaAnimale[0]->cautaAnimalDupaNume(nume); break; }
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
