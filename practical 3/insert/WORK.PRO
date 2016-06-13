trace
domains
	Name=symbol*
predicates
	member(Name,symbol)
	insert(Name,symbol,Name)
	
clauses
	member([X|_],X).
	
	member([_|T],X):-
		member(T,X).
	
	insert([],X,[X]).
	insert(Name,X,[X|Name]).

	append([],X,X).
	
	append(		

		
	
	
			
	