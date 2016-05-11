/********************************************************
*功  能：文件操作类
*
*创建者：吴建平
*
*创建时间：2016/05/10
**********************************************************/
#ifndef __FILE__SYSTEM__H__
#define __FILE__SYSTEM__H__

class FileSys
{
public:
	FileSys(string strfilePath);

	string GetFileName();
	string GetFilePath();
	string GetExtension();
	vector<string> SplitStr(string strSep);

private:
	string m_filePath;
};



#endif //__FILE__SYSTEM__H__