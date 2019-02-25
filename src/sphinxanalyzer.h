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
#if USE_JIEBA
#include <cppjieba/Jieba.hpp>
#endif


namespace SphinxAnalyzer
{

enum TOKEN_TYPE{
	TOKEN_WORD, //commen word
	TOKEN_SENTENCE, //sentence boundary
	TOKEN_PARAGRAPH, //paragraph  boundary
	TOKEN_ZONE,  //zone type
	TOKEN_NUM
	
};

struct SphToken {

	CSphString text;
    int pos;
	TOKEN_TYPE type;
	
};

class ISphAnalyzer
{
public:
    /// trivial ctor
                                    ISphAnalyzer() {}

    /// trivial dtor
    virtual                         ~ISphAnalyzer () {}

	// analyze a text
    virtual bool                Analyze ( const CSphString   & text, CSphVector<SphToken> &tokens) = 0;


};


class AnalyzerStandard : public  ISphAnalyzer 
{
public:

	virtual bool                Analyze ( const CSphString   & text, CSphVector<SphToken> &tokens);
};


#if USE_JIEBA
struct JiebaConfig {
	CSphString DICT_PATH;
	CSphString HMM_PATH;
	CSphString USER_DICT_PATH;
	CSphString IDF_PATH;
	CSphString STOP_WORD_PATH;
};

class AnalyzerJieba : public ISphAnalyzer {
public:
	AnalyzerJieba(const JiebaConfig & config);
	~AnalyzerJieba();
	virtual bool                Analyze ( const CSphString   & text, CSphVector<SphToken> &tokens);
protected:
	cppjieba::Jieba*			  m_pJieba;
};

#endif

}

#endif 
