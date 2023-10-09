/*
 * Copyright (c) 2015, 2019, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0, as
 * published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms,
 * as designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an
 * additional permission to link the program and your derivative works
 * with the separately licensed software that they have included with
 * MySQL.
 *
 * Without limiting anything contained in the foregoing, this file,
 * which is part of MySQL Connector/C++, is also subject to the
 * Universal FOSS Exception, version 1.0, a copy of which can be found at
 * http://oss.oracle.com/licenses/universal-foss-exception.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 */

#include <iostream>
#include <mysql/jdbc.h>
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>


using ::std::cout;
using ::std::endl;

using namespace std;

int main() {

    //创建一个MySQL连接对象
    sql::Driver* driver = get_driver_instance();
    sql::Connection* conn = driver->connect("tcp://127.0.0.1:3306", "root","");

    //通过连接对象创建一个MySQL-connector-C++的Statement对象
    sql::Statement* stmt = conn->createStatement();

    //设置返回值类型为匹配行数和生效行数
    stmt->setReturnRowType(sql::ReturnRowType::RETURN_ROW_MATCHED);

    // 执行update语句
    stmt->executeUpdate("UPDATE demo.test SET name='wayne1' WHERE id in (1,2)");

    //获取返回值
    cout << "affected " << stmt->getUpdateCount() << " rows " << endl;
    cout << "matched " << stmt->getMatchedRowCount() << " rows " << endl;

    //释放资源
    delete stmt;
    delete conn;

    return 0;
}