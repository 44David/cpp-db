#include <iostream>
#include <string>
#include <fstream>

class Table {
    public:
        int ID;
        std::string username;
};

int read_query() {

    std::ifstream db_query("db-query.txt");

    std::string line;

    while (getline (db_query, line)) {
        std::cout << line << std::endl;
    };
    db_query.close();

};

int main() {
    read_query();

}

