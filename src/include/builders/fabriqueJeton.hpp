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
				const Jeton parentheseOuvrante();
				
				/**
				  * Retourne le jeton associe a la parenthese fermante.
                  *
                  * @return le jeton associe a la parenthese fermante.
                  */
				const Jeton parentheseFermante();
				
				/**
				  * Retourne le jeton associe au signe inferieur.
                  *
                  * @return le jeton associe au signe inferieur.
                  */
				const Jeton inferieur();
				
				/**
				  * Retourne le jeton associe au signe superieur.
                  *
                  * @return le jeton associe au signe inferieur.
                  */
				const Jeton superieur();
				
				/**
				  * Retourne le jeton associe a l'operateur plus.
                  *
                  * @return le jeton associe a l'operateur plus.
                  */
				const Jeton operateurPlus();
				
				/**
				  * Retourne le jeton associe a l'operateur moins.
                  *
                  * @return le jeton associe a l'operateur moins.
                  */
				const Jeton operateurMoins();
				
				/**
				  * Retourne le jeton associe a l'operateur multiplie.
                  *
                  * @return le jeton associe a l'operateur multiplie.
                  */
				const Jeton operateurMul();
				
				/**
				  * Retourne le jeton associe a l'operateur divise.
                  *
                  * @return le jeton associe a l'operateur divise.
                  */
				const Jeton operateurDiv();
				
				/**
				  * Retourne le jeton associe au signe egal.
                  *
                  * @return le jeton associe au signe egal.
                  */
				const Jeton egal();
				
				/**
				  * Retourne le jeton associe au point virgule.
                  *
                  * @return le jeton associe au point virgule.
                  */
				const Jeton finExpression();
				
				/**
				  * Retourne le jeton associe au si.
                  *
                  * @return le jeton associe au si.
                  */
				const Jeton si();
				
				/**
				  * Retourne le jeton associe au non.
                  *
                  * @return le jeton associe au non.
                  */
				const Jeton non();
				
				/**
				  * Retourne le jeton associe au alors.
                  *
                  * @return le jeton associe au alors.
                  */
				const Jeton et();
				
				/**
				  * Retourne le jeton associe au alors.
                  *
                  * @return le jeton associe au alors.
                  */
				const Jeton alors();
				
				/**
				  * Retourne le jeton associe a la virgule.
                  *
                  * @return le jeton associe a la virgule.
                  */
				const Jeton separateur();
				
			protected:
				const Jeton parentheseOuvrante_; 
				const Jeton parentheseFermante_; 
				const Jeton superieur_;
				const Jeton inferieur_; 
				const Jeton operateurPlus_; 
				const Jeton operateurMoins_;
				const Jeton operateurMul_; 
				const Jeton operateurDiv_;
				const Jeton egal_;
				const Jeton finExpression_;
				const Jeton si_;
				const Jeton non_;
				const Jeton et_;
				const Jeton alors_;
				const Jeton separateur_;
				/*
				faitBooleen_ = Jeton(superieur, ">");
				faitEntier_ = Jeton(superieur, ">");
				faitSymbolique_ = Jeton(superieur, ">");
				inconnu = Jeton(superieur, ">");*/
		};
	 }
 }
#endif
