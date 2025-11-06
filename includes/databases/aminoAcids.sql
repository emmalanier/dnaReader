---------------------------------------
-- SQL DATABASE TO STORE AMINO ACIDS --
---------------------------------------

--TABLE CREATION--

CREATE TABLE if NOT EXISTS aminoAcids(
  aaAbr TEXT PRIMARY KEY,
  aaLetter TEXT,
  aaName TEXT,
  aaMoleculeId INTEGER,
  FOREIGN KEY (moleculeId) REFERENCES molecules(id)
);

INSERT INTO aminoAcids VALUES('Ala', 'A', ' ', 1);
INSERT INTO aminoAcids VALUES('Arg', 'R', ' ', 2);
INSERT INTO aminoAcids VALUES('Asn', 'N', ' ', 3);
INSERT INTO aminoAcids VALUES('Asp', 'D', ' ', 4);
INSERT INTO aminoAcids VALUES('Cys', 'C', ' ', 5);
INSERT INTO aminoAcids VALUES('Gln', 'Q', ' ', 6);
INSERT INTO aminoAcids VALUES('Glu', 'E', ' ', 7);
INSERT INTO aminoAcids VALUES('Gly', 'G', ' ', 8);
INSERT INTO aminoAcids VALUES('His', 'H', ' ', 9);
INSERT INTO aminoAcids VALUES('Ile', 'I', ' ', 10);
INSERT INTO aminoAcids VALUES('Leu', 'L', ' ', 11);
INSERT INTO aminoAcids VALUES('Lys', 'K', ' ', 12);
INSERT INTO aminoAcids VALUES('Met', 'M', ' ', 13);
INSERT INTO aminoAcids VALUES('Phe', 'F', ' ', 14);
INSERT INTO aminoAcids VALUES('Pro', 'P', ' ', 15);
INSERT INTO aminoAcids VALUES('Ser', 'S', ' ', 16);
INSERT INTO aminoAcids VALUES('Thr', 'T', ' ', 17);
INSERT INTO aminoAcids VALUES('Trp', 'W', ' ', 18);
INSERT INTO aminoAcids VALUES('Tyr', 'Y', ' ', 19);
INSERT INTO aminoAcids VALUES('Val', 'V', ' ', 20);