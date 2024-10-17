#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "CSVRow.h"
#include <vector>
#include <string>
using namespace std;

class CSVParser {
public:
    // Read CSV file and return the data as a vector of CSVRow structs
    vector<CSVRow> readCSV(const string& filename);

private:
    void trim(string& s); // Trim whitespace from strings
};

#endif // CSVPARSER_H
