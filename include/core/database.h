#ifndef DATABASE_H
#define DATABASE_H

#include "student.h"
#include "lecturer.h"
#include "course.h"
#include "class_section.h"
#include "grade.h"

#define MAX_STUDENTS   1000
#define MAX_LECTURERS  200
#define MAX_COURSES    300
#define MAX_CLASSES    500

typedef struct {
    Student students[MAX_STUDENTS];
    int student_count;

    Lecturer lecturers[MAX_LECTURERS];
    int lecturer_count;

    Course courses[MAX_COURSES];
    int course_count;

    ClassSection classes[MAX_CLASSES];
    int class_count;

    Grade grades[MAX_STUDENTS * 10];
    int grade_count;
} Database;

/* Lifecycle */
void db_init(Database* db);
void db_clear(Database* db);

/* Persistence */
int db_load(Database* db);
int db_save(Database* db);

#endif
