/**
 * @file VisiteurFormeAbstrait.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier VisiteurFormeAbstrait.cpp.
 * Définit la classe abstraite VisiteurFormeAbstrait.
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
         * @class FormeConclusionBoolTrue
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormeConclusionBoolTrue;

        /**
         * @class FormeConclusionBoolFalse
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormeConclusionBoolFalse;

        /**
         * @class FormeConclusionEntierExpression
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormeConclusionEntierExpression;

        /**
         * @class FormeConclusionEntierFait
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormeConclusionEntierFait;

        /**
         * @class FormeConclusionSymboliqueConstante
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormeConclusionSymboliqueConstante;

        /**
         * @class FormeConclusionSymboliqueFait
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormeConclusionSymboliqueFait;


        /**
         * @class FormePremisseBoolTrue
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormePremisseBoolTrue;

        /**
         * @class FormePremisseBoolFalse
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormePremisseBoolFalse;

        /**
         * @class FormePremisseEntierExpression
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormePremisseEntierExpression;

        /**
         * @class FormePremisseEntierFait
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormePremisseEntierFait;

        /**
         * @class FormePremisseSymboliqueConstante
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormePremisseSymboliqueConstante;

        /**
         * @class FormePremisseSymboliqueFait
         *
         * Déclaration de classe pour le visiteur.
         * */
        class FormePremisseSymboliqueFait;

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
         * @class VisiteurFormeAbstrait VisiteurFormeAbstrait.hpp
         *
         * Déclaration de la classe VisiteurFormeAbstrait.
         * */
        class VisiteurFormeAbstrait
        {

            public:

                /**
                 * @typedef PtrVisiteurFormeAbstrait
                 *
                 * Un alias pour simplifier l'utilisation d'un shared pointeur de VisiteurFormeAbstrait
                 * */
                typedef std::shared_ptr< VisiteurFormeAbstrait > PtrVisiteurFormeAbstrait;

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in,out] baseFait
                 * La base de fait que l'on veut remplir.
                 * */
                VisiteurFormeAbstrait( const BaseFait::PtrBaseFait & baseFait );

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

            public:

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionBoolTrue
                 * */
                virtual void visiterConclusionBool( const FormeConclusionBoolTrue * conclusion ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormeConclusionBoolFalse
                // * */
                //virtual void visiterConclusionBool( const FormeConclusionBoolFalse * conclusion ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormeConclusionEntierExpression
                // * */
                //virtual void visiterConclusionBool( const FormeConclusionEntierExpression * conclusion ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormeConclusionEntierFait
                // * */
                //virtual void visiterConclusionBool( const FormeConclusionEntierFait * conclusion ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormeConclusionSymboliqueConstante
                // * */
                //virtual void visiterConclusionBool( const FormeConclusionSymboliqueConstante * conclusion ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormeConclusionSymboliqueFait
                // * */
                //virtual void visiterConclusionBool( const FormeConclusionSymboliqueFait * conclusion ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormePremisseBoolTrue
                // * */
                //virtual void visiterPremisse( const FormePremisseBoolTrue * premisse ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormePremisseBoolFalse
                // * */
                //virtual void visiterPremisse( const FormePremisseBoolFalse * premisse ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormePremisseSymboliqueConstante
                // * */
                //virtual void visiterPremisse( const FormePremisseSymboliqueConstante * premisse ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormePremisseSymboliqueFait
                // * */
                //virtual void visiterPremisse( const FormePremisseSymboliqueFait * premisse ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormePremisseEntierExpression
                // * */
                //virtual void visiterPremisse( const FormePremisseEntierExpression * premisse ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] conclusion
                // * La conclusion que l'on veut visiter.
                // * @see FormePremisseEntierFait
                // * */
                //virtual void visiterPremisse( const FormePremisseEntierFait * premisse ) = 0;

            public:

                /**
                 * Destructeur de la VisiteurFormeAbstrait.
                 * */
                virtual ~VisiteurFormeAbstrait() = default;

            protected:
                /**
                 * La base de fait ou on vas ajouter les conclusion déclenchée.
                 * */
                BaseFait::PtrBaseFait baseFait_;

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
