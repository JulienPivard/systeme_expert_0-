#include "syntaxique.hpp"
#include "monException.hpp"
#include <iostream>


namespace sysexp{

	 namespace builders{
		 
		 Syntaxique::Syntaxique(Lexical & lexical):
			lexical_(lexical),
			precharge_(lexical_.suivant())
			{}
		
		 const Lexical	
		 Syntaxique::lireLexical(){
			 return lexical_;
		 }
			
		void
		Syntaxique::parser(){
			declarations();
		}

		void 
		Syntaxique::declarations(){
			declarations_bool();
			declarations_symb();
			declarations_ent();
		}

		void 
		Syntaxique::declarations_bool(){
			if(!precharge_.estFaitBool())
				throw MonException(lexical_);
			precharge_ = lexical_.suivant();
			listeFaits();
		}
		

		void
	 	Syntaxique::declarations_symb(){
	 		if(!precharge_.estFaitSymb())
				throw MonException(lexical_);
			precharge_ = lexical_.suivant();
			listeFaits();	
		}

		void
		Syntaxique::declarations_ent(){
			if(!precharge_.estFaitEnt())
				throw MonException(lexical_);
			precharge_ = lexical_.suivant();
			listeFaits();	
		}

		void
		Syntaxique::listeFaits(){
			if (!precharge_.estEgal())
				throw MonException(lexical_);
			precharge_ = lexical_.suivant();

			while(!precharge_.estFinExpression()){
				if(!precharge_.estIdentificateur())
					throw MonException(lexical_);
				precharge_ = lexical_.suivant();

				if(precharge_.estFinExpression()){
					precharge_ = lexical_.suivant();
					break;
				}
				if (!precharge_.estSeparateur())
					throw MonException(lexical_);
				precharge_ = lexical_.suivant();
			}
		}
	}
}
