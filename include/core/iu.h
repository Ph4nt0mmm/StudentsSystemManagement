#ifndef IH_H
#define IH_H

#include <stdbool.h>
#include <time.h>

// Event types for system events
typedef enum {
    EVENT_USER_LOGIN,
    EVENT_USER_LOGOUT,
    EVENT_DATA_ADD,
    EVENT_DATA_UPDATE,
    EVENT_DATA_DELETE,
    EVENT_ERROR,
    EVENT_SYSTEM_START,
    EVENT_SYSTEM_SHUTDOWN,
    EVENT_BACKUP,
    EVENT_RESTORE,
    EVENT_SECURITY_ALERT
} EventType;

// Event structure
typedef struct {
    int id;
    EventType type;
    char source[50];
    char description[200];
    char details[500];
    time_t timestamp;
    int user_id;
    char ip_address[16];
    int severity; // 1-10 scale
} SystemEvent;

// Interface handler structure
typedef struct {
    SystemEvent* event_log[1000];
    int event_count;
    int max_events;
    char log_file[256];
    bool console_output;
    bool file_output;
    bool email_notifications;
    char notification_email[100];
} InterfaceHandler;

// Function declarations
InterfaceHandler* interface_handler_create();
void interface_handler_destroy(InterfaceHandler* handler);
void interface_log_event(InterfaceHandler* handler, EventType type,
                        const char* source, const char* description,
                        const char* details, int user_id, int severity);
void interface_log_error(InterfaceHandler* handler, const char* source,
                        const char* error_message, int error_code);
void interface_display_message(const char* message_type, const char* title,
                             const char* message, bool is_error);
bool interface_confirm_action(const char* title, const char* message);
void interface_show_progress(int current, int total, const char* message);
void interface_clear_screen();
void interface_show_menu(const char* title, const char* options[], 
                        int option_count, int* choice);
char* interface_get_input(const char* prompt, int max_length, bool is_password);
bool interface_validate_input(const char* input, const char* pattern);
void interface_format_output(const char* format, ...);
SystemEvent** interface_get_events_by_type(InterfaceHandler* handler,
                                          EventType type, int* count);
SystemEvent** interface_get_events_by_date(InterfaceHandler* handler,
                                          time_t start_date, time_t end_date,
                                          int* count);
bool interface_export_event_log(InterfaceHandler* handler,
                               const char* export_file);
bool interface_send_notification(InterfaceHandler* handler,
                                const char* recipient,
                                const char* subject,
                                const char* message);

#endif // IH_H