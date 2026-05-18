-------------------------------------
-- SQL DATABASE TO STORE MOLECULES --
-------------------------------------

CREATE TABLE if NOT EXISTS molecules(

  moleculeId TEXT PRIMARY KEY,
  components TEXT

);

-- Functional groups --

INSERT INTO molecules VALUES ('acetamide_group','(C_1 ; C) - (O_2 ; O) - (primary_amine_3 ; primary_amine)');

INSERT INTO molecules VALUES ('amino_group','(N_1 ; N) - (C_2 ; C) - (C_3 ; C)');

INSERT INTO molecules VALUES ('carboxylic_group','(C_1 ; C) - (O_2 ; O) - (O_3 ; O) - (H_4 ; H)');

INSERT INTO molecules VALUES ('methylene_group', '(C_1 ; C) - (H_2 ; H) - (H_3 ; H)');

INSERT INTO molecules VALUES ('methyl_group', '(C_1 ; C) - (H_2 ; H) - (H_3 ; H) - (H_4 ; H)');

INSERT INTO molecules VALUES ('primary_amine', '(N_1 ; N) - (H_2 ; H) - (H_3 ; H)');

INSERT INTO molecules VALUES ('primary_ketimine', '(C_1 ; C) - (N_2 ; N) - (H_3 ; H)');

INSERT INTO molecules VALUES ('secondary_amine', '(N_1 ; N) - (H_2 ; H)');

-- For optimization purposes, 'aa0' refers to the "head" of amino acids (ie amino group, carboxylic group, and alpha carbon) --
-- In this file, the amino acids molecules are considered to be in their standard chemical structures --

INSERT INTO molecules VALUES ('aa_0','(alpha_C_1 ; C) - (a_g_2 ; amino_group) - (c_g_3 ; carboxylic_group) - (H_4 ; H)');

INSERT INTO molecules VALUES ('aa_1','(head - aa_0) - (side_chain_1 ; methyl_group)');

INSERT INTO molecules VALUES ('aa_2','(head - aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; methylene_group) - (side_chain_3 ; methylene_group) - (side_chain_4 ; secondary_amine) - (side_chain_5 ; primary_ketimine) - (side_chain_6 ; primary_amine)');

INSERT INTO molecules VALUES ('aa_3','','', '', '');

INSERT INTO molecules VALUES ('aa_4','','', '', '');

INSERT INTO molecules VALUES ('aa_5','','', '', '');

INSERT INTO molecules VALUES ('aa_6','','', '', '');

INSERT INTO molecules VALUES ('aa_7','','', '', '');

INSERT INTO molecules VALUES ('aa_8','','', '', '');

INSERT INTO molecules VALUES ('aa_9','','', '', '');

INSERT INTO molecules VALUES ('aa_10','','', '', '');

INSERT INTO molecules VALUES ('aa_11','','', '', '');

INSERT INTO molecules VALUES ('aa_12','','', '', '');

INSERT INTO molecules VALUES ('aa_13','','', '', '');

INSERT INTO molecules VALUES ('aa_14','','', '', '');

INSERT INTO molecules VALUES ('aa_15','','', '', '');

INSERT INTO molecules VALUES ('aa_16','','', '', '');

INSERT INTO molecules VALUES ('aa_17','','', '', '');

INSERT INTO molecules VALUES ('aa_18','','', '', '');

INSERT INTO molecules VALUES ('aa_19','','', '', '');

INSERT INTO molecules VALUES ('aa_20','','', '', '');