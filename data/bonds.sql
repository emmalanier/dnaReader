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

-- Amino group --

-- Benzyl group --

-- Carboxylic group --

-- Hydroxyl group --

-- Hydroxyphenyl group --

-- Imidazole ring --

-- Indolyl group --

-- Methylene group --

-- Methyl group --

-- Phenyl ring --

-- Primary amine --

-- Primary ketimine --

-- Pyrrolidinyl ring --

-- Secondary amine --

-- Thiol group --

-----------------------
-- AMINO ACIDS --
-----------------------

-- Alanine --

-- Arginine --

-- Aspargine --

-- Aspartate --

-- Cysteine --

-- Glutamine --

-- Glutamate --

-- Glycine --

-- Histidine --

-- Isoleucine --

-- Leucine --

-- Lysine --

-- Methionine --

-- Phenylalanine --

-- Proline --

-- Serine --

-- Threonine --

-- Tryptophane --

-- Tyrosine --

-- Valine --
