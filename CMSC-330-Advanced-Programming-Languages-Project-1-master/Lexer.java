
/**
 * CMSC 330 6380 
 * Project 1
 * Anthony Borza
 * February 5, 2017
 * Eclipse under Windows 10
 * 
 * This class was provided by the professor
 * This class provides the lexical analyzer for project 1
 */

// import used

import java.io.*;

public class Lexer
{
    private static final int KEYWORDS = 11;		// number of keywords that are use, which appears to be 11
    private StreamTokenizer tokenizer;			// takes an input stream and parses it into "tokens", allowing the tokens to be read one at a time
    private String punctuation = ",:;.()";		// punctuation declared as a string
    
   // Array of punctuationTokens from the class Token. The tokens defined 
   // below are Enumerated from the class Token.
    
    private Token[] punctuationTokens =
    {
        Token.COMMA, Token.COLON, Token.SEMICOLON, Token.PERIOD, Token.LEFT_PAREN, Token.RIGHT_PAREN	// enum constants from Token class
    };

    /**
     * Constructor that creates a lexical analyzer object given the source file
     * @param fileName
     * @throws FileNotFoundException
     */

    public Lexer(String fileName) throws FileNotFoundException
    {
        tokenizer = new StreamTokenizer(new FileReader(fileName));	// creates a tokenizer that parses the given characters in the file
        tokenizer.ordinaryChar('.');			// specifies character element '.' is ordinary in the tokenizer     
        tokenizer.quoteChar('"');				// specifies " as a quote char
    }

    /**
     * returns the next token in the input stream
     * @return Token.EOF
     * @throws SyntaxError
     * @throws IOException
     */
    
    public Token getNextToken() throws SyntaxError, IOException
    {
        int token = tokenizer.nextToken();				// parses the next token from the input stream of this tokenizer
        
        switch(token)									// switch statement that switches to the next token after previous one has been parsed
        {
            case StreamTokenizer.TT_NUMBER:				// a constant indicating that a number token has been read
            	
                return Token.NUMBER;					// returns that number token that has been read in
                
            case StreamTokenizer.TT_WORD:				// a constant indicating that a word token has been read.
            	
                for(Token aToken : Token.values())		// for each element aToken of type Token in array Token.values()
                {
                    if(aToken.ordinal() == KEYWORDS)	// if the ordinal of enumeration constant, and positioned in the enum declaration, where the initial constant is assigned an ordinal of zero is equal to KEYWORDS
                    {		
                    	break;					// break
                    }
                    if(aToken.name().equals(tokenizer.sval.toUpperCase()))	// if name of token is a word and equals the current token, which is a word token, it will give the token in upper case 
                    {
                    	return aToken;			// return aToken
                    }
                }
                throw new SyntaxError(lineNo(), "Invalid token " + getLexeme());	// throws a Syntax error exception
                
            case StreamTokenizer.TT_EOF:	// indicates that the end of the input stream has been reached
            	
                return Token.EOF;			// returns token at end of the input stream
           
            case '"':						// case for '"'
            	
                return Token.STRING;		// return that specific token as a string
                
            default:	// default
            	
                for(int i = 0; i < punctuation.length(); i++)	// as long as i is equal to zero, and i is less than the length of the string punctuation, then increment 
                {
                    if(token == punctuation.charAt(i))			// if the token is at that specific index
                    {
                        return punctuationTokens[i];			// return that token
                    }
                }
        }
        return Token.EOF;		// return token at the end of the input stream
    }

    /**
     * Returns the lexeme associated with the current token
     * @return tokenizer.sval
     */
    
    public String getLexeme()
    {
        return tokenizer.sval;	// will return if the current token is a word token, and this field contains a string giving the characters of the word token
    }

    /**
     * Returns the numeric value of the current token for numeric tokens
     * @return tokenizer.nval
     */
    
    public double getValue()
    {
        return tokenizer.nval;	// will return if the current token is a number token, and this field contains a value of that number
    }

    /**
     * Returns the current line of the input file
     * @return tokenizer.lineno
     */
    
    public int lineNo()
    {
        return tokenizer.lineno();	// returns the current line number of the stream tokenizer
    }
}
