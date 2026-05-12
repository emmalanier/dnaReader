------------------------------------
-- SQL DATABASE TO STORE ELEMENTS --
------------------------------------

--TABLE CREATION--

CREATE TABLE if NOT EXISTS elements(
  elementSymbol TEXT PRIMARY KEY,
  elementName TEXT,
  atomicNumber INT,
  protonNumber INT,
  atomicRadius REAL,
  electronegativity DECIMAL
);


--ELEMENTS INSERTION--
INSERT INTO elements VALUES('H', 'Hydrogen', 1, 1, 53E-12, 2.20);
INSERT INTO elements VALUES('He', 'Helium', 2, 2, 31E-12, 0.0);
INSERT INTO elements VALUES('Li', 'Lithium', 3, 3, 167E-12, 0.98);
INSERT INTO elements VALUES('Be', 'Beryllium', 4, 4, 112E-12, 1.57);
INSERT INTO elements VALUES('B', 'Boron', 5, 5, 87E-12, 2.04);
INSERT INTO elements VALUES('C', 'Carbon', 6, 6, 67E-12, 2.55);
INSERT INTO elements VALUES('N', 'Nitrogen', 7, 7, 56E-12, 3.04);
INSERT INTO elements VALUES('O', 'Oxygen', 8, 8, 48E-12, 3.44);
INSERT INTO elements VALUES('F', 'Fluorine', 9, 9, 42E-12, 3.98);