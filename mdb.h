#ifndef _MDB_H_
#define _MDB_H_

struct MdbRec {
    char name[16];
    char  msg[24];
};

int loadmdb(FILE *fp, struct List *dest);
void freemdb(struct List *list);
void lookup(FILE* fp, FILE* input, int socket);
#endif /* _MDB_H_ */

