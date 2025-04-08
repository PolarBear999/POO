#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int locuri_parcare = 10;

class LocParcare;

class Admin;

class LocParcare {
private:
    int id;
    string brandMasina;
    string nrInmatriculare;
    float plataParcare;
    string timpIntrare;
    string tipTichet;
    bool locSpecialDizabilitati;
    float oreParcare;
    //struct tm datetime = *localtime(&timpIntrare)
public:
    LocParcare(int id = -1, string brandMasina = "", string nrInmatriculare = "", float plataParcare = 1.0,
        string timpIntrare = "", string tipTichet = "", bool locSpecialDizabilitati = false, float oreParcare = 0.0)
        : id(id), brandMasina(brandMasina), nrInmatriculare(nrInmatriculare), plataParcare(plataParcare),
        timpIntrare(timpIntrare), tipTichet(tipTichet), locSpecialDizabilitati(locSpecialDizabilitati) {
    }

    float calculeazaPretParcare(int oreParcare) {
        return oreParcare * plataParcare;
    }

    void afiseaza() {
        cout << "ID Loc Parcare: " << id << "\n";
        cout << "Brand Masina: " << brandMasina << "\n";
        cout << "Placa Inmatriculare: " << nrInmatriculare << "\n";
        cout << "Timp Intrare: " << timpIntrare << "\n";
        cout << "Tip Tichet: " << tipTichet << "\n";
        cout << "Loc Special pt. Persoane cu Dizabilitati? " << (locSpecialDizabilitati ? "Yes" : "No") << "\n";
    }
    int getId() const { return id; }
    string getbrandMasina() const { return brandMasina; }
    string getnrInmatriculare() const { return nrInmatriculare; }
    float getplataParcare() const { return plataParcare; }
    string gettimpIntrare() const { return timpIntrare; }
    string gettipTichet() const { return tipTichet; }
    bool getlocSpecialDizabilitati() const { return locSpecialDizabilitati; }

    friend class Admin;
};

class Parcare {
private:
    LocParcare locuriParcare[locuri_parcare];
    int locuri_totale;
    int locuri_disponibile;
    int locuri_speciale;
    int locuri_ocupate;

public:
    Parcare(int locuri_totale) : locuri_totale(locuri_totale), locuri_disponibile(locuri_totale), locuri_speciale(0), locuri_ocupate(0) {}

    void adaugaLocParcare(int id, string brandMasina, string nrInmatriculare, float plataParcare,
        string timpIntrare, string tipTichet, bool locSpecialDizabilitati) {
        if (locuri_ocupate < locuri_parcare) {
            locuriParcare[locuri_ocupate] = LocParcare(id, brandMasina, nrInmatriculare, plataParcare, timpIntrare, tipTichet, locSpecialDizabilitati);
            locuri_ocupate++;
            if (locSpecialDizabilitati) {
                locuri_speciale++;
            }
            locuri_disponibile--;
        }
        else {
            cout << "Parcarea este plina! Nu avem locuri disponibile pentru dvs.! Vom reveni in curand~" << endl;
        }
    }

    void stergeLocParcare(int id) {
        for (int i = 0; i < locuri_ocupate; i++) {
            if (locuriParcare[i].getId() == id) {
                if (locuriParcare[i].getlocSpecialDizabilitati()) {
                    locuri_speciale--;
                }
                locuri_disponibile++;
                for (int j = i; j < locuri_ocupate - 1; j++) {
                    locuriParcare[j] = locuriParcare[j + 1];
                }
                locuri_ocupate--;
                break;
            }
        }
    }
    bool esteLoculDisponibil(int id) {
        for (int i = 0; i < locuri_ocupate; i++) {
            if (locuriParcare[i].getId() == id) {
                return false;
            }
        }
        return true;
    }

