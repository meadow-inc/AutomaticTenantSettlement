#ifndef INFOSHEET_H
#define INFOSHEET_H

#include "Tenant.h"
#include <map>
#include <vector>

class Infosheet{
    private: 
        int anzahl_wohnungen;
        std::string zahlungstag;
        float muellabfuhr;
        float wasser_grundpreis;
        float wasser_preis_kubik;
        float niederschlagswasser;
        float schmutzwasser;
        float haftpflichtversicherung;
        float elementarversicherung;
        std::map<std::string, float> grundsteuer;
        float strom_allgemein;
        std::map<std::string, float> apartments;
        std::vector<Tenant> tenants;       

    public:
        Infosheet(
                int anzahl, std::string zahlung, float muell, float wasser_grund, float wasser_kubik,
                float niederschlag, float schmutz, float haftpflicht, float elementar, 
                std::map<std::string, float> steuer, float strom, 
                std::map<std::string, float> aparts, std::vector<Tenant> tnts
                );
        // Getters
        int getAnzahlWohnungen() const;
        std::string getZahlungstag() const ;
        float getMuellabfuhr() const;
        float getWasserGrundpreis() const ;
        float getWasserPreisKubik() const ;
        float getNiederschlagswasser() const ;
        float getSchmutzwasser() const ;
        float getHaftpflichtversicherung() const ;
        float getElementarversicherung() const ;
        std::map<std::string, float> getGrundsteuer() const ;
        float getStromAllgemein() const ;
        std::map<std::string, float> getApartments() const ;
        std::vector<Tenant> getTenants() const ;

        bool validate() const;

        float getPersonenMonate() const;

        float getTotalSquareMeter() const;     

    private:

        bool _validate_anzahl_wohnungen() const ;

        bool _validate_zahlungstag() const ;

        bool _validate_muellabfuhr() const ;
        
        bool _validate_grundsteuer() const;

        bool _validate_apartments()const ;
        
        bool _validate_wasser_preis_kubik() const;

        bool _validate_niederschlagswasser() const ;
        
        bool _validate_schmutzwasser() const ;

        bool _validate_haftpflichtversicherung() const;
        
        bool _validate_elementarversicherung() const;

        bool _validate_strom_allgemein()const;

        bool _validate_ort() const;


};
#endif 
