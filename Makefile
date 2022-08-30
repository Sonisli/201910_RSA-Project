CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g
COVERAGE = --coverage


all: ReallyLongInt_TEST numberTheory_TEST genkeys encrypt decrypt

ReallyLongInt.o:  ReallyLongInt.cpp ReallyLongInt.hpp
	$(CC) $(CFLAGS) -c ReallyLongInt.cpp

ReallyLongInt_TEST: ReallyLongInt_TEST.cpp ReallyLongInt.o catch.hpp
	$(CC) $(CFLAGS) -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.o

numberTheory.o: numberTheory.cpp numberTheory.hpp
	$(CC) $(CFLAGS) -c numberTheory.cpp

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o catch.hpp
	$(CC) $(CFLAGS) -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o

genkeys: genkeys.cpp numberTheory.o ReallyLongInt.o catch.hpp
	$(CC) $(CFLAGS) -o genkeys genkeys.cpp numberTheory.o ReallyLongInt.o 

encrypt: encrypt.cpp numberTheory.o ReallyLongInt.o catch.hpp
	$(CC) $(CFLAGS) -o encrypt encrypt.cpp numberTheory.o ReallyLongInt.o 

decrypt: decrypt.cpp numberTheory.o ReallyLongInt.o catch.hpp
	$(CC) $(CFLAGS) -o decrypt decrypt.cpp numberTheory.o ReallyLongInt.o 

clean:
	rm *.o ReallyLongInt_TEST numberTheory_TEST genkeys encrypt decrypt
