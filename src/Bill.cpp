#include "Bill.h"
#include "Tenant.h"
Bill::Bill(Tenant t, float me, float mm, float we, float wm,
        float wge, float wgm, float sne, float snm, float sae, float sam,
        float ge, float gm, float fhe, float fhm, float he, float hm, float rj, std::string zt):
    tenant(t),
    muell_einheitspreis(me),
    muell_multiplikator(mm),
    wasser_einheitspreis(we),
    wasser_multiplikator(wm),
    wasser_grundgebuehr_einheitspreis(wge),
    wasser_grundgebuehr_multiplikator(wgm),
    schmutz_niederschlagswasser_einheitspreis(sne),
    schmutz_niederschlagswasser_multiplikator(snm),
    strom_allgemein_einheitspreis(sae),
    strom_allgemein_multiplikator(sam),
    grundsteuer_einheitspreis(ge),
    grundsteuer_multiplikator(gm),
    feuer_haftpflicht_einheitspreis(fhe),
    feuer_haftpflicht_multiplikator(fhm),
    hausmeister_einheitspreis(he),
    hausmeister_multiplikator(hm),
    zahlungs_tag(zt)
{};

float Bill::muell_kosten() const {
    return muell_einheitspreis * muell_multiplikator;
}

float Bill::wasser_kosten() const {
    return wasser_einheitspreis * wasser_multiplikator;
}

float Bill::wasser_grundgebuehr_kosten() const {
    return wasser_grundgebuehr_einheitspreis * wasser_grundgebuehr_multiplikator;
}

float Bill::schmutz_niederschlagswasser_kosten() const {
    return schmutz_niederschlagswasser_einheitspreis * schmutz_niederschlagswasser_multiplikator;
}

float Bill::strom_allgemein_kosten() const {
    return strom_allgemein_einheitspreis * strom_allgemein_multiplikator;
}

float Bill::feuer_haftpflicht_kosten() const {
    return feuer_haftpflicht_einheitspreis * feuer_haftpflicht_multiplikator;
}

float Bill::hausmeister_kosten() const {
    return hausmeister_einheitspreis * hausmeister_multiplikator;
}

float Bill::grundsteuer_kosten() const {
    return grundsteuer_einheitspreis * grundsteuer_multiplikator;
}

float Bill::summe_kosten() const {
    float sum = muell_kosten() + wasser_kosten() + wasser_grundgebuehr_kosten() +
        schmutz_niederschlagswasser_kosten() + strom_allgemein_kosten() +
        feuer_haftpflicht_kosten() + hausmeister_kosten();
    return sum;
}

float Bill::summe_nachzahlung() const {
    return summe_kosten() - tenant.getVorauszahlung();
}

Tenant Bill::get_tenant() const {
    return tenant;
}

float Bill::get_muell_einheitspreis() const {
    return muell_einheitspreis;
}

float Bill::get_muell_multiplikator() const {
    return muell_multiplikator;
}

float Bill::get_wasser_einheitspreis() const {
    return wasser_einheitspreis;
}

float Bill::get_wasser_multiplikator() const {
    return wasser_multiplikator;
}

float Bill::get_wasser_grundgebuehr_einheitspreis() const {
    return wasser_grundgebuehr_einheitspreis;
}

float Bill::get_wasser_grundgebuehr_multiplikator() const {
    return wasser_grundgebuehr_multiplikator;
}

float Bill::get_schmutz_niederschlagswasser_einheitspreis() const {
    return schmutz_niederschlagswasser_einheitspreis;
}

float Bill::get_schmutz_niederschlagswasser_multiplikator() const {
    return schmutz_niederschlagswasser_multiplikator;
}

float Bill::get_strom_allgemein_einheitspreis() const {
    return strom_allgemein_einheitspreis;
}

float Bill::get_strom_allgemein_multiplikator() const {
    return strom_allgemein_multiplikator;
}

float Bill::get_grundsteuer_einheitspreis() const {
    return grundsteuer_einheitspreis;
}

float Bill::get_grundsteuer_multiplikator() const {
    return grundsteuer_multiplikator;
}

float Bill::get_feuer_haftpflicht_einheitspreis() const {
    return feuer_haftpflicht_einheitspreis;
}

float Bill::get_feuer_haftpflicht_multiplikator() const {
    return feuer_haftpflicht_multiplikator;
}

float Bill::get_hausmeister_einheitspreis() const {
    return hausmeister_einheitspreis;
}

float Bill::get_hausmeister_multiplikator() const {
    return hausmeister_multiplikator;
}

int Bill::get_rechnungs_jahr() const {
    return rechnungs_jahr;
}
 
std::string Bill::get_zahlungs_tag() const {
    return zahlungs_tag;
}



