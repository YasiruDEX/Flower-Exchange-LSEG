// OrderValidator.cpp
#include "OrderValidator.h"
#include <set>

bool validateOrder(CSVRow& row) {

    std::set<std::string> validInstruments = {"Rose", "Lavender", "Lotus", "Tulip", "Orchid"};
    if (validInstruments.find(row.column2) == validInstruments.end()) {
        row.newColumn = "Reject";
        return false;
    }

    if (std::stoi(row.column3) > 2 || std::stoi(row.column3) < 1) {
        row.newColumn = "Reject";
        return false;
    }

    if (std::stoi(row.column5) <= 0) {
        row.newColumn = "Reject";
        return false;
    }

    if (std::stoi(row.column4) % 10 != 0 || std::stoi(row.column4) < 10 || std::stoi(row.column4) > 1000) {
        row.newColumn = "Reject";
        return false;
    }
    
    if (row.column1.empty() || row.column2.empty() || row.column3.empty() || 
        row.column4.empty() || row.column5.empty()) {
        row.newColumn = "Reject";
        return false;
    }

    return true;
}
