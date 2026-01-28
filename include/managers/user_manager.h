#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ===== Enum phân quyền ===== */
enum class Role {
    ADMIN,
    STUDENT,
    LECTURER
};

/* ===== Struct User ===== */
struct User {
    string username;
    string password;
    Role role;
    bool isActive;

    User(string u = "", string p = "", Role r = Role::STUDENT)
        : username(u), password(p), role(r), isActive(true) {}
};

/* ===== Class UserManager ===== */
class UserManager {
private:
    vector<User> users;

    int findUserIndex(const string& username) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].username == username)
                return i;
        }
        return -1;
    }

public:
    /* ===== Constructor ===== */
    UserManager() {
        // Tạo sẵn admin mặc định
        users.push_back(User("admin", "admin123", Role::ADMIN));
    }

    /* ===== Thêm user ===== */
    bool addUser(const string& username, const string& password, Role role) {
        if (findUserIndex(username) != -1)
            return false;

        users.push_back(User(username, password, role));
        return true;
    }

    /* ===== Xoá user ===== */
    bool removeUser(const string& username) {
        int index = findUserIndex(username);
        if (index == -1)
            return false;

        users.erase(users.begin() + index);
        return true;
    }

    /* ===== Đăng nhập ===== */
    User* login(const string& username, const string& password) {
        int index = findUserIndex(username);
        if (index == -1)
            return nullptr;

        if (users[index].password == password && users[index].isActive)
            return &users[index];

        return nullptr;
    }

    /* ===== Khoá / mở tài khoản ===== */
    bool setActive(const string& username, bool status) {
        int index = findUserIndex(username);
        if (index == -1)
            return false;

        users[index].isActive = status;
        return true;
    }

    /* ===== Đổi mật khẩu ===== */
    bool changePassword(const string& username, const string& newPassword) {
        int index = findUserIndex(username);
        if (index == -1)
            return false;

        users[index].password = newPassword;
        return true;
    }

    /* ===== Hiển thị danh sách user ===== */
    void showUsers() {
        cout << "\n--- USER LIST ---\n";
        for (const auto& u : users) {
            cout << "Username: " << u.username
                 << " | Role: " << roleToString(u.role)
                 << " | Active: " << (u.isActive ? "Yes" : "No") << endl;
        }
    }

    /* ===== Chuyển role sang string ===== */
    string roleToString(Role role) {
        switch (role) {
        case Role::ADMIN: return "Admin";
        case Role::STUDENT: return "Student";
        case Role::LECTURER: return "Lecturer";
        default: return "Unknown";
        }
    }
};

#endif
