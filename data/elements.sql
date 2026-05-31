------------------------------------
-- SQL DATABASE TO STORE ELEMENTS --
------------------------------------

--TABLE CREATION--

CREATE TABLE if NOT EXISTS elements(
  element_symbol TEXT PRIMARY KEY,
  element_name TEXT,
  atomic_number INT,
  atomic_mass REAL,
  atomic_radius REAL,
  electronegativity DECIMAL,
  bonds_number INT
);

-- atomic mass in Daltons (u), other quantities in the usuals SI units
-- datas for atomic mass not entered yet

--ELEMENTS INSERTION--
INSERT INTO elements VALUES('H', 'Hydrogen', 1, 1, 53E-12, 2.20, 1);
INSERT INTO elements VALUES('He', 'Helium', 2, 2, 31E-12, 0.0, 0);
INSERT INTO elements VALUES('Li', 'Lithium', 3, 3, 167E-12, 0.98, 1);
INSERT INTO elements VALUES('Be', 'Beryllium', 4, 4, 112E-12, 1.57, 2);
INSERT INTO elements VALUES('B', 'Boron', 5, 5, 87E-12, 2.04, 3);
INSERT INTO elements VALUES('C', 'Carbon', 6, 6, 67E-12, 2.55, 4);
INSERT INTO elements VALUES('N', 'Nitrogen', 7, 7, 56E-12, 3.04, 3);
INSERT INTO elements VALUES('O', 'Oxygen', 8, 8, 48E-12, 3.44, 2);
INSERT INTO elements VALUES('F', 'Fluorine', 9, 9, 42E-12, 3.98, 1);