// CSVRow.h
#ifndef CSVROW_H
#define CSVROW_H

#include <string>

struct CSVRow {
    std::string ord;       // Order ID
    std::string column1;   // Client Order ID
    std::string column2;   // Instrument
    std::string column3;   // Side (1 = Buy, 2 = Sell)
    std::string newColumn; // Execution Status (New, PFill, Fill, Reject)
    std::string column4;   // Quantity
    std::string column5;   // Price
};

void trim(std::string& s);

#endif // CSVROW_H
