#ifndef CLASS_MANAGER_H
#define CLASS_MANAGER_H

#include "../modules/class_section.h"
#include <stdbool.h>

#define MAX_CLASSES 300

// Class manager structure
typedef struct {
    ClassSection* classes[MAX_CLASSES];
    int class_count;
    char data_file[256];
} ClassManager;

// Function declarations
ClassManager* class_manager_create(const char* data_file);
void class_manager_destroy(ClassManager* manager);
bool class_manager_add(ClassManager* manager, ClassSection* class_section);
bool class_manager_remove(ClassManager* manager, int class_id);
ClassSection* class_manager_find_by_id(ClassManager* manager, int class_id);
ClassSection* class_manager_find_by_code(ClassManager* manager, const char* section_code);
ClassSection** class_manager_find_by_course(ClassManager* manager, int course_id, int* count);
ClassSection** class_manager_find_by_lecturer(ClassManager* manager, int lecturer_id, int* count);
ClassSection** class_manager_find_by_semester(ClassManager* manager, int semester, int year, int* count);
bool class_manager_save_to_file(ClassManager* manager);
bool class_manager_load_from_file(ClassManager* manager);
int class_manager_get_count(ClassManager* manager);
bool class_manager_enroll_student(ClassManager* manager, int class_id);
bool class_manager_drop_student(ClassManager* manager, int class_id);
int class_manager_get_available_seats(ClassManager* manager, int class_id);
ClassSection** class_manager_get_conflicting_classes(ClassManager* manager, ClassSection* section, int* count);
bool class_manager_check_schedule_conflict(ClassManager* manager, int class_id1, int class_id2);
bool class_manager_update_status(ClassManager* manager, int class_id, const char* status);
bool class_manager_generate_class_list(ClassManager* manager, int class_id, const char* output_file);

#endif // CLASS_MANAGER_H