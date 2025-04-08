// Zoo_Management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string citesteParolaDinFisier(const string& path) {
    ifstream fisier(path);
    string linie;

    while (getline(fisier, linie)) {
        if (linie.find("ADMIN_PASSWORD=") == 0) {
            return linie.substr(15);
        }
    }

    return "";
}

class Animal {
protected:
    int varsta;
    double lungime;
    double greutate;
    double cost;
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
    int id;
    bool disponibil;
    string descriere;
    int categorie;
    int continente;
    int habitat;
    int status;
    string continentele;
    string habitatele;
    string cat;
    string statusul;
    void afiseazaHabitate() {
        string habitat;

        switch (this->habitat) {
        case PADURI_TEMPERATE:
            habitat = "Paduri Temperate";
            break;
        case PADURI_CONIFERE:
            habitat = "Paduri Conifere";
            break;
        case PADURI_TROPICALE:
            habitat = "Paduri Tropicale";
            break;
        case MUNTI:
            habitat = "Munti";
            break;
        case DESERT:
            habitat = "Desert";
            break;
        case CAMPIE:
            habitat = "Campie";
            break;
        case LACURI:
            habitat = "Lacuri";
            break;
        case RAURI:
            habitat = "Rauri";
            break;
        case MLASTINI:
            habitat = "Mlastini";
            break;
        case PLAJE:
            habitat = "Plaje";
            break;
        case OCEANE:
            habitat = "Oceane";
            break;
        case RECIFE_CORALI:
            habitat = "Recife Corali";
            break;
        case REGIUNI_POLARE:
            habitat = "Regiuni Polare";
            break;
        case ZONE_URBANE:
            habitat = "Zone Urbane";
            break;
        case PARAZITE:
            habitat = "Parazite";
            break;
        default:
            habitat = "Necunoscut";
        }
        habitatele = habitat;
    }
    void afiseazaCategorie() {
        string categorie;

        switch (this->categorie) {
        case MAMIFERE:
            categorie = "Mamifere";
            break;
        case PASARI:
            categorie = "Pasari";
            break;
        case REPTILE:
            categorie = "Reptile";
            break;
        case AMFIBIENI:
            categorie = "Amfibieni";
            break;
        case PESTI:
            categorie = "Pesti";
            break;
        case NEVERTEBRATE:
            categorie = "Nevertebrate";
            break;
        default:
            categorie = "Necunoscuta";
        }

        cat = categorie;
    }
    void afiseazaStatus() {
        string status;

        switch (this->status) {
        case DISPARUT:
            status = "Disparut";
            break;
        case PERICOL_GRAV:
            status = "Pericol Grav";
            break;
        case PERICOL:
            status = "Pericol";
            break;
        case VULNERABIL:
            status = "Vulnerabil";
            break;
        case RISC_REDUS:
            status = "Risc Redus";
            break;
        case COMUNE:
            status = "Comune";
            break;
        default:
            status = "Necunoscut";
        }

        statusul = status;
    }
    string afiseazaNutritie(int nutritia) {
        string tipNutritie;
        switch (nutritia) {

        case 0:
            tipNutritie = "Carnivor";
            break;
        case 1:
            tipNutritie = "Ierbivor";
            break;
        case 2:
            tipNutritie = "Omnivor";
            break;
        default:
            tipNutritie = "Necunoscut";
        }

        return tipNutritie;
    }
    Animal(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, double cost) : nume(nume), specie(specie), disponibil(disponibil), id(id), varsta(varsta), lungime(lungime), greutate(greutate), descriere(descriere), categorie(categorie), habitat(habitat), status(status), continente(continente), cost(cost) {}
    virtual ~Animal() {}
    virtual void afiseaza() {
        afiseazaContinente();
        afiseazaCategorie();
        afiseazaHabitate();
        afiseazaStatus();
        cout << "ID: " << id << " | " << nume << " (" << cat << ")\n";
        cout << "Specie: " << specie << " | Varsta: " << varsta << " ani | Greutate: " << greutate << " kg\n";
        cout << "Lungime: " << lungime << " m | Cost: " << cost << " lei/luna\n";
        cout << "Habitat: " << habitatele << " | Continente: " << continentele << " | Status: " << statusul << "\n";
        cout << "Descriere: " << descriere << endl;
        cout << "Disponibil: " << (disponibil ? "Da" : "Nu") << endl;
    }
    void citesteContinente() {
        continente = 0;
        string listaContinente;
        cout << "Introduceti continentele, unul pe fiecare linie. Introduceti 'STOP' la final:\n";
        while (listaContinente != "STOP") {
            cin >> listaContinente;
            if (listaContinente == "AMERICA_DE_NORD")
                this->continente |= AMERICA_DE_NORD;
            else if (listaContinente == "AMERICA_DE_SUD")
                this->continente |= AMERICA_DE_SUD;
            else if (listaContinente == "EUROPA")
                this->continente |= EUROPA;
            else if (listaContinente == "AFRICA")
                this->continente |= AFRICA;
            else if (listaContinente == "ASIA")
                this->continente |= ASIA;
            else if (listaContinente == "OCEANIA")
                this->continente |= OCEANIA;
            else if (listaContinente == "ANTARCTICA")
                this->continente |= ANTARCTICA;
            else if (listaContinente == "STOP")
                cout << "Continentele au fost introduse cu success!\n";
            else
                cout << "Continentul introdus este invalid! (" << listaContinente << ")\n";
        }
    }
    void afiseazaContinente() {
        continentele = "";
        if (this->continente & AMERICA_DE_NORD) continentele += "America de Nord ";
        if (this->continente & AMERICA_DE_SUD) continentele += "America de Sud ";
        if (this->continente & EUROPA) continentele += "Europa ";
        if (this->continente & AFRICA) continentele += "Africa ";
        if (this->continente & ASIA) continentele += "Asia ";
        if (this->continente & OCEANIA) continentele += "Oceania ";
        if (this->continente & ANTARCTICA) continentele += "Antarctica ";
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
    static void sorteazaDupaID() {
        for (int i = 0; i < nrAnimale - 1; i++) {
            for (int j = i + 1; j < nrAnimale; j++) {
                if (listaAnimale[i]->id > listaAnimale[j]->id) {
                    swap(listaAnimale[i], listaAnimale[j]);
                }
            }
        }
    }
    static void AnimalDisponibil(string tip) {
        int pret;
        for (int i = 0; i < nrAnimale; i++) {
            if (listaAnimale[i]->specie == tip) {
                switch (listaAnimale[i]->categorie) {
                case 0: pret = 100; break;
                case 1: pret = 75; break;
                case 2: pret = 50; break;
                case 3: pret = 50; break;
                case 4: pret = 25; break;
                case 5: pret = 10; break;
                }
                cout << "Animalul este " << (listaAnimale[i]->disponibil ? "Disponibil" : "Indisponibil") << " pentru vizita.\n";
                if (listaAnimale[i]->disponibil) cout << "Pretul pentru vizita este de " << pret << "lei.\n";
            }
        }
    }
    static void cautaAnimalDupaID(int ID) {
        for (int i = 0; i < nrAnimale; i++) {
            if (listaAnimale[i]->id == ID) {
                listaAnimale[i]->afiseaza();
            }
            else {
                cout << "Animalul cu acest ID nu exista.";
            }
        }
    }
    static void afisareToateAnimalele() {
        cout << "\nAnimalele de la Zoo!\n";
        for (int i = 0; i < nrAnimale; i++) {
            listaAnimale[i]->afiseaza();
        }
        cout << "\n";
    }
    int getID() const {
        return id;
    }
    bool verificaID(int id) {
        for (int i = 0; i < nrAnimale; ++i) {
            if (listaAnimale[i]->getID() == id) {
                return true;
            }
        }
        return false;
    }
    virtual int getAdancimeMax() {
        return -1;
    }
    virtual int getNutritie() {
        return -1;
    }
};
class Admin {
    friend class Animal;
    void sorteazaDupaID() {
        for (int i = 0; i < Animal::nrAnimale - 1; i++) {
            for (int j = i + 1; j < Animal::nrAnimale; j++) {
                if (Animal::listaAnimale[i]->id > Animal::listaAnimale[j]->id) {
                    swap(Animal::listaAnimale[i], Animal::listaAnimale[j]);
                }
            }
        }
    }
public:
    static void meniuAdmin();
};
class Utilizator {
public:
    static void meniuUtilizator();
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
    Mamifer(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, double cost) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(100.0) {}
    void afiseaza() override {
        Animal::afiseaza();
        cout << "Nutritie: " << Animal::afiseazaNutritie(nutritie) << endl;
        cout << "--------------------------------------\n";
    }
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
    Pasare(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, Migratie migratie, double cost) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(75.0), migratie(migratie) {}
    string afiseazaMigratie() {
        string tipMigratie;

        switch (this->migratie) {
        case MIGRATOARE:
            tipMigratie = "Migratoare";
            break;
        case SEMIMIGRATOARE:
            tipMigratie = "Semimigratoare";
            break;
        case NEMIGRATOARE:
            tipMigratie = "Nemigratoare";
            break;
        case NOMADA:
            tipMigratie = "Nomada";
            break;
        default:
            tipMigratie = "Necunoscut";
        }

        return tipMigratie;
    }
    void afiseaza() override {
        Animal::afiseaza();
        cout << "Tip Migratie: " << afiseazaMigratie() << endl;
        cout << "Nutritie: " << Animal::afiseazaNutritie(nutritie) << endl;
        cout << "--------------------------------------\n";
    }
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
    Reptila(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, bool veninos, double cost) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(50.0), veninos(veninos) {}
    void afiseaza() override {
        Animal::afiseaza();
        cout << "Este Veninos? " << boolalpha << veninos << endl;
        cout << "Nutritie: " << Animal::afiseazaNutritie(nutritie) << endl;
        cout << "--------------------------------------\n";
    }
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
    void afiseaza() override {
        Animal::afiseaza();
        cout << "Este acvatic? " << boolalpha << acvatic << endl;
        cout << "Nutritie: " << Animal::afiseazaNutritie(nutritie) << endl;
        cout << "--------------------------------------\n";
    }
    Amfibian(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, bool acvatic, double cost) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(25.0), acvatic(acvatic) {}
};
class Peste : public Animal {
public:
    enum Nutritie {
        CARNIVOR,
        IERBIVOR,
        OMNIVOR
    };
    int nutritie;
    int adancimeMax;
    double pret;
    Peste(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, int adancimeMax, double cost) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(pret), adancimeMax(adancimeMax) {}
    //        int getNutritie() override {
    //            return nutritie;
    //        }
    int getAdancimeMax() override {
        return adancimeMax;
    }
    void afiseaza() override {
        Animal::afiseaza();
        cout << "Adancime Maxima: " << Animal::listaAnimale[Animal::nrAnimale]->getAdancimeMax() << endl;
        cout << "Nutritie: " << Animal::afiseazaNutritie(nutritie) << endl;
        cout << "--------------------------------------\n";
    }
};
class Nevertebrata : public Animal {
public:
    enum Nutritie {
        CARNIVOR,
        IERBIVOR,
        OMNIVOR
    };
    int nutritie;
    double pret;
    Nevertebrata(string nume, string specie, bool disponibil, int id, int varsta, double lungime, double greutate, string descriere, Categorie categorie, Habitat habitat, Status status, int continente, int nutritie, double pret, double cost) : Animal(nume, specie, disponibil, id, varsta, lungime, greutate, descriere, categorie, habitat, status, continente, cost), nutritie(nutritie), pret(10.0) {}
    void afiseaza() override {
        Animal::afiseaza();
        cout << "Nutritie: " << Animal::afiseazaNutritie(nutritie) << endl;
        cout << "--------------------------------------\n";
    }
};
Animal* Animal::listaAnimale[100];
int Animal::nrAnimale = 0;
void Animal::adaugaAnimal() {
    {
        cout << "Introduceti numele: ";
        cin >> this->nume;
        cout << "Introduceti specia: ";
        cin >> this->specie;
        cout << "Este disponibil? (1 - Da, 0 - Nu): ";
        cin >> this->disponibil;
        cout << "Introduceti varsta: ";
        cin >> this->varsta;
        cout << "Introduceti lungimea (m): ";
        cin >> this->lungime;
        cout << "Introduceti greutatea (kg): ";
        cin >> this->greutate;
        cout << "Introduceti descriere: ";
        cin.ignore();
        getline(cin, descriere);
        //            cout << "Introduceti categoria (0-Mamifere, 1-Pasari, 2-Reptile, 3-Amfibieni, 4-Pesti, 5-Nevertebrate): ";
        //            cin >> this->categorie;
        cout << "Introduceti habitatul (0-Paduri Temperate, 1-Paduri Conifere,2-Paduri_Tropicale,3-Munti,4-Desert,5-Campie,6-Lacuri,7-Rauri,8-Mlastini,9-Plaje,10-Oceane,11-Recife Corali,12-Regiuni Polare,13-Zone Urbane, 14-Parazite): ";
        cin >> this->habitat;
        cout << "Introduceti statusul (0-Disparut, 1-Pericol Grav, 2-Pericol, 3-Vulnerabil, 4-Risc Redus, 5-Comun): ";
        cin >> this->status;
        cout << "Introduceti cost aproximativ lunar pentru mentenanta, intretinere si mancare (lei): ";
        cin >> this->cost;
        citesteContinente();
        switch (this->categorie) {
        case 0: {
            int nutritie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            Mamifer* newMamifer = new Mamifer(nume, specie, true, id, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Mamifer::Nutritie(nutritie), 100.0, cost);
            listaAnimale[nrAnimale] = newMamifer;
            break;
        }
        case 1: {
            int nutritie, migratie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            cout << "Introduceti tipul de migratie (0-Migratoare, 1-Semi-migratoare,2-Nemigratoare,3-Nomada): ";
            cin >> migratie;
            Pasare* newPasare = new Pasare(nume, specie, true, id, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Pasare::Nutritie(nutritie), 75.0, Pasare::Migratie(migratie), cost);
            listaAnimale[nrAnimale] = newPasare;
            break;
        }
        case 2: {
            bool veninos;
            cout << "Este veninos? (1 - Da, 0 - Nu): ";
            cin >> veninos;
            int nutritie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            Reptila* newReptila = new Reptila(nume, specie, true, id, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Reptila::Nutritie(nutritie), 50.0, veninos, cost);
            listaAnimale[nrAnimale] = newReptila;
            break;
        }
        case 3: {
            bool acvatic;
            cout << "Poate trai in apa? (1 - Da, 0 - Nu): ";
            cin >> acvatic;
            int nutritie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            Amfibian* newAmfibian = new Amfibian(nume, specie, true, id, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Amfibian::Nutritie(nutritie), 50.0, acvatic, cost);
            listaAnimale[nrAnimale] = newAmfibian;
            break;
        }
        case 4: {
            int adancimeMaxima;
            cout << "Introduceti adancimea maxima la care se gaseste:  ";
            cin >> adancimeMaxima;
            int nutritie;
            cout << "Introduceti nutritia (0-Carnivor, 1-Ierbivor, 2-Omnivor): ";
            cin >> nutritie;
            Peste* newPeste = new Peste(nume, specie, true, id, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Peste::Nutritie(nutritie), 25.0, adancimeMaxima, cost);
            listaAnimale[nrAnimale] = newPeste;
            break;
        }
        case 5: {
            int nutritie;
            Nevertebrata* newNevertebrata = new Nevertebrata(nume, specie, true, id, varsta, lungime, greutate, descriere, Categorie(categorie), Habitat(habitat), Status(status), continente, Nevertebrata::Nutritie(nutritie), 10.0, cost);
            listaAnimale[nrAnimale] = newNevertebrata;
            break;
        }
        default:
            cout << "Optiune invalida!" << endl;
            return;
        }
        cout << "Animalul a fost adaugat cu success!";
        //listaAnimale[nrAnimale-1]->stergeAnimal(nrAnimale);
    }
}
void Utilizator::meniuUtilizator() {
    int opt;
    do {
        cout << "\nMeniu Utilizator\n";
        cout << "1. Afiseaza toate animalele\n";
        cout << "2. Cauta animal dupa ID\n";
        cout << "3. Verifica disponibilitate animal dupa specie\n";
        cout << "0. Inapoi\n";
        cout << "Optiune: ";
        cin >> opt;

        switch (opt) {
        case 1:
            Animal::afisareToateAnimalele();
            break;
        case 2: {
            int id;
            cout << "ID cautat: ";
            cin >> id;
            Animal::cautaAnimalDupaID(id);
            break;
        }
        case 3: {
            string tip;
            cout << "Specie: ";
            cin >> tip;
            Animal::AnimalDisponibil(tip);
            break;
        }
        }
    } while (opt != 0);
}
void Admin::meniuAdmin() {
    //Animal::listaAnimale[Animal::nrAnimale++] = new Animal("Simba", "Leu", true, 1, 10, 2.5, 190, "Leu", "Leul este regele junglei.", Animal::MAMIFERE, Animal::CAMPIE, Animal::VULNERABIL, Animal::AFRICA | Animal::EUROPA, Mamifer::CARNIVOR);
    int optiune;
    Animal::listaAnimale[Animal::nrAnimale++] = new Mamifer("Simba", "Leu", true, 0, 10, 2.0, 190.0, "Leul este regele junglei.", Animal::MAMIFERE, Animal::CAMPIE, Animal::VULNERABIL, Animal::AFRICA | Animal::EUROPA, 2, 100.0, 200.0);
    Animal::listaAnimale[Animal::nrAnimale++] = new Mamifer("Sherekan", "Tigru Alb", false, 1, 8, 3.0, 220.0, "Tigrul alb manzian este foarte rar!", Animal::MAMIFERE, Animal::DESERT, Animal::VULNERABIL, Animal::AFRICA, 2, 100.0, 200.0);
    Animal::listaAnimale[Animal::nrAnimale++] = new Pasare("Dodo", "Dodo", true, 2, 10, 1.0, 10.0, "Dodo a disparut.", Animal::PASARI, Animal::PADURI_CONIFERE, Animal::DISPARUT, Animal::EUROPA, 1, 75.0, Pasare::SEMIMIGRATOARE, 250.0);
    do {
        cout << "\n1. Vezi animale\n2. Adauga animal\n3. Sterge animal\n4. Cauta dupa nume\n5. Cauta Animal dupa ID\n6. Verifica Disponibilitate dupa Specie\n7. Sorteaza Animale dupa ID\n8. Iesire\nOptiune: ";
        cin >> optiune;
        switch (optiune) {
        case 1: {
            Animal::afisareToateAnimalele();
            //            for (int i = 0; i < Animal::nrAnimale; i++) {
            //                Animal::listaAnimale[i]->afiseaza();
            //            }
        }; break;
        case 2: {
            int id;
            bool gasit = false;
            cout << "Introduceti ID: ";
            cin >> id;
            for (int i = 0; i < Animal::nrAnimale; i++) {
                if (Animal::listaAnimale[i]->id == id) {
                    cout << "Un animal cu acest ID exista deja!" << endl;
                    gasit = true;
                }
            }
            if (!gasit) {
                int tipA;
                cout << "Alege tipul animalului (0 - Mamifer, 1 - Pasare, 2 - Reptila, 3 - Amfibian, 4 - Peste, 5 - Nevertebrata): ";
                cin >> tipA;
                switch (tipA) {
                case 0: {
                    Animal::listaAnimale[Animal::nrAnimale++] = new Mamifer("Simba", "Leu", true, id, 10, 2.0, 190.0, "Leul este regele junglei.", Animal::MAMIFERE, Animal::CAMPIE, Animal::VULNERABIL, Animal::AFRICA | Animal::ASIA, Mamifer::OMNIVOR, 100.0, 200.0);
                    Animal::listaAnimale[Animal::nrAnimale - 1]->adaugaAnimal();
                    break;
                }
                case 1: {
                    Animal::listaAnimale[Animal::nrAnimale++] = new Pasare("Pen-Pen", "Pinguin", true, id, 10, 0.5, 5.0, "Pinguinii traiesc la polul sud.", Animal::PASARI, Animal::REGIUNI_POLARE, Animal::RISC_REDUS, Animal::ANTARCTICA, Pasare::OMNIVOR, 75.0, Pasare::NOMADA, 100.0);
                    Animal::listaAnimale[Animal::nrAnimale - 1]->adaugaAnimal();
                    break;
                }
                case 2: {
                    Animal::listaAnimale[Animal::nrAnimale++] = new Reptila("Pancake", "Dragon", true, id, 10, 0.5, 1.6, "Pancake este un dragon adorabil!", Animal::REPTILE, Animal::DESERT, Animal::COMUNE, Animal::AFRICA | Animal::ASIA | Animal::OCEANIA | Animal::AMERICA_DE_NORD, Reptila::OMNIVOR, 50.0, false, 250.0);
                    Animal::listaAnimale[Animal::nrAnimale - 1]->adaugaAnimal();
                    break;
                }
                case 3: {
                    Animal::listaAnimale[Animal::nrAnimale++] = new Amfibian("Nei-Li", "Axolotl", true, id, 10, 0.2, 1.0, "Axolotl provine din cultura azteca!", Animal::AMFIBIENI, Animal::LACURI, Animal::VULNERABIL, Animal::AMERICA_DE_NORD | Animal::OCEANIA, Amfibian::OMNIVOR, 50.0, true, 175.0);
                    Animal::listaAnimale[Animal::nrAnimale - 1]->adaugaAnimal();
                    break;
                }
                case 4: {
                    Animal::listaAnimale[Animal::nrAnimale++] = new Peste("Sharky", "Rechin", true, id, 10, 3.0, 400.0, "Rechinii sunt cei mai mari pesti!", Animal::PESTI, Animal::OCEANE, Animal::VULNERABIL, Animal::OCEANIA, Peste::CARNIVOR, 25.0, 2000, 225.0);
                    Animal::listaAnimale[Animal::nrAnimale - 1]->adaugaAnimal();
                    break;
                }
                case 5: {
                    Animal::listaAnimale[Animal::nrAnimale++] = new Nevertebrata("Spidey", "Paianjen", true, id, 10, 0.005, 0.005, "Panza lor este foarte durabila!", Animal::NEVERTEBRATE, Animal::ZONE_URBANE, Animal::COMUNE, Animal::OCEANIA | Animal::AFRICA | Animal::ASIA | Animal::OCEANIA | Animal::AMERICA_DE_NORD | Animal::AMERICA_DE_SUD, Nevertebrata::OMNIVOR, 10.0, 25.0);
                    Animal::listaAnimale[Animal::nrAnimale - 1]->adaugaAnimal();
                    break;
                }
                default:
                    cout << "Optiune invalida!" << endl;
                }
            }
        } break;
        case 3: { int id; cout << "ID: "; cin >> id; Animal::listaAnimale[0]->stergeAnimal(id); break; }
        case 4: { string nume; cout << "Nume: "; cin >> nume; Animal::listaAnimale[0]->cautaAnimalDupaNume(nume); break; }
        case 5: {
            int id;
            cout << "ID cautat: ";
            cin >> id;
            Animal::cautaAnimalDupaID(id);
            break;
        }
        case 6: {
            string tip;
            cout << "Specie: ";
            cin >> tip;
            Animal::AnimalDisponibil(tip);
            break;
        }
        case 7: {
            Animal::sorteazaDupaID();
            cout << "Animalele au fost sortate dupa ID.\n";
            break;
        }
        }
    } while (optiune != 8);
}
int main()
{
    int optiune;
    do {
        cout << "Meniu Principal\n";
        cout << "1. Utilizator\n";
        cout << "2. Admin\n";
        cout << "3. Iesire\n";
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune) {
        case 1:
            Utilizator::meniuUtilizator();
            break;
        case 2:
            string parolaIntrodusa;
            string parolaCorecta = citesteParolaDinFisier("config.env");

            cout << "Introdu parola de admin: ";
            cin >> parolaIntrodusa;

            if (parolaIntrodusa == parolaCorecta) {
                Admin::meniuAdmin();
            }
            else {
                cout << "Parola incorecta! Acces refuzat.\n";
            }
            break;
        }
    } while (optiune != 3);

    return 0;
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
