#include <stdio.h>
#include <errno.h>

#define SZROOT (3)
#define SZ (SZROOT*SZROOT)
#define SZSQ (SZ*SZ)
#define NOTHER 20

typedef struct ENTRYstr {
  int value;
  int row;
  int col;
  int box;
  struct ENTRYstr* others[NOTHER];
} ENTRY, *pENTRY, **ppENTRY;

static ENTRY entries[SZSQ];
static pENTRY endentry = entries + SZSQ;

void init_entries() {
  int i;
  pENTRY pentry = entries;

  for (i=0; i<SZSQ; ++i, ++pentry) {
    pentry->value = 0;
    pentry->row = i / SZ;
    pentry->col = i % SZ;
    pentry->box = (SZROOT * (pentry->row / SZROOT)) + (pentry->col / SZROOT);
  }
  pentry = entries;
  for (i=0; i<SZSQ; ++i, ++pentry) {
    pENTRY prow = entries + (9 * pentry->row);
    pENTRY pcol = entries + pentry->col;
    pENTRY pbox = entries + ((SZROOT * (pentry->box % SZROOT))
                            + (SZROOT*SZROOT*SZROOT * (pentry->box / SZROOT))
                            );
    ppENTRY pprowothers = pentry->others;
    ppENTRY ppcolothers = pprowothers + 8;
    ppENTRY ppboxothers = ppcolothers + 8;
    int rcb;
    for (rcb=0; rcb<9; ++rcb, ++prow) {
      if (prow->col != pentry->col) { *(pprowothers++) = prow; }
      if (pcol->row != pentry->row) { *(ppcolothers++) = pcol; }
      if (pbox->row != pentry->row && pbox->col != pentry->col) {
        *(ppboxothers++) = pbox;
      }
      pbox += ((rcb%SZROOT)<(SZROOT-1)) ? 1 : 7;
      pcol += 9;
    }
  }
}

void read_data(FILE* fin) {
  pENTRY pentry = entries;
  int ichar;
  errno = 0;
  while (pentry<endentry && EOF!=(ichar=fgetc(fin)) && !errno) {
    if (ichar <= ' ') { continue; }
    pentry->value = ('1'>ichar || ichar > '9') ? 0 : (ichar - '0');
    ++pentry;
  }
  if (pentry != endentry) {
    errno = errno ? errno : EPROTO;
    perror("Problem with sudoku data input");
  }
    
}

void print_data(FILE* fout, char* text) {
  pENTRY pentry = entries;
  fprintf(fout,"\n%s", text);
  for (pentry=entries; pentry<endentry; ++pentry) {
    int ascii;
    if (!((pentry-entries) % SZ)) { fprintf(fout,"%s","\n  "); }
    ascii = pentry->value + 48 + (pentry->value>9 ? 7 : 0);
    fprintf(fout,"%c", pentry->value ? ((char)ascii) : '.');
  }
  fprintf(fout,"%s","\n\n");
}

void solve(pENTRY pentry, FILE* fout) {
  int testval;

  if (pentry==endentry) {
    print_data(fout, "Solution:");
    return;
  }
  else if (0!=pentry->value) {
    solve(pentry+1, fout);
    return;
  }

  for (testval=1; testval<=SZ; ++testval) {
    int iother;
    for (iother=0
        ; iother<NOTHER && pentry->others[iother]->value != testval
        ; ++iother) { ; }
    if (iother < NOTHER) { continue; }
    pentry->value = testval;
    solve(pentry+1, fout);
  }
  pentry->value = 0;

  return;
}


int main(int argc, char** argv) {
  init_entries();
  read_data(stdin);
  print_data(stdout, "Input:");
  solve(entries, stdout);
  return 0;
}
