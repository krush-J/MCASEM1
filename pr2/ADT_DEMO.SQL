-- Abstract Data Types (ADT) -  By using abstract data types, which are user-defined types,
-- together with various routines, you can uniquely define and use data with complex structures
-- and perform operations on such data. When you define a column as having an abstract data type,
-- you can conceptualize and model its data based on object-oriented concepts. In addition, by 
-- applying object-oriented software development techniques, you can reduce the workload for 
-- database design, UAP development, and maintenance 

CREATE OR REPLACE TYPE NAME_20B AS OBJECT(
    FNAME VARCHAR(15),
    MNAME VARCHAR(15),
    LNAME VARCHAR(15)
);
/
CREATE OR REPLACE TYPE ADRESS_20B AS OBJECT(
    CITY VARCHAR(15),    
    STATE VARCHAR(15),
    PINCODE NUMBER(6)
);
/
CREATE TABLE CUSTOMER_20B(
    CUST_ID NUMBER(3) PRIMARY KEY,
    CUST_NAME NAME_20B,
    CUST_ADRESS ADRESS_20B
);
  
SET DESCRIBE DEPTH 2;
DESC CUSTOMER_20B;
 
INSERT INTO CUSTOMER_20B VALUES(12, NAME_20B('krushna', 'chandrakant', 'jadhav'), ADRESS_20B('latur', 'MH', 413512) );
INSERT INTO CUSTOMER_20B VALUES(13, NAME_20B('shree', 'vilas', 'phawade'), ADRESS_20B('latur', 'MH', 413512) );
INSERT INTO CUSTOMER_20B VALUES(14, NAME_20B('amit', 'balaji', 'sapte'), ADRESS_20B('latur', 'MH', 413512) );
INSERT INTO CUSTOMER_20B VALUES(15, NAME_20B('nayan', 'ramji', 'deshmukh'), ADRESS_20B('chhindwara', 'MP', 480334) );
INSERT INTO CUSTOMER_20B VALUES(16, NAME_20B('zyne', 'din', 'malik'), ADRESS_20B('jaypur', 'RJ', 413410) );
 
SELECT CUST_ID AS ID,CUST_NAME AS NAME,CUST_ADRESS AS ADRESS  FROM CUSTOMER_20B;