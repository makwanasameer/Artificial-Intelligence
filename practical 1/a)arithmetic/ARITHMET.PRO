domains
	A,B,N = integer
	
predicates
	solve(N,A,B)
	
	sam_menu
	
	
clauses	
	
	sam_menu:-
		write("1)  Addition \n"),
		write("2)  Subtract \n"),
		write("3)  Multiplication \n"),
		write("4)  Division \n\n"),
		write("  Enter the choice ::\n"),
		readint(N),
		write(" Enter the two numbers ::\n"),
		readint(A),
		readint(B),
		solve(N,A,B)
		.
		
	solve(1,A,B):-
		C=A+B,
		write("Add :: ",C,"\n").
		
	solve(2,A,B):-
		C=A-B,
		write("Sub :: ",C,"\n").
		
	solve(3,A,B):-
		C=A*B,
		write("Mul :: ",C,"\n"). 
		
	solve(4,A,B):-
		C=A/B,
		write("Div :: ",C,"\n").