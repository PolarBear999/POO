#include <iostream>
#include <string>

using namespace std;

class Student; 

class Persoana {
protected:
    string nume;
    int varsta;
public:
    Persoana(string n, int v) : nume(n), varsta(v) {} 

    void afiseazaInformatii() {
        cout << "Nume: " << nume << "\nVarsta: " << varsta << endl;
    }
    string getNume() {
        return nume;
    }
};

class Student : public Persoana {
    float medie;

    
    friend class Admin;
public:
    Student(string n, int v, float m) : Persoana(n, v), medie(m) {} 

    void afiseazaInformatii() {
        Persoana::afiseazaInformatii();
        cout << "Medie: " << medie << endl;
    }
    bool operator<(const Student& other) const {
        return this->medie < other.medie;
    }
    bool operator>(const Student& other) const {
        return this->medie > other.medie;
    }
};

class Admin {
public:
    void modificaMedie(Student& s, float nouaMedie) { 
        s.medie = nouaMedie;
        cout << "Medie modificata: " << s.medie << endl;
    }
};

int main() {
    Student s1("Mihai", 20, 7.5);
    Student s2("Victor", 20, 8.5);
    s1.afiseazaInformatii();
    if (s1 < s2) {
        cout << s1.getNume() << " are media mai mica decat " << s2.getNume() << endl;
    }

    Admin admin;
    admin.modificaMedie(s1, 9.0);
    if (s1 > s2) {
        cout << s2.getNume() << " are media mai mare decat " << s1.getNume() << endl;
    }
    s1.afiseazaInformatii(); 

    return 0;
}
