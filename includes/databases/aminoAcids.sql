---------------------------------------
-- SQL DATABASE TO STORE AMINO ACIDS --
---------------------------------------

--TABLE CREATION--

CREATE TABLE if NOT EXISTS aminoAcids(
  aaAbbr TEXT PRIMARY KEY,
  aaLetter TEXT,
  aaName TEXT,
  aaMoleculeId INTEGER,
  FOREIGN KEY (moleculeId) REFERENCES molecules(id)
);

INSERT INTO aminoAcids VALUES('Ala', 'A', 'Alanine', 1);
INSERT INTO aminoAcids VALUES('Arg', 'R', 'Arginine', 2);
INSERT INTO aminoAcids VALUES('Asn', 'N', 'Aspargine', 3);
INSERT INTO aminoAcids VALUES('Asp', 'D', 'Aspartate', 4);
INSERT INTO aminoAcids VALUES('Cys', 'C', 'Cysteine', 5);
INSERT INTO aminoAcids VALUES('Gln', 'Q', 'Glutamine', 6);
INSERT INTO aminoAcids VALUES('Glu', 'E', 'Glutamate', 7);
INSERT INTO aminoAcids VALUES('Gly', 'G', 'Glycine', 8);
INSERT INTO aminoAcids VALUES('His', 'H', 'Histidine', 9);
INSERT INTO aminoAcids VALUES('Ile', 'I', ' ', 10);
INSERT INTO aminoAcids VALUES('Leu', 'L', 'Leucine', 11);
INSERT INTO aminoAcids VALUES('Lys', 'K', 'Lysine', 12);
INSERT INTO aminoAcids VALUES('Met', 'M', 'Methionine', 13);
INSERT INTO aminoAcids VALUES('Phe', 'F', 'Phen', 14);
INSERT INTO aminoAcids VALUES('Pro', 'P', 'Proline', 15);
INSERT INTO aminoAcids VALUES('Ser', 'S', 'Serine', 16);
INSERT INTO aminoAcids VALUES('Thr', 'T', 'Threonine', 17);
INSERT INTO aminoAcids VALUES('Trp', 'W', 'Tryptophane', 18);
INSERT INTO aminoAcids VALUES('Tyr', 'Y', 'Tyrosine', 19);
INSERT INTO aminoAcids VALUES('Val', 'V', 'Valine', 20);