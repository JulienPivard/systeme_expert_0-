/**
 * @file OperateurAbstrait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier OperateurAbstrait.cpp.
 * Définit la classe abstraite OperateurAbstrait.
 * */


#ifndef operateurabstrait_hpp
#define operateurabstrait_hpp

#include <cstdlib>

#include "ValeurAbstraite.hpp"

/**
 * @namespace sysexp
 * */
namespace sysexp
{
    /**
     * @namespace sysexp::modele
     * */
    namespace modele
    {

        /**
        * @class OperateurAbstrait OperateurAbstrait.hpp
        *
        * Déclaration de la classe OperateurAbstrait.
        * */
        class OperateurAbstrait : public ValeurAbstraite
        {

            public:

                /**
                * Constructeur logique
                *
                * @param[in] filsGauche
                * Le fils gauche de l'opération. Voir @ref filsGauche_.
                * @param[in] filsDroit
                * Le fils droit de l'opération. Voir @ref filsDroit_.
                * */
                OperateurAbstrait( const ValeurAbstraite::Valeur & filsGauche, const ValeurAbstraite::Valeur & filsDroit );

                /**
                * Destructeur de OperateurAbstrait.
                * */
                virtual ~OperateurAbstrait();

            protected:
                /**
                * Le fils gauche de l'opération.
                * */
                const ValeurAbstraite::Valeur filsGauche_;

                /**
                * Le fils droit de l'opération.
                * */
                const ValeurAbstraite::Valeur filsDroit_;

        };

    }
}

#endif
