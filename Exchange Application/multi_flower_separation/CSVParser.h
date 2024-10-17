// CSVParser.h
#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <vector>
#include <string>
#include "CSVRow.h"

std::vector<CSVRow> readCSV(const std::string& filename);

#endif // CSVPARSER_H
