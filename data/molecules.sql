-------------------------------------
-- SQL DATABASE TO STORE MOLECULES --
-------------------------------------

CREATE TABLE if NOT EXISTS molecules(

  moleculeId TEXT PRIMARY KEY,
  component_local_id TEXT,
  component_id TEXT,
  atom_local_id TEXT,
  atom_id TEXT,
  FOREIGN KEY (atom_id) REFERENCES elements(elementSymbol)
  FOREIGN KEY (component_id) REFERENCES molecules(moleculeId)

);

-- For optimization purposes, 'aa0' refers to the "head" of amino acids (ie amino group, carboxylic group, and alpha carbon) --
-- In this file, the amino acids molecules are considered to be in their standard chemical structures --
INSERT INTO molecules VALUES ('amino_group','NULL','NULL', 'N_1', 'N');
INSERT INTO molecules VALUES ('amino_group','NULL','NULL', 'C_2', 'C');
INSERT INTO molecules VALUES ('amino_group','NULL','NULL', 'C_3', 'C');

INSERT INTO molecules VALUES ('aa0','NULL','NULL', 'alpha_C_1', 'C');
INSERT INTO molecules VALUES ('aa0','NULL','NULL', 'NULL', 'NULL');

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