#include "MySQL_Connectivity.h"
#define DEFAULT_URI "tcp://127.0.0.1"
#define EXAMPLE_USER "pawan90101"
#define EXAMPLE_PASS "231123"
#define EXAMPLE_DB "company"
sql::Driver *CMySQLConnection::driver = nullptr;
int main(int args, char *argv[])
{
	CMySQLConnection obj;
	if (obj.initialize(EXAMPLE_USER, EXAMPLE_PASS, DEFAULT_URI, EXAMPLE_DB))
	{
		std::shared_ptr<sql::Statement> stmt = obj.getStatement();
		sql::SQLString query = "select * from employee";
		std::shared_ptr<sql::ResultSet> rt(stmt->executeQuery(query));
		while (rt->next())
		{
			std::cout << rt->getString("emp_id").c_str() <<":";
			std::cout << rt->getString("emp_name").c_str() << ":";
			std::cout << rt->getString("emp_deparment").c_str() << std::endl;
		}
	}
	return 0;
}