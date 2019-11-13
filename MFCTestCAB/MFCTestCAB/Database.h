#pragma once
#include "odbcinst.h"
#include "afxdb.h"


class Database
{
public:
	
	Database();
	~Database();
	void Execute(CString CmdStr);
	void Clean();
	CString load();

private:
	CDatabase database;
	CString sDsn;
};