-- REF Function
-- An entity reference consists of the entity key and an entity set name. 
-- Because different entity sets can be based on the same entity type, a
-- particular entity key can appear in multiple entity sets. However, an
-- entity reference is always unique. If the input expression represents 
-- a persisted entity, a reference to this entity will be returned. If the
-- input expression is not a persisted entity, a null reference will be 
-- returned. If the property extraction operator (.) is used to access a 
-- property of an entity, the reference is automatically dereferenced. 
CREATE OR REPLACE TYPE CAR AS OBJECT(
    MFG VARCHAR(20),
    MODEL VARCHAR(10),
    PRICE NUMBER(10),
    AVERAGE NUMBER(3)
);
/
CREATE TABLE CARINFO_20B OF CAR;
 
INSERT INTO CARINFO_20B VALUES(CAR('DUCATI', '2.0', 5000, 10));
INSERT INTO CARINFO_20B VALUES(CAR('NANO', '3.0', 300, 50));
INSERT INTO CARINFO_20B VALUES(CAR('JAGUAR', '5.0', 300, 50));
INSERT INTO CARINFO_20B VALUES(CAR('LAMBORGHINI', '1.0', 5100, 50));
INSERT INTO CARINFO_20B VALUES(CAR('ROLLS ROYCE', '2.0', 5000, 10));
INSERT INTO CARINFO_20B VALUES(CAR('FERRARI', '2.0', 543000, 10));
INSERT INTO CARINFO_20B VALUES(CAR('BMW', '7.0', 523000, 10));

DESC CARINFO_20B;

SELECT REF(C) FROM CARINFO_20B C;