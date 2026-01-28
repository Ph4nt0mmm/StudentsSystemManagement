#ifndef REPORT_MANAGER_H
#define REPORT_MANAGER_H

#include <stdbool.h>

// Report types
typedef enum {
    REPORT_STUDENT_LIST,
    REPORT_COURSE_CATALOG,
    REPORT_GRADE_REPORT,
    REPORT_ATTENDANCE,
    REPORT_FINANCIAL,
    REPORT_ACADEMIC_STANDING,
    REPORT_ENROLLMENT_STATISTICS,
    REPORT_FACULTY_LOAD
} ReportType;

// Report format
typedef enum {
    FORMAT_CSV,
    FORMAT_PDF,
    FORMAT_HTML,
    FORMAT_TXT
} ReportFormat;

// Report structure
typedef struct {
    int id;
    ReportType type;
    ReportFormat format;
    char title[100];
    char description[500];
    char generated_date[20];
    char generated_by[50];
    char file_path[256];
    bool is_scheduled;
    char schedule_pattern[50]; // Cron-like pattern
    char last_generated[20];
} Report;

// Report manager structure
typedef struct {
    Report* reports[100];
    int report_count;
    char report_dir[256];
} ReportManager;

// Function declarations
ReportManager* report_manager_create(const char* report_dir);
void report_manager_destroy(ReportManager* manager);
Report* report_generate_student_list(ReportManager* manager, const char* title, 
                                   ReportFormat format, int* student_ids, int student_count);
Report* report_generate_course_catalog(ReportManager* manager, const char* title,
                                     ReportFormat format, int semester, int year);
Report* report_generate_grade_report(ReportManager* manager, const char* title,
                                   ReportFormat format, int student_id, int semester, int year);
Report* report_generate_transcript(ReportManager* manager, int student_id, ReportFormat format);
Report* report_generate_enrollment_statistics(ReportManager* manager, const char* title,
                                            ReportFormat format, int semester, int year);
Report* report_generate_faculty_workload(ReportManager* manager, const char* title,
                                       ReportFormat format, int semester, int year);
bool report_save(ReportManager* manager, Report* report);
bool report_delete(ReportManager* manager, int report_id);
Report* report_find_by_id(ReportManager* manager, int report_id);
Report** report_find_by_type(ReportManager* manager, ReportType type, int* count);
bool report_schedule_generation(ReportManager* manager, ReportType type, 
                              ReportFormat format, const char* schedule_pattern);
bool report_execute_scheduled_reports(ReportManager* manager);
bool report_export(Report* report, const char* export_path);
bool report_send_email(Report* report, const char* email_address);
const char* report_type_to_string(ReportType type);
const char* report_format_to_string(ReportFormat format);

#endif // REPORT_MANAGER_H