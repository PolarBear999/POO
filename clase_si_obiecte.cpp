// clase_si_obiecte.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string nume;
    int varsta;
    float medie;
    // Default Constructor
    Student() {
        nume = "";
        varsta = 0;
        medie = 0.0;
    }
    // Constructor
    Student(string n, int v, float m) {
        nume = n;
        varsta = v;
        medie = m;
        cout << "Studentul " << nume << " a fost adaugat! " << endl;
    }

    // Destructor
    ~Student() {
        cout << "Studentul " << nume << " a fost sters! " << endl;
    }
    void afisare() {
        cout << "Nume: " << nume << ", Varsta: " << varsta << ", Medie: " << medie << endl;
    }
};

int main() {

    int n = 0;
    double ceaMaiMareMedie = 0.0;
    double sumamedii = 0.0;
    cout << "Introduceti numarul de studenti: ";
    cin >> n;
    Student* studenti = new Student[n];
    for (int i = 0; i < n; i++) {
        cout << "Dati nume student " << i+1 << " : ";
        cin >> studenti[i].nume;
        cout << "Dati varsta pentru " << studenti[i].nume << ": ";
        cin >> studenti[i].varsta;
        cout << "Dati media pentru " << studenti[i].nume << ": ";
        cin >> studenti[i].medie;
        if (ceaMaiMareMedie < studenti[i].medie) ceaMaiMareMedie = studenti[i].medie;
        sumamedii += studenti[i].medie;
    }
    cout << "Lista studentilor este: \n";
    for (int i = 0; i < n; i++) {
        studenti[i].afisare();
    }
    cout << "Cea mai mare medie este: " << ceaMaiMareMedie;
    cout << "\nMedia mediilor este " << sumamedii / n;
    bool bule;
    do {
        bule = false;
        for (int i = 0; i < n - 1; i++) {
            if (studenti[i].medie < studenti[i + 1].medie) {
                swap(studenti[i], studenti[i + 1]);
                bule = true;
            }
        }
    } while (bule);
    cout << "\nStudentii in ordine descendenta dupa medie:\n";
    for (int i = 0; i < n; i++) {
        studenti[i].afisare();
    }
    delete studenti;
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
