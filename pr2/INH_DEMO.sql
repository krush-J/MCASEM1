-- Inheritance in ORDBMS
-- Inheritance enables you to share attributes between objects such that a subclass inherits
-- attributes from its parent class. OracleAS TopLink provides several methods to preserve
-- inheritance relationships, and enables you to override mappings that are specified in a
-- superclass, or to map attributes that are not mapped in the superclass. Subclasses must
-- include the same database field (or fields) as the parent class for their primary key 
-- (although the primary key can have different names in these two tables). As a result, 
-- when you are mapping relationships to a subclass stored in a separate table, the subclass
-- table must include the parent table primary key, even if the subclass primary key differs
-- from the parent primary key. You can represent inheritance in the database in one of two ways:
--     Multiple tables that represent the parent class and each child class
--     A single table that comprises the parent and all child classes

DROP TABLE STUDENTS_20B;
DROP TYPE PERSON_20B FORCE;
DROP TYPE STUDENT_20B FORCE;
CREATE OR REPLACE TYPE PERSON_20B AS OBJECT(
    FNAME VARCHAR2(20),
    MNAME VARCHAR2(1),
    LNAME VARCHAR2(20),
    CONTACT NUMBER(10)
)
NOT FINAL;
/
CREATE OR REPLACE TYPE STUDENT_20B UNDER PERSON_20B(
    STUD_ID NUMBER(10),
    STUDE_DEPT VARCHAR2(10)
)
FINAL;
/
CREATE TABLE STUDENTS_20B OF STUDENT_20B;
DESC STUDENTS_20B;
INSERT INTO STUDENTS_20B VALUES('KRUSHNA', 'C', 'JADHAV', 9146472343, 26365, 'MCA');
INSERT INTO STUDENTS_20B VALUES('NAYAN', 'R', 'DESHMUKH', 9146938943, 34465, 'MCA');
INSERT INTO STUDENTS_20B VALUES('SHREE', 'V', 'PHAWADE', 9999472343, 26395, 'BTECH');
INSERT INTO STUDENTS_20B VALUES('KRUSHNA', 'P', 'KANDAKURE', 9896472343, 28365, 'BSC');
INSERT INTO STUDENTS_20B VALUES('SANTOSH', 'L', 'PHAWADE', 9146472343, 26395, 'MCA');
SELECT * FROM STUDENTS_20B;