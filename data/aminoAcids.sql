---------------------------------------
-- SQL DATABASE TO STORE AMINO ACIDS --
---------------------------------------

--TABLE CREATION--

CREATE TABLE if NOT EXISTS amino_acids(
  aa_abbr TEXT PRIMARY KEY,
  aa_letter TEXT,
  aa_name TEXT,
  aa_molecule_id TEXT,
  FOREIGN KEY (aa_molecule_id) REFERENCES molecules(molecule_id)
);

INSERT INTO amino_acids VALUES('Ala', 'A', 'Alanine', 'aa_1');
INSERT INTO amino_acids VALUES('Arg', 'R', 'Arginine', 'aa_2');
INSERT INTO amino_acids VALUES('Asn', 'N', 'Aspargine', 'aa_3');
INSERT INTO amino_acids VALUES('Asp', 'D', 'Aspartate', 'aa_4');
INSERT INTO amino_acids VALUES('Cys', 'C', 'Cysteine', 'aa_5');
INSERT INTO amino_acids VALUES('Gln', 'Q', 'Glutamine', 'aa_6');
INSERT INTO amino_acids VALUES('Glu', 'E', 'Glutamate', 'aa_7');
INSERT INTO amino_acids VALUES('Gly', 'G', 'Glycine', 'aa_8');
INSERT INTO amino_acids VALUES('His', 'H', 'Histidine', 'aa_9');
INSERT INTO amino_acids VALUES('Ile', 'I', 'Isoleucine', 'aa_10');
INSERT INTO amino_acids VALUES('Leu', 'L', 'Leucine', 'aa_11');
INSERT INTO amino_acids VALUES('Lys', 'K', 'Lysine', 'aa_12');
INSERT INTO amino_acids VALUES('Met', 'M', 'Methionine', 'aa_13');
INSERT INTO amino_acids VALUES('Phe', 'F', 'Phenylalanine', 'aa_14');
INSERT INTO amino_acids VALUES('Pro', 'P', 'Proline', 'aa_15');
INSERT INTO amino_acids VALUES('Ser', 'S', 'Serine', 'aa_16');
INSERT INTO amino_acids VALUES('Thr', 'T', 'Threonine', 'aa_17');
INSERT INTO amino_acids VALUES('Trp', 'W', 'Tryptophane', 'aa_18');
INSERT INTO amino_acids VALUES('Tyr', 'Y', 'Tyrosine', 'aa_19');
INSERT INTO amino_acids VALUES('Val', 'V', 'Valine', 'aa_20');