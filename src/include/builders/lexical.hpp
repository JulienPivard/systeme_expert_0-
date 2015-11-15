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


/**
 * @namespace sysexp
 * // namespace global de l'application.
 **/
namespace sysexp{
 
	 /**
	   * @namespace sysexp::builders
	   * // namespace builders de l'application.
	  **/
	 namespace builders{
		/**
		  * @class Lexical lexical.hpp
		  * @brief Représente un analyseur lexical de la grammaire lorraine.
		  * Classe représentant un analyseur lexical de la grammaire lorraine.
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
				std::istream & lireFichier();
				
				/**
				 * Accesseur.
				 * @return la ligne dans le fichier.
				 */
				std::string & lireLigne();
				
				/**
				 * Accesseur.
				 * @return la position dans la ligne du fichier.
				 */
				unsigned int lirePosition();
				
				/**
				 * Accesseur.
				 * @return le numero de la ligne du fichier.
				 */
				int lireNumeroLigne();
				
				/**
				 * Permet d'obtenir le jeton suivant.
				 * @return le jeton suivant.
				 */
				const Jeton suivant();
				
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

#endif