    void afiseaza() {
        cout << "Locuri Totale in Parcare: " << locuri_totale << "\n";
        cout << "Locuri Disponibile Acum " << locuri_disponibile << "\n";
        cout << "Locuri Speciale (pt. persoane cu dizabilitati) Disponibile Acum: " << locuri_speciale << "\n";
    }

    void afiseazaToateLocurileParcare() {
        for (int i = 0; i < locuri_ocupate; i++) {
            locuriParcare[i].afiseaza();
            cout << "-------------------------\n";
        }
    }

    void afiseazaLocDupaID(int id) {
        for (int i = 0; i < locuri_ocupate; i++) {
            if (locuriParcare[i].getId() == id) {
                locuriParcare[i].afiseaza();
                return;
            }
        }
        cout << "Nu exista nicio masina pe locul de parcare " << id << "\n";
    }

    void afiseazaLocDupaNumarInmatriculare(string nrInmatriculare) {
        for (int i = 0; i < locuri_ocupate; i++) {
            if (locuriParcare[i].getnrInmatriculare() == nrInmatriculare) {
                locuriParcare[i].afiseaza();
                return;
            }
        }
        cout << "Nu exista nicio masina cu numarul de intmatriculare " << nrInmatriculare << "\n";
    }

    friend class Admin;
};

class Admin {
private:
    string parola = "kaguya";

public:
    bool login(string pass) {
        return pass == parola;
    }

    void afiseazaToateLocurileParcare(Parcare& parcare) {
        parcare.afiseazaToateLocurileParcare();
    }

    void afiseazaLocDupaID(Parcare& parcare, int id) {
        parcare.afiseazaLocDupaID(id);
    }

    void afiseazaLocDupaNrInmatriculare(Parcare& parcare, string nrInmatriculare) {
        parcare.afiseazaLocDupaNumarInmatriculare(nrInmatriculare);
    }

    void stergeMasinaDinLoc(Parcare& parcare, int id) {
        parcare.stergeLocParcare(id);
        cout << "Masina a fost retrasa din locul " << id << "\n";
    }

    void adaugaMasinaInLoc(Parcare& parcare, int id, string brandMasina, string nrInmatriculare, float plataParcare,
        string timpIntrare, string tipTichet, bool locSpecialDizabilitati) {
        parcare.adaugaLocParcare(id, brandMasina, nrInmatriculare, plataParcare, timpIntrare, tipTichet, locSpecialDizabilitati);
        cout << "Masina a fost adaugata in locul " << id << "\n";
    }
};

void userMenu(Parcare& parcare) {
    int optiune;
    cout << "User Menu:\n";
    cout << "1. Verifica Disponibilitate Loc\n";
    cout << "2. Planifica Parcare\n";
    cout << "Alege optiunea: ";
    cin >> optiune;

    if (optiune == 1) {
        int id;
        cout << "Introduceti ID-ul locului de parcare dorit: ";
        cin >> id;
        if (parcare.esteLoculDisponibil(id)) {
            cout << "Locul este disponibil. Doriti ocuparea acestuia?\n";
        }
        else {
            cout << "Locul nu este disponibil momentan. Incercati alt loc!\n";
        }
    }
    else if (optiune == 2) {
        int id;
        string brandMasina, nrInmatriculare, tipTichet, timpIntrare, oreParcare;
        float plataParcare;
        bool locSpecialDizabilitati;
        cout << "Introduceti ID-ul locului de parcare: ";
        cin >> id;
        cout << "Introduceti Brand-ul Masinii: ";
        cin >> brandMasina;
        cout << "Introduceti nr. de inmatriculare al masinii dvs. : ";
        cin >> nrInmatriculare;
        cout << "Introduceti numarul de ore aferente parcarii: ";
        cin >> oreParcare;
        cout << "Introduceti Tip Tichet: ";
        cin >> tipTichet;
        cout << "Cautati un loc special pentru persoane cu dizabilitati? (1- Da, 2-Nu): ";
        cin >> locSpecialDizabilitati;
        //pret = oreParcare*5.0;
        //timpIntrare = time(&timpIntrare);
        //cout << "\nData si Ora Curenta: " << datetime.tm_hour << ", " << datetime.tm_wday << " ," << datetime.tm_mday << " " << datetime.tm_mon;
        parcare.adaugaLocParcare(id, brandMasina, nrInmatriculare, plataParcare, timpIntrare, tipTichet, locSpecialDizabilitati);
        cout << "Locul de parcare a fost ocupat cu success! Pret de platit: " << plataParcare << " lei! \nTimp Intrare: " << timpIntrare << "";
    }
    else {
        cout << "Alegerea dvs este invalida. Va rugam sa incercati din nou!\n";
    }
}

