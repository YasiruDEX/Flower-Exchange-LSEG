#include "OrderValidator.h"

bool OrderValidator::validateOrder(CSVRow &row)
{

    // Trim instrument column
    row.column2.erase(0, row.column2.find_first_not_of(" \t\r\n"));
    row.column2.erase(row.column2.find_last_not_of(" \t\r\n") + 1);

    set<string> validInstruments = {"Rose", "Lavender", "Lotus", "Tulip", "Orchid"};
    if (validInstruments.find(row.column2) == validInstruments.end())
    {
        row.newColumn = "Reject"; // Invalid instrument
        return false;
    }

    // Trim side column
    row.column3.erase(0, row.column3.find_first_not_of(" \t\r\n"));
    row.column3.erase(row.column3.find_last_not_of(" \t\r\n") + 1);

    // Invalid Side, should be "1" or "2"
    if (stoi(row.column3) > 2 || stoi(row.column3) < 1)
    {
        row.newColumn = "Reject";
        return false;
    }

    // Price must be greater than 0
    if (stoi(row.column5) <= 0)
    {
        row.newColumn = "Reject";
        return false;
    }

    // Quantity must be a multiple of 10 and within the range [10, 1000]
    if (stoi(row.column4) % 10 != 0 || stoi(row.column4) < 10 || stoi(row.column4) > 1000)
    {
        row.newColumn = "Reject";
        return false;
    }

    if (row.column1.empty() || row.column2.empty() || row.column3.empty() || row.column4.empty() || row.column5.empty())
    {
        row.newColumn = "Reject"; // Missing fields
        return false;
    }

    return true;
}
