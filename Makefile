
all: sud

test: all bena.sud
	./sud < bena.sud

clean:
	$(RM) sud
