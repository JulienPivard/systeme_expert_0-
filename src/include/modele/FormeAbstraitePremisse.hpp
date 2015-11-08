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
        class FormeAbstraitePremisse
        {

            public:

                /**
                 * @typedef PtrFormeAbstraitePremisse
                 *
                 * Alias pour faciliter l'utilisation d'un shared_ptr de FormeAbstraitePremisse.
                 * */
                typedef std::shared_ptr< FormeAbstraitePremisse > PtrFormeAbstraitePremisse;

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in] nom
                 * Le nom du fait avec lequel sera fait la comparaison.
                 * @param[in] signe
                 * Le signe à utiliser pour faire la comparaison.
                 * */
                FormeAbstraitePremisse( const std::string & nom, const SigneAbstrait & signe );

                /**
                 * Destructeur rendu virtuel.
                 * */
                virtual ~FormeAbstraitePremisse() = default;

        };

    }
}

#endif

