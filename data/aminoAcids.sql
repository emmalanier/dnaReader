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

INSERT INTO aminoAcids VALUES('Ala', 'A', 'Alanine', 'aa_1');
INSERT INTO aminoAcids VALUES('Arg', 'R', 'Arginine', 'aa_2');
INSERT INTO aminoAcids VALUES('Asn', 'N', 'Aspargine', 'aa_3');
INSERT INTO aminoAcids VALUES('Asp', 'D', 'Aspartate', 'aa_4');
INSERT INTO aminoAcids VALUES('Cys', 'C', 'Cysteine', 'aa_5');
INSERT INTO aminoAcids VALUES('Gln', 'Q', 'Glutamine', 'aa_6');
INSERT INTO aminoAcids VALUES('Glu', 'E', 'Glutamate', 'aa_7');
INSERT INTO aminoAcids VALUES('Gly', 'G', 'Glycine', 'aa_8');
INSERT INTO aminoAcids VALUES('His', 'H', 'Histidine', 'aa_9');
INSERT INTO aminoAcids VALUES('Ile', 'I', 'Isoleucine', 'aa_10');
INSERT INTO aminoAcids VALUES('Leu', 'L', 'Leucine', 'aa_11');
INSERT INTO aminoAcids VALUES('Lys', 'K', 'Lysine', 'aa_12');
INSERT INTO aminoAcids VALUES('Met', 'M', 'Methionine', 'aa_13');
INSERT INTO aminoAcids VALUES('Phe', 'F', 'Phenylalanine', 'aa_14');
INSERT INTO aminoAcids VALUES('Pro', 'P', 'Proline', 'aa_15');
INSERT INTO aminoAcids VALUES('Ser', 'S', 'Serine', 'aa_16');
INSERT INTO aminoAcids VALUES('Thr', 'T', 'Threonine', 'aa_17');
INSERT INTO aminoAcids VALUES('Trp', 'W', 'Tryptophane', 'aa_18');
INSERT INTO aminoAcids VALUES('Tyr', 'Y', 'Tyrosine', 'aa_19');
INSERT INTO aminoAcids VALUES('Val', 'V', 'Valine', 'aa_20');