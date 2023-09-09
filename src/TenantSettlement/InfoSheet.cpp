#include "../../include/TenantSettlement/InfoSheet.h"
#include <regex>
#include <string>

Infosheet::Infosheet(
        int anzahl, std::string zahlung, float muell, float wasser_grund, float wasser_kubik,
        float niederschlag, float schmutz, float haftpflicht, float elementar, 
        std::map<std::string, float> steuer, float strom, 
        std::map<std::string, float> aparts, std::vector<Tenant> tnts
        ) :
    anzahl_wohnungen(anzahl), 
    zahlungstag(zahlung),
    muellabfuhr(muell),
    wasser_grundpreis(wasser_grund),
    wasser_preis_kubik(wasser_kubik),
    niederschlagswasser(niederschlag),
    schmutzwasser(schmutz),
    haftpflichtversicherung(haftpflicht),
    elementarversicherung(elementar),
    grundsteuer(steuer),
    strom_allgemein(strom),
    apartments(aparts),
    tenants(tnts) 
{}




// Getters
int Infosheet::getAnzahlWohnungen() const { return anzahl_wohnungen; }
std::string Infosheet::getZahlungstag() const { return zahlungstag; }
float Infosheet::getWasserGrundpreis() const { return wasser_grundpreis; }
float Infosheet::getWasserPreisKubik() const { return wasser_preis_kubik; }
float Infosheet::getNiederschlagswasser() const { return niederschlagswasser; }
float Infosheet::getSchmutzwasser() const { return schmutzwasser; }
float Infosheet::getHaftpflichtversicherung() const { return haftpflichtversicherung; }
float Infosheet::getElementarversicherung() const { return elementarversicherung; }
std::map<std::string, float> Infosheet::getGrundsteuer() const { return grundsteuer; }
float Infosheet::getStromAllgemein() const { return strom_allgemein; }
std::map<std::string, float> Infosheet::getApartments() const { return apartments; }
std::vector<Tenant> Infosheet::getTenants() const { return tenants; }

bool Infosheet::validate() const {
    bool result = _validate_zahlungstag() && _validate_apartments() &&
        _validate_anzahl_wohnungen() && _validate_grundsteuer() &&
        _validate_muellabfuhr() && _validate_schmutzwasser() &&
        _validate_strom_allgemein() && _validate_wasser_preis_kubik() &&
        _validate_niederschlagswasser() && _validate_elementarversicherung() &&
        _validate_haftpflichtversicherung();
    return result;
}

float Infosheet::getPersonenMonate() const {
    float result = 0;
    for (const auto &tenant : tenants){
        float tmp;
        tmp = tenant.getDauer() * tenant.getPersonen();
        result += tmp;
    }
    return result;
}

float Infosheet::getTotalSquareMeter() const {
    float result = 0;
    for (const auto &apartment : apartments){
        result += apartment.second;
    }
    return result;
}

bool Infosheet::_validate_anzahl_wohnungen() const{
    return anzahl_wohnungen > 0;
}

bool Infosheet::_validate_zahlungstag() const {
    std::regex pattern("^(0[1-9]|1[0-9]|2[0-9]|3[0-1])\\.(0[0-9]|1[0-2])\\.([2][0][0-9][0-9])$");  
    return std::regex_match(zahlungstag, pattern);
}

bool Infosheet::_validate_muellabfuhr() const {
    return muellabfuhr > 0;
}

bool Infosheet::_validate_grundsteuer() const {
    bool cond1 = grundsteuer.size() == 3;
    bool cond2 = (grundsteuer.find("Erdgeschoss") != grundsteuer.end() && grundsteuer.at("Erdgeschoss") > 0)
        && (grundsteuer.find("OG_links") != grundsteuer.end() && grundsteuer.at("OG_links") > 0)
        && (grundsteuer.find("OG_rechts") != grundsteuer.end() && grundsteuer.at("OG_rechts") > 0);

    return cond1 && cond2;
}

bool Infosheet::_validate_apartments() const {
    bool cond1 = apartments.size() == 5;
    bool cond2 = (apartments.find("Apartment") != apartments.end() && apartments.at("Apartment") > 0)
        && (apartments.find("OG_rechts") != apartments.end() && apartments.at("OG_rechts") > 0)
        && (apartments.find("OG_links") != apartments.end() && apartments.at("OG_links") > 0)
        && (apartments.find("EG_rechts") != apartments.end() && apartments.at("EG_rechts") > 0)
        && (apartments.find("EG_links") != apartments.end() && apartments.at("EG_links") > 0);

    return cond1 && cond2;
}

bool Infosheet::_validate_wasser_preis_kubik() const{
    return wasser_preis_kubik > 0;
}

bool Infosheet::_validate_niederschlagswasser() const {
    return niederschlagswasser > 0;
}

bool Infosheet::_validate_schmutzwasser() const {
    return schmutzwasser > 0;
}

bool Infosheet::_validate_haftpflichtversicherung() const {
    return haftpflichtversicherung > 0;
}

bool Infosheet::_validate_elementarversicherung() const {
    return elementarversicherung > 0;
}

bool Infosheet::_validate_strom_allgemein() const {
    return strom_allgemein > 0;
}

bool Infosheet::_validate_ort() const {
    for (const auto &tenant : tenants){
        if (apartments.find(tenant.getOrt()) == apartments.end()){
            return false;
        }
    }
    return true;
}

