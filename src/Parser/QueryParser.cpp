
// Generated from Query.g4 by ANTLR 4.7.2


#include "QueryListener.h"
#include "QueryVisitor.h"

#include "QueryParser.h"


using namespace antlrcpp;
using namespace queryparser;
using namespace antlr4;

QueryParser::QueryParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

QueryParser::~QueryParser() {
  delete _interpreter;
}

std::string QueryParser::getGrammarFileName() const {
  return "Query.g4";
}

const std::vector<std::string>& QueryParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& QueryParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Select_stmtContext ------------------------------------------------------------------

QueryParser::Select_stmtContext::Select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Select_stmtContext::SELECT() {
  return getToken(QueryParser::SELECT, 0);
}

QueryParser::ColumnsContext* QueryParser::Select_stmtContext::columns() {
  return getRuleContext<QueryParser::ColumnsContext>(0);
}

tree::TerminalNode* QueryParser::Select_stmtContext::FROM() {
  return getToken(QueryParser::FROM, 0);
}

QueryParser::RelationContext* QueryParser::Select_stmtContext::relation() {
  return getRuleContext<QueryParser::RelationContext>(0);
}

tree::TerminalNode* QueryParser::Select_stmtContext::WHERE() {
  return getToken(QueryParser::WHERE, 0);
}

QueryParser::ExprContext* QueryParser::Select_stmtContext::expr() {
  return getRuleContext<QueryParser::ExprContext>(0);
}

QueryParser::Group_byContext* QueryParser::Select_stmtContext::group_by() {
  return getRuleContext<QueryParser::Group_byContext>(0);
}


size_t QueryParser::Select_stmtContext::getRuleIndex() const {
  return QueryParser::RuleSelect_stmt;
}

void QueryParser::Select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_stmt(this);
}

void QueryParser::Select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_stmt(this);
}


antlrcpp::Any QueryParser::Select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitSelect_stmt(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Select_stmtContext* QueryParser::select_stmt() {
  Select_stmtContext *_localctx = _tracker.createInstance<Select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 0, QueryParser::RuleSelect_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(QueryParser::SELECT);
    setState(37);
    columns();
    setState(38);
    match(QueryParser::FROM);
    setState(39);
    relation(0);
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::WHERE) {
      setState(40);
      match(QueryParser::WHERE);
      setState(41);
      expr(0);
    }
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::GROUP) {
      setState(44);
      group_by();
    }
    setState(47);
    match(QueryParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnsContext ------------------------------------------------------------------

QueryParser::ColumnsContext::ColumnsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QueryParser::Column_aliasContext *> QueryParser::ColumnsContext::column_alias() {
  return getRuleContexts<QueryParser::Column_aliasContext>();
}

QueryParser::Column_aliasContext* QueryParser::ColumnsContext::column_alias(size_t i) {
  return getRuleContext<QueryParser::Column_aliasContext>(i);
}


size_t QueryParser::ColumnsContext::getRuleIndex() const {
  return QueryParser::RuleColumns;
}

void QueryParser::ColumnsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumns(this);
}

void QueryParser::ColumnsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumns(this);
}


antlrcpp::Any QueryParser::ColumnsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitColumns(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::ColumnsContext* QueryParser::columns() {
  ColumnsContext *_localctx = _tracker.createInstance<ColumnsContext>(_ctx, getState());
  enterRule(_localctx, 2, QueryParser::RuleColumns);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    column_alias();
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QueryParser::T__1) {
      setState(50);
      match(QueryParser::T__1);
      setState(51);
      column_alias();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_aliasContext ------------------------------------------------------------------

QueryParser::Column_aliasContext::Column_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::ExprContext* QueryParser::Column_aliasContext::expr() {
  return getRuleContext<QueryParser::ExprContext>(0);
}

tree::TerminalNode* QueryParser::Column_aliasContext::AS() {
  return getToken(QueryParser::AS, 0);
}

QueryParser::AliasContext* QueryParser::Column_aliasContext::alias() {
  return getRuleContext<QueryParser::AliasContext>(0);
}


size_t QueryParser::Column_aliasContext::getRuleIndex() const {
  return QueryParser::RuleColumn_alias;
}

void QueryParser::Column_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_alias(this);
}

void QueryParser::Column_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_alias(this);
}


