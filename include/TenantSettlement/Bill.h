#ifndef BILL_H
#define BILL_H
#include "Tenant.h"

class Bill{
    private:
        Tenant tenant;
        float muell_einheitspreis;
        float muell_multiplikator;
        float wasser_einheitspreis;
        float wasser_multiplikator;
        float wasser_grundgebuehr_einheitspreis;
        float wasser_grundgebuehr_multiplikator;
        float schmutz_niederschlagswasser_einheitspreis;
        float schmutz_niederschlagswasser_multiplikator;
        float strom_allgemein_einheitspreis;
        float strom_allgemein_multiplikator;
        float grundsteuer_einheitspreis;
        float grundsteuer_multiplikator;
        float feuer_haftpflicht_einheitspreis;
        float feuer_haftpflicht_multiplikator;
        float hausmeister_einheitspreis;
        float hausmeister_multiplikator;
        int rechnungs_jahr;
        std::string zahlungs_tag;

    public: 

        Bill(Tenant t, float me, float mm, float we, float wm,
                float wge, float wgm, float sne, float snm, float sae, float sam,
                float ge, float gm, float fhe, float fhm, float he, float hm, float rj, std::string zt);

        Tenant get_tenant() const;
        float get_muell_einheitspreis() const;
        float get_muell_multiplikator() const;
        float get_wasser_einheitspreis() const;
        float get_wasser_multiplikator() const;
        float get_wasser_grundgebuehr_einheitspreis() const;
        float get_wasser_grundgebuehr_multiplikator() const;
        float get_schmutz_niederschlagswasser_einheitspreis() const;
        float get_schmutz_niederschlagswasser_multiplikator() const;
        float get_strom_allgemein_einheitspreis() const;
        float get_strom_allgemein_multiplikator() const;
        float get_grundsteuer_einheitspreis() const;
        float get_grundsteuer_multiplikator() const;
        float get_feuer_haftpflicht_einheitspreis() const;
        float get_feuer_haftpflicht_multiplikator() const;
        float get_hausmeister_einheitspreis() const;
        float get_hausmeister_multiplikator() const;
        int get_rechnungs_jahr() const;
        std::string get_zahlungs_tag() const;

        float muell_kosten() const;
        float wasser_kosten() const;
        float wasser_grundgebuehr_kosten() const;
        float schmutz_niederschlagswasser_kosten() const;
        float strom_allgemein_kosten() const;
        float feuer_haftpflicht_kosten() const;
        float grundsteuer_kosten() const;
        float hausmeister_kosten() const;
        float summe_kosten() const;
        float summe_nachzahlung() const;


};
#endif
