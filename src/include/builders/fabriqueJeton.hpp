#ifndef FabriqueJeton_hpp
#define FabriqueJeton_hpp

#include "jeton.hpp"
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
		  * Classe representant une fabrique de jetons de la grammaire. 
          *
          */
		class FabriqueJeton{
			public:
				/**
				  * Constructeur de la classe FabriqueJeton
                  *
                  */
				FabriqueJeton();
				
				/**
				  * Retourne le jeton associe a la parenthese ouvrante.
                  *
                  * @return le jeton associe a la parenthese ouvrante.
                  */
				static const Jeton parentheseOuvrante();
				
				/**
				  * Retourne le jeton associe a la parenthese fermante.
                  *
                  * @return le jeton associe a la parenthese fermante.
                  */
				static const Jeton parentheseFermante();
				
				/**
				  * Retourne le jeton associe au signe inferieur.
                  *
                  * @return le jeton associe au signe inferieur.
                  */
				static const Jeton inferieur();
				
				/**
				  * Retourne le jeton associe au signe superieur.
                  *
                  * @return le jeton associe au signe inferieur.
                  */
				static const Jeton superieur();
				
				/**
				  * Retourne le jeton associe a l'operateur plus.
                  *
                  * @return le jeton associe a l'operateur plus.
                  */
				static const Jeton operateurPlus();
				
				/**
				  * Retourne le jeton associe a l'operateur moins.
                  *
                  * @return le jeton associe a l'operateur moins.
                  */
				static const Jeton operateurMoins();
				
				/**
				  * Retourne le jeton associe a l'operateur multiplie.
                  *
                  * @return le jeton associe a l'operateur multiplie.
                  */
				static const Jeton operateurMul();
				
				/**
				  * Retourne le jeton associe a l'operateur divise.
                  *
                  * @return le jeton associe a l'operateur divise.
                  */
				static const Jeton operateurDiv();
				
				/**
				  * Retourne le jeton associe au signe egal.
                  *
                  * @return le jeton associe au signe egal.
                  */
				static const Jeton egal();
				
				/**
				  * Retourne le jeton associe au point virgule.
                  *
                  * @return le jeton associe au point virgule.
                  */
				static const Jeton finExpression();
				
				/**
				  * Retourne le jeton associe au si.
                  *
                  * @return le jeton associe au si.
                  */
				static const Jeton si();
				
				/**
				  * Retourne le jeton associe au non.
                  *
                  * @return le jeton associe au non.
                  */
				static const Jeton non();
				
				/**
				  * Retourne le jeton associe au alors.
                  *
                  * @return le jeton associe au alors.
                  */
				static const Jeton et();
				
				/**
				  * Retourne le jeton associe au alors.
                  *
                  * @return le jeton associe au alors.
                  */
				static const Jeton alors();
				
				/**
				  * Retourne le jeton associe a la virgule.
                  *
                  * @return le jeton associe a la virgule.
                  */
				static const Jeton separateur();
				
				/**
				  * Retourne le jeton associe a la fin du fichier.
                  *
                  * @return le jeton associe a la foin du fichier.
                  */
				static const Jeton finFichier();
				
				static const Jeton identificateur(const std::string & representation);
				
				static const Jeton inconnu(const std::string & representation);
				
			protected:
				static const Jeton parentheseOuvrante_; 
				static const Jeton parentheseFermante_; 
				static const Jeton superieur_;
				static const Jeton inferieur_; 
				static const Jeton operateurPlus_; 
				static const Jeton operateurMoins_;
				static const Jeton operateurMul_; 
				static const Jeton operateurDiv_;
				static const Jeton egal_;
				static const Jeton finExpression_;
				static const Jeton si_;
				static const Jeton non_;
				static const Jeton et_;
				static const Jeton alors_;
				static const Jeton separateur_;
				static const Jeton finFichier_;
				
		};
	 }
 }
#endif
