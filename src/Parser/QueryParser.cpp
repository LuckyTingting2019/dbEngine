
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
    setState(38);
    match(QueryParser::SELECT);
    setState(39);
    columns();
    setState(40);
    match(QueryParser::FROM);
    setState(41);
    relation(0);
    setState(44);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::WHERE) {
      setState(42);
      match(QueryParser::WHERE);
      setState(43);
      expr(0);
    }
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::GROUP) {
      setState(46);
      group_by();
    }
    setState(49);
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
    setState(51);
    column_alias();
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QueryParser::T__1) {
      setState(52);
      match(QueryParser::T__1);
      setState(53);
      column_alias();
      setState(58);
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
    setState(59);
    expr(0);
    setState(62);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::AS) {
      setState(60);
      match(QueryParser::AS);
      setState(61);
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
    setState(74);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      match(QueryParser::MUL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(65);
      table();
      setState(66);
      match(QueryParser::T__2);
      setState(67);
      match(QueryParser::MUL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(69);
      match(QueryParser::Name);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(70);
      table();
      setState(71);
      match(QueryParser::T__2);
      setState(72);
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
    setState(89);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::Name: {
        setState(77);
        table();
        setState(80);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          setState(78);
          match(QueryParser::AS);
          setState(79);
          alias();
          break;
        }

        }
        break;
      }

      case QueryParser::T__3: {
        setState(82);
        match(QueryParser::T__3);
        setState(83);
        select_stmt();
        setState(84);
        match(QueryParser::T__4);
        setState(87);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          setState(85);
          match(QueryParser::AS);
          setState(86);
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
    setState(103);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelationContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelation);
        setState(91);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(92);
        join_operator();
        setState(93);
        relation(0);
        setState(95);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          setState(94);
          join_condition();
          break;
        }

        }
        setState(99);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          setState(97);
          match(QueryParser::AS);
          setState(98);
          alias();
          break;
        }

        } 
      }
      setState(105);
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
    setState(106);
    join_type();
    setState(107);
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
    setState(109);
    match(QueryParser::ON);
    setState(110);
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
    setState(112);
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
    setState(116);
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

