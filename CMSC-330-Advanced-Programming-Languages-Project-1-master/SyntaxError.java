
/**
 * CMSC 330 6380 
 * Project 1
 * Anthony Borza
 * February 5, 2017
 * Eclipse under Windows 10
 * 
 * This class was provided by the professor
 */

// Class that defines a syntax error

public class SyntaxError extends Exception
{
	private static final long serialVersionUID = 1L;

	/**
     * Constructor that creates a syntax error object given the line number and error
     * @param line
     * @param description
     */

    public SyntaxError(int line, String description)
    {
        super("Line: " + line + " " + description);
    }
}