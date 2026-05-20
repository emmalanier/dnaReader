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