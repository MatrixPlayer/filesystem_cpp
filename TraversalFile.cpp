
#ifdef WIN32
#include <io.h>
#else
#include <dirent.h>
#endif
#include "direct.h"

void readDirectory(const string& directoryName, vector<string>& filenames, bool addDirectoryName)
{
	filenames.clear();

#ifdef WIN32
	struct _finddata_t s_file;
	string str = directoryName + "\\*.*";

	intptr_t h_file = _findfirst(str.c_str(), &s_file);
	if (h_file != static_cast<intptr_t>(-1.0))
	{
		do
		{
			if (strcmp(".", s_file.name) == 0 || strcmp("..", s_file.name) == 0)
			{
				continue;
			}
			
			if (addDirectoryName)
				filenames.push_back(directoryName + "\\" + s_file.name);
			else
				filenames.push_back((string)s_file.name);
		} while (_findnext(h_file, &s_file) == 0);
	}
	_findclose(h_file);
#else
	DIR* dir = opendir(directoryName.c_str());
	if (dir != NULL)
	{
		struct dirent* dent;
		while ((dent = readdir(dir)) != NULL)
		{
			if (addDirectoryName)
				filenames.push_back(directoryName + "/" + string(dent->d_name));
			else
				filenames.push_back(string(dent->d_name));
		}
	}
#endif

	sort(filenames.begin(), filenames.end());
}

