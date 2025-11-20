-------------------------------------
-- SQL DATABASE TO STORE MOLECULES --
-------------------------------------

CREATE TABLE if NOT EXISTS molecules(

  moleculeName TEXT PRIMARY KEY,
  moleculeId TEXT,
  buildInstructions TEXT

);

INSERT INTO molecules VALUES ('Alanine','','');
INSERT INTO molecules VALUES ('Arginine','','');
INSERT INTO molecules VALUES ('Asparagine','','');
INSERT INTO molecules VALUES ('Aspartate','','');
INSERT INTO molecules VALUES ('Cysteine','','');
INSERT INTO molecules VALUES ('Glutamate','','');
INSERT INTO molecules VALUES ('Glutamine','','');
INSERT INTO molecules VALUES ('Glycine','','');
INSERT INTO molecules VALUES ('Histidine','','');
INSERT INTO molecules VALUES ('Isoleucine','','');
INSERT INTO molecules VALUES ('Leucine','','');
INSERT INTO molecules VALUES ('Lysine','','');
INSERT INTO molecules VALUES ('Methionine','','');
INSERT INTO molecules VALUES ('Phenylalanine','','');
INSERT INTO molecules VALUES ('Proline','','');
INSERT INTO molecules VALUES('Serine', 'aa16', 'PF(C) ; AAAB(N, aa16_C_001, aa16_N_002) ; AAAB(H, aa16_N_002, aa16_H_003) ; AAAB(H, aa16_N_002, aa16_H_003) ; AAAB(C, aa16_C_001, aa16_C_002) ; AAAB(O, aa16_C_002, aa16_O_001) ; AAAB(0, aa16_C_002, aa16_O_002) ; AAAB(H, aa16_O_002, aa_16_H_004) ; AAAB(H, aa16_C_001, aa16_H_005) ; AAAB(C, aa16_C_001, aa16_C_003) ; AAAB(H, aa16_C_003, aa16_H_006) ; AAAB(H, aa16_C_003, aa16_H_007) ; AAAB(O, aa16_C_003, aa16_O_003) ; AAAB(H, aa16_O_003, aa16_H_008)');
INSERT INTO molecules VALUES ('Threonine','','');
INSERT INTO molecules VALUES ('Thryptophan','','');
INSERT INTO molecules VALUES ('Tyrosine','','');
INSERT INTO molecules VALUES ('Valine','','');