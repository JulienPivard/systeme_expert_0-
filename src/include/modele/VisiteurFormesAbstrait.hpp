/**
 * @file VisiteurFormesAbstrait.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier VisiteurFormesAbstrait.cpp.
 * Définit la classe abstraite VisiteurFormesAbstrait.
 * */


#ifndef visiteurformesabstraites_hpp
#define visiteurformesabstraites_hpp

#include <cstdlib>
#include <memory>

#include "BaseFait.hpp"

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
         * @enum Erreurs
         * @brief Constantes d'erreurs.
         *
         * divParZero peut être déclenché par l'évaluation de la premisse entière
         * ou le déclenchement de la conclusion entière.
         * incoherenceFait uniquement pour le déclenchement des conclusions.
         * */
        enum class Erreurs
        {
            toutVaBien,         /**< Pas d'erreur */
            divParZero,         /**< Erreur division par zéro rencontrée. */
            incoherenceFait     /**< Erreur incohérence détectée dans la base de fait. */
        };


        /**
         * @class VisiteurFormesAbstrait VisiteurFormesAbstrait.hpp
         *
         * Déclaration de la classe VisiteurFormesAbstrait.
         * */
        class VisiteurFormesAbstrait
        {

            public:

                /**
                 * @typedef PtrBaseFait
                 *
                 * Le shared pointer vers la base de fait.
                 * */
                typedef std::shared_ptr< BaseFait > PtrBaseFait;

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in,out] baseFait
                 * La base de fait que l'on veut remplir.
                 * */
                VisiteurFormesAbstrait( const VisiteurFormesAbstrait::PtrBaseFait & baseFait );

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] regle
                 * La règle qui va être visitée.
                 * */
                void visiterConclusionBool();

                /**
                 * Accesseur
                 *
                 * @return La premisse est vérifiée.
                 * voir @ref premisseVerifiee_
                 * */
                bool getPremisseVerifiee() const;

                /**
                 * Accesseur
                 *
                 * @return Au moins une conclusion à été ajoutée à la base de fait.
                 * voir @ref conclusionDeclenchee_
                 * */
                bool getConclusionDeclenchee() const;

                /**
                 * Accesseur
                 *
                 * @return Le code d'erreur @ref erreur_ qui à été généré.
                 * */
                Erreurs getCodeErreurExecution() const;

                /**
                 * Destructeur de la VisiteurFormesAbstrait.
                 * */
                virtual ~VisiteurFormesAbstrait() = default;

            protected:
                /**
                 * La base de fait ou on vas ajouter les conclusion déclenchée.
                 * */
                PtrBaseFait baseFait_;

                /**
                 * Permet de savoir si le premisse est vérifiée.
                 * */
                bool premisseVerifiee_;

                /**
                 * Permet de savoir si on a ajouté une conclusion à la base de fait.
                 * */
                bool conclusionDeclenchee_;

                /**
                 * Permet de savoir quel type d'erreur a été rencontrée.
                 * */
                Erreurs erreur_;

        };

    }
}

#endif
