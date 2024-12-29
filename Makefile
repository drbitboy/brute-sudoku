
all: sud

test: all bena.sud
	./sud < bena.sud \
	| gawk '{print $$0 (($$0 in d) && $$0 != "Solution:" && length($$0) ? " (duplicate)" : "")}{d[$$0]++}' > solutions_bena.txt

clean:
	$(RM) sud
