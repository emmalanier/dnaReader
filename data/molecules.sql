-------------------------------------
-- SQL DATABASE TO STORE MOLECULES --
-------------------------------------

CREATE TABLE if NOT EXISTS molecules(

  moleculeId TEXT PRIMARY KEY,
  components TEXT,

);

-- Functional groups --

INSERT INTO molecules VALUES ('amino_group','(N_1 ; N) - (C_2 ; C) - (C_3 ; C)');

INSERT INTO molecules VALUES ('carboxylic_group','(C_1 ; C) - (O_2 ; O) - (O_3 ; O) - (H_4 ; H)');

INSERT INTO molecules VALUES ('methylene_group', '(C_1 ; C) - (H_2 ; H) - (H_3 ; H)');

-- For optimization purposes, 'aa0' refers to the "head" of amino acids (ie amino group, carboxylic group, and alpha carbon) --
-- In this file, the amino acids molecules are considered to be in their standard chemical structures --

INSERT INTO molecules VALUES ('aa0','(alpha_C_1 ; C) - (a_g_1 ; amino_group) - (c_g_1 ; carboxylic_group)');

INSERT INTO molecules VALUES ('aa1','','', '', '');

INSERT INTO molecules VALUES ('aa2','','', '', '');

INSERT INTO molecules VALUES ('aa3','','', '', '');

INSERT INTO molecules VALUES ('aa4','','', '', '');

INSERT INTO molecules VALUES ('aa5','','', '', '');

INSERT INTO molecules VALUES ('aa6','','', '', '');

INSERT INTO molecules VALUES ('aa7','','', '', '');

INSERT INTO molecules VALUES ('aa8','','', '', '');

INSERT INTO molecules VALUES ('aa9','','', '', '');

INSERT INTO molecules VALUES ('aa10','','', '', '');

INSERT INTO molecules VALUES ('aa11','','', '', '');

INSERT INTO molecules VALUES ('aa12','','', '', '');

INSERT INTO molecules VALUES ('aa13','','', '', '');

INSERT INTO molecules VALUES ('aa14','','', '', '');

INSERT INTO molecules VALUES ('aa15','','', '', '');

INSERT INTO molecules VALUES ('aa16','','', '', '');

INSERT INTO molecules VALUES ('aa17','','', '', '');

INSERT INTO molecules VALUES ('aa18','','', '', '');

INSERT INTO molecules VALUES ('aa19','','', '', '');

INSERT INTO molecules VALUES ('aa20','','', '', '');