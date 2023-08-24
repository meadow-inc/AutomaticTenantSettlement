#ifndef TENANT_H 
#define TENANT_H 

#include <string>
class Tenant{
    private:
        std::string vorname;
        std::string nachname;
        float hausmeister;
        std::string ort;
        float dauer;
        float personen;
        float vorauszahlung;
        float ista_rechnung;
        float wassermenge;

    public:
        Tenant(std::string vorname, std::string nachname, float hausmeister,
                std::string ort, float dauer, float personen, float vorauszahlung,
                float ista_rechnung, float wassermenge);

        bool validate();

        // Getters for the private members

        std::string getVorname() const;

        std::string getNachname() const ;

        float getHausmeister() const ;

        std::string getOrt() const ;

        float getDauer() const ;

        float getPersonen() const ;

        float getVorauszahlung() const ;

        float getIstaRechnung() const ;

        float getWassermenge() const ;

        float get_personenmonate();

    private:
        
        bool _validate_vorname();

        bool _validate_nachname();
        
        bool _validate_hausmeister();

        bool _validate_ort();

        bool _validate_dauer();

        bool _validate_personen();

        bool _validate_vorauszahlung();

        bool _validate_ista_rechnung();

        bool _validate_wassermenge();


};
#endif
