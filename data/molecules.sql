-------------------------------------
-- SQL DATABASE TO STORE MOLECULES --
-------------------------------------

CREATE TABLE if NOT EXISTS molecules(

  molecule_id TEXT PRIMARY KEY,
  molecule_name TEXT,
  molecule_IUPAC TEXT,
  molecule_InChI TEXT,
  molecule_SMILES TEXT,
  molecule_formula TEXT
);

INSERT INTO molecules VALUES('aa_1', 'Alanine', '(2S)-2-aminopropanoic acid', 'InChI=1S/C3H7NO2/c1-2(4)3(5)6/h2H,4H2,1H3,(H,5,6)/t2-/m0/s1', 'C[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_2', 'Arginine', '(2S)-2-amino-5-(diaminomethylideneamino)pentanoic acid', 'InChI=1S/C6H14N4O2/c7-4(5(11)12)2-1-3-10-6(8)9/h4H,1-3,7H2,(H,11,12)(H4,8,9,10)/t4-/m0/s1', 'C(C[C@@H](C(=O)O)N)CN=C(N)N');
INSERT INTO molecules VALUES('aa_3', 'Aspargine', '(2S)-2,4-diamino-4-oxobutanoic acid', 'InChI=1S/C4H8N2O3/c5-2(4(8)9)1-3(6)7/h2H,1,5H2,(H2,6,7)(H,8,9)/t2-/m0/s1', 'C([C@@H](C(=O)O)N)C(=O)N');
INSERT INTO molecules VALUES('aa_4', 'Aspartate', '(2S)-2-aminobutanedioic acid', 'InChI=1S/C4H7NO4/c5-2(4(8)9)1-3(6)7/h2H,1,5H2,(H,6,7)(H,8,9)/t2-/m0/s1', 'C([C@@H](C(=O)O)N)C(=O)O');
INSERT INTO molecules VALUES('aa_5', 'Cysteine', '(2R)-2-amino-3-sulfanylpropanoic acid', 'InChI=1S/C3H7NO2S/c4-2(1-7)3(5)6/h2,7H,1,4H2,(H,5,6)/t2-/m0/s1', 'C([C@@H](C(=O)O)N)S');
INSERT INTO molecules VALUES('aa_6', 'Glutamine', '(2S)-2,5-diamino-5-oxopentanoic acid', 'InChI=1S/C5H10N2O3/c6-3(5(9)10)1-2-4(7)8/h3H,1-2,6H2,(H2,7,8)(H,9,10)/t3-/m0/s1', 'C(CC(=O)N)[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_7', 'Glutamate', '(2S)-2-aminopentanedioic acid', 'InChI=1S/C5H9NO4/c6-3(5(9)10)1-2-4(7)8/h3H,1-2,6H2,(H,7,8)(H,9,10)/t3-/m0/s1', 'C(CC(=O)O)[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_8', 'Glycine', '2-aminoacetic acid', 'InChI=1S/C2H5NO2/c3-1-2(4)5/h1,3H2,(H,4,5)', 'C(C(=O)O)N');
INSERT INTO molecules VALUES('aa_9', 'Histidine', '(2S)-2-amino-3-(1H-imidazol-5-yl)propanoic acid', 'InChI=1S/C6H9N3O2/c7-5(6(10)11)1-4-2-8-3-9-4/h2-3,5H,1,7H2,(H,8,9)(H,10,11)/t5-/m0/s1', 'C1=C(NC=N1)C[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_10', 'Isoleucine', '(2S,3S)-2-amino-3-methylpentanoic acid', 'InChI=1S/C6H13NO2/c1-3-4(2)5(7)6(8)9/h4-5H,3,7H2,1-2H3,(H,8,9)/t4-,5-/m0/s1', 'CC[C@H](C)[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_11', 'Leucine', '(2S)-2-amino-4-methylpentanoic acid', 'InChI=1S/C6H13NO2/c1-4(2)3-5(7)6(8)9/h4-5H,3,7H2,1-2H3,(H,8,9)/t5-/m0/s1', 'CC(C)C[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_12', 'Lysine', '(2S)-2,6-diaminohexanoic acid', 'InChI=1S/C6H14N2O2/c7-4-2-1-3-5(8)6(9)10/h5H,1-4,7-8H2,(H,9,10)/t5-/m0/s1', 'C(CCN)C[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_13', 'Methionine', '(2S)-2-amino-4-methylsulfanylbutanoic acid', 'InChI=1S/C5H11NO2S/c1-9-3-2-4(6)5(7)8/h4H,2-3,6H2,1H3,(H,7,8)/t4-/m0/s1', 'CSCC[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_14', 'Phenylalanine', '(2S)-2-amino-3-phenylpropanoic acid', 'InChI=1S/C9H11NO2/c10-8(9(11)12)6-7-4-2-1-3-5-7/h1-5,8H,6,10H2,(H,11,12)/t8-/m0/s1', 'C1=CC=C(C=C1)C[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_15', 'Proline', '4-methylphenol', 'InChI=1S/C7H8O/c1-6-2-4-7(8)5-3-6/h2-5,8H,1H3', 'CC1=CC=C(C=C1)O');
INSERT INTO molecules VALUES('aa_16', 'Serine', '(2S)-2-amino-3-hydroxypropanoic acid', 'InChI=1S/C3H7NO3/c4-2(1-5)3(6)7/h2,5H,1,4H2,(H,6,7)/t2-/m0/s1', 'C([C@@H](C(=O)O)N)O');
INSERT INTO molecules VALUES('aa_17', 'Threonine', '(2S,3R)-2-amino-3-hydroxybutanoic acid', 'InChI=1S/C4H9NO3/c1-2(6)3(5)4(7)8/h2-3,6H,5H2,1H3,(H,7,8)/t2-,3+/m1/s1', 'C[C@H]([C@@H](C(=O)O)N)O');
INSERT INTO molecules VALUES('aa_18', 'Tryptophane', '(2S)-2-amino-3-(1H-indol-3-yl)propanoic acid', 'InChI=1S/C11H12N2O2/c12-9(11(14)15)5-7-6-13-10-4-2-1-3-8(7)10/h1-4,6,9,13H,5,12H2,(H,14,15)/t9-/m0/s1', 'C1=CC=C2C(=C1)C(=CN2)C[C@@H](C(=O)O)N');
INSERT INTO molecules VALUES('aa_19', 'Tyrosine', '(2S)-2-amino-3-(4-hydroxyphenyl)propanoic acid', 'InChI=1S/C9H11NO3/c10-8(9(12)13)5-6-1-3-7(11)4-2-6/h1-4,8,11H,5,10H2,(H,12,13)/t8-/m0/s1', 'C1=CC(=CC=C1C[C@@H](C(=O)O)N)O');
INSERT INTO molecules VALUES('aa_20', 'Valine', '(2S)-2-amino-3-methylbutanoic acid', 'InChI=1S/C5H11NO2/c1-3(2)4(6)5(7)8/h3-4H,6H2,1-2H3,(H,7,8)/t4-/m0/s1', 'CC(C)[C@@H](C(=O)O)N');