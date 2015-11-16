#include "FormePremisseSymboliqueConstante.hpp"

namespace sysexp
{
    namespace modele
    {

        FormePremisseSymboliqueConstante::FormePremisseSymboliqueConstante( const std::string & nomFait,
                FormeAbstraitePremisse::OperateurComparaisonString comparateur,
                const std::string & valeur ):
            FormeAbstraitePremisse( nomFait ),
            signe_( comparateur ),
            valeur_( valeur )
        { }

        void FormePremisseSymboliqueConstante::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( *this );
        }

        bool FormePremisseSymboliqueConstante::test( const std::string & partieGauche, const std::string & partieDroite ) const
        {
            return signe_( partieDroite, partieGauche );
        }

        const std::string & FormePremisseSymboliqueConstante::lireValeur() const
        {
            return valeur_;
        }

    }
}
