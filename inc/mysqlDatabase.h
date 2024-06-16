#ifndef MYSQL_DATABASE_H
#define MYSQL_DATABASE_H

#include "database.h"

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

class MySQLDatabase : public Database
{
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    std::string host;
    std::string user;
    std::string password;

    static std::shared_ptr<MySQLDatabase> instance;

    void checkConnection();

    MySQLDatabase(const std::string &host, const std::string &user, const std::string &password, const std::string &database);

public:
    static void createInstance(const std::string &host, const std::string &user, const std::string &password, const std::string &database);
    static std::shared_ptr<MySQLDatabase> getInstance();

    ~MySQLDatabase();

    MySQLDatabase(const MySQLDatabase &) = delete;
    MySQLDatabase &operator=(const MySQLDatabase &) = delete;

    bool connect() override;
    bool disconnect() override;
    bool executeQuery(const std::string &query) override;
    std::vector<std::vector<std::string>> fetchRows(const std::string &query) override;
};

#endif // MYSQL_DATABASE_H
