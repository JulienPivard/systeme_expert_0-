/**
 * @file FaitAbstrait.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FaitAbstrait.cpp.
 * Définit la classe abstraite Fait.
 * */

#ifndef faitabstrait_hpp
#define faitabstrait_hpp

#include <string>
#include <memory>

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
         * @class FaitAbstrait FaitAbstrait.hpp
         *
         * Déclaration de la classe abstraite FaitAbstrait.
         * */
        class FaitAbstrait
        {

            public:

                /**
                 * @typedef PtrFaitAbstrait
                 *
                 * Nom facile pour un shared_ptr de FaitAbstrait.
                 * */
                typedef std::shared_ptr<FaitAbstrait> PtrFaitAbstrait;

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le @ref nom_ du fait.
                 * */
                FaitAbstrait( const std::string & nom );

                /**
                 * Accesseur
                 *
                 * @return Le @ref nom_ du fait.
                 * */
                const std::string & lireNom() const;

                /**
                 * La méthode virtuel destructeur.
                 * */
                virtual ~FaitAbstrait() = default;

            protected:

                /**
                 * Le nom qu'on a donné au fait.
                 * Le nom n'est pas censé changer je le met donc constant.
                 * */
                const std::string nom_;

        };
    }
}

#endif
