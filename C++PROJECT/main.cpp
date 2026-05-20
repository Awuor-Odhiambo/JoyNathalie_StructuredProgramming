#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

class MenuItem {
private:
    int id;
    string name;
    double price;
    int cookTime;
    string category;
    int orderCount;

public:
    MenuItem(int item_id, string item_name, double item_price, int item_time, string item_cat) {
        id = item_id;
        name = item_name;
        price = item_price;
        cookTime = item_time;
        category = item_cat;
        orderCount = 0;
    }

    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getCookTime() { return cookTime; }
    string getCategory() { return category; }
    int getOrderCount() { return orderCount; }

    void incrementOrderCount() { orderCount++; }

   void display() {
    cout << left
         << setw(4)  << id
         << setw(20) << name
         << "Kshs. " << setw(8) << price
         << " " << setw(2) << cookTime << " mins "
         << " [" << category << "]"
         << endl;
}
};

class Person {
protected:
    string fullName;
    string username;
    string password;

public:
    Person(string name, string user, string pass) {
        fullName = name;
        username = user;
        password = pass;
    }

    string getFullName() { return fullName; }
    string getUsername() { return username; }
    string getPassword() { return password; }

    void showProfile() {
        cout << "Name     : " << fullName << "\n";
        cout << "Username : " << username << "\n";
    }
};

class Order {
private:
    vector<string> itemNames;
    vector<double> itemPrices;
    double total;
    int estimatedWait;
    string date;

public:
    Order(vector<string> names, vector<double> prices, int waitTime, string orderDate) {
        itemNames = names;
        itemPrices = prices;
        estimatedWait = waitTime;
        date = orderDate;

        total = 0.0;
        for (int i = 0; i < prices.size(); i++) {
            total = total + prices[i];
        }
    }

    double getTotal() { return total; }
    int getWait() { return estimatedWait; }
    string getDate() { return date; }
    vector<string> getItemNames() { return itemNames; }

    void display() {
        cout << date << " -> Items: ";
        for (int i = 0; i < itemNames.size(); i++) {
            cout << itemNames[i];
        }
        cout << " | Total: Kshs." << total << "\n";
    }
};

class User : public Person {
private:
    vector<Order> orderHistory;
    int totalVisits;
    double totalSpent;

public:
    User(string name, string user, string pass) : Person(name, user, pass) {
        totalVisits = 0;
        totalSpent = 0.0;
    }

    void addOrder(Order order) {
        orderHistory.push_back(order);
        totalVisits++;
        totalSpent += order.getTotal();
    }

    int getTotalVisits() { return totalVisits; }
    double getTotalSpent() { return totalSpent; }
    vector<Order>& getOrderHistory() { return orderHistory; }

    void showProfile() {
        cout << "-----------------------------------" << "\n";
        cout << "         USER PROFILE" << "\n";
        cout << "-----------------------------------" <<"\n";
        cout << "  Name         : " << fullName <<"\n";
        cout << "  Username     : " << username <<"\n" ;
        cout << "  Total Visits : " << totalVisits <<"\n" ;
        cout << "  Total Spent  : Kshs. " << totalSpent <<"\n";
    }

    string getFavouriteItem() {
        if (orderHistory.empty()) return "None yet";

        vector<string> allItems;
        for (int i = 0; i < orderHistory.size(); i++) {
            vector<string> items = orderHistory[i].getItemNames();
            for (int j = 0; j < items.size(); j++) {
                allItems.push_back(items[j]);
            }
        }

        if (allItems.empty()) return "None yet";

        string favourite = allItems[0];
        int maxCount = 0;

        for (int i = 0; i < allItems.size(); i++) {
            int count = 0;
            for (int j = 0; j < allItems.size(); j++) {
                if (allItems[j] == allItems[i]) {
                    count++;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                favourite = allItems[i];
            }
        }
        return favourite;
    }
};

class Menu {
private:
    vector<MenuItem> items;

public:
    Menu() {
        loadDefaultMenu();
    }

