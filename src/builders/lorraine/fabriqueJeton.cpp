#include "fabriqueJeton.hpp"


namespace sysexp{

	namespace builders{

		namespace lorraine{
			const Jeton FabriqueJeton::parentheseOuvrante_(Jeton(TypeJeton::parentheseOuvrante, "("));
			const Jeton FabriqueJeton::parentheseFermante_(Jeton(TypeJeton::parentheseFermante, ")"));
			const Jeton FabriqueJeton::superieur_(Jeton(TypeJeton::superieur, ">"));
			const Jeton FabriqueJeton::inferieur_(Jeton(TypeJeton::inferieur, "<"));
			const Jeton FabriqueJeton::operateurPlus_(Jeton(TypeJeton::operateurPlus, "+"));
			const Jeton FabriqueJeton::operateurMoins_(Jeton(TypeJeton::operateurMoins, "-"));
			const Jeton FabriqueJeton::operateurMul_(Jeton(TypeJeton::operateurMul, "*"));
			const Jeton FabriqueJeton::operateurDiv_(Jeton(TypeJeton::operateurDiv, "/"));
			const Jeton FabriqueJeton::egal_(Jeton(TypeJeton::egal, "="));
			const Jeton FabriqueJeton::finExpression_(Jeton(TypeJeton::finExpression, ";"));
			const Jeton FabriqueJeton::si_(Jeton(TypeJeton::si, "si"));
			const Jeton FabriqueJeton::non_(Jeton(TypeJeton::non, "non"));
			const Jeton FabriqueJeton::et_(Jeton(TypeJeton::et, "et"));
			const Jeton FabriqueJeton::alors_(Jeton(TypeJeton::alors, "alors"));
			const Jeton FabriqueJeton::separateur_(Jeton(TypeJeton::separateur, ","));
			const Jeton FabriqueJeton::finFichier_(Jeton(TypeJeton::finFichier, ""));
			const Jeton FabriqueJeton::supEgal_(Jeton(TypeJeton::supEgal, ">="));
			const Jeton FabriqueJeton::infEgal_(Jeton(TypeJeton::infEgal, "<="));
			const Jeton FabriqueJeton::different_(Jeton(TypeJeton::different, "/="));
			const Jeton FabriqueJeton::faitBool_(Jeton(TypeJeton::faitBool, "faits_booleens"));
			const Jeton FabriqueJeton::faitSymb_(Jeton(TypeJeton::faitSymb, "faits_symboliques"));
			const Jeton FabriqueJeton::faitEnt_(Jeton(TypeJeton::faitEnt, "faits_entiers"));

			const Jeton
			FabriqueJeton::identificateur(const std::string & representation){
				return Jeton(TypeJeton::identificateur, representation);
			}

			const Jeton
			FabriqueJeton::inconnu(const std::string & representation){
				return Jeton(TypeJeton::inconnu, representation);
			}

			const Jeton
			FabriqueJeton::entier(const std::string & representation){
				return Jeton(TypeJeton::entier, representation);
			}

			const Jeton
			FabriqueJeton::parentheseOuvrante(){
				return parentheseOuvrante_;
			}

			const Jeton
			FabriqueJeton::parentheseFermante(){
				return parentheseFermante_;
			}

			const Jeton
			FabriqueJeton::superieur(){
				return superieur_;
			}

			const Jeton
			FabriqueJeton::inferieur(){
				return inferieur_;
			}

			const Jeton
			FabriqueJeton::operateurPlus(){
				return operateurPlus_;
			}

			const Jeton
			FabriqueJeton::operateurMoins(){
				return operateurMoins_;
			}

			const Jeton
			FabriqueJeton::operateurMul(){
				return operateurMul_;
			}

			const Jeton
			FabriqueJeton::operateurDiv(){
				return operateurDiv_;
			}

			const Jeton
			FabriqueJeton::egal(){
				return egal_;
			}

			const Jeton
			FabriqueJeton::finExpression(){
				return finExpression_;
			}

			const Jeton
			FabriqueJeton::si(){
				return si_;
			}
			const Jeton
			FabriqueJeton::non(){
				return non_;
			}
			const Jeton
			FabriqueJeton::et(){
				return et_;
			}
			const Jeton
			FabriqueJeton::alors(){
				return alors_;
			}
			const Jeton
			FabriqueJeton::separateur(){
				return separateur_;
			}

			const Jeton
			FabriqueJeton::finFichier(){
				return finFichier_;
			}

			const Jeton
			FabriqueJeton::supEgal(){
				return supEgal_;
			}

			const Jeton
			FabriqueJeton::infEgal(){
				return infEgal_;
			}

			const Jeton
			FabriqueJeton::different(){
				return different_;
			}

			const Jeton
			FabriqueJeton::faitBool(){
				return faitBool_;
			}

			const Jeton
			FabriqueJeton::faitSymb(){
				return faitSymb_;
			}

			const Jeton
			FabriqueJeton::faitEnt(){
				return faitEnt_;
			}
		}
	}
}
