#ifndef BILLPROCESSOR_H
#define BILLPROCESSOR_H

#include "Bill.h"
#include "Infosheet.h"
#include "Tenant.h"
class BillProcessor{
    private:
        Infosheet infosheet;
        Tenant tenant;

    public:
        BillProcessor(Infosheet is, Tenant t);
        Bill process() const;

    private:

        float _calc_muell_einheitspreis() const;
        float _calc_muell_multiplikator() const;
        float _calc_wasser_einheitspreis() const;
        float _calc_wasser_multiplikator() const;
        float _calc_wasser_grundgebuehr_einheitspreis() const;
        float _calc_wasser_grundgebuehr_multiplikator() const;
        float _calc_schmutz_niederschlagswasser_einheitspreis() const;
        float _calc_schmutz_niederschlagswasser_multiplikator() const;
        float _calc_strom_allgemein_einheitspreis() const;
        float _calc_strom_allgemein_multiplikator() const;
        float _calc_grundsteuer_einheitspreis() const;
        float _calc_grundsteuer_multiplikator() const;
        float _calc_feuer_haftpflicht_einheitspreis() const;
        float _calc_feuer_haftpflicht_multiplikator() const;
        float _calc_hausmeister_einheitspreis() const;
        float _calc_hausmeister_multiplikator() const;
        int _calc_rechnungs_jahr() const;
        
};
#endif
