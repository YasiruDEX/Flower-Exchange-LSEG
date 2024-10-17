#ifndef CSVROW_H
#define CSVROW_H

#include <string>
using namespace std;

struct CSVRow {
    string ord;       // Order ID
    string column1;   // Client Order ID
    string column2;   // Instrument
    string column3;   // Side
    string newColumn; // Execution Status (New, PFill, Fill, Reject)
    string column4;   // Quantity
    string column5;   // Price
};

#endif // CSVROW_H
