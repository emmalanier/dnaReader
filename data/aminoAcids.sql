---------------------------------------
-- SQL DATABASE TO STORE AMINO ACIDS --
---------------------------------------

--TABLE CREATION--

CREATE TABLE if NOT EXISTS amino_acids(
  aa_abbr TEXT PRIMARY KEY,
  aa_letter TEXT,
  aa_name TEXT,
  aa_molecule_id TEXT,
  aa_IUPAC TEXT,
  aa_InChI TEXT,
  aa_SMILES TEXT,
  FOREIGN KEY (aa_molecule_id) REFERENCES molecules(molecule_id)
);

INSERT INTO amino_acids VALUES('Ala', 'A', 'Alanine', 'aa_1', '(2S)-2-aminopropanoic acid', 'InChI=1S/C3H7NO2/c1-2(4)3(5)6/h2H,4H2,1H3,(H,5,6)/t2-/m0/s1', 'C[C@@H](C(=O)O)N');
INSERT INTO amino_acids VALUES('Arg', 'R', 'Arginine', 'aa_2', '(2S)-2-amino-5-(diaminomethylideneamino)pentanoic acid', 'InChI=1S/C6H14N4O2/c7-4(5(11)12)2-1-3-10-6(8)9/h4H,1-3,7H2,(H,11,12)(H4,8,9,10)/t4-/m0/s1', 'C(C[C@@H](C(=O)O)N)CN=C(N)N');
INSERT INTO amino_acids VALUES('Asn', 'N', 'Aspargine', 'aa_3', '', '', '');
INSERT INTO amino_acids VALUES('Asp', 'D', 'Aspartate', 'aa_4', '', '', '');
INSERT INTO amino_acids VALUES('Cys', 'C', 'Cysteine', 'aa_5', '', '', '');
INSERT INTO amino_acids VALUES('Gln', 'Q', 'Glutamine', 'aa_6', '', '', '');
INSERT INTO amino_acids VALUES('Glu', 'E', 'Glutamate', 'aa_7', '', '', '');
INSERT INTO amino_acids VALUES('Gly', 'G', 'Glycine', 'aa_8', '', '', '');
INSERT INTO amino_acids VALUES('His', 'H', 'Histidine', 'aa_9', '', '', '');
INSERT INTO amino_acids VALUES('Ile', 'I', 'Isoleucine', 'aa_10', '', '', '');
INSERT INTO amino_acids VALUES('Leu', 'L', 'Leucine', 'aa_11', '', '', '');
INSERT INTO amino_acids VALUES('Lys', 'K', 'Lysine', 'aa_12', '', '', '');
INSERT INTO amino_acids VALUES('Met', 'M', 'Methionine', 'aa_13', '', '', '');
INSERT INTO amino_acids VALUES('Phe', 'F', 'Phenylalanine', 'aa_14', '', '', '');
INSERT INTO amino_acids VALUES('Pro', 'P', 'Proline', 'aa_15', '', '', '');
INSERT INTO amino_acids VALUES('Ser', 'S', 'Serine', 'aa_16', '', '', '');
INSERT INTO amino_acids VALUES('Thr', 'T', 'Threonine', 'aa_17', '', '', '');
INSERT INTO amino_acids VALUES('Trp', 'W', 'Tryptophane', 'aa_18', '', '', '');
INSERT INTO amino_acids VALUES('Tyr', 'Y', 'Tyrosine', 'aa_19', '', '', '');
INSERT INTO amino_acids VALUES('Val', 'V', 'Valine', 'aa_20', '', '', '');