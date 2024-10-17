// OrderMatcher.cpp
#include "OrderMatcher.h"
#include <algorithm>
#include <fstream>
#include <iostream>

void writeLineToOutputCSV(const CSVRow& row) {
    std::ofstream csvFile("execution_rep.csv", std::ios_base::app);
    if (!csvFile.is_open()) {
        std::cerr << "Error opening execution_rep.csv file." << std::endl;
        return;
    }

    csvFile << row.ord << "," << row.column1 << "," << row.column2 << ","
            << row.column3 << "," << row.newColumn << ","
            << row.column4 << "," << row.column5 << std::endl;

    csvFile.close();
}

void processOrderBook(std::vector<CSVRow>& buyTable, std::vector<CSVRow>& sellTable) {
    std::sort(buyTable.begin(), buyTable.end(), [](const CSVRow& a, const CSVRow& b) {
        return std::stoi(a.column5) > std::stoi(b.column5);
    });

    std::sort(sellTable.begin(), sellTable.end(), [](const CSVRow& a, const CSVRow& b) {
        return std::stoi(a.column5) < std::stoi(b.column5);
    });

    for (auto sellRow = sellTable.begin(); sellRow != sellTable.end(); ++sellRow) {
        for (CSVRow& buyRow : buyTable) {
            if (std::stoi(sellRow->column5) <= std::stoi(buyRow.column5)) {
                if (std::stoi(sellRow->column4) > std::stoi(buyRow.column4)) {
                    buyRow.newColumn = "Fill";
                    sellRow->column4 = std::to_string(std::stoi(sellRow->column4) - std::stoi(buyRow.column4));
                    sellRow->newColumn = "PFill";
                    writeLineToOutputCSV(buyRow);
                } else if (std::stoi(sellRow->column4) == std::stoi(buyRow.column4)) {
                    buyRow.newColumn = "Fill";
                    sellRow->newColumn = "Fill";
                    writeLineToOutputCSV(buyRow);
                    writeLineToOutputCSV(*sellRow);
                    break;
                } else {
                    sellRow->newColumn = "Fill";
                    buyRow.column4 = std::to_string(std::stoi(buyRow.column4) - std::stoi(sellRow->column4));
                    buyRow.newColumn = "PFill";
                    writeLineToOutputCSV(*sellRow);
                }
            }
        }
    }
}
