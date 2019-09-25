#pragma once
#include <iostream>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/sqlstring.h>

class CMySQLConnection
{
	std::string username_;
	std::string password_;
	std::string host_;
	std::string database_;
	static sql::Driver *driver;
	std::unique_ptr<sql::Connection> connection;
	std::shared_ptr<sql::Statement> statement;
public:
	const std::shared_ptr<sql::Statement> getStatement();
	bool initialize(std::string username_, std::string password_, std::string  host_, std::string database);
};