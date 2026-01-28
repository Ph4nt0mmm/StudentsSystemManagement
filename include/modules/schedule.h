#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <stdbool.h>

// Schedule entry structure
typedef struct ScheduleEntry {
    int id;
    int class_section_id;
    int student_id;
    char day[10];
    char start_time[6];
    char end_time[6];
    char room[20];
    struct ScheduleEntry* next;
} ScheduleEntry;

// Weekly schedule structure
typedef struct {
    ScheduleEntry* monday;
    ScheduleEntry* tuesday;
    ScheduleEntry* wednesday;
    ScheduleEntry* thursday;
    ScheduleEntry* friday;
    ScheduleEntry* saturday;
    ScheduleEntry* sunday;
} WeeklySchedule;

// Schedule manager structure
typedef struct {
    int student_id;
    int semester;
    int year;
    WeeklySchedule weekly;
    int total_credits;
    bool has_conflicts;
} StudentSchedule;

// Function declarations
ScheduleEntry* schedule_entry_create(int id, int class_section_id, int student_id,
                                    const char* day, const char* start_time,
                                    const char* end_time, const char* room);
void schedule_entry_destroy(ScheduleEntry* entry);
StudentSchedule* student_schedule_create(int student_id, int semester, int year);
void student_schedule_destroy(StudentSchedule* schedule);
bool student_schedule_add_entry(StudentSchedule* schedule, ScheduleEntry* entry);
bool student_schedule_remove_entry(StudentSchedule* schedule, int entry_id);
bool student_schedule_check_conflict(StudentSchedule* schedule, ScheduleEntry* new_entry);
void student_schedule_display_daily(StudentSchedule* schedule, const char* day);
int student_schedule_count_daily_classes(StudentSchedule* schedule, const char* day);
bool student_schedule_validate_credits(StudentSchedule* schedule, int max_credits);

#endif // SCHEDULE_H