// mosteniri.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 3 modificatori:
//

#include <iostream>
#include <string>
using namespace std;
class Persoana {
protected:
    string nume;
    int varsta;
public:
    Persoana() : nume(""), varsta(0) {}
    Persoana(string nume, int varsta) {
        this->nume = nume;
        this->varsta = varsta;
    }
    string getNume() const { return nume; }
    int getVarsta() const { return varsta; }
    void afisare_detalii() {
        cout << "Nume: " << nume << ", Varsta: " << varsta << endl;
    }
};

class Student : public Persoana {
private:
    float medie;

public:
    Student() : Persoana(), medie(0.0) {}
    Student(string nume, int varsta, float medie):Persoana(nume, varsta) {
        this->medie = medie;
    }
    void afisare_informatii() {
        cout << "Nume: " << nume << " , Varsta: " << varsta << " , Medie: " << medie << endl;
    }
};
int main()
{
    int n = 0,varsta=0;
    float media = 0.0;
    string numele = "";
    //Student s1("Ion", 21, 10);
    //s1.afisare_informatii();
    cout << "Introduceti numarul de studenti: ";
    cin >> n;
    Student* studenti = new Student[n];
    for (int i = 0; i < n; i++) {
        cout << "Dati nume student " << i + 1 << " : ";
        cin >> numele;
        cout << "Dati varsta pentru " << numele << ": ";
        cin >> varsta;
        cout << "Dati media pentru " << numele << ": ";
        cin >> media;
        studenti[i] = Student(numele, varsta, media);
    // Sa se scrie un program in c++ pentru gestiunea unei gradini zoologice folosind clase, obiecte, si conceptul de mostenire.
    // Clasa Animal. --> Clasa Pasari: Lungime.. Masa etc. etc. 
    // Mamifere, Pasari, Pesti, Amfibieni, Reptile, Nevertebrate; Tip Specie, Areal Geografic, Nutritie, etc.
    // Enum pentru continent :p
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
