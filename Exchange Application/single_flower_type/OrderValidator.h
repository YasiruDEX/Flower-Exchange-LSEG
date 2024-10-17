#ifndef ORDERVALIDATOR_H
#define ORDERVALIDATOR_H

#include "CSVRow.h"
#include <set>
#include <string>

class OrderValidator {
public:
    // Validate order and determine if it should be accepted or rejected
    bool validateOrder(CSVRow& row);
};

#endif // ORDERVALIDATOR_H
