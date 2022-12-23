-- DEREF returns the object reference of argument expr, where expr must return a REF to an object.
-- If you do not use this function in a query, then Oracle Database returns the object ID of the 
-- REF instead. The DEREF operator dereferences a reference value and produces the result of that
-- dereference. For example, if r is a reference of type ref<T>, Deref(r) is an expression of type
-- T that yields the entity referenced by r. If the reference value is null, or is dangling (that 
-- is, the target of the reference does not exist), the result of the DEREF operator is null.
CREATE OR REPLACE TYPE CAR_INFO AS OBJECT(
    MFG VARCHAR(20),
    MODEL VARCHAR(10),
    PRICE NUMBER(10),
    AVERAGE NUMBER(3)
);
/
CREATE TABLE CARINFOS_20B OF CAR_INFO;
 
INSERT INTO CARINFOS_20B VALUES(CAR_INFO('DUCATI', '2.0', 5000, 10));
INSERT INTO CARINFOS_20B VALUES(CAR_INFO('NANO', '3.0', 300, 50));
INSERT INTO CARINFOS_20B VALUES(CAR_INFO('JAGUAR', '5.0', 300, 50));
INSERT INTO CARINFOS_20B VALUES(CAR_INFO('LAMBORGHINI', '1.0', 5100, 50));
INSERT INTO CARINFOS_20B VALUES(CAR_INFO('ROLLS ROYCE', '2.0', 5000, 10));
INSERT INTO CARINFOS_20B VALUES(CAR_INFO('FERRARI', '2.0', 543000, 10));
INSERT INTO CARINFOS_20B VALUES(CAR_INFO('BMW', '7.0', 523000, 10));

CREATE TABLE CAR_OWNER_20B(
    OWNER_NAME VARCHAR2(20),
    VEHICAL REF CAR_INFO
);
INSERT INTO CAR_OWNER_20B 
    SELECT 'Krushna', REF(C) FROM CARINFOS_20B C WHERE MFG = 'DUCATI';
INSERT INTO CAR_OWNER_20B 
    SELECT 'RAM', REF(C) FROM CARINFOS_20B C WHERE MFG = 'BMW';
INSERT INTO CAR_OWNER_20B 
    SELECT 'SUMEET', REF(C) FROM CARINFOS_20B C WHERE MFG = 'ROLLS ROYCE';

SELECT OWNER_NAME, DEREF(C.VEHICAL) FROM CAR_OWNER_20B C;