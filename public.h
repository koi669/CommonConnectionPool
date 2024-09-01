#pragma once

//存放：把这个项目的各个文件共享的 宏 类型，给其他源文件直接使用
#define LOG(str) \
	cout<<__FILE__<<":"<<__LINE__<<" "<<__TIMESTAMP__<<" : "<<str<<endl

