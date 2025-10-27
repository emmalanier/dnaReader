----------------------------------
--SQL DATABASE TO STORE ELEMENTS--
----------------------------------

CREATE TABLE elements(
  elementSymbol VARCHAR PRIMARY KEY,
  elementName VARCHAR,
  atomicNumber INT,
  protonNumber INT,
  atomicRadius DECIMAL,

);