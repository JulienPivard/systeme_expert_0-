#ifndef Jeton_hpp
#define Jeton_hpp

#include <string>

/**
 * @class Jeton Jeton.hpp
 * Classe representant un jeton de la grammaire.
 * 
 */
class Jeton:
public:
	Jeton(const Type& type, const std::string& representation);
	
public:
	/**
     * Type enumere fortement type representant les differentes types de
     * jetons.
     */
	enum Type { parentheseOuvrante, parentheseFermante, superieur, inferieur,
		operateurPlus, operateurMoins, operateurMul, operateurDiv, 
		egal, finExpression, faitBooleen, faitEntier, faitSymbolique,
		si, non, alors, separateur, inconnu};

public:
	/**
     * Accesseur.
     *
     * @return la valeur de @ref type_.
     */
	const Type& lireType() const;
	
	/**
     * Accesseur.
     *
     * @return la valeur de @ref representation_.
     */
	const std::string& lireRepresentation() const;
	
	/**
     * Indique si le jeton est une parenthese ouvrante.
     */
	bool estParentheseOuvrante();
	
	/**
     * Indique si le jeton est une parenthese fermante.
     */
	bool estparentheseFermante();
	
	/**
     * Indique si le jeton est superieur.
     */
	bool estSuperieur();
	
	/**
     * Indique si le jeton est inferieur.
     */
	bool estInferieur();
	
	/**
     * Indique si le jeton est un plus.
     */
	bool estOperateurPlus();
	
	/**
     * Indique si le jeton est un moins.
     */
	bool estOperateurMoins();
	
	/**
     * Indique si le jeton est un fois.
     */
	bool estOperateurMul();
	
	/**
     * Indique si le jeton est un div.
     */
	bool estOperateurDiv();
	
	/**
     * Indique si le jeton est un egal
     */
	bool estEgal();
	
	/**
     * Indique si le jeton est un point virgule.
     */
	bool estFinExpression();
	
	/**
     * Indique si le jeton est un fait booleen.
     */
	bool estFaitBooleen();
	
	/**
     * Indique si le jeton est un fait entier.
     */
	bool estFaitEntier();
	
	/**
     * Indique si le jeton est un fait symbolique.
     */
	bool estFaitSymbolique();
	
	/**
     * Indique si le jeton est un si .
     */
	bool estSi();
	
	/**
     * Indique si le jeton est un non.
     */
	bool estNon();
	
	/**
     * Indique si le jeton est un alors.
     */
	bool estAlors();
	
	/**
     * Indique si le jeton est une virgule .
     */
	bool estSeparateur();
	
	/**
     * Indique si le jeton est inconnu.
     */
	bool estInconnu();
	
protected:
	 Type type_;
	 std::string representation_;
