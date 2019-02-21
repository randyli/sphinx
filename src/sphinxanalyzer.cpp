//
// $Id$
//

//
// Copyright (c) 2019, Randy
// Copyright (c) 2019, Sogou Technologies Inc
// All rights reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org/
//


#include "sphinxanalyzer.h"
namespace SphinxAnalyzer{


	bool AnalyzerStandard::Analyze(const CSphString & text, CSphVector < SphToken > & tokens){
			return true;
	}

}

int main(){

	SphinxAnalyzer::ISphAnalyzer* a = new SphinxAnalyzer::AnalyzerStandard();

	return 0;
}


