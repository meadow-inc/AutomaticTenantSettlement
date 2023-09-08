#include "LetterCreator.h"
#include "Bill.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

LetterCreator::LetterCreator(Bill b, std::string ls, std::string ts)
    : bill(b)
{

    std::ifstream letter_file(ls);

    if (!letter_file) {
        std::cerr << "Failed to open file: " << ls << std::endl;
    }
    std::stringstream bufLetter;
    bufLetter << letter_file.rdbuf();

    std::ifstream table_file(ts);

    if (!table_file){
        std::cerr << "Failed to open file: " << ts << std::endl;
    }

    std::stringstream bufTable;
    bufTable << table_file.rdbuf();

    letter = bufLetter.str();
    table = bufTable.str();

}

void LetterCreator::_replace_table_placeholder(const std::string placeholder, const std::string value) {
    size_t pos = table.find(placeholder);
    if (pos != std::string::npos){
        table.replace(pos, placeholder.length(), value);
    }
    else {
        std::cerr << "Error: Placeholder for table not found" << std::endl;
    }
}

void LetterCreator::_replace_letter_placeholder(const std::string placeholder, const std::string value){
    size_t pos = letter.find(placeholder);
    if (pos != std::string::npos){
        letter.replace(pos, placeholder.length(), value);
    }
    else {
        std::cerr << "Error: Placeholder for letter not found" << std::endl;
    }


}
std::string LetterCreator::_floatToStringWithPrecision(float value, int precision){
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << value;
    return out.str();
}

void LetterCreator::_createLetter(){

    _replace_letter_placeholder("summe_nachzahlung", _floatToStringWithPrecision(bill.summe_nachzahlung(), 2));
    _replace_letter_placeholder("rechnungs_jahr", std::to_string(bill.get_rechnungs_jahr()));
    _replace_letter_placeholder("tenant_vorname", bill.get_tenant().getVorname());
    _replace_letter_placeholder("tenant_nachname", bill.get_tenant().getNachname());
    _replace_letter_placeholder("zahlungstag", bill.get_zahlungs_tag());
    _replace_letter_placeholder("overview_table", table); 
}



void LetterCreator::_createTable(){
    _replace_table_placeholder("\\placeholder{ista_abrechnung}", _floatToStringWithPrecision(bill.get_tenant().getIstaRechnung(), 2));
    _replace_table_placeholder("\\placeholder{muell_einheitspreis}", _floatToStringWithPrecision(bill.get_muell_einheitspreis(), 2));
    _replace_table_placeholder("\\placeholder{muell_multiplikator}", _floatToStringWithPrecision(bill.get_muell_multiplikator(), 2));
    _replace_table_placeholder("\\placeholder{muell_gesamt}", _floatToStringWithPrecision(bill.muell_kosten(), 2));
    _replace_table_placeholder("\\placeholder{wasser_einheitspreis}", _floatToStringWithPrecision(bill.get_wasser_einheitspreis(), 2));
    _replace_table_placeholder("\\placeholder{wasser_multiplikator}", _floatToStringWithPrecision(bill.get_wasser_multiplikator(), 2));
    _replace_table_placeholder("\\placeholder{wasser_gesamt}", _floatToStringWithPrecision(bill.wasser_kosten(), 2));
    _replace_table_placeholder("\\placeholder{wasser_grundgebuehr_einheitspreis}", _floatToStringWithPrecision(bill.get_wasser_grundgebuehr_einheitspreis(), 2));
    _replace_table_placeholder("\\placeholder{wasser_grundgebuehr_multiplikator}", _floatToStringWithPrecision(bill.get_wasser_grundgebuehr_multiplikator(), 2));
    _replace_table_placeholder("\\placeholder{wasser_grundgebuehr_gesamt}", _floatToStringWithPrecision(bill.wasser_grundgebuehr_kosten(), 2));
    _replace_table_placeholder("\\placeholder{schmutz_niederschlagswasser_einheitspreis}", _floatToStringWithPrecision(bill.get_schmutz_niederschlagswasser_einheitspreis(), 2));
    _replace_table_placeholder("\\placeholder{schmutz_niederschlagswasser_multiplikator}", _floatToStringWithPrecision(bill.get_schmutz_niederschlagswasser_multiplikator(), 2));
    _replace_table_placeholder("\\placeholder{schmutz_niederschlagswasser_gesamt}", _floatToStringWithPrecision(bill.schmutz_niederschlagswasser_kosten(), 2));
    _replace_table_placeholder("\\placeholder{strom_allgemein_einheitspreis}", _floatToStringWithPrecision(bill.get_strom_allgemein_einheitspreis(), 2));
    _replace_table_placeholder("\\placeholder{strom_allgemein_multiplikator}", _floatToStringWithPrecision(bill.get_strom_allgemein_multiplikator(), 2));
    _replace_table_placeholder("\\placeholder{strom_allgemein_gesamt}", _floatToStringWithPrecision(bill.strom_allgemein_kosten(), 2));
    _replace_table_placeholder("\\placeholder{grundsteuer_einheitspreis}", _floatToStringWithPrecision(bill.get_grundsteuer_einheitspreis(), 2));
    _replace_table_placeholder("\\placeholder{grundsteuer_multiplikator}", _floatToStringWithPrecision(bill.get_grundsteuer_multiplikator(), 2));
    _replace_table_placeholder("\\placeholder{grundsteuer_gesamt}", _floatToStringWithPrecision(bill.get_grundsteuer_multiplikator(), 2)); // TDODOODODODO
    _replace_table_placeholder("\\placeholder{feuer_haftpflicht_einheitspreis}", _floatToStringWithPrecision(bill.get_feuer_haftpflicht_einheitspreis(), 2));
    _replace_table_placeholder("\\placeholder{feuer_haftpflicht_multiplikator}", _floatToStringWithPrecision(bill.get_feuer_haftpflicht_multiplikator(), 2));
    _replace_table_placeholder("\\placeholder{feuer_haftpflicht_gesamt}", _floatToStringWithPrecision(bill.feuer_haftpflicht_kosten(), 2));
    _replace_table_placeholder("\\placeholder{hausmeister_einheitspreis}", _floatToStringWithPrecision(bill.get_hausmeister_einheitspreis(), 2));
    _replace_table_placeholder("\\placeholder{hausmeister_multiplikator}", _floatToStringWithPrecision(bill.get_hausmeister_multiplikator(), 2));
    _replace_table_placeholder("\\placeholder{hausmeister_gesamt}", _floatToStringWithPrecision(bill.hausmeister_kosten(), 2));
    _replace_table_placeholder("\\placeholder{summe_kosten}", _floatToStringWithPrecision(bill.summe_kosten(), 2));
    _replace_table_placeholder("\\placeholder{summe_vorauszahlung}", _floatToStringWithPrecision(bill.get_tenant().getVorauszahlung(), 2));
    _replace_table_placeholder("\\placeholder{summe_nachzahlung}", _floatToStringWithPrecision(bill.summe_nachzahlung(), 2));
    

}
