mysql root 密码:hsp

连接到mysql服务的指令：mysql -h 主机ip -P 端口 -u 用户名 -p密码      （p和密码之间没有空格）

mysql的原理：
MySQL的三层结构：
客户端、命令终端------> 通过端口连接（3306）：数据库（数据库管理系统（dbms）（数据库（数据类型：表等）））
普通表都是文件

mysql一些数据类型:
数值类型：
	（区分unsigned）整形： tinyint【1个字节】
	           smallint【2个字节】
                           mediumint【3个字节】
                           int 【4个字节】
                           bigint【8个字节】
	小数类型：float【单精度4个字节】
                                 double 【双精度8个字节】
                                 decimal【M,D】大小不确定
	文本类型（字符串类型）：
  				char 0-255
 				varchar 0-65535 0-2^16-1
				text 0-2^16-1
				longtext 0-2^32-1
	二进制数据类型：	blob 0-2^16-1
		  	longblob 0-2^32-1
	日期类型:	data [日期 年月日】
		time 【时间 时分秒】
		datetime【存放年月日 时分秒】
		timestamp【时间戳】            
                     	ye		







# SQL语句分类：

DDL:数据定义语句 creat 表，库
DML:数据操作语句 增加 insert 修改
DQL：数据查询语句 select
DCL：数据控制语句 管理数据库：比如用户权限 grant授予 revoke撤销

## 创建数据库指令：

CREATE DATABASE 数据库 CHARACTER SET 字符集 COLLATE 排序规则
创建时如果规避名称为关键字可以加反引号' '                                                                                                                                                                                    
数据库创建参数：
字符集，校验规则

## 删除数据库指令：

DROP DATABASE 数据库(慎重！！)

## 查询语句：

SELECT FROM 表名 WHERE NAME="" 查找表中名字为什么。。。的

## 分页查询

SELECT ... LIMIT START ROWS

从start+1行开始取，取出rows行，start从0开始算

## 多表查询

（笛卡尔集）在默认情况下，当两个表查询时，规则如下：

1.从第一张表中取出一行，与第二表的每一条（行）记录进行组合，得到多个记录，返回结果。

2.返回记录数，第一张表的行数*第二张表的行数。

3.写正确的过滤条件where 就能得到想要的结果

当要显示指定的某列名时，要加表.列 指定要的那一列

## 多表查询的自连接

自连接的特点：

1.把同一张表当作两张表使用

2.需要给表取别名，表名 表别名

3.列名不明确可以指定列的别名

## 多行子查询

SELECT deptno FROM emp WHERE ename=‘s’

SELECT * FROM emp WHERE deptno = （SELECT deptno FROM emp WHERE ename=‘s’）	

### ALL

SELECT  \`name\` FROM emp WHERE sal> ALL (SELECT sal FROM emp WHERE DEPTNO=30);

### ANY

SELECT  \`name\` FROM emp WHERE sal> ANY (SELECT sal FROM emp WHERE DEPTNO=30)





## 显示数据库语句

SHOW DATABASES        (S!!!!) 
SHOW CREATE DATABASE db01 查看前面创建的db01

## 创建表：

CREATE TABLE table_name
(
         field1  datatype,
          ......
)character set 字符集 collate 校对类型 engine 存储引擎
field: 列名 datatype：列数据类型
character set :如不指定则为所在数据库字符集
collate：校对规则 同上
engine ：存储引擎

## 显示表结构desc

DESC 表名

## 表操作

### 添加列

ALTER TABLE tablename 

​							·ADD image varchar(32)  NOT NULL DEFAULT ' '

​                             AFTER RESUME

### 修改列：

ALTER TABLE tablename 

​							MODIFY job varchar(32)  NOT NULL DEFAULT ' '

### 删除列：

ALTER TABLE tablename 

​						DROP job 

### 修改表名：

RENAME TABLE 表名 TO 新表名

修改字符集 ALTER TABLE 表名 CHARACTER SET 字符集

### 修改列名

ALTER TABLE 表名

​		CHANGE 列名 列名 VARCHAR(64) NOT NULL DEFAULT ' '

## 左右外连接

左边或者右边完全显示

表1 left join 表2

## 主键

PRIMARY KEY 

不能为空，且不能重复

一个表只能由一个主键但可以是复合主键（几个列共同组成）；

## NOT NULL

## UNIQUE

该列不能重复

## FOREIGN外键

外键约束只能定义在从表上，主表则必须具有主键约束或是unique约束，当定义外键约束后，要求外键列数据必须在主表的主键列存在或是为null

FOREIGN KEY(本表字段名)REFERENCES 主表名（主键名或是unique）

## 自增长

id INT PRIMARY KEY AUT0_INCREMENT

自增长的那一列插入数值时，为NULL因为它是自增长，自动赋值

自增长一般配合主键使用，但是也可以单独使用和，必须约束unique

自增长修饰的数据类型为整型

默认从1开始，但是如果想要自定义在后面=x；就可以

自增长也可以指定值不用自增长 并且之后会从指定的值开始 666 667

# 索引

## 索引的原理

二叉树

如果对表进行修改删除添加等操作，会对索引进行维护，对速度有影响。

## 创建索引

CREATE INDEX 索引名称 ON 表名（列名） 在表名的empno创建的索引

创建索引后 索引本身也会占用空间。

创建索引后，只对创建索引的列有效

## mysql索引类型

1.主键索引，主键自动为主索引

2.唯一索引 unique unique索引

3.普通索引 index 

4.全文索引 fulltext 

开发中考虑使用：全文搜索Solr 和 ElasticSearch （ES）

## 索引操作

添加唯一索引

CREATE UNIQUE INDEX id_index ON emp (id);

添加普通索引

CREATE INDEX id_index ON emp (id);

另一种方式

ALTER TABLE emp ADD INDEX id_index (id);

列的值不会重复使用唯一索引，否则普通索引

添加主键索引 ALTER INDEX emp ADD PRIMARY KEY (id)；

删除索引

DROP INDEX id_index ON t25

删除主键索引

ALTER TABLE emp DROP PRIMARY KEY;

修改索引 先删除，再添加新的索引。

查询索引

1.SHOW INDEX FROM emp

2.SHOW INDEXES FROM emp

3.SHOW KEYS FROM emp

4.DESC emp； KEY 为MUL 就是索引

## 索引使用时机

1.较频繁的作为查询条件字段应该创建索引

2.唯一性太差的字段不适合单独创建索引，

3.更新非常频繁的字段不适合

4.不会出现在WHERE子句中字段不该创建索引

# 事务

## 事务

事务用于保证数据的一致性。他由一组相关的dml(update，insert，delete)语句组成，该组的dml语句要么全部成功，要么全部失败。

## 事务和锁

当执行事务操作时，mysql会在表上加锁，防止其它用户改表的数据。这对用户来讲是非常重要的。

## 事务操作

start transaction 开始一个事务

savepoint x 设置保存点a 保存点可以多个

执行dml操作

rollback to x 回滚到b保存点，把这个点到b之间的dml操作全部撤销了

rollback  全部回滚，回到最开始

commit 提交事务提交事务之后，不能再回滚，并删除所有的保存点，所有的数据就正式生效。

回退保存点不能越级，回退到某个保存点后，这两个保存点之间的保存点全部会删除。

## 事务注意事项

1.如果不开始事务，默认情况下，dml操作是自动提交,不能回滚

2.如果开始一个事务，没有创建保存点，可以执行rollback，默认就是回退到事务开始的状态。

3.事务没有提交时，可以创建多个保存点。

4.没有事务提交时，可以回退到任意保存点。

5.mysql的事务机制需要innodb的存储引擎才可以使用，myisam不好使

6.开始一个事务，start transaction，或者set autocommit=off；

## mysql事务的隔离级别

### 概念

多个连接开启各自事务操作数据库中数据时，数据库系统要负责隔离操作，以保证各个连接在获取数据时的准确性。

### 出现状况

脏读：当一个事务读取另一个事务尚未提交的修改时

不可重复读：同一个查询在同一事务中多次进行，由于其他提交事务所做的**修改**或**删除**，每次返回不同的结果集，此时发生不可重复读

幻读：同一查询在同一事务中进行多次，由于其他提交事务所做的**插入**操作，每次返回不同的结果集，此时发生幻读。

### 事务隔离级别

mysql隔离级别定义了事务与事务之间的隔离程度



# CRUD 语句

## insert

INSERT INTO 表名 （列名）

VALUES （）；

创建表定义数据类型时，可以表明是否NOT NULL 意思是能不能为空，或者再继续添加一个NOT NULL DEFAULT 100不能为空如果为空就会添加为默认值100

## update

UPDATE 表名 SET 列名=；

把全部的列名为=的更改。

UPDATE XXX SET 列名= WHERE 列名= 把表中where后面列名为xxx的列名项更新

## delete

DELETE FROM 

WHERE 

## select

### SELECT (DISTINCT)是否去除重复 *|(列名) FROM

### 使用表达式对查询的列进行运算：

SELECT *|(列名|expression，...) FROM 表名

例：SELECT 'name' (english+chinese+math) FROM student;

### 在SELECT语句中可使用as语句

SELECT column_name AS 别名 from 表名；

例：SELECT 'name' (english+chinese+math) AS total_score FROM student;

### WHERE用法：

WHERE  =  >  后可接 AND  OR NOT 条件语句 BETWEEN...AND... 在某一区间 IN(set)显示在in列表中的值，例：in（100，200）  IS NULL 判断为空



### LIKE 

‘韩%’ 像姓韩的

like 

%表示0-多个任意字符

_表示单个任意字符



### ORDER BY 排序

SELECT  列名 FROM 表名 ORDER BY 列名 ASC|DESC 升序|降序

这个子句一般应该位于select的结尾

可以有两个order by 但是有顺序，先按第一个排然后第二个再排

## count

合计/统计函数

Count返回行的总数

SELECT COUNT(*) FROM 

COUNT(*)返回满足条件的记录的行数

COUNT(列)统计满足条件的某列有多少个，但是会排除为NULL

## SUM

一般使用在数值的列

## AVG

求平均

## MAX/MIN

返回满足where条件的一列的数值的平均值

## group by

分组

SELECT  FROM ... GROUP BY 按某分组来查询

BY 后面可以跟多个 比如部门和岗位即按几个标准来进行分组

### having（过滤）

SELECT AVG(sal) AS avg_sal，deptno

​           FROM  emp GRPUP BY 

​                                   HAVING avg_sal <2000；

# 函数

## 字符串相关函数

### CHARSET（str）

 返回字串字符集

### CONCAT （string2 [,.....]）

 连接字串 将多个列拼接成一列

SELECT CONCAT (ename，‘工作是’，job) FROM emp；

### INSTR (string，substring) 

返回substring在string中出现的位置，没有返回0

### UCASE (string)

转换成大写

### LCASE(string)

转为小写

### LEFT（sting，length）

从string的左边起取length个字符

### RIGHT

### LENGTH（string）

string的长度

### REPLACE(str，search_str，replace_str)

替换

### STRCMP(str1,str2)

比较 0 -1 

### SUBSTRING(str，position ，[length])

这里的字符串的首地址是1

从str开始从position开始，取length

### LTRIM(str) RTRIM(STR)TRIM(STR)

去除前面空格，去除后面空格，去除所有空格

## 数学函数

### ABS(num)

绝对值

### BIN（num）

十进制转二进制

### CELLING（number） 

向上取整，得到比num2小的最大整数

### CONV（number2，frombase，tobase）

进制转换

SELECT CONV(8,10,2) 

### FLOOR(NUM)

向下取整，比num小的最大整数。

### FORMAT(number，decimal_places)

保留小数部分，四舍五入

### HEX（num）

转十六进制

### LEAST(NUM,NUM)

求最小值

### MOD（num，除数）

求余

### RAND([seed]) 

返回随机数 范围在0《=v《=1.0

seed不为空时，这个值就固定了

## 日期相关函数

### CURRENT_DATE()

当前日期

### CURRENT_TIME()

当前时间

### CURRENT_TIMESTAMP()

当前的时间戳

### NOW()

当前时间

### DATE(datetime) 

返回日期时间 不返回时间

### DATE_ADD（date2，INTERVAL d_value d_type）

在date2中加上日期或者时间 

DATE_ADD(send_time,10,minutes) 加上10分钟

### YEAR MONTH DAY 

### YEAR(NOW()) 查看当前年

### unix_timestamp()

返回的是1970-1-1 到现在的秒数

### FROM_UNIXTIME()

把一个unix_timestamp（）秒数转换为指定格式的日起

### DATE_SUB （date2，INTERVAL d_value d_type)

在date2上减去一个时间

### DATEDIFF(date1，date2)

两个日期差

## 加密和系统函数

### USER()

查询当前用户 及ip地址

### DATEBASE()

查询当前使用的数据库名称

### MD5(str)

为字符串算出一个MD5 32的字符串，常用（用户密码）加密 

root密码是hsp->加密MD5->在数据库中存放的是加密后的密码

### PASSWORD(str)

加密函数

## 控制流程函数

### IF(EX1,EX2,EX3)

如果1为true返回2，false返回3

IF ( EX1 IS NULL)不是IF (EX1 == NULL)

### IFNULL（ex1，ex2）

如果ex1不为NULL，返回ex1，否则返回ex2

### CASE

SELECT CASE WHEN EX1 THEN EX2 WHEN EX3 THEN EX4..... ELSE EX5 END;

如果ex1为真返回ex2，。。。。最终如果都不是返回ex5



# 多表查询





# DOS命令

## 备份数据库

musqldump -u 用户名 -p -B 数据库1 数据库2 数据库n > 文件名.sql
musqldump -u 用户名 -p  数据库 表1 表2 表n > 文件名.sql  备份库的表

## 恢复数据库（注意 进入Mysql命令行再执行）

source .sql

​               

