#pragma once
#include <string>
#include<queue>
#include<mutex>
#include <atomic>
#include"Connection.h"
#include <thread>
#include <condition_variable>
#include <memory>
#include<functional>//����
using namespace std;

/*���ӳ�ģ��*/
class ConnectionPool
{
public:
	//��ȡ���ӳض���ʵ����
	static ConnectionPool* getConnectionPool();
	//���ⲿ�ṩ�ӿڣ������ӳ��л�ȡһ�����õĿ�������
	shared_ptr<Connection> getConnection();//����ָ���Զ������ͷŹ���
private:
	ConnectionPool();//����1 ���캯��˽�л�

	bool loadConfigFile();//�������ļ��м���������

	//�����ڶ������߳��У�ר�Ÿ�������������
	void produceConnectionTask();
	//����һ���µĶ�ʱ�̣߳�ɨ�賬��maxIdleTimeʱ��Ŀ������ӣ����ж�������ӻ���
	void scannerConnectionTask();


	string _ip;//mysql��ip��ַ
	unsigned short _port;//mysql�Ķ˿ں�3306
	string _username;//mysql��¼�û���
	string _password;//mysql��¼����
	string _dbname;//���ӵ����ݿ�����
	int _initSize;//���ӳصĳ�ʼ������
	int _maxSize;//���ӳص����������
	int _maxIdleTime;//���ӳ�������ʱ��
	int _connectionTimeout;//���ӳػ�ȡ���ӵĳ�ʱʱ��

	queue<Connection*>_connectionQue; //�洢mysql���ӵĶ���
	mutex _queueMutex;//ά�����Ӷ��е��̰߳�ȫ������
	atomic_int _connectionCnt;//��¼������������connection���ӵ�������
	condition_variable cv;//�������������������������̺߳����������̵߳�ͨ��
};