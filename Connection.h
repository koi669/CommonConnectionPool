#pragma once
#include <string>
#include <mysql.h>
#include <ctime>
/*
实现MySQL数据库的操作
*/

using namespace std;
// 数据库操作类
class Connection
{

public:
	// 初始化数据库连接
	Connection();

	// 释放数据库连接资源
	~Connection();

	// 连接数据库
	bool connect(string ip, //IP地址
		unsigned short port, //端口号
		string user,//用户名
		string password,//密码
		string dbname);//数据库名

	// 更新操作 insert、delete、update
	bool update(string sql);
	// 查询操作 select
	MYSQL_RES* query(string sql);

	//刷新一下连接的起始的空闲时间点
	void refreshAliveTime() { _alivetime = clock(); }
	//返回存活的时间
	clock_t getAliveeTime() { return clock() - _alivetime; }
private:
	MYSQL* _conn; // 表示和MySQL Server的一条连接
	clock_t _alivetime;//记录空闲状态后的起始存活时间
};
