// Generated from Query.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class QueryLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, NUMERIC_LITERAL=7, STRING_LITERAL=8, 
		AND=9, OR=10, EQ=11, NEQ=12, LTEQ=13, LT=14, GTEQ=15, GT=16, IS=17, ADD=18, 
		SUB=19, MUL=20, DIV=21, SELECT=22, FROM=23, WHERE=24, JOIN=25, INNER=26, 
		LEFT=27, RIGHT=28, NATURAL=29, ON=30, GROUP=31, BY=32, SUM=33, AVG=34, 
		COUNT=35, MIN=36, MAX=37, AS=38, Name=39, WS=40;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "NUMERIC_LITERAL", "STRING_LITERAL", 
			"AND", "OR", "EQ", "NEQ", "LTEQ", "LT", "GTEQ", "GT", "IS", "ADD", "SUB", 
			"MUL", "DIV", "SELECT", "FROM", "WHERE", "JOIN", "INNER", "LEFT", "RIGHT", 
			"NATURAL", "ON", "GROUP", "BY", "SUM", "AVG", "COUNT", "MIN", "MAX", 
			"AS", "DIGIT", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", 
			"L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", 
			"Z", "Name", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "','", "'.'", "'('", "')'", "'NULL'", null, null, "'AND'", 
			"'OR'", "'='", "'<>'", "'<='", "'<'", "'>='", "'>'", "'IS'", "'+'", "'-'", 
			"'*'", "'/'", "'SELECT'", "'FROM'", "'WHERE'", "'JOIN'", "'INNER'", "'LEFT'", 
			"'RIGHT'", "'NATURAL'", "'ON'", "'GROUP'", "'BY'", "'SUM'", "'AVG'", 
			"'COUNT'", "'MIN'", "'MAX'", "'AS'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, "NUMERIC_LITERAL", "STRING_LITERAL", 
			"AND", "OR", "EQ", "NEQ", "LTEQ", "LT", "GTEQ", "GT", "IS", "ADD", "SUB", 
			"MUL", "DIV", "SELECT", "FROM", "WHERE", "JOIN", "INNER", "LEFT", "RIGHT", 
			"NATURAL", "ON", "GROUP", "BY", "SUM", "AVG", "COUNT", "MIN", "MAX", 
			"AS", "Name", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public QueryLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Query.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2*\u0189\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\3\2\3\2\3\3\3\3\3\4\3\4\3\5"+
		"\3\5\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\b\6\b\u009a\n\b\r\b\16\b\u009b\3\b"+
		"\3\b\7\b\u00a0\n\b\f\b\16\b\u00a3\13\b\5\b\u00a5\n\b\3\b\3\b\5\b\u00a9"+
		"\n\b\3\b\6\b\u00ac\n\b\r\b\16\b\u00ad\5\b\u00b0\n\b\3\b\3\b\6\b\u00b4"+
		"\n\b\r\b\16\b\u00b5\3\b\3\b\5\b\u00ba\n\b\3\b\6\b\u00bd\n\b\r\b\16\b\u00be"+
		"\5\b\u00c1\n\b\5\b\u00c3\n\b\3\t\3\t\3\t\3\t\7\t\u00c9\n\t\f\t\16\t\u00cc"+
		"\13\t\3\t\3\t\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\f\3\f\3\r\3\r\3\r\3\16"+
		"\3\16\3\16\3\17\3\17\3\20\3\20\3\20\3\21\3\21\3\22\3\22\3\22\3\23\3\23"+
		"\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\30"+
		"\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32"+
		"\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3\35\3\35"+
		"\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\37\3\37"+
		"\3\37\3 \3 \3 \3 \3 \3 \3!\3!\3!\3\"\3\"\3\"\3\"\3#\3#\3#\3#\3$\3$\3$"+
		"\3$\3$\3$\3%\3%\3%\3%\3&\3&\3&\3&\3\'\3\'\3\'\3(\3(\3)\3)\3*\3*\3+\3+"+
		"\3,\3,\3-\3-\3.\3.\3/\3/\3\60\3\60\3\61\3\61\3\62\3\62\3\63\3\63\3\64"+
		"\3\64\3\65\3\65\3\66\3\66\3\67\3\67\38\38\39\39\3:\3:\3;\3;\3<\3<\3=\3"+
		"=\3>\3>\3?\3?\3@\3@\3A\3A\3B\3B\3C\3C\7C\u017e\nC\fC\16C\u0181\13C\3D"+
		"\6D\u0184\nD\rD\16D\u0185\3D\3D\2\2E\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21"+
		"\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30"+
		"/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O\2Q\2S\2U\2W"+
		"\2Y\2[\2]\2_\2a\2c\2e\2g\2i\2k\2m\2o\2q\2s\2u\2w\2y\2{\2}\2\177\2\u0081"+
		"\2\u0083\2\u0085)\u0087*\3\2\"\4\2--//\3\2))\3\2\62;\4\2CCcc\4\2DDdd\4"+
		"\2EEee\4\2FFff\4\2GGgg\4\2HHhh\4\2IIii\4\2JJjj\4\2KKkk\4\2LLll\4\2MMm"+
		"m\4\2NNnn\4\2OOoo\4\2PPpp\4\2QQqq\4\2RRrr\4\2SSss\4\2TTtt\4\2UUuu\4\2"+
		"VVvv\4\2WWww\4\2XXxx\4\2YYyy\4\2ZZzz\4\2[[{{\4\2\\\\||\4\2C\\c|\5\2\62"+
		";C\\c|\5\2\13\f\17\17\"\"\2\u017c\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2"+
		"\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3"+
		"\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2"+
		"\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2"+
		"\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2"+
		"\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2"+
		"\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2"+
		"\u0085\3\2\2\2\2\u0087\3\2\2\2\3\u0089\3\2\2\2\5\u008b\3\2\2\2\7\u008d"+
		"\3\2\2\2\t\u008f\3\2\2\2\13\u0091\3\2\2\2\r\u0093\3\2\2\2\17\u00c2\3\2"+
		"\2\2\21\u00c4\3\2\2\2\23\u00cf\3\2\2\2\25\u00d3\3\2\2\2\27\u00d6\3\2\2"+
		"\2\31\u00d8\3\2\2\2\33\u00db\3\2\2\2\35\u00de\3\2\2\2\37\u00e0\3\2\2\2"+
		"!\u00e3\3\2\2\2#\u00e5\3\2\2\2%\u00e8\3\2\2\2\'\u00ea\3\2\2\2)\u00ec\3"+
		"\2\2\2+\u00ee\3\2\2\2-\u00f0\3\2\2\2/\u00f7\3\2\2\2\61\u00fc\3\2\2\2\63"+
		"\u0102\3\2\2\2\65\u0107\3\2\2\2\67\u010d\3\2\2\29\u0112\3\2\2\2;\u0118"+
		"\3\2\2\2=\u0120\3\2\2\2?\u0123\3\2\2\2A\u0129\3\2\2\2C\u012c\3\2\2\2E"+
		"\u0130\3\2\2\2G\u0134\3\2\2\2I\u013a\3\2\2\2K\u013e\3\2\2\2M\u0142\3\2"+
		"\2\2O\u0145\3\2\2\2Q\u0147\3\2\2\2S\u0149\3\2\2\2U\u014b\3\2\2\2W\u014d"+
		"\3\2\2\2Y\u014f\3\2\2\2[\u0151\3\2\2\2]\u0153\3\2\2\2_\u0155\3\2\2\2a"+
		"\u0157\3\2\2\2c\u0159\3\2\2\2e\u015b\3\2\2\2g\u015d\3\2\2\2i\u015f\3\2"+
		"\2\2k\u0161\3\2\2\2m\u0163\3\2\2\2o\u0165\3\2\2\2q\u0167\3\2\2\2s\u0169"+
		"\3\2\2\2u\u016b\3\2\2\2w\u016d\3\2\2\2y\u016f\3\2\2\2{\u0171\3\2\2\2}"+
		"\u0173\3\2\2\2\177\u0175\3\2\2\2\u0081\u0177\3\2\2\2\u0083\u0179\3\2\2"+
		"\2\u0085\u017b\3\2\2\2\u0087\u0183\3\2\2\2\u0089\u008a\7=\2\2\u008a\4"+
		"\3\2\2\2\u008b\u008c\7.\2\2\u008c\6\3\2\2\2\u008d\u008e\7\60\2\2\u008e"+
		"\b\3\2\2\2\u008f\u0090\7*\2\2\u0090\n\3\2\2\2\u0091\u0092\7+\2\2\u0092"+
		"\f\3\2\2\2\u0093\u0094\7P\2\2\u0094\u0095\7W\2\2\u0095\u0096\7N\2\2\u0096"+
		"\u0097\7N\2\2\u0097\16\3\2\2\2\u0098\u009a\5O(\2\u0099\u0098\3\2\2\2\u009a"+
		"\u009b\3\2\2\2\u009b\u0099\3\2\2\2\u009b\u009c\3\2\2\2\u009c\u00a4\3\2"+
		"\2\2\u009d\u00a1\7\60\2\2\u009e\u00a0\5O(\2\u009f\u009e\3\2\2\2\u00a0"+
		"\u00a3\3\2\2\2\u00a1\u009f\3\2\2\2\u00a1\u00a2\3\2\2\2\u00a2\u00a5\3\2"+
		"\2\2\u00a3\u00a1\3\2\2\2\u00a4\u009d\3\2\2\2\u00a4\u00a5\3\2\2\2\u00a5"+
		"\u00af\3\2\2\2\u00a6\u00a8\5Y-\2\u00a7\u00a9\t\2\2\2\u00a8\u00a7\3\2\2"+
		"\2\u00a8\u00a9\3\2\2\2\u00a9\u00ab\3\2\2\2\u00aa\u00ac\5O(\2\u00ab\u00aa"+
		"\3\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae"+
		"\u00b0\3\2\2\2\u00af\u00a6\3\2\2\2\u00af\u00b0\3\2\2\2\u00b0\u00c3\3\2"+
		"\2\2\u00b1\u00b3\7\60\2\2\u00b2\u00b4\5O(\2\u00b3\u00b2\3\2\2\2\u00b4"+
		"\u00b5\3\2\2\2\u00b5\u00b3\3\2\2\2\u00b5\u00b6\3\2\2\2\u00b6\u00c0\3\2"+
		"\2\2\u00b7\u00b9\5Y-\2\u00b8\u00ba\t\2\2\2\u00b9\u00b8\3\2\2\2\u00b9\u00ba"+
		"\3\2\2\2\u00ba\u00bc\3\2\2\2\u00bb\u00bd\5O(\2\u00bc\u00bb\3\2\2\2\u00bd"+
		"\u00be\3\2\2\2\u00be\u00bc\3\2\2\2\u00be\u00bf\3\2\2\2\u00bf\u00c1\3\2"+
		"\2\2\u00c0\u00b7\3\2\2\2\u00c0\u00c1\3\2\2\2\u00c1\u00c3\3\2\2\2\u00c2"+
		"\u0099\3\2\2\2\u00c2\u00b1\3\2\2\2\u00c3\20\3\2\2\2\u00c4\u00ca\7)\2\2"+
		"\u00c5\u00c9\n\3\2\2\u00c6\u00c7\7)\2\2\u00c7\u00c9\7)\2\2\u00c8\u00c5"+
		"\3\2\2\2\u00c8\u00c6\3\2\2\2\u00c9\u00cc\3\2\2\2\u00ca\u00c8\3\2\2\2\u00ca"+
		"\u00cb\3\2\2\2\u00cb\u00cd\3\2\2\2\u00cc\u00ca\3\2\2\2\u00cd\u00ce\7)"+
		"\2\2\u00ce\22\3\2\2\2\u00cf\u00d0\7C\2\2\u00d0\u00d1\7P\2\2\u00d1\u00d2"+
		"\7F\2\2\u00d2\24\3\2\2\2\u00d3\u00d4\7Q\2\2\u00d4\u00d5\7T\2\2\u00d5\26"+
		"\3\2\2\2\u00d6\u00d7\7?\2\2\u00d7\30\3\2\2\2\u00d8\u00d9\7>\2\2\u00d9"+
		"\u00da\7@\2\2\u00da\32\3\2\2\2\u00db\u00dc\7>\2\2\u00dc\u00dd\7?\2\2\u00dd"+
		"\34\3\2\2\2\u00de\u00df\7>\2\2\u00df\36\3\2\2\2\u00e0\u00e1\7@\2\2\u00e1"+
		"\u00e2\7?\2\2\u00e2 \3\2\2\2\u00e3\u00e4\7@\2\2\u00e4\"\3\2\2\2\u00e5"+
		"\u00e6\7K\2\2\u00e6\u00e7\7U\2\2\u00e7$\3\2\2\2\u00e8\u00e9\7-\2\2\u00e9"+
		"&\3\2\2\2\u00ea\u00eb\7/\2\2\u00eb(\3\2\2\2\u00ec\u00ed\7,\2\2\u00ed*"+
		"\3\2\2\2\u00ee\u00ef\7\61\2\2\u00ef,\3\2\2\2\u00f0\u00f1\7U\2\2\u00f1"+
		"\u00f2\7G\2\2\u00f2\u00f3\7N\2\2\u00f3\u00f4\7G\2\2\u00f4\u00f5\7E\2\2"+
		"\u00f5\u00f6\7V\2\2\u00f6.\3\2\2\2\u00f7\u00f8\7H\2\2\u00f8\u00f9\7T\2"+
		"\2\u00f9\u00fa\7Q\2\2\u00fa\u00fb\7O\2\2\u00fb\60\3\2\2\2\u00fc\u00fd"+
		"\7Y\2\2\u00fd\u00fe\7J\2\2\u00fe\u00ff\7G\2\2\u00ff\u0100\7T\2\2\u0100"+
		"\u0101\7G\2\2\u0101\62\3\2\2\2\u0102\u0103\7L\2\2\u0103\u0104\7Q\2\2\u0104"+
		"\u0105\7K\2\2\u0105\u0106\7P\2\2\u0106\64\3\2\2\2\u0107\u0108\7K\2\2\u0108"+
		"\u0109\7P\2\2\u0109\u010a\7P\2\2\u010a\u010b\7G\2\2\u010b\u010c\7T\2\2"+
		"\u010c\66\3\2\2\2\u010d\u010e\7N\2\2\u010e\u010f\7G\2\2\u010f\u0110\7"+
		"H\2\2\u0110\u0111\7V\2\2\u01118\3\2\2\2\u0112\u0113\7T\2\2\u0113\u0114"+
		"\7K\2\2\u0114\u0115\7I\2\2\u0115\u0116\7J\2\2\u0116\u0117\7V\2\2\u0117"+
		":\3\2\2\2\u0118\u0119\7P\2\2\u0119\u011a\7C\2\2\u011a\u011b\7V\2\2\u011b"+
		"\u011c\7W\2\2\u011c\u011d\7T\2\2\u011d\u011e\7C\2\2\u011e\u011f\7N\2\2"+
		"\u011f<\3\2\2\2\u0120\u0121\7Q\2\2\u0121\u0122\7P\2\2\u0122>\3\2\2\2\u0123"+
		"\u0124\7I\2\2\u0124\u0125\7T\2\2\u0125\u0126\7Q\2\2\u0126\u0127\7W\2\2"+
		"\u0127\u0128\7R\2\2\u0128@\3\2\2\2\u0129\u012a\7D\2\2\u012a\u012b\7[\2"+
		"\2\u012bB\3\2\2\2\u012c\u012d\7U\2\2\u012d\u012e\7W\2\2\u012e\u012f\7"+
		"O\2\2\u012fD\3\2\2\2\u0130\u0131\7C\2\2\u0131\u0132\7X\2\2\u0132\u0133"+
		"\7I\2\2\u0133F\3\2\2\2\u0134\u0135\7E\2\2\u0135\u0136\7Q\2\2\u0136\u0137"+
		"\7W\2\2\u0137\u0138\7P\2\2\u0138\u0139\7V\2\2\u0139H\3\2\2\2\u013a\u013b"+
		"\7O\2\2\u013b\u013c\7K\2\2\u013c\u013d\7P\2\2\u013dJ\3\2\2\2\u013e\u013f"+
		"\7O\2\2\u013f\u0140\7C\2\2\u0140\u0141\7Z\2\2\u0141L\3\2\2\2\u0142\u0143"+
		"\7C\2\2\u0143\u0144\7U\2\2\u0144N\3\2\2\2\u0145\u0146\t\4\2\2\u0146P\3"+
		"\2\2\2\u0147\u0148\t\5\2\2\u0148R\3\2\2\2\u0149\u014a\t\6\2\2\u014aT\3"+
		"\2\2\2\u014b\u014c\t\7\2\2\u014cV\3\2\2\2\u014d\u014e\t\b\2\2\u014eX\3"+
		"\2\2\2\u014f\u0150\t\t\2\2\u0150Z\3\2\2\2\u0151\u0152\t\n\2\2\u0152\\"+
		"\3\2\2\2\u0153\u0154\t\13\2\2\u0154^\3\2\2\2\u0155\u0156\t\f\2\2\u0156"+
		"`\3\2\2\2\u0157\u0158\t\r\2\2\u0158b\3\2\2\2\u0159\u015a\t\16\2\2\u015a"+
		"d\3\2\2\2\u015b\u015c\t\17\2\2\u015cf\3\2\2\2\u015d\u015e\t\20\2\2\u015e"+
		"h\3\2\2\2\u015f\u0160\t\21\2\2\u0160j\3\2\2\2\u0161\u0162\t\22\2\2\u0162"+
		"l\3\2\2\2\u0163\u0164\t\23\2\2\u0164n\3\2\2\2\u0165\u0166\t\24\2\2\u0166"+
		"p\3\2\2\2\u0167\u0168\t\25\2\2\u0168r\3\2\2\2\u0169\u016a\t\26\2\2\u016a"+
		"t\3\2\2\2\u016b\u016c\t\27\2\2\u016cv\3\2\2\2\u016d\u016e\t\30\2\2\u016e"+
		"x\3\2\2\2\u016f\u0170\t\31\2\2\u0170z\3\2\2\2\u0171\u0172\t\32\2\2\u0172"+
		"|\3\2\2\2\u0173\u0174\t\33\2\2\u0174~\3\2\2\2\u0175\u0176\t\34\2\2\u0176"+
		"\u0080\3\2\2\2\u0177\u0178\t\35\2\2\u0178\u0082\3\2\2\2\u0179\u017a\t"+
		"\36\2\2\u017a\u0084\3\2\2\2\u017b\u017f\t\37\2\2\u017c\u017e\t \2\2\u017d"+
		"\u017c\3\2\2\2\u017e\u0181\3\2\2\2\u017f\u017d\3\2\2\2\u017f\u0180\3\2"+
		"\2\2\u0180\u0086\3\2\2\2\u0181\u017f\3\2\2\2\u0182\u0184\t!\2\2\u0183"+
		"\u0182\3\2\2\2\u0184\u0185\3\2\2\2\u0185\u0183\3\2\2\2\u0185\u0186\3\2"+
		"\2\2\u0186\u0187\3\2\2\2\u0187\u0188\bD\2\2\u0188\u0088\3\2\2\2\22\2\u009b"+
		"\u00a1\u00a4\u00a8\u00ad\u00af\u00b5\u00b9\u00be\u00c0\u00c2\u00c8\u00ca"+
		"\u017f\u0185\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}