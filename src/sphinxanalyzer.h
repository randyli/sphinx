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

#ifndef _sphinx_analyzer_
#define _sphinx_analyzer_

#include "sphinxstd.h"


namespace SphinxAnalyzer
{

struct SphToken {

	CSphString text;
	int pos;
	

};

class ISphAnalyzer
{
public:
    /// trivial ctor
                                    ISphAnalyzer() {}

    /// trivial dtor
    virtual                         ~ISphAnalyzer () {}

	// analyze a text
    virtual bool                Analyze ( const CSphString   & text, CSphVector &tokens) = 0;


};


class AnalyzerStandard : public  ISphAnalyzer {
public：

	virtual bool                Analyze ( const CSphString   & text, CSphVector<SphToken> &tokens);

};



#if USE_JIEBA
class AnalyzerJieba : public ISphAnalyzer {
	
};

#endif

}

#endif 
