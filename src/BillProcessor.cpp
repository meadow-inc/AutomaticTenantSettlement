#include "BillProcessor.h"
#include "Infosheet.h"
#include <stdexcept>
#include <string>

BillProcessor::BillProcessor(Infosheet is, Tenant t):
    infosheet(is),
    tenant(t){};

Bill BillProcessor::process() const {
    float me = _calc_muell_einheitspreis();
    float mm = tenant.get_personenmonate();
    float we = _calc_wasser_einheitspreis();
    float wm = tenant.getWassermenge();
    float wge = _calc_wasser_grundgebuehr_einheitspreis();
    float wgm = 1;
    float sne = _calc_schmutz_niederschlagswasser_einheitspreis();
    float snm = infosheet.getApartments().at(tenant.getOrt());
    float sae = _calc_strom_allgemein_einheitspreis();
    float sam = infosheet.getApartments().at(tenant.getOrt());
    float ge = _calc_grundsteuer_einheitspreis();
    float gm = infosheet.getApartments().at(tenant.getOrt());
    float fhe = _calc_feuer_haftpflicht_einheitspreis();
    float fhm = infosheet.getApartments().at(tenant.getOrt());
    float he = tenant.getHausmeister();
    float hm = tenant.getDauer();
    int rj = _calc_rechnungs_jahr();
    std::string zt = infosheet.getZahlungstag();
    Bill result = Bill(tenant, me, mm, we, wm, wge, wgm, sne, snm, sae,
            sam, ge, gm, fhe, fhm, he, hm, rj, zt);
    return result;

    
}

float BillProcessor::_calc_muell_einheitspreis() const {
    return infosheet.getMuellabfuhr() / infosheet.getPersonenMonate();
}

float BillProcessor::_calc_wasser_einheitspreis() const{
    return infosheet.getWasserPreisKubik() / 0.93;
}

float BillProcessor::_calc_wasser_grundgebuehr_einheitspreis() const {
    return infosheet.getWasserGrundpreis() / 0.93 / infosheet.getAnzahlWohnungen();
}

float BillProcessor::_calc_schmutz_niederschlagswasser_einheitspreis() const {
    return (infosheet.getSchmutzwasser() + infosheet.getNiederschlagswasser()) / infosheet.getTotalSquareMeter();
}

float BillProcessor::_calc_strom_allgemein_einheitspreis() const {
    return infosheet.getStromAllgemein() / 2 / infosheet.getTotalSquareMeter();
}

float BillProcessor::_calc_grundsteuer_einheitspreis() const {
    float geschoss_grundsteuer;
    float geschoss_groesse = 0;
    if (tenant.getOrt() == "Apartment" || tenant.getOrt().find("EG_") != std::string::npos){
        geschoss_grundsteuer = infosheet.getGrundsteuer().at("Erdgeschoss");
        geschoss_groesse += infosheet.getApartments().at("Apartment") + infosheet.getApartments().at("EG_link") +
            infosheet.getApartments().at("EG_rechts");
    }
    else if (tenant.getOrt() == "OG_links"){
        geschoss_grundsteuer = infosheet.getGrundsteuer().at("OG_links");
        geschoss_groesse += infosheet.getApartments().at("OG_links");
    }
    else if (tenant.getOrt() == "OG_rechts"){
        geschoss_grundsteuer = infosheet.getGrundsteuer().at("OG_rechts");
        geschoss_groesse += infosheet.getApartments().at("OG_rechts");
    }
    else{
        throw std::runtime_error("Tenant has wrong location");
    }

    return geschoss_grundsteuer / geschoss_groesse;
}

float BillProcessor::_calc_feuer_haftpflicht_einheitspreis() const{
    return (infosheet.getHaftpflichtversicherung() + infosheet.getElementarversicherung()) / infosheet.getTotalSquareMeter(); 
}

int BillProcessor::_calc_rechnungs_jahr() const{
    std::string year = infosheet.getZahlungstag().substr(6,4);
    int value = std::stoi(year);
    return value - 1;
}

