#ifndef GRADE_H
#define GRADE_H

#include <stdbool.h>

// Grade components
typedef struct {
    float attendance;
    float assignment;
    float midterm;
    float final;
    float project;
} GradeComponents;

// Grade structure
typedef struct {
    int id;
    int student_id;
    int class_section_id;
    GradeComponents components;
    float total_score;
    char letter_grade[3];  // "A", "B+", "C", etc.
    float grade_point;
    bool is_finalized;
    char last_updated[20];
    char notes[200];
} Grade;

// Grading scale
typedef struct {
    char letter_grade[3];
    float min_score;
    float max_score;
    float grade_point;
} GradingScale;

// Function declarations
Grade* grade_create(int id, int student_id, int class_section_id);
void grade_destroy(Grade* grade);
bool grade_update_component(Grade* grade, const char* component_type, float score);
bool grade_calculate_total(Grade* grade, const float* weights);
bool grade_assign_letter_grade(Grade* grade, const GradingScale* scale, int scale_size);
float grade_calculate_gpa(Grade** grades, int count);
bool grade_is_passing(Grade* grade);
char* grade_get_grade_description(const char* letter_grade);
float grade_get_grade_point(const char* letter_grade);
bool grade_validate_components(GradeComponents components);

#endif // GRADE_H