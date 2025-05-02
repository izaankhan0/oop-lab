#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Client {
public:
    string id;
    string fname;
    string lname;
    string location;
    string contact;

    Client(string uid, string fn, string ln, string addr, string mail)
        : id(uid), fname(fn), lname(ln), location(addr), contact(mail) {}

    string pack() const {
        return id + "," + fname + "," + lname + "," + location + "," + contact;
    }

    static Client unpack(const string& data) {
        stringstream stream(data);
        string uid, fn, ln, addr, mail;
        getline(stream, uid, ',');
        getline(stream, fn, ',');
        getline(stream, ln, ',');
        getline(stream, addr, ',');
        getline(stream, mail, ',');
        return Client(uid, fn, ln, addr, mail);
    }
};

class Item {
public:
    string id;
    string title;
    string detail;
    int cost;

    Item(string pid, string name, string desc, int price)
        : id(pid), title(name), detail(desc), cost(price) {}

    string pack() const {
        return id + "," + title + "," + detail + "," + to_string(cost);
    }

    static Item unpack(const string& line) {
        stringstream ss(line);
        string pid, name, desc, price;
        getline(ss, pid, ',');
        getline(ss, name, ',');
        getline(ss, desc, ',');
        getline(ss, price, ',');
        return Item(pid, name, desc, stoi(price));
    }
};

class Invoice {
public:
    string id;
    string buyer;
    string item;
    int amount;

    Invoice(string oid, string uid, string pid, int total)
        : id(oid), buyer(uid), item(pid), amount(total) {}

    string pack() const {
        return id + "," + buyer + "," + item + "," + to_string(amount);
    }

    static Invoice unpack(const string& line) {
        stringstream ss(line);
        string oid, uid, pid, total;
        getline(ss, oid, ',');
        getline(ss, uid, ',');
        getline(ss, pid, ',');
        getline(ss, total, ',');
        return Invoice(oid, uid, pid, stoi(total));
    }
};

void createSampleFiles() {
    ofstream clients("clients.txt");
    clients << Client("C101", "Leo", "King", "Sunset Road", "leo@mail.com").pack() << endl;
    clients << Client("C102", "Zara", "Moon", "Elm Street", "zara@earth.org").pack() << endl;
    clients.close();

    ofstream items("items.txt");
    items << Item("I501", "Solar Charger", "Portable 20W unit", 300).pack() << endl;
    items << Item("I502", "AI Notebook", "Advanced smart notepad", 700).pack() << endl;
    items.close();

    ofstream invoices("invoices.txt");
    invoices << Invoice("B201", "C101", "I501", 300).pack() << endl;
    invoices << Invoice("B202", "C102", "I502", 700).pack() << endl;
    invoices.close();
}

vector<Client> getClients() {
    vector<Client> list;
    ifstream file("clients.txt");
    string line;
    while (getline(file, line)) {
        list.push_back(Client::unpack(line));
    }
    return list;
}

vector<Item> getItems() {
    vector<Item> list;
    ifstream file("items.txt");
    string line;
    while (getline(file, line)) {
        list.push_back(Item::unpack(line));
    }
    return list;
}

vector<Invoice> getInvoices() {
    vector<Invoice> list;
    ifstream file("invoices.txt");
    string line;
    while (getline(file, line)) {
        list.push_back(Invoice::unpack(line));
    }
    return list;
}

void findItemsBoughtBy(const string& firstName) {
    vector<Client> clients = getClients();
    vector<Item> items = getItems();
    vector<Invoice> invoices = getInvoices();

    string client_id = "";

    for (const auto& c : clients) {
        if (c.fname == firstName) {
            client_id = c.id;
            break;
        }
    }

    if (client_id == "") {
        cout << "Client not found.\n";
        return;
    }

    vector<string> bought;
    for (const auto& inv : invoices) {
        if (inv.buyer == client_id) {
            bought.push_back(inv.item);
        }
    }

    cout << "\nItems bought by " << firstName << ":\n";
    for (const auto& item_id : bought) {
        for (const auto& item : items) {
            if (item.id == item_id) {
                cout << "- " << item.title << endl;
            }
        }
    }
}

int main() {
    createSampleFiles();
    findItemsBoughtBy("Leo");
    return 0;
}
