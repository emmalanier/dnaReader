-------------------------------------
-- SQL DATABASE TO STORE MOLECULES --
-------------------------------------

CREATE TABLE if NOT EXISTS molecules(

  molecule_id TEXT PRIMARY KEY,
  components TEXT

);

-- Functional groups --

--INSERT INTO molecules VALUES ('acetamide_group','(C_1 ; C) - (O_1 ; O) - (primary_amine_1 ; primary_amine)');

--INSERT INTO molecules VALUES ('benzyl_group','(m_g_1 ; methylene_group) - (p_r_1 ; phenyl_ring)');

--INSERT INTO molecules VALUES ('carboxylic_group','(C_1 ; C) - (O_1_a ; O) - (O_1_b ; O) - (H_1_b ; H)');

--INSERT INTO molecules VALUES ('hydroxyl_group','(O_1 ; O) - (H_1 ; H)');

--INSERT INTO molecules VALUES ('hydroxyphenyl_group','(h_g_1 ; hydroxyl_group) - (C_2 ; C) - (C_3 ; C) - (H_4 ; H) - (C_5 ; C) - (H_6 ; H) - (C_7 ; C) - (C_8 ; C) - (H_9 ; H) - (C_10 ; C) - (H_11 ; H)');

--INSERT INTO molecules VALUES ('imidazole_ring','(N_1 ; N) - (H_2 ; H) - (C_3 ; C) - (H_4 ; H) - (C_5 ; C) - (N_6 ; N) - (C_7 ; C) - (H_8 ; H)');

--INSERT INTO molecules VALUES ('indolyl_group','(N_1 ; N) - (H_2 ; H) - (C_3 ; C) - (H_4 ; H) - (C_5 ; C) - (C_6 ; C) - (C_7 ; C) - (H_8 ; H) - (C_9 ; C) - (H_10 ; H) - (C_11 ; C) - (H_12 ; H) - (C_13 ; C) - (H_14 ; H) - (C_15 ; C)');

--INSERT INTO molecules VALUES ('methylene_group', '(C_1 ; C) - (H_2 ; H) - (H_3 ; H)');

--INSERT INTO molecules VALUES ('methyl_group', '(C_1 ; C) - (H_2 ; H) - (H_3 ; H) - (H_4 ; H)');

--INSERT INTO molecules VALUES ('phenyl_ring','(C_1 ; C) - (C_2 ; C) - (H_3 ; H) - (C_4 ; C) - (H_5 ; H) - (C_6 ; C) - (H_7 ; H) - (C_8 ; C) - (H_9 ; H) - (C_10 ; C) - (H_11 ; H)');

--INSERT INTO molecules VALUES ('primary_amine', '(N_1 ; N) - (H_2 ; H) - (H_3 ; H)');

--INSERT INTO molecules VALUES ('primary_ketimine', '(C_1 ; C) - (N_2 ; N) - (H_3 ; H)');

--INSERT INTO molecules VALUES ('pyrrolidinyl_ring','(s_a_1 ; secondary_amine) - (m_g_2 ; methylene_group) - (m_g_3 ; methylene_group) - (m_g_4 ; methylene_group) - (C_5 ; C) - (H_6 ; H)');

--INSERT INTO molecules VALUES ('secondary_amine', '(N_1 ; N) - (H_2 ; H)');

--INSERT INTO molecules VALUES ('thiol_group', '(S_1 ; S) - (H_2 ; H)');

-- For optimization purposes, 'aa0' refers to the "head" of amino acids (ie primary amine, carboxylic group, and alpha carbon) --
-- In this file, the amino acids molecules are considered to be in their standard chemical structures --

INSERT INTO molecules VALUES ('aa_0','(alpha_C_1 ; C) - (p_a_2 ; primary_amine) - (c_g_3 ; carboxylic_group) - (H_4 ; H)');

INSERT INTO molecules VALUES ('aa_1','(head ; aa_0) - (side_chain_1 ; methyl_group)');

INSERT INTO molecules VALUES ('aa_2','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; methylene_group) - (side_chain_3 ; methylene_group) - (side_chain_4 ; secondary_amine) - (side_chain_5 ; primary_ketimine) - (side_chain_6 ; primary_amine)');
  
INSERT INTO molecules VALUES ('aa_3','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; acetamide_group)');

INSERT INTO molecules VALUES ('aa_4','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; carboxylic_group)');

INSERT INTO molecules VALUES ('aa_5','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; thiol_group)');

INSERT INTO molecules VALUES ('aa_6','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; methylene_group) - (side_chain_3 ; carboxylic_group)');

INSERT INTO molecules VALUES ('aa_7','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; methylene_group) - (side_chain_3 ; acetamide_group)');

INSERT INTO molecules VALUES ('aa_8','(head ; aa_0) - (H_1 ; H)');

INSERT INTO molecules VALUES ('aa_9','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; imidazole_ring)');

INSERT INTO molecules VALUES ('aa_10','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; methyl_group) - (side_chain_3 ; methylene_group) - (side_chain_4 ; methyl_group)');

INSERT INTO molecules VALUES ('aa_11','(head ; aa_0) - (side_chain_1 ; methylene_group) - (C_2 ; C) - (H_3 ; H) - (side_chain_4 ; methyl_group) - (side_chain_5 ; methyl_group)');

INSERT INTO molecules VALUES ('aa_12','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; methylene_group) - (side_chain_3 ; methylene_group) - (side_chain_4 ; methylene_group) - (side_chain_5 ; primary_amine)');

INSERT INTO molecules VALUES ('aa_13','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; methylene_group) - (S_3 ; S) - (side_chain_4 ; methyl_group)');

INSERT INTO molecules VALUES ('aa_14','(head ; aa_0) - (side_chain_1 ; benzyl_group)');

INSERT INTO molecules VALUES ('aa_15','(c_g_1 ; carboxylic_group) - (pyr_r_2 ; pyrrolidinyl_ring)');

INSERT INTO molecules VALUES ('aa_16','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; hydroxyl_group)');

INSERT INTO molecules VALUES ('aa_17','(head ; aa_0) - (C_1 ; C) - (H_2 ; H) - (side_chain_3 ; hydroxyl_group) - (side_chain_4 ; methyl_group)');

INSERT INTO molecules VALUES ('aa_18','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; indolyl_group)');

INSERT INTO molecules VALUES ('aa_19','(head ; aa_0) - (side_chain_1 ; methylene_group) - (side_chain_2 ; hydroxyphenyl_group)');

INSERT INTO molecules VALUES ('aa_20','(head ; aa_0) - (H_1 ; H) - (C_2 ; C) - (H_3 ; H) - (side_chain_4 ; methyl_group) - (side_chain_5 ; methyl_group)');