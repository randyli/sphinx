#include "gtest/gtest.h"
#include "sphinxanalyzer.h"

using namespace SphinxAnalyzer;


class TokenizerTest : public ::testing::Test {
protected:



	virtual void SetUp() {
		
		JiebaConfig config;
		config.DICT_PATH = "/home/sphinx/sphinx/cppjieba/dict/jieba.dict.utf8";
		config.HMM_PATH = "/home/sphinx/sphinx/cppjieba/dict/hmm_model.utf8";
		config.USER_DICT_PATH = "/home/sphinx/sphinx/cppjieba/dict/user.dict.utf8";
		config.IDF_PATH = "/home/sphinx/sphinx/cppjieba/dict/idf.utf8";
		config.STOP_WORD_PATH = "/home/sphinx/sphinx/cppjieba/dict/stop_words.utf8";
		
		analyzer = new AnalyzerJieba(config); 
	}

	virtual void TearDown() {
		delete analyzer;
	}


	ISphAnalyzer* analyzer;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(TokenizerTest, SimpleEnglish) {
	CSphString text = "this is a test";
	CSphVector<SphToken> tokens;
	bool res = analyzer->Analyze(text, tokens);
	ASSERT_EQ(res, true);
	ASSERT_EQ((tokens[0].text == "this"), true);
	ASSERT_EQ(tokens[0].pos, 1);
}


TEST_F(TokenizerTest, UTF8Chinese) {
	CSphString text = "这是一个测试";
	CSphVector<SphToken> tokens;
	bool res = analyzer->Analyze(text, tokens);
	ASSERT_EQ(res, true);
	ASSERT_EQ((tokens[0].text == "这是"), true);
	ASSERT_EQ(tokens[0].pos, 1);
}


