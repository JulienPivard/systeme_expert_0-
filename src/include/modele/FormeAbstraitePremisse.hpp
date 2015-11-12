/**
 * @file FormeAbstraitePremisse.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeAbstraitePremisse.cpp.
 * Définit la classe abstraite FormeAbstraitePremisse.
 * */


#ifndef formeabstraitepremisse_hpp
#define formeabstraitepremisse_hpp

#include <memory>

#include "FormeAbstraite.hpp"

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
         * @class FormeAbstraitePremisse FormeAbstraitePremisse.hpp
         * @brief Le squelette de représentation d'une prémisse.
         *
         * Déclaration de la classe FormeAbstraitePremisse.
         * */
        class FormeAbstraitePremisse : public FormeAbstraite
        {

            public:

                /**
                 * @typedef PtrFormeAbstraitePremisse
                 *
                 * Alias pour faciliter l'utilisation d'un shared_ptr de FormeAbstraitePremisse.
                 * */
                typedef std::shared_ptr< FormeAbstraitePremisse > PtrFormeAbstraitePremisse;

                /**
                 * @typedef OperateurComparaison
                 *
                 * Le prototype de l'opérateur de comparaison.
                 * */
                typedef bool (&OperateurComparaison)( const long int &, const long int& );

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in] nom
                 * Le nom du fait avec lequel sera fait la comparaison.
                 * */
                FormeAbstraitePremisse( const std::string & nom );

                /**
                 * Destructeur rendu virtuel.
                 * */
                virtual ~FormeAbstraitePremisse() = default;

        };

    }
}

#endif
