#ifndef INFOSHEETPARSER_H
#define INFOSHEETPARSER_H

#include "Tenant.h"
#include <string>
#include <map>
#include <vector>

class InfoSheetParser {
private:
    std::string input;

    std::vector<Tenant> extract_tenants();
    std::map<std::string, float> parseDictionary(const std::string &search_term);
    std::string extractValue(const std::string &key);
    int _extract_int_value(const std::string &key);
    float _extract_float_value(const std::string &key);
    std::string _extract_string_value(const std::string &key);

public:
    InfoSheetParser(const std::string &source_destination);
};

#endif // INFOSHEETPARSER_H

 
