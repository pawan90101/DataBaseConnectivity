
#include "MySQL_Connectivity.h"
bool CMySQLConnection::initialize(std::string username_, std::string password_, std::string  host_, std::string database)
{
	bool rect = true;
	try
	{
		if (driver == nullptr)
		{
			driver = get_driver_instance();
		}

		connection.reset(driver->connect(sql::SQLString(host_.c_str()), sql::SQLString(username_.c_str()), sql::SQLString(password_.c_str())));
		connection->setSchema(sql::SQLString(database.c_str()));
		statement.reset(connection->createStatement());
	}
	catch (sql::SQLException &e)
	{
		std::cout << e.what();
		rect = false;
	}

	return rect;
}

const std::shared_ptr<sql::Statement> CMySQLConnection::getStatement()
{
	return statement;
}