/**
 * @file MoteurInference.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier MoteurInference.cpp.
 * Définit la classe MoteurInference.
 * */


#ifndef moteurinference_hpp
#define moteurinference_hpp

#include "RegleAbstraite.hpp"
#include "BaseFait.hpp"


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Le moteur d'inférence qui va s'exécuter sur la base de règles,
         * pour produire la base de faits.
         *
         * Déclaration de la classe MoteurInference.
         * */
        class MoteurInference
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] baseDeRegles
                 * La base de règles qui va être utilisé pour produire la base de faits.
                 * */
                MoteurInference( const RegleAbstraite::PtrRegleAbstraite & baseDeRegles );

                /**
                 * Crée une nouvelle instance vide de base de faits.
                 * */
                void creerInstanceBaseFaits();

                /**
                 * Analyse la base de règles, pour produire la base de faits.
                 * */
                void analyserBaseRegles();

                /**
                 * Affiche la base de faits sur la sortie standard.
                 * */
                void afficherBaseFaits();

            protected:

                /**
                 * La base de faits.
                 * */
                BaseFait::PtrBaseFait baseFaits_;

                /**
                 * La base de règles.
                 * */
                const RegleAbstraite::PtrRegleAbstraite baseDeRegles_;

        };

    }
}

#endif
