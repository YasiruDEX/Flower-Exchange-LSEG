// main.cpp
#include "CSVParser.h"
#include "OrderValidator.h"
#include "OrderMatcher.h"
#include <unordered_map>
#include <chrono>
#include <fstream>

int main() {
    std::string filename = "orders.csv";
    std::vector<CSVRow> csvData = readCSV(filename);

    std::unordered_map<std::string, std::pair<std::vector<CSVRow>, std::vector<CSVRow>>> orderBooks = {
        {"Rose", {{}, {}}},
        {"Lavender", {{}, {}}},
        {"Lotus", {{}, {}}},
        {"Tulip", {{}, {}}},
        {"Orchid", {{}, {}}}
    };

    auto start = std::chrono::high_resolution_clock::now();

    for (CSVRow& row : csvData) {
        if (!validateOrder(row)) {
            writeLineToOutputCSV(row);
            continue;
        }

        auto& [buyTable, sellTable] = orderBooks[row.column2];
        (row.column3 == "1" ? buyTable : sellTable).push_back(row);

        processOrderBook(buyTable, sellTable);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::ofstream csvFile("execution_rep.csv", std::ios_base::app);
    csvFile << "Execution Time (ms)," << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

    return 0;
}
