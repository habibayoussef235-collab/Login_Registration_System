#include <iostream>
#include <fstream> // File Handling
#include <string>

using namespace std;

int main() {
    int choice;
    string username, password;

    cout << "--- Welcome to Project 6: Login & Registration System ---" << endl;
    cout << "1. Register\n2. Exit\nChoose an option: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

    
        ofstream file("database.txt", ios::app);
        file << username << " " << password << endl;
        file.close();

        cout << "User registered successfully! Data saved to database.txt" << endl;
    }

    return 0;
}