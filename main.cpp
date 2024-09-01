#include "pch.h"
#include <iostream>
#include "Connection.h"
#include"CommonConnectionPool.h"

using namespace std;

int main()
{
    Connection conn;
    conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
   /*
   Connection conn;
    char sql[1024] = { 0 };
    sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
        "zhang san",20,"male");
    conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
    conn.update(sql);
    return 0;
   */ 

    //ConnectionPool* cp = ConnectionPool::getConnectionPool();
    //cp->loadConfigFile();

    clock_t begin = clock();
    //ConnectionPool* cp = ConnectionPool::getConnectionPool();
   
    thread t1([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        shared_ptr<Connection> sp = cp->getConnection();
        for (int i = 0; i < 250; ++i) {
            
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                "zhang san", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
            /*Connection conn;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                    "zhang san", 20, "male");
            conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
             conn.update(sql);*/
        }
        });
    thread t2([]() {
        
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        shared_ptr<Connection> sp = cp->getConnection();
        for (int i = 0; i < 250; ++i) {

            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                "zhang san", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
            /*Connection conn;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                "zhang san", 20, "male");
            conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
            conn.update(sql);*/
        }
        });
    thread t3([]() {
      
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        shared_ptr<Connection> sp = cp->getConnection();
        for (int i = 0; i < 250; ++i) {

            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                "zhang san", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
            /*Connection conn;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                "zhang san", 20, "male");
            conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
            conn.update(sql);*/
        }
        });

    thread t4([]() {
      
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        shared_ptr<Connection> sp = cp->getConnection();
        for (int i = 0; i < 250; ++i) {

            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                "zhang san", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
            /*Connection conn;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                "zhang san", 20, "male");
            conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
            conn.update(sql);*/
        }
        });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    clock_t end = clock();
    cout << (end - begin) << "ms" << endl;

#if 0
    for (int i = 0; i < 1000; ++i) {
        /*Connection conn;
        char sql[1024] = { 0 };
        sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
            "zhang san", 20, "male");
        conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
        conn.update(sql);*/

        /*  shared_ptr<Connection> sp = cp->getConnection();
          char sql[1024] = { 0 };
          sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
              "zhang san", 20, "male");
          sp->update(sql);*/
    }
#endif

    return 0;

}