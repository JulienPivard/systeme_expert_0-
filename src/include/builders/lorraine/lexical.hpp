/**
 * @file lexical.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier lexical.cpp.
 * Définit la classe Lexical.
 * */

#ifndef Lexical_hpp
#define Lexical_hpp

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <cctype>
#include "jeton.hpp"
#include "fabriqueJeton.hpp"


namespace sysexp{

	 namespace builders{

	 	namespace lorraine{

			/**
			  * @brief Représente un analyseur lexical de la grammaire lorraine.
	          */
	          class Lexical{
				public:
					/**
					  * Constructeur de la classe Lexical
					  * @param [in] fichier  fichier a lire.
	                  */
					Lexical(std::istream & fichier);

				public:
					/**
					 * Accesseur.
					 * @return le fichier a analyser.
					 */
					const std::istream & lireFichier() const;

					/**
					 * Accesseur.
					 * @return la ligne dans le fichier.
					 */
					const std::string & lireLigne() const;

					/**
					 * Accesseur.
					 * @return la position dans la ligne du fichier.
					 */
					const unsigned int & lirePosition() const;

					/**
					 * Accesseur.
					 * @return la position jeton précédent dans la ligne du fichier.
					 */
					const unsigned int & lireOldPosition() const;

					/**
					 * Accesseur.
					 * @return le numero de la ligne du fichier.
					 */
					const int & lireNumeroLigne() const;

					/**
					 * @return le jeton suivant.
					 */
					const Jeton suivant();

                public:

                    Lexical & operator=( const Lexical & autre ) = delete;

				protected:

					/**
					 * Permet d'avancer dans le fichier.
					 * @return true si on peut avancer dans le fichier, false sinon.
					 */
					bool avancer();

					/**
					 * Permet d'extraire un entier dans le fichier
					 * @return un jeton associe a un entier.
					 */
					const Jeton extraireEntier();

					/**
					 * Permet d'extraire une chaine de caractère dans le fichier
					 * @return un jeton associé à un identificateur ou un si, alors, non, et.
					 */
					const Jeton extraireChaine();

				protected:

					/**
					 * Ligne dans le fichier.
					 */
					std::string ligne_;

					/**
					 * Position dans le fichier.
					 */
					unsigned int position_;

					/**
					 * Position du jeton précédent dans le fichier (pour l'affichage des erreurs).
					 */
					unsigned int oldPosition_;

					/**
					 * Fichier à analyser.
					 */
					std::istream & fichier_;

					/**
					 * Numéro de la ligne du fichier à analyser.
					 */
					int numeroLigne_;
	        };
	    }
    }
}

#endif
