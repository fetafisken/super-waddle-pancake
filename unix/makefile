CPP=g++
CPPFLAGS=-std=c++11
SDIR=source/
SRC=$(wildcard $(SDIR)*.cc)
ODIR=obj/
OBJS=$(patsubst $(SDIR)%.cc,$(ODIR)%.o,$(SRC))
LDIR=header
DEP=$(wildcard $(LDIR)*.hh)
OUTDIR=output/

.PHONY: all test rlab5 dot open clean
all: lab5

lab5: $(OBJS)
	@mkdir -p output
	$(CPP) $(CPPFLAGS) -o$@ $^

$(ODIR)%.o: $(SDIR)%.cc $(DEP)
	@mkdir -p $(ODIR)
	$(CPP) $(CPPFLAGS) -I$(LDIR) -c -o$@ $<



# Create executable from testcase in lab5.
test: rlab5 etest ctest atest
rlab5: lab5
	./lab5

etest: $(SDIR)t.c
	@echo "\n\nEXAMPLE TEST: $^"
	@echo "----------------------------------------------------------"
	@$(CPP) $(CPPFLAGS) -o$(OUTDIR)$@ $^
	@./$(OUTDIR)$@

ctest: $(OUTDIR)int.c
	@echo "\n\nC CODE TEST: $^"
	@echo "----------------------------------------------------------"
	@$(CPP) $(CPPFLAGS) -o$(OUTDIR)$@ $^
	@./$(OUTDIR)$@

atest: $(OUTDIR)ass.c
	@echo "\n\nASSEMBLY CODE TEST: $^"
	@echo "----------------------------------------------------------"
	@$(CPP) $(CPPFLAGS) -o$(OUTDIR)$@ $^
	@./$(OUTDIR)$@



# generate and open .dot file(svg)
dot: int.svg

int.svg: rlab5
	dot $(OUTDIR)int.dot -o$(OUTDIR)$@ -Tsvg

open: int.svg
	xviewer $(OUTDIR)$< &

# clean up the directory
clean:
	rm -rf $(OUTDIR) $(ODIR) lab5
