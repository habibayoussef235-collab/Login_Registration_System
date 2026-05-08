#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to handle the login process
bool loginUser() {
    string username, password, storedUser, storedPass;

    cout << "\n--- Sign In ---" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Open the file corresponding to the entered username
    ifstream userFile(username + ".txt");
    
    if (!userFile) {
        return false; // User file does not exist
    }

    getline(userFile, storedUser);
    getline(userFile, storedPass);
    userFile.close();

    // Validate credentials
    if (storedUser == username && storedPass == password) {
        return true;
    } else {
        return false;
    }
}

// Function to handle the registration process
void registerUser() {
    string username, password;

    cout << "\n--- Registration ---" << endl;
    cout << "Select a username: ";
    cin >> username;
    cout << "Select a password: ";
    cin >> password;

    // (BONUS) Create a separate file for each registered user as a database record
    ofstream dbFile;
    dbFile.open(username + ".txt");
    dbFile << username << endl << password;
    dbFile.close();

    cout << "Registration successful! Record created for: " << username << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n================================" << endl;
        cout << "   SIMPLE AUTHENTICATION SYSTEM " << endl;
        cout << "================================" << endl;
        cout << "1: Register\n2: Login\n3: Exit\nYour choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } 
        else if (choice == 2) {
            if (loginUser()) {
                cout << "\n[SUCCESS] Welcome! Access Granted." << endl;
            } else {
                cout << "\n[ERROR] Invalid username or password." << endl;
            }
        } 
        else if (choice == 3) {
            cout << "Exiting system. Goodbye!" << endl;
            break;
        } 
        else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }

    return 0;
}