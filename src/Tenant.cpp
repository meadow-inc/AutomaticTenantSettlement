#include "Tenant.h"
#include <string>


Tenant::Tenant(std::string vorname, std::string nachname, float hausmeister,
        std::string ort, float dauer, float personen, float vorauszahlung,
        float ista_rechnung, float wassermenge):
    vorname(vorname),
    nachname(nachname),
    hausmeister(hausmeister),
    ort(ort),
    dauer(dauer),
    personen(personen),
    vorauszahlung(vorauszahlung),
    ista_rechnung(ista_rechnung),
    wassermenge(wassermenge){}

    bool Tenant::validate(){
        bool result = _validate_ort() && _validate_dauer() &&
            _validate_vorname() && _validate_nachname() && 
            _validate_hausmeister() && _validate_personen() &&
            _validate_wassermenge() && _validate_ista_rechnung() &&
            _validate_vorauszahlung();
        return result;
    }

// Getters for the private members

std::string Tenant::getVorname() const {
    return vorname;
}

std::string Tenant::getNachname() const {
    return nachname;
}

float Tenant::getHausmeister() const {
    return hausmeister;
}

std::string Tenant::getOrt() const {
    return ort;
}

float Tenant::getDauer() const {
    return dauer;
}

float Tenant::getPersonen() const {
    return personen;
}

float Tenant::getVorauszahlung() const {
    return vorauszahlung;
}

float Tenant::getIstaRechnung() const {
    return ista_rechnung;
}

float Tenant::getWassermenge() const {
    return wassermenge;
}

float Tenant::get_personenmonate(){
    return dauer * personen;
}


bool Tenant::_validate_vorname(){
    return !vorname.empty();
}

bool Tenant::_validate_nachname(){
    return !nachname.empty();
}

bool Tenant::_validate_hausmeister(){
    return hausmeister > 0;
}

bool Tenant::_validate_ort(){
    return !ort.empty();
}

bool Tenant::_validate_dauer(){
    return dauer > 0;
}

bool Tenant::_validate_personen(){
    return personen > 1;
}

bool Tenant::_validate_vorauszahlung(){
    return vorauszahlung > 0;
}

bool Tenant::_validate_ista_rechnung(){
    return ista_rechnung > 0;
}

bool Tenant::_validate_wassermenge(){
    return wassermenge > 0;
}