    void loadDefaultMenu() {
        items.push_back(MenuItem(1, "Grilled Chicken", 89.99, 20, "Mains"));
        items.push_back(MenuItem(2, "Beef Burger", 75.00, 15, "Mains"));
        items.push_back(MenuItem(3, "Margherita Pizza", 95.00, 25, "Mains"));
        items.push_back(MenuItem(4, "Penne Pasta", 70.00, 18, "Mains"));
        items.push_back(MenuItem(5, "Caesar Salad", 55.00, 5, "Starters"));
        items.push_back(MenuItem(6, "Garlic Bread", 35.00, 8, "Starters"));
        items.push_back(MenuItem(7, "Tomato Soup", 45.00, 10, "Starters"));
        items.push_back(MenuItem(8, "Chocolate Cake", 50.00, 0, "Desserts"));
        items.push_back(MenuItem(9, "Ice Cream", 35.00, 0, "Desserts"));
        items.push_back(MenuItem(10, "Cheesecake", 55.00, 0, "Desserts"));
        items.push_back(MenuItem(11, "Coca Cola", 20.00, 0, "Drinks"));
        items.push_back(MenuItem(12, "Orange Juice", 25.00, 0, "Drinks"));
        items.push_back(MenuItem(13, "Sparkling Water", 15.00, 0, "Drinks"));
    }

    vector<MenuItem>& getItems() { return items; }

    void displayMenu(string filter = "All") {
        cout << "-----------------------------------" <<"\n" ;
        cout << "             THE MENU              " <<"\n";
        cout << "-----------------------------------" << "\n";
        for (int i = 0; i < items.size(); i++) {
            if (filter == "All" || items[i].getCategory() == filter) {
                items[i].display();
            }
        }
        cout << "-----------------------------------" << "\n";
    }

    MenuItem* findById(int id) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i].getId() == id) {
                return &items[i];
            }
        }
        return nullptr;
    }

    vector<MenuItem*> searchByName(string keyword) {
        vector<MenuItem*> results;
        keyword = toLower(keyword);
        for (int i = 0; i < items.size(); i++) {
            string currentItemName = toLower(items[i].getName());
            if (currentItemName.find(keyword) != string::npos) {
                results.push_back(&items[i]);
            }
        }
        return results;
    }

    void sortByPrice() {
        int n = items.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (items[j].getPrice() > items[j + 1].getPrice()) {
                    MenuItem temp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = temp;
                }
            }
        }
    }

    void sortByName() {
        int n = items.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (items[j].getName() > items[j + 1].getName()) {
                    MenuItem temp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = temp;
                }
            }
        }
    }
};

class UserManager {
private:
    vector<User> users;
    int currentUserIndex;

public:
    UserManager() {
        currentUserIndex = -1;
    }

    User* findUser(string username) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == username) {
                return &users[i];
            }
        }
        return nullptr;
    }

    bool registerUser(string fullName, string username, string password) {
        if (findUser(username) != nullptr) return false;

        User newUser(fullName, username, password);
        users.push_back(newUser);
        return true;
    }

    User* login(string username, string password) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == username && users[i].getPassword() == password) {
                currentUserIndex = i;
                return &users[currentUserIndex];
            }
        }
        return nullptr;
    }

    void logout() {
        currentUserIndex = -1;
    }

    User* getCurrentUser() {
        if (currentUserIndex == -1) return nullptr;
        return &users[currentUserIndex];
    }
};

class Restaurant {
private:
    Menu menu;
    UserManager userManager;
    vector<string> pageHistory;

    void pushPage(string page) { pageHistory.push_back(page); }

public:
    void showWelcomeScreen() {
        clearScreen();
        cout << "*************************************************" <<"\n";
        cout << "*            WELCOME TO BLACK DANDY             *" << "\n";
        cout << "*************************************************" <<"\n" ;
        cout << "  1. Login" << "\n";
        cout << "  2. Register" << "\n";
        cout << "  3. Exit" <<"\n" ;
    }

