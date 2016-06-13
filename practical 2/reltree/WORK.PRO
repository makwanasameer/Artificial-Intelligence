domains
	
	



predicates
	male_get(string)
	male(string)
	female_get(string)
	female(string)
	parent(string)
	brother(string,string)
	sister(string,string)
	parent_son(string,string)
	parent_daught(string,string)
	parent_of(string,string)
	bro_sis(string,string)
clauses
	male_get(X):-
		male(X).
		
		
	male(sameer).
	male(ravi).
	male(kishan).
	male(rameshbhai).
	
	female_get(X):-
		female(X).
	
	female(miral).
	female(pooja).
	female(labhuben).
	
	parent(labhuben).
	parent(rameshbhai).
	parent_son(rameshbhai,sameer).
	parent_son(rameshbhai,ravi).
	parent_son(labhuben,sameer).
	parent_son(labhuben,ravi).
	parent_daught(rameshbhai,miral).
	parent_daught(labhuben,miral).
	
	parent_of(X,Y):-
		parent_son(rameshbhai,X),
		parent_daught(labhuben,Y).
	parent_of(X,Y):-
		parent_son(rameshbhai,X),
		parent_son(rameshbhai,Y).
	parent_of(X,Y):-
		parent_daught(labhuben,X),
		parent_daught(labhuben,Y).
	
		
	
	brother(X,Y):-
		male(X),
		male(Y),
		parent_of(X,Y),
		X<>Y,
		write(X," and ",Y," are brothers") .
		
	brother(X,Y):-
		write(X," and ",Y," are not brothers").
		
	sister(X,Y):-
		female(X),
		female(Y),
		parent_of(X,Y),
		X<>Y,
		write(X," and ",Y," are sisters").
	
	sister(X,Y):-
		
		write(X," and ",Y," are not sisters").
		
	bro_sis(X,Y):-
		male(X),
		female(Y),
		parent_of(X,Y),
		write(X," and ",Y," are brother and sister").
	
	bro_sis(X,Y):-
		write(X," and ",Y," are not brother and sister").
		