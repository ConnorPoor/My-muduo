#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <stdio.h>
#include <string>

// 文件指针封装类
class FileUtil {
public:
    explicit FileUtil(std::string& fileName);
    ~FileUtil();

    // 添加log消息到文件末尾
    void append(const char* data, size_t len);

    // 冲刷文件到磁盘
    void flush();

    // 返回已写字节数
    off_t writtenBytes() const { return writtenBytes_; }

private:    
    // 写数据到文件，由append()函数调用
    size_t write(const char* data, size_t len);

    FILE* fp_;                  // 文件指针
    char buffer_[64 * 1024];    // fp_的缓冲区
    off_t writtenBytes_;        // off_t用于指示文件的偏移量
};

#endif // FILE_UTIL_H