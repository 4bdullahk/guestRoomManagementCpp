#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int roomNumber;
    char guestName[20];
    Node* next;
    Node* prev;
};

Node* head = NULL;

string logs[50];
int logIndex = 0;

void addLog(const string& msg) {
    if (logIndex < 50) logs[logIndex++] = msg;
}

struct StackNode {
    int roomNumber;
    char guestName[20];
};
StackNode undoStack[50];
int top = -1;

void pushUndo(int room, const char* name) {
    if (top < 49) {
        top++;
        undoStack[top].roomNumber = room;
        strcpy(undoStack[top].guestName, name);
    }
}

bool popUndo(int& room, char* name) {
    if (top == -1) return false;
    room = undoStack[top].roomNumber;
    strcpy(name, undoStack[top].guestName);
    top--;
    return true;
}

void displayMenu() {
    cout << "\n==============================\n";
    cout << "  Guest House Management\n";
    cout << "==============================\n";
    cout << "1. Allocate Room\n";
    cout << "2. Edit Guest Info\n";
    cout << "3. Display All Rooms\n";
    cout << "4. Search Room\n";
    cout << "5. Delete Room\n";
    cout << "6. Undo Last Delete\n";
    cout << "7. Show Logs\n";
    cout << "8. Exit\n";
}

void insert_begin(int room, const char* name) {
    Node* newNode = new Node;
    newNode->roomNumber = room;
    strcpy(newNode->guestName, name);
    newNode->prev = NULL;
    newNode->next = head;

    if (head) head->prev = newNode;
    head = newNode;

    addLog("Inserted room " + to_string(room) + " at beginning");
}

void insert_end(int room, const char* name) {
    Node* newNode = new Node;
    newNode->roomNumber = room;
    strcpy(newNode->guestName, name);
    newNode->next = NULL;

    if (!head) {
        newNode->prev = NULL;
        head = newNode;
        addLog("Inserted room " + to_string(room) + " as first node");
        return;
    }

    Node* temp = head;
    while (temp->next) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    addLog("Inserted room " + to_string(room) + " at end");
}

bool insert_at(int room, const char* name, int pos) {
    if (pos < 0) return false;
    if (pos == 0) {
        insert_begin(room, name);
        return true;
    }

    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp) return false;

    Node* newNode = new Node;
    newNode->roomNumber = room;
    strcpy(newNode->guestName, name);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;

    addLog("Inserted room " + to_string(room) + " at position " + to_string(pos));
    return true;
}

Node* search(int room) {
    for (Node* t = head; t; t = t->next)
        if (t->roomNumber == room)
            return t;
    return NULL;
}

void edit_guest_info(int room) {
    Node* target = search(room);
    if (!target) {
        cout << "Room not found!" << endl;
        return;
    }

    cout << "Enter new guest name: ";
    cin.ignore();
    cin.getline(target->guestName, 20);

    addLog("Edited guest info in room " + to_string(room));
    cout << "Updated successfully!\n";
}

void displayAll() {
    if (!head) {
        cout << "No rooms allocated." << endl;
        return;
    }

    for (Node* t = head; t; t = t->next)
        cout << "Room " << t->roomNumber << " -> Guest: " << t->guestName << endl;
}

void delete_room(int room) {
    Node* target = search(room);
    if (!target) {
        cout << "Room not found!" << endl;
        return;
    }

    pushUndo(target->roomNumber, target->guestName);

    if (target == head) {
        head = head->next;
        if (head) head->prev = NULL;
    } else {
        target->prev->next = target->next;
        if (target->next) target->next->prev = target->prev;
    }

    addLog("Deleted room " + to_string(room));
    delete target;

    cout << "Room deleted successfully!\n";
}

void undo_delete() {
    int room;
    char name[20];

    if (!popUndo(room, name)) {
        cout << "Nothing to undo!\n";
        return;
    }

    insert_end(room, name);
    cout << "Undo successful! Restored room " << room << endl;
}

void showLogs() {
    if (logIndex == 0) {
        cout << "No logs yet.\n";
        return;
    }

    cout << "\n--- Operation Logs ---" << endl;
    for (int i = 0; i < logIndex; i++)
        cout << logs[i] << endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int room, pos;
            int opt;
            char name[20];

            cout << "Enter room number: ";
            cin >> room;

            cout << "Enter guest name: ";
            cin.ignore();
            cin.getline(name, 20);

            cout << "Insert:\n1. At end\n2. At specific position\nChoice: ";
            cin >> opt;

            if (opt == 1) {
                insert_end(room, name);
                cout << "Room allocated!\n";
            } 
            else if (opt == 2) {
                cout << "Enter position: ";
                cin >> pos;

                if (insert_at(room, name, pos))
                    cout << "Room allocated!" << endl;
                else
                    cout << "Invalid position! Allocation failed.\n";
            }
            else
                cout << "Invalid choice." << endl;
        }
        else if (choice == 2) {
            int room;
            cout << "Enter room number to edit: ";
            cin >> room;
            edit_guest_info(room);
        }
        else if (choice == 3) displayAll();
        else if (choice == 4) {
            int room;
            cout << "Enter room to search: ";
            cin >> room;
            Node* f = search(room);
            if (f)
                cout << "Room " << room << " -> Guest: " << f->guestName << endl;
            else
                cout << "Room is available.\n";
        }
        else if (choice == 5) {
            int room;
            cout << "Enter room to delete: ";
            cin >> room;
            delete_room(room);
        }
        else if (choice == 6) undo_delete();
        else if (choice == 7) showLogs();
        else if (choice == 8) cout << "Goodbye!!" << endl;
        else cout << "Invalid choice!\n";

    } while (choice != 8);

    return 0;
}