    void showMainMenu() {
        User* user = userManager.getCurrentUser();
        clearScreen();
        cout << "  Welcome back, " << user->getFullName() << "!" << "\n";
        cout << "  Favourite item : " << user->getFavouriteItem() << "\n";
        cout << "  Total orders   : " << user->getTotalVisits() << "\n";
        cout << "  Total spent    : R" << user->getTotalSpent() << "\n";

        cout << "  1. View Full Menu" <<"\n" ;
        cout << "  2. Place an Order" <<"\n" ;
        cout << "  3. View Order History" << "\n";
        cout << "  4. My Profile" << "\n";
        cout << "  5. Search Menu" <<"\n" ;
        cout << "  6. Sort Menu" << "\n";
        cout << "  7. Logout" << "\n";
    }

    void handleRegister() {
        clearScreen();
        cout << "-----------------------------------" <<"\n" ;
        cout << "      NEW ACCOUNT REGISTRATION     " << "\n";
        cout << "-----------------------------------" <<"\n" ;

        string fullName, username, password;
        cout << "Full Name : "; cin.ignore(); getline(cin, fullName);
        cout << "Username  : "; cin >> username;
        cout << "Password  : "; cin >> password;

        if (userManager.registerUser(fullName, username, password)) {
            cout << "\nAccount created! Welcome, " << fullName << "!" <<"\n";
        } else {
            cout << "\nUsername already exists. Try another." <<"\n" ;
        }
        pauseScreen();
    }

    bool handleLogin() {
        clearScreen();
        cout << "-----------------------------------" <<"\n" ;
        cout << "               LOGIN               " <<"\n" ;
        cout << "-----------------------------------" << "\n";

        string username, password;
        int attempts = 0;

        while (attempts < 3) {
            cout << "Username : "; cin >> username;
            cout << "Password : "; cin >> password;

            if (userManager.login(username, password)) {
                cout << "\nLogin successful!" << "\n";
                pauseScreen();
                return true;
            } else {
                attempts++;
                cout << "\nWrong credentials. (" << (3 - attempts) << " attempts left)" << "\n";
            }
        }
        cout << "\nToo many failed attempts." <<"\n" ;
        pauseScreen();
        return false;
    }

    void handleViewMenu() {
        pushPage("menu");
        clearScreen();
        cout << "Filter: 1.All  2.Mains  3.Starters  4.Desserts  5.Drinks" << "\n";
        cout << "Choose filter number: ";
        int f; cin >> f;

        string filter = "All";
        if (f == 2) filter = "Mains";
        else if (f == 3) filter = "Starters";
        else if (f == 4) filter = "Desserts";
        else if (f == 5) filter = "Drinks";

        clearScreen();
        menu.displayMenu(filter);
        pauseScreen();
    }

