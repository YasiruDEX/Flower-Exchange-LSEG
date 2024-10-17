#include "CSVParser.h"
#include "OrderValidator.h"
#include "OrderMatcher.h"
#include <chrono>
#include <iostream>
#include <fstream>

int main() {
    string filename = "orders.csv"; // Input CSV file

    // Instantiate necessary objects
    CSVParser parser;
    OrderValidator validator;
    OrderMatcher matcher;

    vector<CSVRow> csvData = parser.readCSV(filename);
    vector<CSVRow> buyTable;  // Table for buy orders (side 1)
    vector<CSVRow> sellTable; // Table for sell orders (side 2)

    // Open output CSV file
    ofstream csvFile("execution_rep.csv");
    if (!csvFile.is_open()) {
        cerr << "Error opening execution_rep.csv file." << endl;
        return 1;
    }
    csvFile.close(); // Close immediately, as we'll append later

    // Start execution timer
    auto start = chrono::high_resolution_clock::now();

    for (CSVRow& row : csvData) {
        // Validate the current row
        bool isValid = validator.validateOrder(row);

        // Write rejected rows immediately
        if (!isValid) {
            matcher.writeLineToOutputCSV(row);
            continue;
        }

        // Add row to buy or sell table
        if (row.column3 == "1") {
            buyTable.push_back(row); // Side 1 is Buy
        } else {
            sellTable.push_back(row); // Side 2 is Sell
        }

        // Match buy/sell orders
        matcher.matchOrders(buyTable, sellTable);
    }

    // End execution timer
    auto end = chrono::high_resolution_clock::now();
    long long executionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Write execution time to CSV
    ofstream csvFileTime("execution_rep.csv", ios_base::app);
    csvFileTime << "Execution Time (ms)," << executionTime << endl;
    csvFileTime.close();

    return 0;
}
