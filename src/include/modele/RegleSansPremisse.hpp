/**
 * @file RegleSansPremisse.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier RegleSansPremisse.cpp.
 * Définit la classe concrète RegleSansPremisse.
 * */


#ifndef reglesansconclusion_hpp
#define reglesansconclusion_hpp

#include <exception>

#include "RegleAbstraite.hpp"
#include "FormeAbstraiteConclusion.hpp"
#include "VisiteurForme.hpp"


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Représente une règle sans prémisse.
         *
         * Déclaration de la classe RegleSansPremisse.
         * */
        class RegleSansPremisse : public RegleAbstraite
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] numeroRegle
                 * Le @ref numeroRegle_ de la règle dans la base de connaissance,
                 * à l'intention de l'utilisateur en cas d'erreur d'exécution.
                 * @param[in] conclusion
                 * La @ref conclusion_ de la règle.
                 *
                 * @note N'utiliser traceExecution que pour le debogage ! Laissez le champ vide sinon.
                 * */
                RegleSansPremisse( const unsigned int & numeroRegle,
                        const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion );

                /**
                 * Vérifie que toutes les prémisses sont vérifiées par rapport à la base de faits.
                 *
                 * @param[in] base
                 * La base de faits utilisée pour vérifier les prémisses.
                 *
                 * @return Toutes les prémisses sont vérifiées.
                 * */
                bool verifierPremisses( const BaseFait::PtrBaseFait & base );

        };

    }
}

#endif
