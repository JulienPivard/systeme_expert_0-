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
#include "ExceptionFaitDejaAjoute.hpp"

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
            toutVaBien,             /**< Pas d'erreur */
            divParZero,             /**< Erreur division par zéro rencontrée. */
            incoherenceFait,        /**< Erreur incohérence détectée dans la base de fait. */
            faitEntierInconnu,      /**< Erreur le fait entier n'existe pas */
            faitExpressionInconnu,  /**< Erreur le fait n'existe pas dans l'expression. */
            faitSymboliqueInconnu   /**< Erreur le fait symbolique n'existe pas. */
        };

        /**
         * @class VisiteurFormeAbstrait VisiteurFormeAbstrait.hpp
         * @brief Le squelette du visiteur de règle avec ou sans prémisse.
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

                /**
                 * Pour faciliter l'affichage des variables de visiteur,
                 * de manière lisible.
                 * À n'utiliser qu'à des fins de debogage.
                 * */
                void afficher() const;

            public:

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionBoolTrue
                 * */
                virtual void visiter( const FormeConclusionBoolTrue * conclusion ) = 0;

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionBoolFalse
                 * */
                virtual void visiter( const FormeConclusionBoolFalse * conclusion ) = 0;

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionEntierExpression
                 * */
                virtual void visiter( const FormeConclusionEntierExpression * conclusion ) = 0;

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionEntierFait
                 * */
                virtual void visiter( const FormeConclusionEntierFait * conclusion ) = 0;

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionSymboliqueConstante
                 * */
                virtual void visiter( const FormeConclusionSymboliqueConstante * conclusion ) = 0;

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionSymboliqueFait
                 * */
                virtual void visiter( const FormeConclusionSymboliqueFait * conclusion ) = 0;

            public:

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseBoolTrue
                 * */
                virtual void visiter( const FormePremisseBoolTrue * premisse ) = 0;

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseBoolFalse
                 * */
                virtual void visiter( const FormePremisseBoolFalse * premisse ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] premisse
                // * La conclusion que l'on veut visiter.
                // * @see FormePremisseSymboliqueConstante
                // * */
                //virtual void visiter( const FormePremisseSymboliqueConstante * premisse ) = 0;

                ///**
                // * Visite la règle passé en argument.
                // * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                // *
                // * @param[in,out] premisse
                // * La conclusion que l'on veut visiter.
                // * @see FormePremisseSymboliqueFait
                // * */
                //virtual void visiter( const FormePremisseSymboliqueFait * premisse ) = 0;

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseEntierExpression
                 * */
                virtual void visiter( const FormePremisseEntierExpression * premisse ) = 0;

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseEntierFait
                 * */
                virtual void visiter( const FormePremisseEntierFait * premisse ) = 0;

            public:

                /**
                 * Destructeur de la VisiteurFormeAbstrait.
                 * */
                virtual ~VisiteurFormeAbstrait() = default;

            protected:

                /**
                 * Ajoute un fait à la base de fait.
                 * @param[in] fait
                 * Le fait que l'on veut ajouter à la base de fait.
                 * */
                void AjouterUnFait( const FaitAbstrait::PtrFaitAbstrait & fait );

            protected:

                /**
                 * La base de fait ou on vas ajouter les conclusion déclenchée.
                 * */
                BaseFait::PtrBaseFait baseFait_;

                /**
                 * Permet de savoir si le prémisse est vérifiée.
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
