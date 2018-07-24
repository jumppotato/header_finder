//
// Created by 王文轩 on 2018/7/24.
//

#ifndef HEADERFINDER_FILE_READER_HPP
#define HEADERFINDER_FILE_READER_HPP

#include <vector>
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

class FileReader {
public:
    void ex(){
        boost::filesystem::path path("/test/test1");   //初始化
        boost::filesystem::path old_cpath = boost::filesystem::current_path(); //取得当前程序所在文件夹
        std::cout << "old path : " << old_cpath << std::endl;
        boost::filesystem::path parent_path = old_cpath.parent_path();//取old_cpath的上一层父文件夹路径
        boost::filesystem::path file_path = old_cpath / "file"; //path支持重载/运算符
        std::cout << "path.filename : " << path.filename() << std::endl;
        if (boost::filesystem::exists(file_path))  //推断文件存在性
        {
            std::string strPath = file_path.string();
            int x = 1;
        } else {
            //文件夹不存在;
            boost::filesystem::create_directory(file_path);  //文件夹不存在。创建
        }
        bool bIsDirectory = boost::filesystem::is_directory(file_path); //推断file_path是否为文件夹
        boost::filesystem::recursive_directory_iterator beg_iter(file_path);
        boost::filesystem::recursive_directory_iterator end_iter;
        for (; beg_iter != end_iter; ++beg_iter) {
            if (boost::filesystem::is_directory(*beg_iter)) {
                continue;
            } else {
                std::string strPath = beg_iter->path().string();  //遍历出来的文件名称
                std::cout << strPath << std::endl;
            }
        }
        boost::filesystem::path new_file_path = file_path / "test.txt";
        if (boost::filesystem::is_regular_file(new_file_path))    //推断是否为普通文件
        {
            size_t sizefile = boost::filesystem::file_size(new_file_path);  //文件大小(字节)
            int x = 1;
        }
        boost::filesystem::remove(new_file_path);//删除文件new_file_path
    }
    static std::vector<std::string> GetAllFileName(const std::string &path) {
        using boost::filesystem::path;
        path dir(path);

    }


};


#endif //HEADERFINDER_FILE_READER_HPP
