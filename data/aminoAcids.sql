---------------------------------------
-- SQL DATABASE TO STORE AMINO ACIDS --
---------------------------------------

--TABLE CREATION--

CREATE TABLE if NOT EXISTS aminoAcids(
  aaAbbr TEXT PRIMARY KEY,
  aaLetter TEXT,
  aaName TEXT,
  aaMoleculeId TEXT,
  FOREIGN KEY (aaMoleculeId) REFERENCES molecules(moleculeId)
);

INSERT INTO aminoAcids VALUES('Ala', 'A', 'Alanine', 'aa1');
INSERT INTO aminoAcids VALUES('Arg', 'R', 'Arginine', 'aa2');
INSERT INTO aminoAcids VALUES('Asn', 'N', 'Aspargine', 'aa3');
INSERT INTO aminoAcids VALUES('Asp', 'D', 'Aspartate', 'aa4');
INSERT INTO aminoAcids VALUES('Cys', 'C', 'Cysteine', 'aa5');
INSERT INTO aminoAcids VALUES('Gln', 'Q', 'Glutamine', 'aa6');
INSERT INTO aminoAcids VALUES('Glu', 'E', 'Glutamate', 'aa7');
INSERT INTO aminoAcids VALUES('Gly', 'G', 'Glycine', 'aa8');
INSERT INTO aminoAcids VALUES('His', 'H', 'Histidine', 'aa9');
INSERT INTO aminoAcids VALUES('Ile', 'I', ' ', 'aa10');
INSERT INTO aminoAcids VALUES('Leu', 'L', 'Leucine', 'aa11');
INSERT INTO aminoAcids VALUES('Lys', 'K', 'Lysine', 'aa12');
INSERT INTO aminoAcids VALUES('Met', 'M', 'Methionine', 'aa13');
INSERT INTO aminoAcids VALUES('Phe', 'F', 'Phen', 'aa14');
INSERT INTO aminoAcids VALUES('Pro', 'P', 'Proline', 'aa15');
INSERT INTO aminoAcids VALUES('Ser', 'S', 'Serine', 'aa16');
INSERT INTO aminoAcids VALUES('Thr', 'T', 'Threonine', 'aa17');
INSERT INTO aminoAcids VALUES('Trp', 'W', 'Tryptophane', 'aa18');
INSERT INTO aminoAcids VALUES('Tyr', 'Y', 'Tyrosine', 'aa19');
INSERT INTO aminoAcids VALUES('Val', 'V', 'Valine', 'aa20');