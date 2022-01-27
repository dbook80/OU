grandmother(shirley).
female(shirley). 	   %maternal grandmother
grandfather(ronald). 
male(ronald).              %maternal grandfather
spouse(shirley, ronald). 
spouse(ronald, shirley).
mother(shirley, julia).
mother(shirley, eric).
father(ronald, julia). 
father(ronald, eric).
female(julia).             %mother
male(eric).                %maternal uncle
grandmother(mary).
female(mary).    	   %paternal grandmother
grandfather(willie).       %paternal grandfather
male(willie).
spouse(mary, willie).
spouse(willie, mary).
mother(mary, freddy).
mother(mary, bridget). 
mother(mary, william).
father(willie, freddy). 
father(willie, bridget). 
father(willie, william).
male(freddy).              %paternal uncle
female(bridget).           %paternal aunt
male(william).             %father
father(eric, trey).
father(eric, arielle). 
male(trey).		   %maternal cousins
female(arielle).
father(freddy, ebony).                          
mother(bridget, gary).
mother(bridget, tim).
female(ebony).		   %paternal cousins
male(gary).
male(tim).
spouse(julia,william).     %direct family
spouse(william, julia). 
mother(julia, caesar). 
mother(julia, ashley). 
mother(julia, dblock).
father(william, will). 
father(william, ashley). 
father(william, dblock).
male(caesar).              %half brother
male(will).                %half brother
female(ashley).            %sister
male(dblock).              %me

cousin(X,Y) :- mother(A,C), father(B,C), mother(A,D), father(B,D), mother(C,Y), father(D,X). 				 %Me & Siblings <-> Trey&Arielle
%cousin(X,Y) :- mother(A,C), father(B,C), mother(A,D), father(B,D), mother(A,E), father(B,E), father(C,X), mother(D,Y). 	       %Ebony to Gary&Tim
cousin(X,Y) :- mother(A,C), father(B,C), mother(A,D), father(B,D), mother(A,E), father(B,E), father(C,X), father(E,Y), X \== Y, C \== E.                 %Ebony 
to Me & 
Siblings
cousin(X,Y) :- mother(A,C), father(B,C), mother(A,D), father(B,D), mother(A,E), father(B,E), mother(D,X), father(E,Y), X \== Y, C \== E.                 
%Gary&Tim to 
Me 
& Siblings

uncle(X,Y) :- mother(A,C), father(B,C), mother(A,X), father(B,X), female(C), male(X), mother(C,Y).   				       %Uncle Eric to Me & siblings
uncle(X,Y) :- mother(A,X), father(B,X), mother(A,D), father(B,D), mother(A,E), father(B,E), male(X), female(D), male(E), father(E,Y),E \== X.  %Uncle Freddy to 
me & 
siblings
uncle(X,Y) :- mother(A,X), father(B,X), mother(A,D), father(B,D), mother(A,E), father(B,E), male(X), female(D), male(E), mother(D,Y).  %Uncle Freddy to Gary&Tim
uncle(X,Y) :- mother(A,C), father(B,C), mother(A,D), father(B,D), mother(A,X), father(B,X), male(C), female(D), male(X), mother(D,Y).  %Uncle William to Gary&Tim
uncle(X,Y) :- mother(A,C), father(B,C), mother(A,D), father(B,D), mother(A,X), father(B,X), male(C), female(D), male(X), father(C,Y), C \== X.  %Uncle William 
to Ebony

