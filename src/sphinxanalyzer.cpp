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
using namespace std;
namespace SphinxAnalyzer{


	bool AnalyzerStandard::Analyze(const CSphString & text, CSphVector < SphToken > & tokens){
			return false;
	}


	bool AnalyzerStandard::AnalyzeQuery(const CSphString & query, CSphVector < SphToken > & tokens){
			return false;
	}

#if USE_JIEBA
	AnalyzerJieba::AnalyzerJieba(const JiebaConfig & config){
	this->m_pJieba = new cppjieba::Jieba(
		config.DICT_PATH.cstr(),
        config.HMM_PATH.cstr(),
        config.USER_DICT_PATH.cstr(),
        config.IDF_PATH.cstr(),
        config.STOP_WORD_PATH.cstr()
	);
	
	}

	AnalyzerJieba::~AnalyzerJieba(){
		if(this->m_pJieba) {
			delete this->m_pJieba;
		}
	}
	bool AnalyzerJieba::Analyze(const CSphString & text, CSphVector < SphToken > & tokens){

		if(!this->m_pJieba) return false;

		vector<string> words;
		string _text = text.cstr();
		this->m_pJieba->CutForSearch(_text, words);
		int pos = 0;
		for(vector<string>::iterator it=words.begin(); it!=words.end(); it++){
			SphToken token;
			token.text = it->c_str();
			token.pos = ++pos;
			token.type = TOKEN_WORD;
			tokens.Add(token);
		}
		return true;
	}
	bool AnalyzerJieba::AnalyzeQuery(const CSphString & query, CSphVector < SphToken > & tokens){

		return Analyze(query, tokens);
		
	}
#endif
}