QueryParser::DistinctContext* QueryParser::ExprContext::distinct() {
  return getRuleContext<QueryParser::DistinctContext>(0);
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
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::T__5:
      case QueryParser::NUMERIC_LITERAL:
      case QueryParser::STRING_LITERAL: {
        setState(119);
        literal_value();
        break;
      }

      case QueryParser::MUL:
      case QueryParser::Name: {
        setState(120);
        column();
        break;
      }

      case QueryParser::T__3:
      case QueryParser::SUM:
      case QueryParser::AVG:
      case QueryParser::COUNT:
      case QueryParser::MIN:
      case QueryParser::MAX: {
        setState(121);
        function();
        break;
      }

      case QueryParser::DISTINCT: {
        setState(122);
        distinct();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(145);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(143);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(125);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(126);
          mul_div();
          setState(127);
          expr(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(129);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(130);
          add_sub();
          setState(131);
          expr(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(133);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(134);
          compare_operator();
          setState(135);
          expr(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(137);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(138);
          match(QueryParser::AND);
          setState(139);
          expr(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(140);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(141);
          match(QueryParser::OR);
          setState(142);
          expr(4);
          break;
        }

        } 
      }
      setState(147);
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

//----------------- DistinctContext ------------------------------------------------------------------

QueryParser::DistinctContext::DistinctContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::DistinctContext::DISTINCT() {
  return getToken(QueryParser::DISTINCT, 0);
}

std::vector<QueryParser::ColumnContext *> QueryParser::DistinctContext::column() {
  return getRuleContexts<QueryParser::ColumnContext>();
}

QueryParser::ColumnContext* QueryParser::DistinctContext::column(size_t i) {
  return getRuleContext<QueryParser::ColumnContext>(i);
}


size_t QueryParser::DistinctContext::getRuleIndex() const {
  return QueryParser::RuleDistinct;
}

void QueryParser::DistinctContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDistinct(this);
}

void QueryParser::DistinctContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDistinct(this);
}


antlrcpp::Any QueryParser::DistinctContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitDistinct(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::DistinctContext* QueryParser::distinct() {
  DistinctContext *_localctx = _tracker.createInstance<DistinctContext>(_ctx, getState());
  enterRule(_localctx, 22, QueryParser::RuleDistinct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(QueryParser::DISTINCT);
    setState(149);
    column();
    setState(154);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(150);
        match(QueryParser::T__1);
        setState(151);
        column(); 
      }
      setState(156);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
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
  enterRule(_localctx, 24, QueryParser::RuleMul_div);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
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
  enterRule(_localctx, 26, QueryParser::RuleAdd_sub);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
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
  enterRule(_localctx, 28, QueryParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::SUM:
      case QueryParser::AVG:
      case QueryParser::COUNT:
      case QueryParser::MIN:
      case QueryParser::MAX: {
        enterOuterAlt(_localctx, 1);
        setState(161);
        function_name();

        setState(162);
        match(QueryParser::T__3);
        setState(163);
        expr(0);
        setState(168);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == QueryParser::T__1) {
          setState(164);
          match(QueryParser::T__1);
          setState(165);
          expr(0);
          setState(170);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(171);
        match(QueryParser::T__4);
        break;
      }

      case QueryParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(173);
        match(QueryParser::T__3);
        setState(174);
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
  enterRule(_localctx, 30, QueryParser::RuleFunction_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
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
  enterRule(_localctx, 32, QueryParser::RuleCompare_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
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
  enterRule(_localctx, 34, QueryParser::RuleLiteral_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
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
  enterRule(_localctx, 36, QueryParser::RuleGroup_by);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(QueryParser::GROUP);
    setState(184);
    match(QueryParser::BY);
    setState(185);
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
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);

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
  "join_condition", "join_type", "table", "alias", "expr", "distinct", "mul_div", 
  "add_sub", "function", "function_name", "compare_operator", "literal_value", 
  "group_by"
};

std::vector<std::string> QueryParser::_literalNames = {
  "", "';'", "','", "'.'", "'('", "')'", "'NULL'", "", "", "'AND'", "'OR'", 
  "'='", "'<>'", "'<='", "'<'", "'>='", "'>'", "'IS'", "'+'", "'-'", "'*'", 
  "'/'", "'SELECT'", "'FROM'", "'WHERE'", "'JOIN'", "'INNER'", "'LEFT'", 
  "'RIGHT'", "'NATURAL'", "'ON'", "'GROUP'", "'BY'", "'SUM'", "'AVG'", "'COUNT'", 
  "'MIN'", "'MAX'", "'AS'", "'DISTINCT'"
};

std::vector<std::string> QueryParser::_symbolicNames = {
  "", "", "", "", "", "", "", "NUMERIC_LITERAL", "STRING_LITERAL", "AND", 
  "OR", "EQ", "NEQ", "LTEQ", "LT", "GTEQ", "GT", "IS", "ADD", "SUB", "MUL", 
  "DIV", "SELECT", "FROM", "WHERE", "JOIN", "INNER", "LEFT", "RIGHT", "NATURAL", 
  "ON", "GROUP", "BY", "SUM", "AVG", "COUNT", "MIN", "MAX", "AS", "DISTINCT", 
  "Name", "WS"
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
    0x3, 0x2b, 0xbe, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x2f, 0xa, 0x2, 
    0x3, 0x2, 0x5, 0x2, 0x32, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x39, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3c, 0xb, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x41, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x4d, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x53, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x5a, 0xa, 0x6, 0x5, 0x6, 0x5c, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x62, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x66, 0xa, 0x6, 0x7, 0x6, 0x68, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x6b, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x7e, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x92, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x95, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0x9b, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x9e, 0xb, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xa9, 0xa, 0x10, 0xc, 0x10, 0xe, 
    0x10, 0xac, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 
    0x10, 0xb2, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x2, 0x4, 0xa, 0x16, 0x15, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x2, 
    0x8, 0x3, 0x2, 0x1c, 0x1f, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x14, 0x15, 
    0x3, 0x2, 0x23, 0x27, 0x3, 0x2, 0xd, 0x13, 0x3, 0x2, 0x8, 0xa, 0x2, 
    0xc2, 0x2, 0x28, 0x3, 0x2, 0x2, 0x2, 0x4, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x6c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x72, 0x3, 0x2, 0x2, 0x2, 0x12, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x76, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x96, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x24, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x18, 
    0x2, 0x2, 0x29, 0x2a, 0x5, 0x4, 0x3, 0x2, 0x2a, 0x2b, 0x7, 0x19, 0x2, 
    0x2, 0x2b, 0x2e, 0x5, 0xa, 0x6, 0x2, 0x2c, 0x2d, 0x7, 0x1a, 0x2, 0x2, 
    0x2d, 0x2f, 0x5, 0x16, 0xc, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x31, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 
    0x5, 0x26, 0x14, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x3, 
    0x2, 0x2, 0x34, 0x3, 0x3, 0x2, 0x2, 0x2, 0x35, 0x3a, 0x5, 0x6, 0x4, 
    0x2, 0x36, 0x37, 0x7, 0x4, 0x2, 0x2, 0x37, 0x39, 0x5, 0x6, 0x4, 0x2, 
    0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x5, 
    0x16, 0xc, 0x2, 0x3e, 0x3f, 0x7, 0x28, 0x2, 0x2, 0x3f, 0x41, 0x5, 0x14, 
    0xb, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x7, 0x3, 0x2, 0x2, 0x2, 0x42, 0x4d, 0x7, 0x16, 0x2, 0x2, 
    0x43, 0x44, 0x5, 0x12, 0xa, 0x2, 0x44, 0x45, 0x7, 0x5, 0x2, 0x2, 0x45, 
    0x46, 0x7, 0x16, 0x2, 0x2, 0x46, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4d, 
    0x7, 0x2a, 0x2, 0x2, 0x48, 0x49, 0x5, 0x12, 0xa, 0x2, 0x49, 0x4a, 0x7, 
    0x5, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x2a, 0x2, 0x2, 0x4b, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x42, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x8, 0x6, 0x1, 0x2, 0x4f, 
    0x52, 0x5, 0x12, 0xa, 0x2, 0x50, 0x51, 0x7, 0x28, 0x2, 0x2, 0x51, 0x53, 
    0x5, 0x14, 0xb, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x6, 
    0x2, 0x2, 0x55, 0x56, 0x5, 0x2, 0x2, 0x2, 0x56, 0x59, 0x7, 0x7, 0x2, 
    0x2, 0x57, 0x58, 0x7, 0x28, 0x2, 0x2, 0x58, 0x5a, 0x5, 0x14, 0xb, 0x2, 
    0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x69, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0xc, 
    0x4, 0x2, 0x2, 0x5e, 0x5f, 0x5, 0xc, 0x7, 0x2, 0x5f, 0x61, 0x5, 0xa, 
    0x6, 0x2, 0x60, 0x62, 0x5, 0xe, 0x8, 0x2, 0x61, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x64, 0x7, 0x28, 0x2, 0x2, 0x64, 0x66, 0x5, 0x14, 0xb, 0x2, 0x65, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x6d, 0x5, 0x10, 0x9, 0x2, 0x6d, 0x6e, 0x7, 0x1b, 0x2, 0x2, 
    0x6e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x20, 0x2, 0x2, 0x70, 
    0x71, 0x5, 0x16, 0xc, 0x2, 0x71, 0xf, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 
    0x9, 0x2, 0x2, 0x2, 0x73, 0x11, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 
    0x2a, 0x2, 0x2, 0x75, 0x13, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x2a, 
    0x2, 0x2, 0x77, 0x15, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x8, 0xc, 0x1, 
    0x2, 0x79, 0x7e, 0x5, 0x24, 0x13, 0x2, 0x7a, 0x7e, 0x5, 0x8, 0x5, 0x2, 
    0x7b, 0x7e, 0x5, 0x1e, 0x10, 0x2, 0x7c, 0x7e, 0x5, 0x18, 0xd, 0x2, 0x7d, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x80, 0xc, 0x9, 0x2, 0x2, 0x80, 0x81, 0x5, 0x1a, 
    0xe, 0x2, 0x81, 0x82, 0x5, 0x16, 0xc, 0xa, 0x82, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x83, 0x84, 0xc, 0x8, 0x2, 0x2, 0x84, 0x85, 0x5, 0x1c, 0xf, 0x2, 
    0x85, 0x86, 0x5, 0x16, 0xc, 0x9, 0x86, 0x92, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x88, 0xc, 0x7, 0x2, 0x2, 0x88, 0x89, 0x5, 0x22, 0x12, 0x2, 0x89, 0x8a, 
    0x5, 0x16, 0xc, 0x8, 0x8a, 0x92, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0xc, 
    0x6, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0xb, 0x2, 0x2, 0x8d, 0x92, 0x5, 0x16, 
    0xc, 0x7, 0x8e, 0x8f, 0xc, 0x5, 0x2, 0x2, 0x8f, 0x90, 0x7, 0xc, 0x2, 
    0x2, 0x90, 0x92, 0x5, 0x16, 0xc, 0x6, 0x91, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x83, 0x3, 0x2, 0x2, 0x2, 0x91, 0x87, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x17, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x97, 0x7, 0x29, 0x2, 0x2, 0x97, 0x9c, 0x5, 0x8, 0x5, 
    0x2, 0x98, 0x99, 0x7, 0x4, 0x2, 0x2, 0x99, 0x9b, 0x5, 0x8, 0x5, 0x2, 
    0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x9, 
    0x3, 0x2, 0x2, 0xa0, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x9, 0x4, 
    0x2, 0x2, 0xa2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x20, 0x11, 
    0x2, 0xa4, 0xa5, 0x7, 0x6, 0x2, 0x2, 0xa5, 0xaa, 0x5, 0x16, 0xc, 0x2, 
    0xa6, 0xa7, 0x7, 0x4, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0x16, 0xc, 0x2, 0xa8, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x7, 
    0x2, 0x2, 0xae, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x6, 0x2, 
    0x2, 0xb0, 0xb2, 0x7, 0x7, 0x2, 0x2, 0xb1, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb4, 0x9, 0x5, 0x2, 0x2, 0xb4, 0x21, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 
    0x9, 0x6, 0x2, 0x2, 0xb6, 0x23, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x9, 
    0x7, 0x2, 0x2, 0xb8, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x21, 
    0x2, 0x2, 0xba, 0xbb, 0x7, 0x22, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x4, 0x3, 
    0x2, 0xbc, 0x27, 0x3, 0x2, 0x2, 0x2, 0x13, 0x2e, 0x31, 0x3a, 0x40, 0x4c, 
    0x52, 0x59, 0x5b, 0x61, 0x65, 0x69, 0x7d, 0x91, 0x93, 0x9c, 0xaa, 0xb1, 
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
