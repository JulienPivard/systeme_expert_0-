#include "FormeAbstraitePremisse.hpp"

namespace sysexp
{

    namespace modele
    {

        bool compLess( const long int & partieGauche, const long int & partieDroite )
        {
            return partieGauche < partieDroite;
        }

        bool compLessEqual( const long int & partieGauche, const long int & partieDroite )
        {
            return partieGauche <= partieDroite;
        }

        bool compSup( const long int & partieGauche, const long int & partieDroite )
        {
            return partieGauche > partieDroite;
        }

        bool compSupEqual( const long int & partieGauche, const long int & partieDroite )
        {
            return partieGauche >= partieDroite;
        }

        bool compEqualEqual( const long int & partieGauche, const long int & partieDroite )
        {
            return partieGauche == partieDroite;
        }

        bool compDiff( const long int & partieGauche, const long int & partieDroite )
        {
            return partieGauche != partieDroite;
        }

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        bool compEqualEqual( const std::string & partieGauche, const std::string & partieDroite )
        {
            return partieGauche == partieDroite;
        }

        bool compDiff( const std::string & partieGauche, const std::string & partieDroite )
        {
            return partieGauche != partieDroite;
        }


        FormeAbstraitePremisse::FormeAbstraitePremisse( const std::string & nom ):
            FormeAbstraite( nom )
        { }

    }

}
