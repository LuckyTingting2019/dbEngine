
// Generated from Query.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"


namespace queryparser {


class  QueryLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, NUMERIC_LITERAL = 7, 
    STRING_LITERAL = 8, AND = 9, OR = 10, EQ = 11, NEQ = 12, LTEQ = 13, 
    LT = 14, GTEQ = 15, GT = 16, IS = 17, ADD = 18, SUB = 19, MUL = 20, 
    DIV = 21, SELECT = 22, FROM = 23, WHERE = 24, JOIN = 25, INNER = 26, 
    LEFT = 27, RIGHT = 28, NATURAL = 29, ON = 30, GROUP = 31, BY = 32, SUM = 33, 
    AVG = 34, COUNT = 35, MIN = 36, MAX = 37, Name = 38, WS = 39
  };

  QueryLexer(antlr4::CharStream *input);
  ~QueryLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace queryparser
