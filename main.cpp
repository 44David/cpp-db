#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Table {
    public:
        std::string tableName;
        std::string ID;
        std::string username;
};

void read_query() {

        std::vector<std::string> table_vector;

        std::ifstream db_query("db-query.txt");

        std::string line;

        while (getline (db_query, line)) {
            table_vector.push_back(line);
        };
        db_query.close();

        Table data_table;

        data_table.tableName = table_vector[0];
        data_table.ID = table_vector[1];
        data_table.username = table_vector[2];

        std::cout << data_table.tableName;



        std::ofstream output_table("output-table.txt");
        for (size_t i  = 0; i < table_vector.size(); i++) {
            output_table << table_vector[i] << std::endl;
        };



    
};

int main() {
    read_query();
    
    
}

