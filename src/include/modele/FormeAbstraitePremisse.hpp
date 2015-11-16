/**
 * @file FormeAbstraitePremisse.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FormeAbstraitePremisse.cpp.
 * Définit la classe abstraite FormeAbstraitePremisse.
 * */


#ifndef formeabstraitepremisse_hpp
#define formeabstraitepremisse_hpp

#include <memory>

#include "FormeAbstraite.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
         * Comparaison de deux entiers long.
         *
         * @param[in] partieGauche
         * La partie gauche de la comparaison.
         * @param[in] partieDroite
         * La partie droite de la comparaison.
         *
         * @return partieGauche < partieDroite.
         * */
        bool compLess( const long int & partieGauche, const long int & partieDroite );

        /**
         * Comparaison de deux entiers long.
         *
         * @param[in] partieGauche
         * La partie gauche de la comparaison.
         * @param[in] partieDroite
         * La partie droite de la comparaison.
         *
         * @return partieGauche <= partieDroite.
         * */
        bool compLessEqual( const long int & partieGauche, const long int & partieDroite );

        /**
         * Comparaison de deux entiers long.
         *
         * @param[in] partieGauche
         * La partie gauche de la comparaison.
         * @param[in] partieDroite
         * La partie droite de la comparaison.
         *
         * @return partieGauche > partieDroite.
         * */
        bool compSup( const long int & partieGauche, const long int & partieDroite );

        /**
         * Comparaison de deux entiers long.
         *
         * @param[in] partieGauche
         * La partie gauche de la comparaison.
         * @param[in] partieDroite
         * La partie droite de la comparaison.
         *
         * @return partieGauche >= partieDroite.
         * */
        bool compSupEqual( const long int & partieGauche, const long int & partieDroite );

        /**
         * Comparaison de deux entiers long.
         *
         * @param[in] partieGauche
         * La partie gauche de la comparaison.
         * @param[in] partieDroite
         * La partie droite de la comparaison.
         *
         * @return partieGauche == partieDroite.
         * */
        bool compEqualEqual( const long int & partieGauche, const long int & partieDroite );

        /**
         * Comparaison de deux entiers long.
         *
         * @param[in] partieGauche
         * La partie gauche de la comparaison.
         * @param[in] partieDroite
         * La partie droite de la comparaison.
         *
         * @return partieGauche != partieDroite.
         * */
        bool compDiff( const long int & partieGauche, const long int & partieDroite );

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        /**
         * Comparaison de deux string.
         *
         * @param[in] partieGauche
         * La partie gauche de la comparaison.
         * @param[in] partieDroite
         * La partie droite de la comparaison.
         *
         * @return partieGauche == partieDroite.
         * */
        bool compEqualEqual( const std::string & partieGauche, const std::string & partieDroite );

        /**
         * Comparaison de deux string.
         *
         * @param[in] partieGauche
         * La partie gauche de la comparaison.
         * @param[in] partieDroite
         * La partie droite de la comparaison.
         *
         * @return partieGauche != partieDroite.
         * */
        bool compDiff( const std::string & partieGauche, const std::string & partieDroite );


        /**
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
                 * @typedef OperateurComparaisonEntier
                 *
                 * Le prototype de l'opérateur de comparaison entre entier.
                 * */
                typedef bool (&OperateurComparaisonEntier)( const long int &, const long int& );

                /**
                 * @typedef OperateurComparaisonString
                 *
                 * Le prototype de l'opérateur de comparaison entre string.
                 * */
                typedef bool (&OperateurComparaisonString)( const std::string &, const std::string & );

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in] nom
                 * Le @ref nom_ du fait avec lequel sera fait la comparaison.
                 * */
                FormeAbstraitePremisse( const std::string & nom );

                /**
                 * Destructeur rendu virtuel.
                 * */
                virtual ~FormeAbstraitePremisse() = default;

            public:

                FormeAbstraitePremisse( const FormeAbstraitePremisse & autre ) = delete;

                FormeAbstraitePremisse & operator=( const FormeAbstraitePremisse & autre ) = delete;

        };

    }
}

#endif