antlrcpp::Any QueryParser::Column_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitColumn_alias(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Column_aliasContext* QueryParser::column_alias() {
  Column_aliasContext *_localctx = _tracker.createInstance<Column_aliasContext>(_ctx, getState());
  enterRule(_localctx, 4, QueryParser::RuleColumn_alias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    expr(0);
    setState(60);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::AS) {
      setState(58);
      match(QueryParser::AS);
      setState(59);
      alias();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnContext ------------------------------------------------------------------

QueryParser::ColumnContext::ColumnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::ColumnContext::MUL() {
  return getToken(QueryParser::MUL, 0);
}

QueryParser::TableContext* QueryParser::ColumnContext::table() {
  return getRuleContext<QueryParser::TableContext>(0);
}

tree::TerminalNode* QueryParser::ColumnContext::Name() {
  return getToken(QueryParser::Name, 0);
}


size_t QueryParser::ColumnContext::getRuleIndex() const {
  return QueryParser::RuleColumn;
}

void QueryParser::ColumnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn(this);
}

void QueryParser::ColumnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn(this);
}


antlrcpp::Any QueryParser::ColumnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitColumn(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::ColumnContext* QueryParser::column() {
  ColumnContext *_localctx = _tracker.createInstance<ColumnContext>(_ctx, getState());
  enterRule(_localctx, 6, QueryParser::RuleColumn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(72);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(62);
      match(QueryParser::MUL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(63);
      table();
      setState(64);
      match(QueryParser::T__2);
      setState(65);
      match(QueryParser::MUL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(67);
      match(QueryParser::Name);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(68);
      table();
      setState(69);
      match(QueryParser::T__2);
      setState(70);
      match(QueryParser::Name);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationContext ------------------------------------------------------------------

QueryParser::RelationContext::RelationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::TableContext* QueryParser::RelationContext::table() {
  return getRuleContext<QueryParser::TableContext>(0);
}

tree::TerminalNode* QueryParser::RelationContext::AS() {
  return getToken(QueryParser::AS, 0);
}

QueryParser::AliasContext* QueryParser::RelationContext::alias() {
  return getRuleContext<QueryParser::AliasContext>(0);
}

QueryParser::Select_stmtContext* QueryParser::RelationContext::select_stmt() {
  return getRuleContext<QueryParser::Select_stmtContext>(0);
}

std::vector<QueryParser::RelationContext *> QueryParser::RelationContext::relation() {
  return getRuleContexts<QueryParser::RelationContext>();
}

QueryParser::RelationContext* QueryParser::RelationContext::relation(size_t i) {
  return getRuleContext<QueryParser::RelationContext>(i);
}

QueryParser::Join_operatorContext* QueryParser::RelationContext::join_operator() {
  return getRuleContext<QueryParser::Join_operatorContext>(0);
}

QueryParser::Join_conditionContext* QueryParser::RelationContext::join_condition() {
  return getRuleContext<QueryParser::Join_conditionContext>(0);
}


size_t QueryParser::RelationContext::getRuleIndex() const {
  return QueryParser::RuleRelation;
}

void QueryParser::RelationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelation(this);
}

void QueryParser::RelationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelation(this);
}


antlrcpp::Any QueryParser::RelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitRelation(this);
  else
    return visitor->visitChildren(this);
}


QueryParser::RelationContext* QueryParser::relation() {
   return relation(0);
}

QueryParser::RelationContext* QueryParser::relation(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  QueryParser::RelationContext *_localctx = _tracker.createInstance<RelationContext>(_ctx, parentState);
  QueryParser::RelationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, QueryParser::RuleRelation, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::Name: {
        setState(75);
        table();
        setState(78);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          setState(76);
          match(QueryParser::AS);
          setState(77);
          alias();
          break;
        }

        }
        break;
      }

      case QueryParser::T__3: {
        setState(80);
        match(QueryParser::T__3);
        setState(81);
        select_stmt();
        setState(82);
        match(QueryParser::T__4);
        setState(85);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          setState(83);
          match(QueryParser::AS);
          setState(84);
          alias();
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(101);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelationContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelation);
        setState(89);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(90);
        join_operator();
        setState(91);
        relation(0);
        setState(93);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          setState(92);
          join_condition();
          break;
        }

        }
        setState(97);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          setState(95);
          match(QueryParser::AS);
          setState(96);
          alias();
          break;
        }

        } 
      }
      setState(103);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Join_operatorContext ------------------------------------------------------------------

