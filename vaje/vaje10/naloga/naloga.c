#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student **studentje, int stStudentov, int vpisna) {
    int obstaja = -1;
    for (int i = 0; i < stStudentov; i++) {
        if (studentje[i]->vpisna == vpisna) {
            obstaja = i;
        }
    }
    return obstaja;
}

int poisciPO(Student *student, char *predmet) {
    int ocena = -1;
    for (int i = 0; i < student->stPO; i++) {
        if (strcmp(student->po[i].predmet, predmet) == 0) {
            ocena = i;
        }
    }

    return ocena;
}

int dodaj(Student **studentje, int stStudentov, int vpisna, char *predmet,
          int ocena) {
    int iStudenta = poisciStudenta(studentje, stStudentov, vpisna);
    if (iStudenta != -1) {
        int iPredmeta = poisciPO(studentje[iStudenta], predmet);
        if (iPredmeta != -1) {
            studentje[iStudenta]->po[iPredmeta].ocena = ocena;
        } else {
                
            studentje[iStudenta]->po[studentje[iStudenta]->stPO].ocena = ocena;
            strcpy(studentje[iStudenta]->po[studentje[iStudenta]->stPO].predmet, predmet);
            studentje[iStudenta]->stPO++;

        }
    } else {
        // novi student
        Student *s = calloc(sizeof(Student *), 1);
        s->vpisna = vpisna;
        s->stPO = 1;
        s->po = calloc(sizeof(PO), 10);
        strcpy(s->po[0].predmet, predmet);
        s->po[0].ocena = ocena;
        studentje[stStudentov] = s;
        stStudentov++;
    }
    return stStudentov;
}

#ifndef test

int main() { return 0; }

#endif
