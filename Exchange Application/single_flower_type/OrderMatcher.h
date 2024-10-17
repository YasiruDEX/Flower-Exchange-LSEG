#ifndef ORDERMATCHER_H
#define ORDERMATCHER_H

#include "CSVRow.h"
#include <vector>

class OrderMatcher {
public:
    void matchOrders(vector<CSVRow>& buyTable, vector<CSVRow>& sellTable);
    void writeLineToOutputCSV(const CSVRow& row);

private:
    // void writeLineToOutputCSV(const CSVRow& row);
};

#endif // ORDERMATCHER_H
