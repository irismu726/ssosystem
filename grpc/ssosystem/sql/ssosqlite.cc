/*
 * ssosqlite.cc
 *
 *  Created on: 2018-7-10
 *      Author: mule
 */


#include "ssosqlite.h"

SSOSqlite::SSOSqlite()
{
	 InitSqlite();
}

SSOSqlite::~SSOSqlite()
{
	sqlite3_close(db);
}

bool SSOSqlite::InitSqlite()
{

	   rc = sqlite3_open("sso.db", &db);

	   if( rc ){
	      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	      return true;
	   }else{
	      fprintf(stderr, "Opened database successfully\n");
	   }

	return false;
}


bool SSOSqlite::OpenTable()
{
	   sql = "CREATE TABLE SSOSYSTEM("  \
	         "NAME           TEXT    NOT NULL," \
	         "KEY            INT     NOT NULL," \
	         "TOKEN        INT," \ );";

	   /* Execute SQL statement */
	   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	   if( rc != SQLITE_OK ){
	   fprintf(stderr, "SQL error: %s\n", zErrMsg);
	      sqlite3_free(zErrMsg);
		   return true;
	   }else{
	      fprintf(stdout, "Table created successfully\n");
	   }

return false;
}


bool SSOSqlite::AddData(std::string username,int key,int token)
{
	   /* Create SQL statement */
	   sql = "INSERT INTO SSOSYSTEM (NAME,AGE,ADDRESS,SALARY) "  \
	         "VALUES ("+username+ ","+key+","+token+" ); " ;

	   /* Execute SQL statement */
	   rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);

	   if( rc != SQLITE_OK ){
			iservice->callback_reg(fallse);
	      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	      sqlite3_free(zErrMsg);
	   }else{
			iservice->callback_reg(true);
	      fprintf(stdout, "Records created successfully\n");
	   }
}
bool SSOSqlite::SelectKey(std::string username,int key,int token)
{
	 sql = "SELECT KEY from SSOSYSTEM where  NAME = "+username;

	   /* Execute SQL statement */
	   rc = sqlite3_exec(db, sql, 0, (void*)data, &zErrMsg);

	   if( rc != SQLITE_OK ){
	      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	      sqlite3_free(zErrMsg);
	   }else{
		   if(*data == key)
		   {
			   iservice->callback_login(true,token);
		   }else{
			   iservice->callback_login(false,token);
		   }
		   SelectToken(username,token);

	      fprintf(stdout, "Operation done successfully\n");
	   }
	   SelectToken(username);
}


bool SSOSqlite::SelectToken(std::string username,int token)
{
	 sql = "SELECT TOKEN from SSOSYSTEM where  NAME = "+username;

	   /* Execute SQL statement */
	   rc = sqlite3_exec(db, sql, callback_token, (void*)data, &zErrMsg);

	   if( rc != SQLITE_OK ){
	      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	      sqlite3_free(zErrMsg);
	   }else{
		   if(token!=*data)
		   {
			   iservice->callback_out(token);
		   }
	      fprintf(stdout, "Operation done successfully\n");
	   }
}

