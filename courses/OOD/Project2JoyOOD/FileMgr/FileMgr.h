#ifndef FILEMGR_H
#define FILEMGR_H

#include "FileSystem.h"
#include "../DataStore/DataStore.h"
#include <iostream>

class FileMgr
{
public:
  using iterator = DataStore::iterator;
  using patterns = std::vector<std::string>;

  FileMgr(const std::string& path, DataStore& ds) : path_(path), store_(ds)
  {
    patterns_.push_back("*.*");
  }

  void addPattern(const std::string& patt)
  {
    if (patterns_.size() == 1 && patterns_[0] == "*.*")
      patterns_.pop_back();
    patterns_.push_back(patt);
  }

  void search()
  {
	  if (path_[path_.length() - 1] == '\\')				// it will remove the trailing '\' in the provided file path
		  path_ = path_.substr(0, path_.length() - 1);

	  std::cout << "\n Searching for files in Path :" << path_;
	  std::cout << "\n\n File List";
	  std::cout << "\n =========";
	  find(path_);
	  std::cout << "\n\n";
  }

  void find(const std::string& path)
  {
    std::string fpath = FileSystem::Path::getFullFileSpec(path);
	std::cout << "\n  ++ " << fpath;
    
	for (auto patt : patterns_)  
    {                            
      std::vector<std::string> files = FileSystem::Directory::getFiles(fpath, patt);
	  
	  fpath = fpath + "\\";								// Add '\' at the end of the fpath since the datastore will
														// be storing will be concat of fpath and filename.
	  for (auto f : files)				
      {
        std::cout << "\n  --   " << f;
        store_.save(fpath+f);
      }
    }
    std::vector<std::string> dirs = FileSystem::Directory::getDirectories(fpath);
    for (auto d : dirs)
    {
      if (d == "." || d == "..")
        continue;
      std::string dpath = fpath + "\\" + d;  
      find(dpath);
    }
  }
private:
  std::string path_;
  DataStore& store_;
  patterns patterns_;
};

#endif
