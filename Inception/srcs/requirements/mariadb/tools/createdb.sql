CREATE DATABASE DQ;
CREATE USER 'dq'@'%' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON DQ.* TO 'dq'@'%';
FLUSH PRIVILEGES;

ALTER USER 'root'@'localhost' IDENTIFIED BY '12345';
