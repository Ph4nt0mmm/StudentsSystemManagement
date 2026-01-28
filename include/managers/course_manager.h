#ifndef COURSE_MANAGER_H
#define COURSE_MANAGER_H

#include "../modules/course.h"
#include <stdbool.h>

#define MAX_COURSES 500

// Course manager structure
typedef struct {
    Course* courses[MAX_COURSES];
    int course_count;
    char data_file[256];
} CourseManager;

// Function declarations
CourseManager* course_manager_create(const char* data_file);
void course_manager_destroy(CourseManager* manager);
bool course_manager_add(CourseManager* manager, Course* course);
bool course_manager_remove(CourseManager* manager, int course_id);
Course* course_manager_find_by_id(CourseManager* manager, int course_id);
Course* course_manager_find_by_code(CourseManager* manager, const char* course_code);
Course** course_manager_find_by_name(CourseManager* manager, const char* name, int* count);
Course** course_manager_find_by_department(CourseManager* manager, int department_id, int* count);
Course** course_manager_find_by_semester(CourseManager* manager, int semester, int* count);
bool course_manager_save_to_file(CourseManager* manager);
bool course_manager_load_from_file(CourseManager* manager);
int course_manager_get_count(CourseManager* manager);
bool course_manager_check_prerequisites(CourseManager* manager, int course_id, const char* student_courses);
Course** course_manager_get_available_courses(CourseManager* manager, int* count);
bool course_manager_update_enrollment(CourseManager* manager, int course_id, int change);
int course_manager_count_by_type(CourseManager* manager, CourseType type);
bool course_manager_generate_catalog(CourseManager* manager, const char* catalog_file);
bool course_manager_validate_schedule(CourseManager* manager, int course_id1, int course_id2);

#endif // COURSE_MANAGER_H