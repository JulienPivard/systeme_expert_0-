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
 *
 **/
namespace sysexp{
 
	 /**
	   * @namespace sysexp::builders
	   * 
	  **/
	 namespace builders{
		/**
		  * Classe representant un analyseur lexical de la grammaire.
          *
          */
          class Lexical{
			  public:
				/**
				  * Constructeur de la classe Lexical
				  * @param [in] fichier  fichier a lire.
                  *
                  */
				Lexical(std::istream & fichier);
				
			  public: 
				/**
				 * Accesseur.
				 *
				 * @return le fichier a analyser.
				 */
				std::istream & lireFichier();
				
				/**
				 * Accesseur.
				 *
				 * @return la ligne dans le fichier.
				 */
				std::string & lireLigne();
				
				/**
				 * Accesseur.
				 *
				 * @return la position dans la ligne du fichier.
				 */
				unsigned int lirePosition();
				
				/**
				 * Accesseur.
				 *
				 * @return le numero de la ligne du fichier.
				 */
				int lireNumeroLigne();
				/**
				 * Permet d'obtenir le jeton suivant.
				 *
				 * @return le jeton suivant.
				 */
				const Jeton suivant();
				
			  protected:
				/**
				 * Permet d'avancer dans le fichier.
				 *
				 * @retval TRUE si on peut encore avancer dans le fichier.
				 * @retval FALSE si on a atteint la fin du fichier.
				 */
				bool avancer();
				
				/**
				 * permet d'extraire un entier dans le fichier
				 *
				 * @return un jeton associe a un entier.
				 */
				const Jeton extraireEntier();
				
				/**
				 * permet d'extraire une chaine de caractere dans le fichier
				 *
				 * @return un jeton associe a un identificateur ou un si, alors, non, et.
				 */
				const Jeton extraireChaine();
			
			protected: 
				/**
				 * ligne dans le fichier.
				 */
				std::string ligne_;
				
				/**
				 * position dans le fichier.
				 */
				unsigned int position_;
				
				/**
				 * fichier a analyser.
				 */
				std::istream & fichier_;

				int numeroLigne_;
          };
     }
}

#endif
