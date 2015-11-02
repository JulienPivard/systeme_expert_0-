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

#include <cstdlib>
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
         * @enum TypeFait
         * @brief Énumération des différents type de fait.
         *
         * Les différents type de fait que l'on peut rencontrer.
         * */
        enum class TypeFait
        {
            faitBool,          /**< un fait de type FaitBool */
            faitEntier,        /**< un fait de type FaitEntier */
            faitSymbolique     /**< un fait de type FaitSymbolique */
        };

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
                 * @param[in] type
                 * Le @ref type_ du fait.
                 * */
                FaitAbstrait( const std::string & nom, const TypeFait & type );

                /**
                 * Accesseur
                 *
                 * @return Le @ref nom_ du fait.
                 * */
                const std::string & lireNom() const;

                /**
                 * Permet de connaitre le type du fait.
                 *
                 * @return Le @ref type_ du fait.
                 * */
                const TypeFait & type() const;

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

                /**
                 * Le type de fait que l'on va manipuler.
                 * */
                const TypeFait type_;

        };
    }
}

#endif
