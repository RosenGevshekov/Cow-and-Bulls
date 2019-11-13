
#include "stdafx.h"
#include "Database.h"
#include <string>

Database::Database():
	database()
{
	CString sDriver = L"ODBC Driver 17 for SQL Server";						//set the Driver
	CString path = L"C:\\Program Files\\Microsoft SQL Server\\MSSQL13.SQLEXPRESS\\MSSQL\\DATA\\test.mdf"; //set path to the DB
	CString serverName = L"DESKTOP-A8IF336\\SQLEXPRESS";				//set Server Name
	CString nameDB = L"test";											//set DATABASE Name
	CString user = L"Player";											//set user Name for access DataBase
	CString pass = L"asddsafghhgf";											//set password for access DataBase

	sDsn.Format(L"ODBC;DRIVER={%s};Server=%s;DSN='';DBQ=%s;DATABASE=%s; UID=%s; PWD=%s", sDriver,serverName, path, nameDB, user, pass); // DSN String
}

Database::~Database() {
	
}


void Database::Execute(CString CmdStr)
{
	
	// Build ODBC connection string
		TRY{
			// Open the database
			database.Open(NULL,false,false,sDsn);

			database.ExecuteSQL(CmdStr);

			// Close the database
			database.Close();
		}CATCH(CDBException, e) {
			// If a database exception occured, show error msg
			AfxMessageBox(L"Database error: " + e->m_strError);
		}
		END_CATCH;
	
}

void Database::Clean() {
	
	TRY{
		database.Open(NULL, false, false, sDsn);

		CString SqlString = _T("IF(EXISTS(SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = 'dbo' AND TABLE_NAME = 'Players')) BEGIN DROP TABLE Players; END");
		database.ExecuteSQL(SqlString);

		// Close the database
		database.Close();
		
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: " + e->m_strError);
	}
	END_CATCH;

}

CString Database::load() {
	//LOAD DATA
	CString loadingData;
	CDBVariant var;
	CString strNumber, strHistory;
	CString SqlString = _T("SELECT PlayerID, PlayerNumber, History FROM Players");

	TRY{
		// Open the database
		database.Open(NULL,false,false,sDsn);

		CRecordset recset(&database);
		recset.Open(CRecordset::forwardOnly, SqlString);

		while (!recset.IsEOF()) {
			// Copy each column into a variable
			recset.GetFieldValue(1, strNumber);
			recset.GetFieldValue(2, strHistory);

			loadingData += strNumber + _T("+") + strHistory + _T("+");
			// goto next record
			recset.MoveNext();
		}

		// Close the database
		database.Close();
		return loadingData;
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		return _T("No Data");
	}
	END_CATCH;

}