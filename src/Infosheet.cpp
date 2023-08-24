#include <map>
#include <regex>
#include <string>
#include <vector>

class Tenant{
    
};

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
        int getAnzahlWohnungen() const { return anzahl_wohnungen; }
        std::string getZahlungstag() const { return zahlungstag; }
        float getWasserGrundpreis() const { return wasser_grundpreis; }
        float getWasserPreisKubik() const { return wasser_preis_kubik; }
        float getNiederschlagswasser() const { return niederschlagswasser; }
        float getSchmutzwasser() const { return schmutzwasser; }
        float getHaftpflichtversicherung() const { return haftpflichtversicherung; }
        float getElementarversicherung() const { return elementarversicherung; }
        std::map<std::string, float> getGrundsteuer() const { return grundsteuer; }
        float getStromAllgemein() const { return strom_allgemein; }
        std::map<std::string, float> getApartments() const { return apartments; }
        std::vector<Tenant> getTenants() const { return tenants; }

        bool validate(){
            bool result = _validate_zahlungstag() && _validate_apartments() &&
                _validate_anzahl_wohnungen() && _validate_grundsteuer() &&
                _validate_muellabfuhr() && _validate_schmutzwasser() &&
                _validate_strom_allgemein() && _validate_wasser_preis_kubik() &&
                _validate_niederschlagswasser() && _validate_elementarversicherung() &&
                _validate_haftpflichtversicherung();
            return result;
        }


    private:

        bool _validate_anzahl_wohnungen(){
            return anzahl_wohnungen > 0;
        }

        bool _validate_zahlungstag(){
            std::regex pattern("^(0[1-9]|1[0-9]|2[0-9]|3[0-1])\\.(0[0-9]|1[0-2])\\.([2][0][0-9][0-9])$");  
            return std::regex_match(zahlungstag, pattern);
        }

        bool _validate_muellabfuhr(){
            return muellabfuhr > 0;
        }

        bool _validate_grundsteuer(){
            bool cond1 = grundsteuer.size() == 3;
            bool cond2 = (grundsteuer.find("Erdgeschoss") != grundsteuer.end() && grundsteuer["Erdgeschoss"] > 0)
                && (grundsteuer.find("OG_links") != grundsteuer.end() && grundsteuer["OG_links"] > 0)
                && (grundsteuer.find("OG_rechts") != grundsteuer.end() && grundsteuer["OG_rechts"] > 0);

            return cond1 && cond2;
        }

        bool _validate_apartments(){
            bool cond1 = apartments.size() == 5;
            bool cond2 = (apartments.find("Apartment") != apartments.end() && apartments["Apartment"] > 0)
                && (apartments.find("OG_rechts") != apartments.end() && apartments["OG_rechts"] > 0)
                && (apartments.find("OG_links") != apartments.end() && apartments["OG_links"] > 0)
                && (apartments.find("EG_rechts") != apartments.end() && apartments["EG_rechts"] > 0)
                && (apartments.find("EG_links") != apartments.end() && apartments["EG_links"] > 0);

            return cond1 && cond2;
        }

        bool _validate_wasser_preis_kubik(){
            return wasser_preis_kubik > 0;
        }

        bool _validate_niederschlagswasser(){
            return niederschlagswasser > 0;
        }

        bool _validate_schmutzwasser(){
            return schmutzwasser > 0;
        }

        bool _validate_haftpflichtversicherung(){
            return haftpflichtversicherung > 0;
        }

        bool _validate_elementarversicherung(){
            return elementarversicherung > 0;
        }

        bool _validate_strom_allgemein(){
            return strom_allgemein > 0;
        }
        
        //TODO validate tenants for being in proper location
};

