import sqlite3
from sqlite3 import Error
def sql_connection():
    try:
        conn=sqlite3.connect('student.db')
        return conn
    except Error:
        print(Error)

def sql_table(conn):
    cursorObj=conn.cursor()
    # cursorObj.execute("CREATE TABLE STUDENT(student_id n(5),name char(30),course char(20),score decimal(5,2));")
    # cursorObj.executescript("""
    # INSERT INTO STUDENT VALUES(101,"john","mca",98.05);
    # INSERT INTO STUDENT VALUES(102,"lucky","cse",80.16);
    # INSERT INTO STUDENT VALUES(103,"ricky","eee",76.10);
    # INSERT INTO STUDENT VALUES(104,"doe","ece",86.52);
    # INSERT INTO STUDENT VALUES(105,"jessi","mech",91.75);
    # INSERT INTO STUDENT VALUES(106,"siva","civil",88.76);
    #  """)
    # conn.commit()
    cursorObj.execute("SELECT * FROM student")
    rows = cursorObj.fetchall()
    print("student details:")
    for x in rows:
        print(x)
    return cursorObj

# def update(conn):
#     cursorObj = conn.cursor()
#     print("\nupdate score 91.75 to 78.23 where id is 105:")
#     sql_update_query="""update student set score =78.23 where student_id=105"""
#     cursorObj.execute(sql_update_query)
#     conn.commit()
#     print("Records updated successfully")
#     cursorObj.execute("select * from student")
#     rows=cursorObj.fetchall()
#     print("\nAfter updating details:")
#     for x in rows:
#         print(x)

def delete(conn):
    cursorObj = conn.cursor()
    print("\n Delete student_id 105:")
    s_id = 105
    cursorObj.execute("""
        DELETE FROM student WHERE student_id=? """, (s_id,))
    conn.commit()
    cursorObj.execute("select * from student")
    rows = cursorObj.fetchall()
    print("\nafter updating details:")
     for x in rows:
         print(x)

def count(conn):
    cursorObj = conn.cursor()
    cursor = cursorObj.execute('select * from student;')
    print("\nNumber of records after inserting rows:")
    print(len(cursor.fetchall()))

sqlite3_conn=sql_connection()
sql_table(sqlite3_conn)
# update(sqlite3_conn)
delete(sqlite3_conn)
count(sqlite3_conn)
if(sqlite3_conn):
    sqlite3_conn.close()
    print("\n the sqlite connection is closed.")