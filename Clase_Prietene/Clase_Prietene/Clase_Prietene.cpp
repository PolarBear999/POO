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
    s1.afiseazaInformatii();

    Admin admin;
    admin.modificaMedie(s1, 9.0); 

    s1.afiseazaInformatii(); 

    return 0;
}
