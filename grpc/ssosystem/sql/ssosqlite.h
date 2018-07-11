/*
 * ssosqlite.h
 *
 *  Created on: 2018-7-10
 *      Author: mule
 */

#ifndef SSOSQLITE_H_
#define SSOSQLITE_H_
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "IService.h"
class SSOSqlite {
public:
	SSOSqlite();
	~SSOSqlite();
	bool InitSqlite();
	bool OpenTable();
	bool GetData(CString strSql, CString *strQueryCloum, int nCloumNum,
			CStringArray& strDataValue);

	bool AddData(std::string username, int key, int token);

	bool EditData(CString strSQL, int nColumnNum, CString* pStrFieldName,
			CStringArray &saValue);

	bool SelectKey(std::string username)
	bool SelectToken(std::string username)
	sqlite3 *db;
	char *zErrMsg = 0;
	char *sql;
	IService*isevice;
};

#endif /* SSOSQLITE_H_ */
