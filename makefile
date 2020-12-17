CXX = g++
CXX_Flags = -w -o

Practica10: cripto

cripto: funciones_cripto.h funciones_cripto.cc cripto.cc
	$(CXX) $(CXX_Flags) cripto funciones_cripto.h funciones_cripto.cc cripto.cc