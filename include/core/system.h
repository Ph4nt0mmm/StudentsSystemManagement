#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdbool.h>
#include <time.h>

// System configuration
typedef struct {
    char system_name[50];
    char version[20];
    char institution_name[100];
    char academic_year[20];
    int max_students;
    int max_courses;
    int max_lecturers;
    char data_directory[256];
    char log_directory[256];
    char backup_directory[256];
    bool email_notifications;
    bool auto_backup;
    int backup_frequency; // in hours
    int session_timeout; // in minutes
    bool debug_mode;
    char default_language[10];
} SystemConfig;

// System status
typedef enum {
    SYSTEM_RUNNING,
    SYSTEM_MAINTENANCE,
    SYSTEM_SHUTDOWN,
    SYSTEM_ERROR
} SystemStatus;

// System resource usage
typedef struct {
    int user_count;
    int active_sessions;
    int database_connections;
    time_t uptime;
    float cpu_usage;
    long memory_usage;
    long disk_usage;
    int error_count;
} SystemMetrics;

// System manager structure
typedef struct {
    SystemConfig config;
    SystemStatus status;
    SystemMetrics metrics;
    time_t start_time;
    time_t last_maintenance;
    char status_file[256];
    bool is_initialized;
} SystemManager;

// Function declarations
SystemManager* system_manager_create();
void system_manager_destroy(SystemManager* manager);
bool system_initialize(SystemManager* manager, const char* config_file);
bool system_shutdown(SystemManager* manager);
bool system_save_config(SystemManager* manager, const char* config_file);
bool system_load_config(SystemManager* manager, const char* config_file);
SystemMetrics system_get_metrics(SystemManager* manager);
bool system_check_health(SystemManager* manager);
bool system_perform_maintenance(SystemManager* manager);
bool system_backup(SystemManager* manager, const char* backup_path);
bool system_restore(SystemManager* manager, const char* backup_path);
bool system_cleanup_temp_files(SystemManager* manager);
bool system_update_status(SystemManager* manager, SystemStatus new_status);
void system_log_status(SystemManager* manager);
bool system_validate_license(SystemManager* manager);
bool system_check_updates(SystemManager* manager);
char* system_get_version(SystemManager* manager);
time_t system_get_uptime(SystemManager* manager);
bool system_lock_database(SystemManager* manager);
bool system_unlock_database(SystemManager* manager);
bool system_generate_report(SystemManager* manager, const char* report_type,
                           const char* output_file);

#endif // SYSTEM_H