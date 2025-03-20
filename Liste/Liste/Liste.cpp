#include <iostream>

using namespace std;

struct Nod {
    int data;
    Nod* link;
};

void adaugaInceput(Nod*& head, int valoare) {
    Nod* nou = new Nod{ valoare, head };
    head = nou;
}
void expandareLista(Nod*& head, int nrElemente) {
    for (int i = 0; i < nrElemente; i++) {
        Nod* nou = new Nod{ 0, head };
        head = nou;
    }
}
void adaugaLaFinal(Nod*& head, int valoare) {
    Nod* nou = new Nod{ valoare, nullptr };
    if (head == nullptr) {
        head = nou;
        return;
    }
    Nod* temp = head;
    while (temp->link) {
        temp = temp->link;
    }
    temp->link = nou;
}
void stergeNod(Nod*& head, int valoare) {
    if (!head) return;

    if (head->data == valoare) {
        Nod* temp = head;
        head = head->link;
        delete temp;
        return;
    }

    Nod* temp = head;
    while (temp->link && temp->link->data != valoare) {
        temp = temp->link;
    }
    
    if (temp->link) {
        Nod* deSters = temp->link;
        temp->link = temp->link->link;
        delete deSters;
    }
}

void parcurgeLista(Nod* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->link;
    }
    cout << "NULL\n";
}

void golesteLista(Nod*& head) {
    while (head) {
        Nod* temp = head;
        head = head->link;
        delete temp;
    }
}

int main() {
    Nod* lista = nullptr;

    adaugaInceput(lista, 10);
    adaugaInceput(lista, 20);
    adaugaInceput(lista, 30);
    adaugaLaFinal(lista, 26);
    
    cout << "Lista dupa adaugari: ";
    parcurgeLista(lista);
    expandareLista(lista, 3);
    stergeNod(lista, 20);
    cout << "Lista dupa stergere: ";
    parcurgeLista(lista);
    
    golesteLista(lista);
    cout << "Lista dupa golire: ";
    parcurgeLista(lista);
    
    return 0;
}
