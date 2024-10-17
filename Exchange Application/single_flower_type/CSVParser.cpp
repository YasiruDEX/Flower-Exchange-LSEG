#include "CSVParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Trim whitespace from the beginning and end of a string
void CSVParser::trim(string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start != string::npos && end != string::npos) {
        s = s.substr(start, end - start + 1);
    } else {
        s.clear();
    }
}

// Read CSV file and return the data as a vector of CSVRow structs
vector<CSVRow> CSVParser::readCSV(const string& filename) {
    vector<CSVRow> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        CSVRow row;

        row.ord = "ord" + to_string(data.size() + 1); // Generate Order ID

        getline(ss, row.column1, ',');
        getline(ss, row.column2, ',');
        getline(ss, row.column3, ',');
        row.newColumn = "New"; // Default status for new orders
        getline(ss, row.column4, ',');
        getline(ss, row.column5, ',');

        trim(row.column3); // Trim whitespace from column3

        data.push_back(row);
    }

    file.close();
    return data;
}
