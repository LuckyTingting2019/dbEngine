grammar Query;

select_stmt : SELECT columns FROM relation ( WHERE expr )? (group_by)? ';';

columns : expr ( ',' expr )* ;

column : '*' | table '.' '*' | Name | table '.' Name ;

relation
 : table
 | relation join_operator relation (join_condition) ?
 | '(' select_stmt ')'
 ;

join_operator : join_type JOIN ;

join_condition : ON expr;

join_type : INNER | LEFT | RIGHT | NATURAL ;

table : Name ;

expr
: literal_value
| column
| expr mul_div expr //part of filter, columns
| expr add_sub expr //part of filter, columns
| expr compare_operator expr // filter and join condition
| expr AND expr //filter
| expr OR expr //filter
| function //columns
;

mul_div : MUL | DIV;
add_sub : ADD | SUB;

function : function_name ( '(' expr (',' expr)* ')' ) | ( '(' ')' );

function_name : SUM | AVG | COUNT | MIN | MAX;
compare_operator: GTEQ | NEQ | EQ | GT | LTEQ | LT | IS ;

literal_value : NUMERIC_LITERAL | STRING_LITERAL | 'NULL' ;

NUMERIC_LITERAL
 : DIGIT+ ( '.' DIGIT* )? ( E [-+]? DIGIT+ )?
 | '.' DIGIT+ ( E [-+]? DIGIT+ )?
 ;

STRING_LITERAL : '\'' ( ~'\'' | '\'\'' )* '\'' ;

group_by : GROUP BY columns;

AND : 'AND';
OR : 'OR';
EQ : '=';
NEQ : '<>';
LTEQ : '<=';
LT : '<';
GTEQ : '>=';
GT : '>';
IS : 'IS';
ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
SELECT : 'SELECT';
FROM : 'FROM';
WHERE : 'WHERE';
JOIN : 'JOIN';
INNER : 'INNER';
LEFT : 'LEFT';
RIGHT : 'RIGHT';
NATURAL : 'NATURAL';
ON : 'ON';
GROUP : 'GROUP';
BY : 'BY';
SUM : 'SUM';
AVG : 'AVG';
COUNT : 'COUNT';
MIN : 'MIN';
MAX : 'MAX';

fragment DIGIT : [0-9];
fragment A : [aA];
fragment B : [bB];
fragment C : [cC];
fragment D : [dD];
fragment E : [eE];
fragment F : [fF];
fragment G : [gG];
fragment H : [hH];
fragment I : [iI];
fragment J : [jJ];
fragment K : [kK];
fragment L : [lL];
fragment M : [mM];
fragment N : [nN];
fragment O : [oO];
fragment P : [pP];
fragment Q : [qQ];
fragment R : [rR];
fragment S : [sS];
fragment T : [tT];
fragment U : [uU];
fragment V : [vV];
fragment W : [wW];
fragment X : [xX];
fragment Y : [yY];
fragment Z : [zZ];


Name : [a-zA-Z] [a-zA-Z0-9]* ;
 
WS : [ \t\r\n]+ -> skip ;