QueryParser::Join_operatorContext::Join_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::Join_typeContext* QueryParser::Join_operatorContext::join_type() {
  return getRuleContext<QueryParser::Join_typeContext>(0);
}

tree::TerminalNode* QueryParser::Join_operatorContext::JOIN() {
  return getToken(QueryParser::JOIN, 0);
}


size_t QueryParser::Join_operatorContext::getRuleIndex() const {
  return QueryParser::RuleJoin_operator;
}

void QueryParser::Join_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_operator(this);
}

void QueryParser::Join_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_operator(this);
}


antlrcpp::Any QueryParser::Join_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitJoin_operator(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Join_operatorContext* QueryParser::join_operator() {
  Join_operatorContext *_localctx = _tracker.createInstance<Join_operatorContext>(_ctx, getState());
  enterRule(_localctx, 10, QueryParser::RuleJoin_operator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    join_type();
    setState(105);
    match(QueryParser::JOIN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_conditionContext ------------------------------------------------------------------

QueryParser::Join_conditionContext::Join_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Join_conditionContext::ON() {
  return getToken(QueryParser::ON, 0);
}

QueryParser::ExprContext* QueryParser::Join_conditionContext::expr() {
  return getRuleContext<QueryParser::ExprContext>(0);
}


size_t QueryParser::Join_conditionContext::getRuleIndex() const {
  return QueryParser::RuleJoin_condition;
}

void QueryParser::Join_conditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_condition(this);
}

void QueryParser::Join_conditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_condition(this);
}


antlrcpp::Any QueryParser::Join_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitJoin_condition(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Join_conditionContext* QueryParser::join_condition() {
  Join_conditionContext *_localctx = _tracker.createInstance<Join_conditionContext>(_ctx, getState());
  enterRule(_localctx, 12, QueryParser::RuleJoin_condition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(QueryParser::ON);
    setState(108);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_typeContext ------------------------------------------------------------------

QueryParser::Join_typeContext::Join_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Join_typeContext::INNER() {
  return getToken(QueryParser::INNER, 0);
}

tree::TerminalNode* QueryParser::Join_typeContext::LEFT() {
  return getToken(QueryParser::LEFT, 0);
}

tree::TerminalNode* QueryParser::Join_typeContext::RIGHT() {
  return getToken(QueryParser::RIGHT, 0);
}

tree::TerminalNode* QueryParser::Join_typeContext::NATURAL() {
  return getToken(QueryParser::NATURAL, 0);
}


size_t QueryParser::Join_typeContext::getRuleIndex() const {
  return QueryParser::RuleJoin_type;
}

void QueryParser::Join_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_type(this);
}

void QueryParser::Join_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_type(this);
}


antlrcpp::Any QueryParser::Join_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitJoin_type(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Join_typeContext* QueryParser::join_type() {
  Join_typeContext *_localctx = _tracker.createInstance<Join_typeContext>(_ctx, getState());
  enterRule(_localctx, 14, QueryParser::RuleJoin_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QueryParser::INNER)
      | (1ULL << QueryParser::LEFT)
      | (1ULL << QueryParser::RIGHT)
      | (1ULL << QueryParser::NATURAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableContext ------------------------------------------------------------------

QueryParser::TableContext::TableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::TableContext::Name() {
  return getToken(QueryParser::Name, 0);
}


size_t QueryParser::TableContext::getRuleIndex() const {
  return QueryParser::RuleTable;
}

void QueryParser::TableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable(this);
}

void QueryParser::TableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable(this);
}


antlrcpp::Any QueryParser::TableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitTable(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::TableContext* QueryParser::table() {
  TableContext *_localctx = _tracker.createInstance<TableContext>(_ctx, getState());
  enterRule(_localctx, 16, QueryParser::RuleTable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    match(QueryParser::Name);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasContext ------------------------------------------------------------------

QueryParser::AliasContext::AliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::AliasContext::Name() {
  return getToken(QueryParser::Name, 0);
}


size_t QueryParser::AliasContext::getRuleIndex() const {
  return QueryParser::RuleAlias;
}

void QueryParser::AliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlias(this);
}

void QueryParser::AliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlias(this);
}


antlrcpp::Any QueryParser::AliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitAlias(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::AliasContext* QueryParser::alias() {
  AliasContext *_localctx = _tracker.createInstance<AliasContext>(_ctx, getState());
  enterRule(_localctx, 18, QueryParser::RuleAlias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(QueryParser::Name);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

QueryParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::Literal_valueContext* QueryParser::ExprContext::literal_value() {
  return getRuleContext<QueryParser::Literal_valueContext>(0);
}

QueryParser::ColumnContext* QueryParser::ExprContext::column() {
  return getRuleContext<QueryParser::ColumnContext>(0);
}

QueryParser::FunctionContext* QueryParser::ExprContext::function() {
  return getRuleContext<QueryParser::FunctionContext>(0);
}

std::vector<QueryParser::ExprContext *> QueryParser::ExprContext::expr() {
  return getRuleContexts<QueryParser::ExprContext>();
}

QueryParser::ExprContext* QueryParser::ExprContext::expr(size_t i) {
  return getRuleContext<QueryParser::ExprContext>(i);
}

QueryParser::Mul_divContext* QueryParser::ExprContext::mul_div() {
  return getRuleContext<QueryParser::Mul_divContext>(0);
}

QueryParser::Add_subContext* QueryParser::ExprContext::add_sub() {
  return getRuleContext<QueryParser::Add_subContext>(0);
}

QueryParser::Compare_operatorContext* QueryParser::ExprContext::compare_operator() {
  return getRuleContext<QueryParser::Compare_operatorContext>(0);
}

tree::TerminalNode* QueryParser::ExprContext::AND() {
  return getToken(QueryParser::AND, 0);
}

tree::TerminalNode* QueryParser::ExprContext::OR() {
  return getToken(QueryParser::OR, 0);
}


size_t QueryParser::ExprContext::getRuleIndex() const {
  return QueryParser::RuleExpr;
}

void QueryParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void QueryParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any QueryParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


QueryParser::ExprContext* QueryParser::expr() {
   return expr(0);
}

QueryParser::ExprContext* QueryParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  QueryParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  QueryParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, QueryParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(120);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::T__5:
      case QueryParser::NUMERIC_LITERAL:
      case QueryParser::STRING_LITERAL: {
        setState(117);
        literal_value();
        break;
      }

      case QueryParser::MUL:
      case QueryParser::Name: {
        setState(118);
        column();
        break;
      }

      case QueryParser::T__3:
      case QueryParser::SUM:
      case QueryParser::AVG:
      case QueryParser::COUNT:
      case QueryParser::MIN:
      case QueryParser::MAX: {
        setState(119);
        function();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(142);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(140);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(122);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(123);
          mul_div();
          setState(124);
          expr(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(126);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(127);
          add_sub();
          setState(128);
          expr(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(130);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(131);
          compare_operator();
          setState(132);
          expr(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(134);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(135);
          match(QueryParser::AND);
          setState(136);
          expr(4);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(137);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(138);
          match(QueryParser::OR);
          setState(139);
          expr(3);
          break;
        }

        } 
      }
      setState(144);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Mul_divContext ------------------------------------------------------------------

QueryParser::Mul_divContext::Mul_divContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Mul_divContext::MUL() {
  return getToken(QueryParser::MUL, 0);
}

tree::TerminalNode* QueryParser::Mul_divContext::DIV() {
  return getToken(QueryParser::DIV, 0);
}


size_t QueryParser::Mul_divContext::getRuleIndex() const {
  return QueryParser::RuleMul_div;
}

void QueryParser::Mul_divContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMul_div(this);
}

void QueryParser::Mul_divContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMul_div(this);
}


antlrcpp::Any QueryParser::Mul_divContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitMul_div(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Mul_divContext* QueryParser::mul_div() {
  Mul_divContext *_localctx = _tracker.createInstance<Mul_divContext>(_ctx, getState());
  enterRule(_localctx, 22, QueryParser::RuleMul_div);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    _la = _input->LA(1);
    if (!(_la == QueryParser::MUL

    || _la == QueryParser::DIV)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Add_subContext ------------------------------------------------------------------

QueryParser::Add_subContext::Add_subContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Add_subContext::ADD() {
  return getToken(QueryParser::ADD, 0);
}

tree::TerminalNode* QueryParser::Add_subContext::SUB() {
  return getToken(QueryParser::SUB, 0);
}


size_t QueryParser::Add_subContext::getRuleIndex() const {
  return QueryParser::RuleAdd_sub;
}

void QueryParser::Add_subContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd_sub(this);
}

void QueryParser::Add_subContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd_sub(this);
}


antlrcpp::Any QueryParser::Add_subContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitAdd_sub(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Add_subContext* QueryParser::add_sub() {
  Add_subContext *_localctx = _tracker.createInstance<Add_subContext>(_ctx, getState());
  enterRule(_localctx, 24, QueryParser::RuleAdd_sub);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    _la = _input->LA(1);
    if (!(_la == QueryParser::ADD

    || _la == QueryParser::SUB)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

QueryParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::Function_nameContext* QueryParser::FunctionContext::function_name() {
  return getRuleContext<QueryParser::Function_nameContext>(0);
}

std::vector<QueryParser::ExprContext *> QueryParser::FunctionContext::expr() {
  return getRuleContexts<QueryParser::ExprContext>();
}

QueryParser::ExprContext* QueryParser::FunctionContext::expr(size_t i) {
  return getRuleContext<QueryParser::ExprContext>(i);
}


size_t QueryParser::FunctionContext::getRuleIndex() const {
  return QueryParser::RuleFunction;
}

void QueryParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void QueryParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


antlrcpp::Any QueryParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::FunctionContext* QueryParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 26, QueryParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::SUM:
      case QueryParser::AVG:
      case QueryParser::COUNT:
      case QueryParser::MIN:
      case QueryParser::MAX: {
        enterOuterAlt(_localctx, 1);
        setState(149);
        function_name();

        setState(150);
        match(QueryParser::T__3);
        setState(151);
        expr(0);
        setState(156);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == QueryParser::T__1) {
          setState(152);
          match(QueryParser::T__1);
          setState(153);
          expr(0);
          setState(158);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(159);
        match(QueryParser::T__4);
        break;
      }

      case QueryParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(161);
        match(QueryParser::T__3);
        setState(162);
        match(QueryParser::T__4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

QueryParser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Function_nameContext::SUM() {
  return getToken(QueryParser::SUM, 0);
}

tree::TerminalNode* QueryParser::Function_nameContext::AVG() {
  return getToken(QueryParser::AVG, 0);
}

tree::TerminalNode* QueryParser::Function_nameContext::COUNT() {
  return getToken(QueryParser::COUNT, 0);
}

tree::TerminalNode* QueryParser::Function_nameContext::MIN() {
  return getToken(QueryParser::MIN, 0);
}

tree::TerminalNode* QueryParser::Function_nameContext::MAX() {
  return getToken(QueryParser::MAX, 0);
}


size_t QueryParser::Function_nameContext::getRuleIndex() const {
  return QueryParser::RuleFunction_name;
}

void QueryParser::Function_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_name(this);
}

void QueryParser::Function_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_name(this);
}


antlrcpp::Any QueryParser::Function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitFunction_name(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Function_nameContext* QueryParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 28, QueryParser::RuleFunction_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QueryParser::SUM)
      | (1ULL << QueryParser::AVG)
      | (1ULL << QueryParser::COUNT)
      | (1ULL << QueryParser::MIN)
      | (1ULL << QueryParser::MAX))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compare_operatorContext ------------------------------------------------------------------

QueryParser::Compare_operatorContext::Compare_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Compare_operatorContext::GTEQ() {
  return getToken(QueryParser::GTEQ, 0);
}

tree::TerminalNode* QueryParser::Compare_operatorContext::NEQ() {
  return getToken(QueryParser::NEQ, 0);
}

tree::TerminalNode* QueryParser::Compare_operatorContext::EQ() {
  return getToken(QueryParser::EQ, 0);
}

tree::TerminalNode* QueryParser::Compare_operatorContext::GT() {
  return getToken(QueryParser::GT, 0);
}

tree::TerminalNode* QueryParser::Compare_operatorContext::LTEQ() {
  return getToken(QueryParser::LTEQ, 0);
}

tree::TerminalNode* QueryParser::Compare_operatorContext::LT() {
  return getToken(QueryParser::LT, 0);
}

tree::TerminalNode* QueryParser::Compare_operatorContext::IS() {
  return getToken(QueryParser::IS, 0);
}


size_t QueryParser::Compare_operatorContext::getRuleIndex() const {
  return QueryParser::RuleCompare_operator;
}

void QueryParser::Compare_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompare_operator(this);
}

void QueryParser::Compare_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompare_operator(this);
}


antlrcpp::Any QueryParser::Compare_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitCompare_operator(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Compare_operatorContext* QueryParser::compare_operator() {
  Compare_operatorContext *_localctx = _tracker.createInstance<Compare_operatorContext>(_ctx, getState());
  enterRule(_localctx, 30, QueryParser::RuleCompare_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QueryParser::EQ)
      | (1ULL << QueryParser::NEQ)
      | (1ULL << QueryParser::LTEQ)
      | (1ULL << QueryParser::LT)
      | (1ULL << QueryParser::GTEQ)
      | (1ULL << QueryParser::GT)
      | (1ULL << QueryParser::IS))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Literal_valueContext ------------------------------------------------------------------

QueryParser::Literal_valueContext::Literal_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Literal_valueContext::NUMERIC_LITERAL() {
  return getToken(QueryParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* QueryParser::Literal_valueContext::STRING_LITERAL() {
  return getToken(QueryParser::STRING_LITERAL, 0);
}


size_t QueryParser::Literal_valueContext::getRuleIndex() const {
  return QueryParser::RuleLiteral_value;
}

void QueryParser::Literal_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral_value(this);
}

void QueryParser::Literal_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral_value(this);
}


antlrcpp::Any QueryParser::Literal_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitLiteral_value(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Literal_valueContext* QueryParser::literal_value() {
  Literal_valueContext *_localctx = _tracker.createInstance<Literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 32, QueryParser::RuleLiteral_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QueryParser::T__5)
      | (1ULL << QueryParser::NUMERIC_LITERAL)
      | (1ULL << QueryParser::STRING_LITERAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_byContext ------------------------------------------------------------------

QueryParser::Group_byContext::Group_byContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::Group_byContext::GROUP() {
  return getToken(QueryParser::GROUP, 0);
}

tree::TerminalNode* QueryParser::Group_byContext::BY() {
  return getToken(QueryParser::BY, 0);
}

QueryParser::ColumnsContext* QueryParser::Group_byContext::columns() {
  return getRuleContext<QueryParser::ColumnsContext>(0);
}


size_t QueryParser::Group_byContext::getRuleIndex() const {
  return QueryParser::RuleGroup_by;
}

void QueryParser::Group_byContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroup_by(this);
}

void QueryParser::Group_byContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroup_by(this);
}


antlrcpp::Any QueryParser::Group_byContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitGroup_by(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::Group_byContext* QueryParser::group_by() {
  Group_byContext *_localctx = _tracker.createInstance<Group_byContext>(_ctx, getState());
  enterRule(_localctx, 34, QueryParser::RuleGroup_by);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(QueryParser::GROUP);
    setState(172);
    match(QueryParser::BY);
    setState(173);
    columns();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool QueryParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return relationSempred(dynamic_cast<RelationContext *>(context), predicateIndex);
    case 10: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool QueryParser::relationSempred(RelationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool QueryParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> QueryParser::_decisionToDFA;
atn::PredictionContextCache QueryParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN QueryParser::_atn;
std::vector<uint16_t> QueryParser::_serializedATN;

std::vector<std::string> QueryParser::_ruleNames = {
  "select_stmt", "columns", "column_alias", "column", "relation", "join_operator", 
  "join_condition", "join_type", "table", "alias", "expr", "mul_div", "add_sub", 
  "function", "function_name", "compare_operator", "literal_value", "group_by"
};

std::vector<std::string> QueryParser::_literalNames = {
  "", "';'", "','", "'.'", "'('", "')'", "'NULL'", "", "", "'AND'", "'OR'", 
  "'='", "'<>'", "'<='", "'<'", "'>='", "'>'", "'IS'", "'+'", "'-'", "'*'", 
  "'/'", "'SELECT'", "'FROM'", "'WHERE'", "'JOIN'", "'INNER'", "'LEFT'", 
  "'RIGHT'", "'NATURAL'", "'ON'", "'GROUP'", "'BY'", "'SUM'", "'AVG'", "'COUNT'", 
  "'MIN'", "'MAX'", "'AS'"
};

std::vector<std::string> QueryParser::_symbolicNames = {
  "", "", "", "", "", "", "", "NUMERIC_LITERAL", "STRING_LITERAL", "AND", 
  "OR", "EQ", "NEQ", "LTEQ", "LT", "GTEQ", "GT", "IS", "ADD", "SUB", "MUL", 
  "DIV", "SELECT", "FROM", "WHERE", "JOIN", "INNER", "LEFT", "RIGHT", "NATURAL", 
  "ON", "GROUP", "BY", "SUM", "AVG", "COUNT", "MIN", "MAX", "AS", "Name", 
  "WS"
};

dfa::Vocabulary QueryParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> QueryParser::_tokenNames;

QueryParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2a, 0xb2, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x2d, 0xa, 0x2, 0x3, 0x2, 0x5, 0x2, 
    0x30, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x37, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3a, 0xb, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x3f, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x4b, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x51, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x58, 0xa, 0x6, 0x5, 0x6, 0x5a, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x60, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x64, 0xa, 0x6, 0x7, 0x6, 0x66, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x69, 
    0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x7b, 0xa, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x8f, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0x92, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x9d, 0xa, 0xf, 0xc, 0xf, 
    0xe, 0xf, 0xa0, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0xa6, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x2, 0x4, 0xa, 0x16, 0x14, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 0x8, 
    0x3, 0x2, 0x1c, 0x1f, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x14, 0x15, 0x3, 
    0x2, 0x23, 0x27, 0x3, 0x2, 0xd, 0x13, 0x3, 0x2, 0x8, 0xa, 0x2, 0xb5, 
    0x2, 0x26, 0x3, 0x2, 0x2, 0x2, 0x4, 0x33, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x4a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x6a, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x70, 0x3, 0x2, 0x2, 0x2, 0x12, 0x72, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x74, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x18, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x95, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x20, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xab, 0x3, 0x2, 0x2, 0x2, 0x24, 0xad, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x27, 0x7, 0x18, 0x2, 0x2, 0x27, 0x28, 0x5, 0x4, 0x3, 0x2, 
    0x28, 0x29, 0x7, 0x19, 0x2, 0x2, 0x29, 0x2c, 0x5, 0xa, 0x6, 0x2, 0x2a, 
    0x2b, 0x7, 0x1a, 0x2, 0x2, 0x2b, 0x2d, 0x5, 0x16, 0xc, 0x2, 0x2c, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x24, 0x13, 0x2, 0x2f, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x32, 0x7, 0x3, 0x2, 0x2, 0x32, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x38, 0x5, 0x6, 0x4, 0x2, 0x34, 0x35, 0x7, 0x4, 0x2, 0x2, 0x35, 
    0x37, 0x5, 0x6, 0x4, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x3e, 0x5, 0x16, 0xc, 0x2, 0x3c, 0x3d, 0x7, 0x28, 0x2, 
    0x2, 0x3d, 0x3f, 0x5, 0x14, 0xb, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x4b, 0x7, 0x16, 0x2, 0x2, 0x41, 0x42, 0x5, 0x12, 0xa, 0x2, 0x42, 0x43, 
    0x7, 0x5, 0x2, 0x2, 0x43, 0x44, 0x7, 0x16, 0x2, 0x2, 0x44, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x4b, 0x7, 0x29, 0x2, 0x2, 0x46, 0x47, 0x5, 0x12, 
    0xa, 0x2, 0x47, 0x48, 0x7, 0x5, 0x2, 0x2, 0x48, 0x49, 0x7, 0x29, 0x2, 
    0x2, 0x49, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x41, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x45, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
    0x8, 0x6, 0x1, 0x2, 0x4d, 0x50, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x4f, 0x7, 
    0x28, 0x2, 0x2, 0x4f, 0x51, 0x5, 0x14, 0xb, 0x2, 0x50, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x5a, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x53, 0x7, 0x6, 0x2, 0x2, 0x53, 0x54, 0x5, 0x2, 0x2, 0x2, 
    0x54, 0x57, 0x7, 0x7, 0x2, 0x2, 0x55, 0x56, 0x7, 0x28, 0x2, 0x2, 0x56, 
    0x58, 0x5, 0x14, 0xb, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x59, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x52, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x5c, 0xc, 0x4, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0xc, 0x7, 
    0x2, 0x5d, 0x5f, 0x5, 0xa, 0x6, 0x2, 0x5e, 0x60, 0x5, 0xe, 0x8, 0x2, 
    0x5f, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x28, 0x2, 0x2, 0x62, 0x64, 
    0x5, 0x14, 0xb, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x69, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0x10, 0x9, 0x2, 0x6b, 
    0x6c, 0x7, 0x1b, 0x2, 0x2, 0x6c, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 
    0x7, 0x20, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x16, 0xc, 0x2, 0x6f, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x71, 0x9, 0x2, 0x2, 0x2, 0x71, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x73, 0x7, 0x29, 0x2, 0x2, 0x73, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x75, 0x7, 0x29, 0x2, 0x2, 0x75, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x77, 0x8, 0xc, 0x1, 0x2, 0x77, 0x7b, 0x5, 0x22, 0x12, 0x2, 0x78, 
    0x7b, 0x5, 0x8, 0x5, 0x2, 0x79, 0x7b, 0x5, 0x1c, 0xf, 0x2, 0x7a, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x7b, 0x90, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0xc, 0x8, 
    0x2, 0x2, 0x7d, 0x7e, 0x5, 0x18, 0xd, 0x2, 0x7e, 0x7f, 0x5, 0x16, 0xc, 
    0x9, 0x7f, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0xc, 0x7, 0x2, 0x2, 
    0x81, 0x82, 0x5, 0x1a, 0xe, 0x2, 0x82, 0x83, 0x5, 0x16, 0xc, 0x8, 0x83, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0xc, 0x6, 0x2, 0x2, 0x85, 0x86, 
    0x5, 0x20, 0x11, 0x2, 0x86, 0x87, 0x5, 0x16, 0xc, 0x7, 0x87, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x89, 0xc, 0x5, 0x2, 0x2, 0x89, 0x8a, 0x7, 0xb, 
    0x2, 0x2, 0x8a, 0x8f, 0x5, 0x16, 0xc, 0x6, 0x8b, 0x8c, 0xc, 0x4, 0x2, 
    0x2, 0x8c, 0x8d, 0x7, 0xc, 0x2, 0x2, 0x8d, 0x8f, 0x5, 0x16, 0xc, 0x5, 
    0x8e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x80, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x8f, 0x92, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x9, 0x3, 0x2, 
    0x2, 0x94, 0x19, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x9, 0x4, 0x2, 0x2, 
    0x96, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x5, 0x1e, 0x10, 0x2, 0x98, 
    0x99, 0x7, 0x6, 0x2, 0x2, 0x99, 0x9e, 0x5, 0x16, 0xc, 0x2, 0x9a, 0x9b, 
    0x7, 0x4, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0x16, 0xc, 0x2, 0x9c, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x7, 0x2, 0x2, 
    0xa2, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x6, 0x2, 0x2, 0xa4, 
    0xa6, 0x7, 0x7, 0x2, 0x2, 0xa5, 0x97, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x9, 
    0x5, 0x2, 0x2, 0xa8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x9, 0x6, 
    0x2, 0x2, 0xaa, 0x21, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x9, 0x7, 0x2, 
    0x2, 0xac, 0x23, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x21, 0x2, 0x2, 
    0xae, 0xaf, 0x7, 0x22, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x4, 0x3, 0x2, 0xb0, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x12, 0x2c, 0x2f, 0x38, 0x3e, 0x4a, 0x50, 
    0x57, 0x59, 0x5f, 0x63, 0x67, 0x7a, 0x8e, 0x90, 0x9e, 0xa5, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

QueryParser::Initializer QueryParser::_init;
