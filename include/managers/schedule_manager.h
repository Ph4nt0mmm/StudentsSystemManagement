#ifndef SCHEDULE_MANAGER_H
#define SCHEDULE_MANAGER_H

#include "../modules/schedule.h"
#include "../modules/class_section.h"
#include <stdbool.h>

#define MAX_SCHEDULES 500

// Schedule manager structure
typedef struct {
    StudentSchedule* schedules[MAX_SCHEDULES];
    int schedule_count;
    char data_file[256];
} ScheduleManager;

// Function declarations
ScheduleManager* schedule_manager_create(const char* data_file);
void schedule_manager_destroy(ScheduleManager* manager);
bool schedule_manager_add(ScheduleManager* manager, StudentSchedule* schedule);
bool schedule_manager_remove(ScheduleManager* manager, int student_id);
StudentSchedule* schedule_manager_find_by_student(ScheduleManager* manager, int student_id, int semester, int year);
bool schedule_manager_save_to_file(ScheduleManager* manager);
bool schedule_manager_load_from_file(ScheduleManager* manager);
int schedule_manager_get_count(ScheduleManager* manager);
bool schedule_manager_add_class(ScheduleManager* manager, int student_id, ClassSection* class_section);
bool schedule_manager_remove_class(ScheduleManager* manager, int student_id, int class_section_id);
bool schedule_manager_check_conflicts(ScheduleManager* manager, int student_id, ClassSection* new_class);
ClassSection** schedule_manager_get_conflicting_classes(ScheduleManager* manager, int student_id, ClassSection* new_class, int* count);
bool schedule_manager_generate_schedule(ScheduleManager* manager, int student_id, int semester, int year, ClassSection** classes, int class_count);
bool schedule_manager_validate_schedule(ScheduleManager* manager, int student_id, int max_credits);
void schedule_manager_display_schedule(ScheduleManager* manager, int student_id, const char* day);
bool schedule_manager_export_schedule(ScheduleManager* manager, int student_id, const char* export_file);
int schedule_manager_count_daily_classes(ScheduleManager* manager, int student_id, const char* day);
bool schedule_manager_check_time_available(ScheduleManager* manager, int student_id, const char* day, const char* start_time, const char* end_time);

#endif // SCHEDULE_MANAGER_H