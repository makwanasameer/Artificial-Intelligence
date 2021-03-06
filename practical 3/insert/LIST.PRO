trace
domains
	list=symbol*
predicates
	search(list,symbol)
	insert_first(symbol,list,list)
	insert_last(symbol,list,list)
	append(list,list,list)
	position(list,symbol,integer)
	reverse(list,list)
	rev_t(list,list,list)
clauses
	search([X|_],X).
	
	search([_|T],X):-
		search(T,X).
	
	insert_first(X,L,[X|L]).
	append([],X,X).
	
	append([H|T],X,[H|T1]):-
		append(T,X,T1).
	
	insert_last(X,L,L1):-
		append(L,[X],L1).
	
	position([X|_],X,1).
	
	position([_|T],L,R):-
		position(T,L,Y),
		R=Y+1.
	
	reverse(L1,L2):-
		rev_t(L1,[],L2).
		rev_t([],L2,L2).
	rev_t([H|T],L3,L):-
		insert_first(H,L3,L2),
		rev_t(T,L2,L).