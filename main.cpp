#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>

struct Table {
    public:
        std::string tableName;
        std::string ID;
        std::string username;
        std::string createdAt;
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

        time_t outputAt;
        time(&outputAt);

        data_table.tableName = table_vector[0];
        data_table.ID = table_vector[1];
        data_table.username = table_vector[2];

        std::time_t result = std::time(nullptr);

        data_table.createdAt = std::asctime(std::localtime(&result));

        std::cout << data_table.tableName;  


        std::make_heap(table_vector.begin(), table_vector.end());

        std::ofstream output_table("output-table.txt");

        output_table << "TABLE " << data_table.tableName << " {" << std::endl;
        for (size_t i  = 1; i < table_vector.size(); i++) {
            output_table << table_vector[i] << std::endl;
        };
        output_table << "Created at: " << data_table.createdAt << std::endl;
        output_table << "}";
        output_table.close();
};

int main() {
    read_query();
}

