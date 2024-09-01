#pragma once
#include <string>
#include <mysql.h>
#include <ctime>
/*
ʵ��MySQL���ݿ�Ĳ���
*/

using namespace std;
// ���ݿ������
class Connection
{

public:
	// ��ʼ�����ݿ�����
	Connection();

	// �ͷ����ݿ�������Դ
	~Connection();

	// �������ݿ�
	bool connect(string ip, //IP��ַ
		unsigned short port, //�˿ں�
		string user,//�û���
		string password,//����
		string dbname);//���ݿ���

	// ���²��� insert��delete��update
	bool update(string sql);
	// ��ѯ���� select
	MYSQL_RES* query(string sql);

	//ˢ��һ�����ӵ���ʼ�Ŀ���ʱ���
	void refreshAliveTime() { _alivetime = clock(); }
	//���ش���ʱ��
	clock_t getAliveeTime() { return clock() - _alivetime; }
private:
	MYSQL* _conn; // ��ʾ��MySQL Server��һ������
	clock_t _alivetime;//��¼����״̬�����ʼ���ʱ��
};
