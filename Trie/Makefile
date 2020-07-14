# Compiler to use
CC = g++

# Flags to use
CFLAGS = -Wall -std=c++11

TrieTest: TrieTest.cpp Trie.o Node.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.cpp Trie.o Node.o

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

clean:
	rm ./TrieTest *.o

test:
	./TrieTest inputWords.txt testWords.txt
