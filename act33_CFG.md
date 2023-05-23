# Actividad 3.3 - Practicando Lenguajes Libres de Contexto
### Authors:
- Alina Rosas A01252720
- Fernanda Cantú A01782232
### 22 de mayo de 2023

<hr>
<br>

# Notación BNF
## **Modules**
\<module\> ::= defmodule \<module_name\> do \<module_body\> end

\<module_name\> ::= \<upp_identifier\>

\<module_body\> ::= \<function\> | \<function\> \<module_body\>


## **Functions**

\<function\> ::= def \<function_name\> ( \<func_arguments\> ) do \<function_body\> end

\<function_name\> ::= \<low_identifier\>

\<func_arguments\> ::= \<low_identifier\> | \<identifier\> , \<func_arguments\>

\<function_body\> ::= \<expression\> | \<expression\> \<function_body\>

\<expression\> ::= \<alphanumeric\>*

## **General**

\<upp_identifier\> ::= \<upper_letter\> | \<upper_letter\> \<alphanumeric\>

\<low_identifier\> ::= \<lower_letter\> | \<lower_letter\> \<alphanumeric\>

\<lower_letter\> ::= a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z

\<upper_letter\> ::= A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z

\<digit\> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

\<alphanumeric\> ::= \<lower_letter\> | \<upper_letter\> | \<digit\>

---
# EBNF Notation
## **Modules**
MODULE ::== "defmodule" MODULE_NAME "do" MODULE_BODY "end"

MODULE_NAME ::= UPP_IDENTIFIER

MODULE_BODY ::= (FUNCTION | FUNCTION MODULE_BODY)

## **Functions**

FUNCTION ::== "def" FUNCTION_NAME '(' FUNC_ARGUMENTS ')' "do" FUNCTION_BODY "end"

FUNCTION_NAME ::= LOW_IDENTIFIER

FUNC_ARGUMENTS ::= EXPRESSION | EXPRESSION FUNC_ARGUMENTS 

FUNCTION_BODY ::= EXPRESSION | EXPRESSION FUNCTION_BODY 

EXPRESSION ::= { ALPHANUMERIC }

## **General**

UPP_IDENTIFIER ::= UPPER_LETTER | UPPER_LETTER ALPHANUMERIC

LOW_IDENTIFIER ::= LOWER_LETTER | LOWER_LETTER ALPHANUMERIC

LOWER_LETTER ::= 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm' | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z'

UPPER_LETTER ::= 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L' | 'M' | 'N' | 'O' | 'P' | 'Q' | 'R' | 'S' | 'T' | 'U' | 'V' | 'W' | 'X' | 'Y' | 'Z'

DIGIT ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

ALPHANUMERIC ::= LOWER_LETTER | UPPER_LETTER | DIGIT