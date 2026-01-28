#ifndef CLASS_SECTION_H
#define CLASS_SECTION_H

#include <stdbool.h>

// Class schedule structure
typedef struct {
    char day[10];  // "Monday", "Tuesday", etc.
    char start_time[6];  // "08:00"
    char end_time[6];    // "09:30"
    char room[20];
} ClassSchedule;

// Class section structure
typedef struct {
    int id;
    char section_code[20];
    int course_id;
    int lecturer_id;
    int semester;  // 1, 2, or 3 (summer)
    int year;
    int capacity;
    int enrolled_students;
    ClassSchedule schedule[5]; // Max 5 sessions per week
    int schedule_count;
    char status[20];  // "OPEN", "CLOSED", "CANCELLED"
    char notes[200];
} ClassSection;

// Function declarations
ClassSection* class_section_create(int id, const char* section_code, 
                                  int course_id, int semester, int year);
void class_section_destroy(ClassSection* section);
bool class_section_add_student(ClassSection* section);
bool class_section_remove_student(ClassSection* section);
bool class_section_check_capacity(ClassSection* section);
bool class_section_add_schedule(ClassSection* section, const char* day, 
                               const char* start_time, const char* end_time, 
                               const char* room);
bool class_section_remove_schedule(ClassSection* section, int index);
bool class_section_check_time_conflict(ClassSection* section1, ClassSection* section2);
void class_section_update_status(ClassSection* section, const char* status);
int class_section_get_available_seats(ClassSection* section);

#endif // CLASS_SECTION_H