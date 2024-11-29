#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
protected:
    string name, password;
    bool connected = false;

public:
    User(string name, string password) {
        this->name = name;
        this->password = password;
    }

    string getName() const {
        return this->name;
    }

    void connect(string name, string password) {
        if (name == this->name && password == this->password) {
            cout << "You are connected, " << this->name << "!\n";
            connected = true;
        }
        else {
            cout << "The password or the user is wrong!\n";
        }
    }

    void disconnect() {
        if (connected) {
            cout << "You are disconnected\n";
            connected = false;
        }
        else {
            cout << "Not connected!\n";
        }
    }

    bool isConnected() const {
        return connected;
    }
};

class Admin : public User {
public:
    Admin(string name, string password) : User(name, password) {}

    void viewUsers(const vector<User*>& users) const {
        cout << "Users from network:\n";
        for (const auto& user : users) {
            cout << "- " << user->getName() << " (Connected: "
                << (user->isConnected() ? "Yes" : "No") << ")\n";
        }
    }

    void disconnectUser(User* user) {
        if (user->isConnected()) {
            user->disconnect();
        }
        else {
            cout << user->getName() << " is already disconnected\n";
        }
    }
};

class CRetea {
private:
    string name;
    vector<User*> users;
    Admin* admin;

public:
    CRetea(string name) {
        this->name = name;
        this->admin = nullptr;
    }

    bool addUser(User* user) {
        if (users.size() >= 10) {
            cout << "The network is full\n";
            return false;
        }
        users.push_back(user);
        cout << "User " << user->getName() << " is added to the network.\n";
        return true;
    }

    bool addAdmin(Admin* adminAdded) {
        if (admin != nullptr) {
            cout << "An admin is already in the network!\n";
            return false;
        }
        admin = adminAdded;
        users.push_back(admin);
        cout << "Admin is: " << admin->getName() << "\n";
        return true;
    }

    vector<User*>& getUsers() {
        return users;
    }

    Admin* getAdmin() {
        return admin;
    }
};

int main() {
    // Create a network
    CRetea retea("Campus Network");

    // Create users and an admin
    User user1("Ion", "password123");
    User user2("Maria", "pass456");
    Admin admin("Admin", "adminpass");

    // Add users to the network
    retea.addUser(&user1);
    retea.addUser(&user2);
    retea.addAdmin(&admin);

    // Simulate users connecting
    cout << "\nConnecting users:\n";
    user1.connect("Ion", "password123");  // Correct password
    user2.connect("Maria", "wrongpass");  // Incorrect password

    // Admin views all users in the network
    cout << "\nAdmin views users:\n";
    admin.viewUsers(retea.getUsers());

    // Admin disconnects a user
    cout << "\nAdmin disconnects user Ion:\n";
    admin.disconnectUser(&user1);

    // Admin views users again after disconnection
    cout << "\nAdmin views users again:\n";
    admin.viewUsers(retea.getUsers());

    // Trying to disconnect an already disconnected user
    cout << "\nAdmin tries to disconnect Maria (not connected):\n";
    admin.disconnectUser(&user2);

    return 0;
}
