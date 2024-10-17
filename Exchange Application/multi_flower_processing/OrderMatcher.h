// OrderMatcher.h
#ifndef ORDERMATCHER_H
#define ORDERMATCHER_H

#include <vector>
#include "CSVRow.h"

void processOrderBook(std::vector<CSVRow>& buyTable, std::vector<CSVRow>& sellTable);
void writeLineToOutputCSV(const CSVRow& row);

#endif // ORDERMATCHER_H
