#ifndef COURSE_H
#define COURSE_H

#include <stdbool.h>

// Course type
typedef enum {
    COURSE_REQUIRED,
    COURSE_ELECTIVE,
    COURSE_SPECIALIZATION,
    COURSE_GENERAL_EDUCATION
} CourseType;

// Course level
typedef enum {
    LEVEL_UNDERGRADUATE,
    LEVEL_GRADUATE,
    LEVEL_DOCTORAL
} CourseLevel;

// Course structure
typedef struct {
    int id;
    char course_code[20];
    char name[100];
    char description[500];
    CourseType type;
    CourseLevel level;
    int credits;
    int semester;  // 0 if offered in multiple semesters
    int max_students;
    int current_students;
    char prerequisites[200];
    char learning_outcomes[500];
    char textbook[200];
    bool is_active;
    int department_id;
    char schedule_pattern[50]; // e.g., "MWF 8-9", "TTh 10-11:30"
} Course;

// Function declarations
Course* course_create(int id, const char* course_code, const char* name,
                     CourseType type, int credits, int department_id);
void course_destroy(Course* course);
bool course_add_student(Course* course);
bool course_remove_student(Course* course);
bool course_check_prerequisites(const char* student_prerequisites);
bool course_is_available(Course* course);
bool course_validate_schedule(const char* schedule);
int course_calculate_workload(Course* course);
const char* course_type_to_string(CourseType type);
const char* course_level_to_string(CourseLevel level);
CourseType string_to_course_type(const char* type_str);
CourseLevel string_to_course_level(const char* level_str);

#endif // COURSE_H