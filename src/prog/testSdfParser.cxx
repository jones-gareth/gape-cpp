/*
 * sdfParser.cpp
 *
 *  Created on: May 17, 2014
 *      Author: Gareth Jones
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "../mol/Molecule.h"
#include "../util/Reporter.h"
#include "RocsSdfMolecule.h"

using namespace std;
using namespace GarethUtil;
using namespace GarethMol;
using namespace Difgape;

/**
 * Test routine for reading molecules
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
	assert(argc == 3);
	string inFile = string(argv[1]);
	string outFile = string(argv[2]);

	Reporter::setMinReportingLevel(Reporter::DETAIL);
	REPORT(Reporter::NORMAL) << "reading file " << inFile;

	vector<Molecule::MoleculePtr> mols = Molecule::readMoleculesFromFile(
			inFile);
	vector<RocsSdfMolecule::RocsSdfMoleculePtr> rocsSdfMols { };
	rocsSdfMols.reserve(mols.size());

	for (Molecule::MoleculePtr & mol : mols) {
		REPORT(Reporter::DETAIL) << "Processing mol " << mol->getName();
		RocsSdfMolecule::RocsSdfMoleculePtr rocsSdfMol =
				RocsSdfMolecule::RocsSdfMoleculePtr(new RocsSdfMolecule(mol));
		rocsSdfMols.push_back(rocsSdfMol);
	}


	REPORT(Reporter::DETAIL) << "Done";
	return 1;
}

