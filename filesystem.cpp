#include "filesystem.h"


FileSys::FileSys(string strfilePath)
{
	m_filePath = strfilePath;
}

string FileSys::GetFileName()
{
	string strFileName;
	int iPos = m_filePath.find_last_of("\\");
	if (-1 == iPos)
	{
		return "";
	}
	strFileName = m_filePath.substr(iPos + 1);

	return strFileName;
}

string FileSys::GetFilePath()
{
	string strFilePath;
	int iPos = m_filePath.find_last_of("\\");
	if (-1 == iPos)
	{
		return "";
	}
	strFilePath = m_filePath.substr(0, iPos);

	return strFilePath;
}

string FileSys::GetExtension()
{
	string strExt;
	int iPos = m_filePath.find_last_of(".");
	if (-1 == iPos)
	{
		return "";
	}
	strExt = m_filePath.substr(iPos);

	return strExt;
}

vector<string> FileSys::SplitStr(string strSep)
{
	vector<string> strArr;
	string strCur = m_filePath;
	string strTmp;
	int iLen = strSep.size();

	int iPos = strCur.find(strSep);
	while (-1 != iPos)
	{
		strTmp = strCur.substr(0, iPos);
		strCur = strCur.substr(iPos + iLen);
		if ("" != strTmp)
		{
			strArr.push_back(strTmp);
		}
		iPos = strCur.find(strSep);
	}
	strArr.push_back(strCur);

	return strArr;
}

