#ifndef GRADE_MANAGER_H
#define GRADE_MANAGER_H

#include "../modules/grade.h"
#include <stdbool.h>

#define MAX_GRADES 10000

// Grade manager structure
typedef struct {
    Grade* grades[MAX_GRADES];
    int grade_count;
    GradingScale grading_scale[12]; // Typically A, A-, B+, B, B-, C+, C, C-, D+, D, D-, F
    int scale_size;
    char data_file[256];
} GradeManager;

// Function declarations
GradeManager* grade_manager_create(const char* data_file);
void grade_manager_destroy(GradeManager* manager);
bool grade_manager_add(GradeManager* manager, Grade* grade);
bool grade_manager_remove(GradeManager* manager, int grade_id);
Grade* grade_manager_find_by_id(GradeManager* manager, int grade_id);
Grade** grade_manager_find_by_student(GradeManager* manager, int student_id, int* count);
Grade** grade_manager_find_by_class(GradeManager* manager, int class_section_id, int* count);
Grade* grade_manager_find_by_student_and_class(GradeManager* manager, int student_id, int class_section_id);
bool grade_manager_save_to_file(GradeManager* manager);
bool grade_manager_load_from_file(GradeManager* manager);
int grade_manager_get_count(GradeManager* manager);
bool grade_manager_update_grade(GradeManager* manager, int grade_id, GradeComponents components);
bool grade_manager_finalize_grade(GradeManager* manager, int grade_id);
float grade_manager_calculate_student_gpa(GradeManager* manager, int student_id);
Grade** grade_manager_get_class_grades(GradeManager* manager, int class_section_id, int* count);
bool grade_manager_import_grades(GradeManager* manager, const char* import_file, int class_section_id);
bool grade_manager_export_grades(GradeManager* manager, int class_section_id, const char* export_file);
// Grade statistics structure
typedef struct {
    int total_students;
    int passing_students;
    int failing_students;
    float average_score;
    float highest_score;
    float lowest_score;
    float standard_deviation;
    char grade_distribution[12][3]; // Letter grades and counts
} GradeStatistics;

GradeStatistics grade_manager_calculate_statistics(GradeManager* manager, int class_section_id);
bool grade_manager_apply_curve(GradeManager* manager, int class_section_id, float curve_amount);

#endif // GRADE_MANAGER_H