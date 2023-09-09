#include "../../include/TenantSettlement/InfoSheetParser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

InfoSheetParser::InfoSheetParser(const std::string &source_destination){
    std::ifstream fileStream(source_destination);
    if (!fileStream.is_open()){
        throw std::runtime_error("Could not open file: " + source_destination);
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    input = buffer.str();
    fileStream.close();
}

std::vector<Tenant> InfoSheetParser::extract_tenants(){
    std::vector<std::string> sections;

    std::size_t start = 0;
    std::size_t end = 0;

    while ((start = input.find("<Tenant>")) != std::string::npos){
        if ((end = input.find("<\\Tenant>", start + 1)) == std::string::npos){
            throw std::runtime_error("Wrong formatting for <Tenant>");
        }
        std::string section = input.substr(start + std::string("<Tenant>").length(),
                end - start - std::string("<Tenant>").length());
        sections.push_back(section);
    }

    std::vector<Tenant> result;

    for (const auto &section: sections){
        std::string vorname, nachname, ort;
        float hausmeister, dauer, personen, vorauszahlung, ista_rechnung, wasser_kubik;
        std::stringstream iss(section);
        std::string line;

        while (std::getline(iss, line)){
            std::size_t pos = line.find(':');
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](unsigned char ch) {
                        return !std::isspace(ch);
                        }));
            value.erase(std::find_if(value.rbegin(), value.rend(), [](unsigned char ch) {
                        return !std::isspace(ch);
                        }).base(), value.end());

            if (key == "first_name") vorname = value;
            else if (key == "last_name") nachname = value;
            else if (key == "house_master_price") hausmeister = std::stof(value);
            else if (key == "location") ort = value;
            else if (key == "duration") dauer = std::stof(value);
            else if (key == "quantity") personen = std::stof(value);
            else if (key == "advance_payment") vorauszahlung = std::stof(value);
            else if (key == "ista_bill") ista_rechnung = std::stof(value);
            else if (key == "water-cubic") wasser_kubik = std::stof(value);

            Tenant tmp = Tenant(vorname, nachname, hausmeister, ort, dauer, personen, vorauszahlung, ista_rechnung, wasser_kubik);
            result.push_back(tmp);
        }
    }
    return result;
}

std::map<std::string, float> InfoSheetParser::parseDictionary(const std::string &search_term) {
    std::map<std::string, float> resultMap;

    std::size_t start = input.find("<" + search_term + ">");
    std::size_t end = input.find("<\\" + search_term + ">");

    if (start == std::string::npos || end == std::string::npos) {
        throw std::runtime_error(search_term + "-section not found");
    }

    std::string section = input.substr(start + std::string("<" + search_term + ">").length(), 
            end - start - std::string("<" + search_term + ">").length());
    std::istringstream iss(section);
    std::string line;

    while (std::getline(iss, line)) {
        std::size_t colonPos = line.find(":");
        if (colonPos != std::string::npos) {
            std::string key = line.substr(0, colonPos);
            key = key.substr(0, key.find_last_not_of(" ")); // Trim trailing spaces

            std::string valueStr = line.substr(colonPos + 1);
            valueStr = valueStr.substr(valueStr.find_first_not_of(" ")); // Trim leading spaces

            float value = std::stof(valueStr);

            resultMap[key] = value;
        }else{
            throw std::runtime_error("Kein \":\" in Grundsteuer Dictionary");
        }
    }

    return resultMap;
}

std::string InfoSheetParser::extractValue(const std::string &key) {
    std::istringstream stream(input);
    std::string line;

    while (std::getline(stream, line)) {
        std::size_t pos = line.find(key);
        if (pos != std::string::npos) {
            return line.substr(pos + key.size());
        }
    }
    throw std::runtime_error("Key not found: " + key);
}

int InfoSheetParser::_extract_int_value(const std::string &key){
    std::string valueString = extractValue(key);
    int value;
    std::istringstream(valueString) >> value;
    return value;
} 

float InfoSheetParser::_extract_float_value(const std::string &key){
    std::string valueString = extractValue(key);
    int value;
    std::istringstream(valueString) >> value;
    return value;
}

std::string InfoSheetParser::_extract_string_value(const std::string &key){
    std::string valueString = extractValue(key);                
    return valueString;
}