void adminMenu(Parcare& parcare, Admin& admin) {
    string pass;
    cout << "Introduceti Parola Admin: ";
    cin >> pass;

    if (!admin.login(pass)) {
        cout << "Parola introdusa este invalida! Incearca din nou!\n";
        return;
    }

    int optiune;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Verifica Toate Locurile de Parcare\n";
        cout << "2. Verifica Loc dupa ID\n";
        cout << "3. Verifica Loc dupa Nr. de Inmatriculare\n";
        cout << "4. Sterge Masina Parcata\n";
        cout << "5. Adauga Masina Parcata\n";
        cout << "0. Iesire\n";
        cout << "Alegeti optiunea: ";
        cin >> optiune;

        if (optiune == 1) {
            admin.afiseazaToateLocurileParcare(parcare);
        }
        else if (optiune == 2) {
            int id;
            cout << "Introduceti ID-ul Locului de Parcare: ";
            cin >> id;
            admin.afiseazaLocDupaID(parcare, id);
        }
        else if (optiune == 3) {
            string nrInmatriculare;
            cout << "Introduceti Nr. de Inmatriculare Vehicul: ";
            cin >> nrInmatriculare;
            admin.afiseazaLocDupaNrInmatriculare(parcare, nrInmatriculare);
        }
        else if (optiune == 4) {
            int id;
            cout << "Introduceti ID-ul Locului de Parcare: ";
            cin >> id;
            admin.stergeMasinaDinLoc(parcare, id);
        }
        else if (optiune == 5) {
            int id;
            string brandMasina, nrInmatriculare, tipTichet, timpIntrare;
            float plataParcare;
            bool locSpecialDizabilitati;
            cout << "Introduceti ID-ul Locului de Parcare: ";
            cin >> id;
            cout << "Introduceti Brand-ul Masinii: ";
            cin >> brandMasina;
            cout << "Introduceti Nr. de Inmatriculare al vehiculului: ";
            cin >> nrInmatriculare;
            cout << "Introduceti Pretul/Ora (lei) pentru parcare: ";
            cin >> plataParcare;
            cout << "Introduceti Tipul de Tichet: ";
            cin >> tipTichet;
            cout << "Locul Special? (0-Da, 1-Nu)";
            cin >> locSpecialDizabilitati;
            admin.adaugaMasinaInLoc(parcare, id, brandMasina, nrInmatriculare, plataParcare, timpIntrare, tipTichet, locSpecialDizabilitati);
        }
        else if (optiune == 0) {
            cout << "Se inchide Meniul Admin...\n";
        }
        else {
            cout << "Optiune Invalida.\n";
        }
    } while (optiune != 0);
}

int main() {
    Parcare parcare(10);
    Admin admin;

    int userType;
    cout << "Bun venit in Sistemul de Parcari\n";
    cout << "1. Login User\n";
    cout << "2. Login Admin\n";
    cout << "Introduceti Optiunea: ";
    cin >> userType;

    if (userType == 1) {
        userMenu(parcare);
    }
    else if (userType == 2) {
        adminMenu(parcare, admin);
    }
    else {
        cout << "Optiune Invalida.\n";
    }

    return 0;
}
