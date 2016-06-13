domains
	
predicates
	entry
	equate(real,real,real)
clauses
	entry:-
		write("Enter a:"),
		readreal(A),
		write("Enter b:"),
		readreal(B),
		write("Enter c:"),
		readreal(C),
		equate(A,B,C).
	
	equate(0,B,C):-
		write("A=0 ,Not a quadratic equation",B,C).
	
	
	equate(A,B,C):-
		D=sqrt((B*B)-(4*A*C)),
		L=(-B+D)/(2*A),
		M=(-B-D)/(2*A),
		write("Alpha ::",L),
		write("\nBeta ::",M,"\n").
	
	