
domains

predicates
	enter
	solve(integer,integer,integer)
clauses
	enter:-
		A=0,
		B=1,
		write("Enter the value::"),
		readint(N),
		solve(N,A,B).
	solve(0,A,B):-
		write("$  \nEnd of the string",A,B).
		
	solve(N,A,B):-
		C=A+B,
		write(A,"\n"),
		Z=B,
		Y=C,
		T=N-1,
		solve(T,Z,Y).
		
		

	