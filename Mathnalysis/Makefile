all: Mathnalysis

Mathnalysis: Mathnalysis.o EcuacionesUnaVariable/PuntoFijo.o EcuacionesUnaVariable/raices_multiples.o EcuacionesUnaVariable/biseccion.o EcuacionesUnaVariable/busqueda_incrementa.o EcuacionesUnaVariable/newton.o EcuacionesUnaVariable/reglaFalsa.o EcuacionesUnaVariable/secante.o VariasVariables/gaussSeidel.o VariasVariables/crout.o VariasVariables/doolittle.o VariasVariables/EGS.o VariasVariables/jacobi.o VariasVariables/PivParcial.o VariasVariables/PivTotal.o  VariasVariables/Cholesky.o analizador/analizer.o analizador/scanner.o analizador/token.o analizador/ast.o analizador/parser.o analizador/calculator.o 
			g++ -std=c++11 -o $@ $^ -fopenmp

Mathnalysis.o: Mathnalysis.cpp Mathnalysis.h exceptions.h EcuacionesUnaVariable/PuntoFijo.h EcuacionesUnaVariable/raices_multiples.h EcuacionesUnaVariable/biseccion.h EcuacionesUnaVariable/busqueda_incrementa.h EcuacionesUnaVariable/newton.h EcuacionesUnaVariable/reglaFalsa.h EcuacionesUnaVariable/secante.h VariasVariables/gaussSeidel.h VariasVariables/crout.h

EcuacionesUnaVariable/PuntoFijo.o:  EcuacionesUnaVariable/PuntoFijo.cpp EcuacionesUnaVariable/PuntoFijo.h

EcuacionesUnaVariable/raices_multiples.o: EcuacionesUnaVariable/raices_multiples.cpp EcuacionesUnaVariable/raices_multiples.h

EcuacionesUnaVariable/biseccion.o: EcuacionesUnaVariable/biseccion.cpp EcuacionesUnaVariable/biseccion.h

EcuacionesUnaVariable/busqueda_incrementa.o: EcuacionesUnaVariable/busqueda_incrementa.cpp EcuacionesUnaVariable/busqueda_incrementa.h

EcuacionesUnaVariable/newton.o: EcuacionesUnaVariable/newton.cpp EcuacionesUnaVariable/newton.h

EcuacionesUnaVariable/reglaFalsa.o: EcuacionesUnaVariable/reglaFalsa.cpp EcuacionesUnaVariable/reglaFalsa.h

EcuacionesUnaVariable/secante.o: EcuacionesUnaVariable/secante.cpp EcuacionesUnaVariable/secante.h

VariasVariables/gaussSeidel.o: VariasVariables/gaussSeidel.cpp VariasVariables/gaussSeidel.h

VariasVariables/crout.o: VariasVariables/crout.cpp VariasVariables/crout.h

VariasVariables/Cholesky.o: VariasVariables/Cholesky.cpp VariasVariables/Cholesky.h

VariasVariables/doolittle.o: VariasVariables/doolittle.cpp VariasVariables/doolittle.h 

VariasVariables/EGS.o: VariasVariables/EGS.cpp VariasVariables/EGS.h

VariasVariables/jacobi.o: VariasVariables/jacobi.cpp VariasVariables/jacobi.h

VariasVariables/PivParcial.o: VariasVariables/PivParcial.cpp VariasVariables/PivParcial.h

VariasVariables/PivTotal.o: VariasVariables/PivTotal.cpp VariasVariables/PivTotal.h

VariasVariables/Cholesky.o: VariasVariables/Cholesky.cpp VariasVariables/Cholesky.h

analizador/analizer.o: analizador/analizer.cpp analizador/analizer.h analizador/scanner.h analizador/token.h

analizador/calculator.o: analizador/calculator.cpp analizador/calculator.h analizador/parser.h analizador/ast.h

analizador/scanner.o: analizador/scanner.cpp analizador/scanner.h analizador/token.h

analizador/token.o: analizador/token.cpp analizador/token.h

analizador/ast.o: analizador/ast.cpp analizador/ast.h

analizador/parser.o: analizador/parser.cpp analizador/parser.h

clean:
		rm -f *.o
		rm -f *.*~
		rm -f Mathnalysis
