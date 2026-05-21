-----------------------------------------
--SQL file for storing molecules' bonds--
-----------------------------------------

CREATE TABLE if NOT EXISTS bonds(
  bond_id TEXT PRIMARY KEY,
  bond_type TEXT,
  bond_element_1_id TEXT,
  bond_element_2_id TEXT,
  bond_molecule_id TEXT,
  FOREIGN KEY (bond_molecule_id) REFERENCES molecules(molecule_id)
);

-----------------------
-- FUNCTIONAL GROUPS --
------------------------

-- Acetamide group --
INSERT INTO bonds VALUES ('acetamide_b_1','double','C_1','O_2','acetamide_group');
INSERT INTO bonds VALUES ('acetamide_b_2','single','C_1','primary_amine_3','acetamide_group');

-- Benzyl group --
INSERT INTO bonds VALUES ('benzyl_b_1','single','m_g_1','p_r_2','benzyl_group');

-- Carboxylic group --
INSERT INTO bonds VALUES ('carboxylic_b_1','double','C_1','O_2','carboxylic_group');
INSERT INTO bonds VALUES ('carboxylic_b_2','single','C_1','O_3','carboxylic_group');
INSERT INTO bonds VALUES ('carboxylic_b_3','single','O_3','H_4','carboxylic_group');

-- Hydroxyl group --
INSERT INTO bonds VALUES ('hydroxyl_b_1','single','O_1','H_2','hydroxyl_group');

-- Hydroxyphenyl group --
INSERT INTO bonds VALUES ('','','','','');

-- Imidazole ring --
INSERT INTO bonds VALUES ('','','','','');

-- Indolyl group --
INSERT INTO bonds VALUES ('','','','','');

-- Methylene group --
INSERT INTO bonds VALUES ('','','','','');

-- Methyl group --
INSERT INTO bonds VALUES ('','','','','');

-- Phenyl ring --
INSERT INTO bonds VALUES ('','','','','');

-- Primary amine --
INSERT INTO bonds VALUES ('','','','','');

-- Primary ketimine --
INSERT INTO bonds VALUES ('','','','','');

-- Pyrrolidinyl ring --
INSERT INTO bonds VALUES ('','','','','');

-- Secondary amine --
INSERT INTO bonds VALUES ('','','','','');

-- Thiol group --
INSERT INTO bonds VALUES ('','','','','');

-----------------------
-- AMINO ACIDS --
-----------------------

-- Alanine --
INSERT INTO bonds VALUES ('','','','','');

-- Arginine --
INSERT INTO bonds VALUES ('','','','','');

-- Aspargine --
INSERT INTO bonds VALUES ('','','','','');

-- Aspartate --
INSERT INTO bonds VALUES ('','','','','');

-- Cysteine --
INSERT INTO bonds VALUES ('','','','','');

-- Glutamine --
INSERT INTO bonds VALUES ('','','','','');

-- Glutamate --
INSERT INTO bonds VALUES ('','','','','');

-- Glycine --
INSERT INTO bonds VALUES ('','','','','');

-- Histidine --
INSERT INTO bonds VALUES ('','','','','');

-- Isoleucine --
INSERT INTO bonds VALUES ('','','','','');

-- Leucine --
INSERT INTO bonds VALUES ('','','','','');

-- Lysine --
INSERT INTO bonds VALUES ('','','','','');

-- Methionine --
INSERT INTO bonds VALUES ('','','','','');

-- Phenylalanine --
INSERT INTO bonds VALUES ('','','','','');

-- Proline --
INSERT INTO bonds VALUES ('','','','','');

-- Serine --
INSERT INTO bonds VALUES ('','','','','');

-- Threonine --
INSERT INTO bonds VALUES ('','','','','');

-- Tryptophane --
INSERT INTO bonds VALUES ('','','','','');

-- Tyrosine --
INSERT INTO bonds VALUES ('','','','','');

-- Valine --
INSERT INTO bonds VALUES ('','','','','');
