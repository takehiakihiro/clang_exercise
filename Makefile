TARGET=binary_tree_test echo_server echo_client text_0 kadai_1 kadai_2 kadai_3 kadai_5 kadai_7 kadai_8 kadai_9
CC=gcc

all: $(TARGET)

binary_tree_test: binary_tree.o binary_tree_test.o
	gcc -o $@ $^

text_0: text_0.c
	gcc -o $@ $<

kadai_1: kadai_1.c
	gcc -o $@ $<

kadai_2: kadai_2.c
	gcc -o $@ $<

kadai_3: kadai_3.c
	gcc -o $@ $<

kadai_5: kadai_5.c
	gcc -o $@ $<

kadai_7: kadai_7.c
	gcc -o $@ $<

kadai_8: kadai_8.c
	gcc -o $@ $<

kadai_9: kadai_9.c
	gcc -o $@ $<

echo_server: echo_server.c
	gcc -o $@ $<

echo_client: echo_client.c
	gcc -o $@ $<

clean:
	rm -f *.o $(TARGET)
