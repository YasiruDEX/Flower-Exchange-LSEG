#include "OrderMatcher.h"
#include <algorithm>
#include <fstream>
#include <iostream>

// Write a row to the output CSV file
void OrderMatcher::writeLineToOutputCSV(const CSVRow& row) {
    ofstream csvFile("execution_rep.csv", ios_base::app); // Append mode

    if (!csvFile.is_open()) {
        cerr << "Error opening output.csv file." << endl;
        return;
    }

    csvFile << row.ord << "," << row.column1 << "," << row.column2 << "," << row.column3 << ","
            << row.newColumn << "," << row.column4 << "," << row.column5 << endl;

    csvFile.close();
}

void OrderMatcher::matchOrders(vector<CSVRow>& buyTable, vector<CSVRow>& sellTable) {
    // Sort buyTable (descending by price)
    sort(buyTable.begin(), buyTable.end(), [](const CSVRow& a, const CSVRow& b) {
        return stoi(a.column5) > stoi(b.column5);  // Compare prices as integers
    });

    // Sort sellTable (ascending by price)
    sort(sellTable.begin(), sellTable.end(), [](const CSVRow& a, const CSVRow& b) {
        return stoi(a.column5) < stoi(b.column5);  // Compare prices as integers
    });

    // Matching buy and sell orders based on price and quantity
    while (!buyTable.empty() && !sellTable.empty()) {
        CSVRow& buyOrder = buyTable.front();  // Get the highest buy order
        CSVRow& sellOrder = sellTable.front(); // Get the lowest sell order

        int buyPrice = stoi(buyOrder.column5); // Buy order price
        int sellPrice = stoi(sellOrder.column5); // Sell order price
        int buyQuantity = stoi(buyOrder.column4); // Buy order quantity
        int sellQuantity = stoi(sellOrder.column4); // Sell order quantity

        // Match if buy price is greater than or equal to sell price
        if (buyPrice >= sellPrice) {
            int executedQuantity = min(buyQuantity, sellQuantity); // The minimum of buy/sell quantities

            // Update quantities after matching
            buyOrder.column4 = to_string(buyQuantity - executedQuantity);
            sellOrder.column4 = to_string(sellQuantity - executedQuantity);

            // Set the execution status
            buyOrder.newColumn = (buyOrder.column4 == "0") ? "Fill" : "PFill";
            sellOrder.newColumn = (sellOrder.column4 == "0") ? "Fill" : "PFill";

            // Write the partially or fully filled orders to output CSV
            writeLineToOutputCSV(buyOrder);
            writeLineToOutputCSV(sellOrder);

            // Remove fully filled orders
            if (buyOrder.column4 == "0") buyTable.erase(buyTable.begin());
            if (sellOrder.column4 == "0") sellTable.erase(sellTable.begin());
        } else {
            // No match possible, break the loop
            break;
        }
    }
}