    void handlePlaceOrder() {
        pushPage("order");
        clearScreen();
        menu.displayMenu();

        cout << "How many items do you want to order? ";
        int count; cin >> count;

        vector<MenuItem*> selected;
        for (int i = 0; i < count; i++) {
            cout << "Enter item ID #" << (i + 1) << ": ";
            int id; cin >> id;
            MenuItem* item = menu.findById(id);
            if (item != nullptr) {
                selected.push_back(item);
            } else {
                cout << "Invalid ID. Skipped." << "\n";
            }
        }

        if (selected.empty()) {
            cout << "\nNo valid items selected." << "\n";
            pauseScreen();
            return;
        }

        double total = 0;
        int maxWait = 0;
        vector<string> names;
        vector<double> prices;

        clearScreen();
        cout << "-----------------------------------" << "\n";
        cout << "         YOUR ORDER SUMMARY        " <<"\n";
        cout << "-----------------------------------" << "\n";

        for (int i = 0; i < selected.size(); i++) {
            MenuItem* m = selected[i];
            cout << "- " << m->getName() << " (Kshs." << m->getPrice() << ")" << "\n";
            total += m->getPrice();
            if (m->getCookTime() > maxWait) maxWait = m->getCookTime();
            names.push_back(m->getName());
            prices.push_back(m->getPrice());
        }

        cout << "TOTAL: Kshs. " << total << "\n";
        cout << "Estimated cook time: " << maxWait << " mins" << "\n";

        cout << "Confirm order? (y/n): ";
        char confirm; cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            Order newOrder(names, prices, maxWait, "2026-05-18");
            userManager.getCurrentUser()->addOrder(newOrder);

            for (int i = 0; i < selected.size(); i++) {
                selected[i]->incrementOrderCount();
            }
            cout << "\nOrder placed successfully!" << "\n";
        } else {
            cout << "\nOrder cancelled." << "\n";
        }
        pauseScreen();
    }

    void handleOrderHistory() {
        pushPage("history");
        clearScreen();
        User* user = userManager.getCurrentUser();
        vector<Order>& history = user->getOrderHistory();

        if (history.empty()) {
            cout << "No orders found." << "\n";
            pauseScreen();
            return;
        }

        double grandTotal = 0;
        for (int i = 0; i < history.size(); i++) {
            history[i].display();
            grandTotal += history[i].getTotal();
        }

        cout << "GRAND TOTAL SPENT: Kshs. " << grandTotal << "\n";
        pauseScreen();
    }

    void handleProfile() {
        pushPage("profile");
        clearScreen();
        userManager.getCurrentUser()->showProfile();
        pauseScreen();
    }

    void handleSearchMenu() {
        pushPage("search");
        clearScreen();
        cout << "Enter search keyword: ";
        string keyword; cin >> keyword;

        vector<MenuItem*> results = menu.searchByName(keyword);

        if (results.empty()) {
            cout << "\nNo items found match standard criteria." << "\n";
        } else {
            cout << "\nFound items:\n" << "\n";
            for (int i = 0; i < results.size(); i++) {
                results[i]->display();
            }
        }
        pauseScreen();
    }

    void handleSortMenu() {
        pushPage("sort");
        clearScreen();
        cout << "1. Sort by Price (Low to High)" << "\n";
        cout << "2. Sort by Name (A to Z)" << "\n";
        cout << "Enter choice: ";
        int choice; cin >> choice;

        if (choice == 1) {
            menu.sortByPrice();
            cout << "\nSorted by price!" << "\n";
        } else if (choice == 2) {
            menu.sortByName();
            cout << "\nSorted by name!" << "\n";
        } else {
            cout << "\nInvalid choice." <<"\n";
        }
        pauseScreen();
        handleViewMenu();
    }

    void run() {
        while (true) {
            showWelcomeScreen();
            cout << "Choose: ";
            int choice; cin >> choice;

            if (choice == 1) {
                if (handleLogin()) {
                    while (userManager.getCurrentUser() != nullptr) {
                        showMainMenu();
                        cout << "Choose: ";
                        int opt; cin >> opt;

                        if (opt == 1) handleViewMenu();
                        else if (opt == 2) handlePlaceOrder();
                        else if (opt == 3) handleOrderHistory();
                        else if (opt == 4) handleProfile();
                        else if (opt == 5) handleSearchMenu();
                        else if (opt == 6) handleSortMenu();
                        else if (opt == 7) {
                            userManager.logout();
                            cout << "\nLogged out successfully!" << "\n";
                            pauseScreen();
                        } else {
                            cout << "\nInvalid input choice." << "\n";
                            pauseScreen();
                        }
                    }
                }
            } else if (choice == 2) {
                handleRegister();
            } else if (choice == 3) {
                cout << "\nGoodbye!" << "\n";
                break;
            } else {
                cout << "\nInvalid option." << "\n";
                pauseScreen();
            }
        }
    }
};

int main() {
    Restaurant app;
    app.run();
    return 0;
}
