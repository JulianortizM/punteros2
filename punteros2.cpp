#include <iostream>

//Julian David Ortiz Molina
//Punteros con 4 funciones

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void append(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void update(int oldValue, int newValue) {
        Node* current = head;
        while (current) {
            if (current->data == oldValue) {
                current->data = newValue;
                return;
            }
            current = current->next;
        }
        std::cout << "El valor " << oldValue << " no se encontró en la lista." << std::endl;
    }

    void remove(int value) {
        if (!head) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }

        std::cout << "El valor " << value << " no se encontró en la lista." << std::endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList myList;

    myList.append(3);
    myList.append(7);
    myList.append(1);
    myList.append(9);
    myList.append(4);
    myList.append(6);
    myList.append(2);
    myList.append(5);

    std::cout << "Lista enlazada: ";
    myList.display();

    int valorInsertar;
    std::cout << "Digite un numero para insertar al inicio: ";
    std::cin >> valorInsertar;
    myList.insert(valorInsertar);
    std::cout << "Resultado despues de digitar el numero: ";
    myList.display();

    int valorAntiguo, valorNuevo;
    std::cout << "Digite un numero a actualizar: ";
    std::cin >> valorAntiguo;
    std::cout << "Ingrese el nuevo valor: ";
    std::cin >> valorNuevo;
    myList.update(valorAntiguo, valorNuevo);
    std::cout << "Lista enlazada después de actualizarse: ";
    myList.display();
    
    int valorEliminar;
    std::cout <<"Digite un numero que desee eliminar: ";
    std::cin >> valorEliminar;
    myList.remove(valorEliminar);
    std::cout << "Asi queda la lista: ";
    myList.display();

    return 0;
}

