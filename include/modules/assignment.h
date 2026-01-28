#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <stdbool.h>

// Assignment type
typedef enum {
    ASSIGNMENT_HOMEWORK,
    ASSIGNMENT_PROJECT,
    ASSIGNMENT_LAB,
    ASSIGNMENT_PRESENTATION,
    ASSIGNMENT_QUIZ
} AssignmentType;

// Assignment status
typedef enum {
    ASSIGNMENT_PENDING,
    ASSIGNMENT_SUBMITTED,
    ASSIGNMENT_GRADED,
    ASSIGNMENT_LATE,
    ASSIGNMENT_MISSED
} AssignmentStatus;

// Assignment structure
typedef struct {
    int id;
    int class_section_id;
    char title[100];
    char description[500];
    AssignmentType type;
    float max_score;
    float weight;  // Percentage of final grade
    char due_date[11];  // YYYY-MM-DD
    char due_time[6];   // HH:MM
    char submission_instructions[500];
    char attachments[200];  // File paths
    int total_submissions;
    int graded_submissions;
} Assignment;

// Student assignment submission
typedef struct {
    int id;
    int assignment_id;
    int student_id;
    char submission_date[11];
    char submission_time[6];
    char file_path[200];
    float score;
    char feedback[500];
    AssignmentStatus status;
    bool is_late;
    char grader_notes[200];
} AssignmentSubmission;

// Function declarations
Assignment* assignment_create(int id, int class_section_id, const char* title,
                            AssignmentType type, float max_score, float weight);
void assignment_destroy(Assignment* assignment);
AssignmentSubmission* assignment_submission_create(int id, int assignment_id, 
                                                  int student_id);
void assignment_submission_destroy(AssignmentSubmission* submission);
bool assignment_submit(AssignmentSubmission* submission, const char* file_path);
bool assignment_grade_submission(AssignmentSubmission* submission, float score,
                                const char* feedback);
bool assignment_check_deadline(const char* due_date, const char* due_time,
                              const char* submission_date, const char* submission_time);
float assignment_calculate_average(Assignment* assignment, AssignmentSubmission** submissions,
                                 int count);
int assignment_count_submissions(Assignment* assignment, AssignmentSubmission** submissions,
                               int count, AssignmentStatus status);
const char* assignment_type_to_string(AssignmentType type);
const char* assignment_status_to_string(AssignmentStatus status);

#endif // ASSIGNMENT_H