#ifndef LETTERCREATOR_H
#define LETTERCREATOR_H

#include "Bill.h"
#include <iostream>
#include <ostream>
#include <string>
class LetterCreator{

    private:
        Bill bill;
        std::string table;
        std::string letter;

    public: 
        LetterCreator(Bill b, std::string ls, std::string ts);
        
    private:
        void _createTable();
        void _replace_table_placeholder(const std::string placeholder, const std::string value) ;
        void _replace_letter_placeholder(const std::string placeholder, const std::string value);
        void _createLetter();
        std::string _floatToStringWithPrecision(float value, int precision);
};
#endif
