
/**
 * CMSC 330 6380 
 * Project 1
 * Anthony Borza
 * February 5, 2017
 * Eclipse under Windows 10
 * 
 * GUIParser.java: the purpose of this class to to write a program that parses, 
 * using recursive descent, a GUI definition language that is defined in an input
 * file and generate the GUI that it defines, using a supplied lexical analyzer. The 
 * grammar for this project is the following:
 * 
	   gui ::=
	    	Window STRING '(' NUMBER ',' NUMBER ')' layout widgets End '.'
	    	
		layout ::=
	    	Layout layout_type ':'
	    	
		layout_type ::=
	    	Flow |
	    	Grid '(' NUMBER ',' NUMBER [',' NUMBER ',' NUMBER] ')'
	    	
		widgets ::=
	    	widget widgets |
	    	widget
	    	
		widget ::=
		    Button STRING ';' |
		    Group radio_buttons End ';' |
		    Label STRING ';' |
		    Panel layout widgets End ';' |
		    Textfield NUMBER ';'
		    
		radio_buttons ::=
		    radio_button radio_buttons |
		    radio_button
		    
		radio_button ::=
	    	Radio STRING ';'

  *  Each segment of grammar represents a method in this class, as you will see 
  *  throughout this class. The class uses a variety of switch statements, and
  *  if, else if, and else statements that are defined in each method. The goal 
  *  of this program is to understand the meaning of the symbols in the above 
  *  production, which will help you better understand the necessary actions
  *  that are performed when each of the productions (segments of grammar) 
  *  are parsed.
 */

// imports that are used throughout the program

import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.io.IOException;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;


public class GUIParser 
{
	// calls the classes Token.java, and Lexer.java
	
	private Token token;				// calls Token.java class, and assigns it the variable token
    private Lexer lexer;				// calls Lexer.java class, and assigns it the variable lexer

    // Components of the GUI
    
    private JFrame frame;				// frame is declared as a JFrame and set to private
    private JFileChooser jfc;			// jfc is declared as a JFileChooser and set to private
    private ButtonGroup bg1;			// bg1 is declared as a ButtonGroup  and set to private
    private Container container;		// container is declared as a Container and set to private
    private Container parentContainer;	// privateContainer is declared as a Container and set to private
    private JPanel panel;    			// panel is declared as a JPanel and set to private
    
  //-----------------------------------------------------------Constructor -------------------------------------------------------------------------//    
    
   /**
    * Constructor: calls the readFileMethod, which is used to read in a file to be parsed
    * using the defined grammar for this assignment.
    */
    
    public GUIParser()
    {
    	readFile();		// calls readFile method
    }
    
    
    //-----------------------------------------------------------readFile Method --------------------------------------------------------------------//
    /**
     * readFile method: purpose is to read in a file to be parsed. If the 
     * file is not in the correct format, it will catch it and either throw
     * a Syntax error, or IOException error.
     */
    
    public void readFile()
    {
        try		//	exception handling 
        {
            jfc = new JFileChooser(".");	// chose file from current directory
            
            if(jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)		// displays dialog box for opening file
            {
                 lexer = new Lexer(jfc.getSelectedFile().toString());		// calls the Lexer class and reads that specific file in as a string
            }
            getNextToken();			// calls getNextToken method
            this.GUI();				// calls the parseGUI method
        } 
        catch(SyntaxError e) 		// catches a syntax error 
        {
        	JOptionPane.showMessageDialog(null, "An syntax error has occured:\n" + e);		// displays a syntax error message has occurred
        	System.out.println(e);
        }
        catch(IOException e) 		// catches a syntax error 
        {
        	JOptionPane.showMessageDialog(null, "No File Found error has occured:\n" + e);		// displays a syntax error message has occurred
        	System.out.println(e);
        }
    }
    
    //-----------------------------------------------------------getToken Method --------------------------------------------------------------------//
    
    /**
     * getNextToken method: a method that is called to get the next token in the 
     * file that is being read in, and getting parsed. 
     * @throws SyntaxError
     * @throws IOException
     */
    
    public void getNextToken() throws SyntaxError, IOException
    {
          token = lexer.getNextToken();	// gets the next token by calling the Lexer.java class, and the getNextToken() method 
    }
        
    //-----------------------------------------------------------GUI Method --------------------------------------------------------------------//
    
    /**
     * boolean GUI method: this method is used to parse through the following
     * grammar that is stated below.
     * 
     * Grammar for this method:
     * gui ::= 
     * 	  Window STRING '(' NUMBER ',' NUMBER ')' layout widgets End '.'	
     *  
     * Terminal Symbols: Window STRING '(' NUMBER ',' NUMBER ')' End '.'
     * Nonterminal Symbols: gui layout widgets
     * BNF Metasymbol's: ::=
     * 
     * @return false
     * @throws SyntaxError
     * @throws IOException
     */
    
    public boolean GUI() throws SyntaxError, IOException
    {
    	int width; 		// represents  NUMBER in the grammar shown above, is width of window, and is also of data type integer 
    	int height;		// represents  NUMBER in the grammar shown above, is height of window, and is also of data type integer
    	
        if(token == Token.WINDOW)												// if the token in the file represents WINDOW, and is labeled for example in the file input.txt, Window  		
        {
            getNextToken();														// calls getNextToken method
            
            if(token == Token.STRING)  											// if the token in the file represent the STRING, and is labeled for example in the file input.txt, "Basic Calculator"		
            {
                container = frame = new JFrame(lexer.getLexeme());				// calls the getLexeme method from the Lexer.java class, and sets the top border of the frame window to "Basic Calculator"	
                getNextToken();													// calls getNextToken method
      
                if(token == Token.LEFT_PAREN)									// if the token in the file represent a LEFT parenthesize and is labeled for example in the file input.txt, '(' 
                {
                	 getNextToken();											// calls getNextToken method
            
                    if(token == Token.NUMBER)									// if the token in the file represent a NUMBER, which in our case would be the width 
                    {
                        width = (int) lexer.getValue();							// gets the value of that NUMBER and sets the width to the defined number in the text file
                        getNextToken();											// calls getNextToken method
              
                        if(token == Token.COMMA)								// if the token in the file represent a COMMA and is labeled for example in the file input.txt  ','
                        {
                        	 getNextToken();									// calls getNextToken method
                        	
                            if(token == Token.NUMBER)							// if the token in the file represent a NUMBER, which in our case would be the height 
                            {
                                height = (int) lexer.getValue();				// gets the value of that NUMBER and sets the height to the defined number in the text file
                                getNextToken();									// calls getNextToken method
                          
                                if(token == Token.RIGHT_PAREN)					// if the token in the file represent a RIGHT parenthesize and is labeled for example in the file input.txt, ')' 
                                {
                                    frame.setSize(width, height);				// sets the frame to defined numbers in the file
                                    getNextToken();								// calls getNextToken method
                            
                                    if(Layout(container))						// calls Layout, and passes in container as a parameter
                                    {    
                                    	getNextToken();							// calls getNextToken method
                                    	
                                    	if(Widgets(container))					// calls Widgets method and passes in a container
                                    	{
	                                    	if(token == Token.END) 				// if the token in the file represents the END of the line and is labeled for example in the file input.txt End
	                                        {
	                                    		getNextToken();					// calls getNextToken method
	                                     
	                                            if(token == Token.PERIOD)		// if the token in the file represents a PERIOD and is labeled for example in the file input.txt '.'
	                                            {
	                                            	 frame.setMinimumSize(new Dimension(width, height));	// sets the size of frame: width, height
	                                                 frame.setVisible(true);								// set the visibility of the frame to true
	                                                 return true;											// then return true	                                                 
	                                            }	                                            
	                                         }		                                    	
                                          }	                                    
                                       }                                
                                   }	
                                }
                            }
                        }
                    }
                }
            }	
        return false;	// return false
    }
    

    
  //----------------------------------------------------------------Layout Method --------------------------------------------------------------------//
    
    /**
     * Layout method: this method it defined to get the layout type of the file that is being read
     * in. 
     * 
     * Grammar for this method:
     * layout ::= 
     * 	  Layout layout_type ':' 	
     *  
     * Terminal Symbols: layout ':'
     * Nonterminal Symbols: layout layout_type
     * BNF Metasymbol's: ::=
     * 
     * @return false
     * @throws SyntaxError
     * @throws IOException
     * @return false
     */
     
    public boolean Layout(Container container) throws SyntaxError, IOException 
    {
    	 if(token == Token.LAYOUT)				// if the token in the file for layout is equal to the LAYOUT	
    	 {
    		  getNextToken();					// calls getNextToken method
              
              if(LayoutType(container))			// calls LayoutType method and passes in a container
              {
            	  getNextToken();				// if the getLayoutType method and token are equal to a COLON ':' in the file
             
            	  if(token == Token.COLON)		// if the token in the file is labeled COLON ":"
            	  {					
            		  return true;				// return true
            	  }
              }
          }
          return false;		// returns false
    }

    //-----------------------------------------------------------LayoutType Method --------------------------------------------------------------------//
    
    /**
     * LayoutType method: This method defines both the Flow and Grid layout of the defined grammar. 
     * This method implements a switch statement for Flow and Grid. This takes care of the number
     * of rows, columns, horizontal column gap, and vertical row gap for Grid layout. 
     * 
     * Grammar for this method:
     * layout_type ::= 
     * 	   Flow | 
     *     Grid '(' NUMBER ',' NUMBER [ ',' NUMBER ',' NUMBER] ')'
     *  
     * Terminal Symbols: Flow and Grid '(' NUMBER ',' NUMBER  ',' NUMBER ',' NUMBER ')'
     * Nonterminal Symbols: layout_type
     * BNF Metasymbol's: ::= | and [ ]
     * @param container
     * @return false
     * @throws SyntaxError
     * @throws IOException
     */
    
    public boolean LayoutType(Container container) throws SyntaxError, IOException 
    {
    	 int rows;						// represents  NUMBER for Grid layout in the grammar shown above, is number of rows, and is also of data type integer
    	 int columns;					// represents  NUMBER for Grid layout in the grammar shown above, is number of columns, and is also of data type integer
    	 int horizontalColumnGap;		// represents  NUMBER for Grid layout in the grammar shown above, is horizontal column gap, and is also of data type integer
    	 int verticalRowGap;			// represents  NUMBER for Grid layout in the grammar shown above, is vertical column gap, and is also of data type integer
    	 
    	 switch(token)		// start of switch statement
    	 {
    	 	case FLOW:		// case for if the GUI layout is FLOW
	        	
	            container.setLayout(new FlowLayout());					// sets layout of container to Flow       
	            return true;											// return true
	            
    	 	case GRID:		// case for if the GUI layout is GRID
	        
    	 		getNextToken();											// calls getNextToken method	
	                      
	            if(token == Token.LEFT_PAREN)							// if the token in the file represent a LEFT parenthesize and is labeled for example in the file input.txt, '(' 
	            {
	            	getNextToken();										// calls getNextToken method           
	                
	                if(token == Token.NUMBER)							// if the token in the file represent a NUMBER, which in our case would number of rows
	                {
	                    rows = (int) lexer.getValue();					// gets the number of rows, for example, in the input.txt file it is 6, and then cast it to an integer
	                    getNextToken();									// calls getNextToken method
	                                        
	                    if(token == Token.COMMA)						// if the token in the file represent a COMMA and is labeled for example in the file input.txt  ',' 
	                    {
	                    	getNextToken();								// calls getNextToken method
	                                                
	                        if(token == Token.NUMBER)					// if the token in the file represent a NUMBER, which in our case would be the number of columns
	                        {
	                            columns = (int) lexer.getValue();		// gets the number of columns, for example, in the input.txt file it is 4, and then cast it to an integer
	                            getNextToken();							// calls getNextToken method	
	   
	                            if(token == Token.RIGHT_PAREN)			// if the token in the file represent a RIGHT parenthesize and is labeled for example in the file input.txt, ')'
	                            {
	                            	container.setLayout(new GridLayout(rows, columns));		// sets layout for number of rows, and columns
	                                return true;											// return true
	                            }	                            
	                            else if(token == Token.COMMA)								// if the token in the file represent a COMMA and is labeled for example in the file input.txt  ',' 
	                            {
	                            	getNextToken();											// calls getNextToken method
	
	                                if(token == Token.NUMBER)								// if the token in the file represent a NUMBER, which in our case would be horizontal column gap
	                                {
	                                    horizontalColumnGap = (int) lexer.getValue();		// gets the value for the horizontal column gap if it is defined in the file
	                                    getNextToken();										// calls getNextToken method
	            
	                                    if(token == Token.COMMA)							// if the token in the file represent a COMMA and is labeled for example in the file input.txt  ','
	                                    {
	                                    	getNextToken();									// calls getNextToken method
	  
	                                        if(token == Token.NUMBER)						// if the token in the file represent a NUMBER, which in our case would be vertical row gap
	                                        {
	                                            verticalRowGap = (int) lexer.getValue();	// gets the value for the vertical row gap if it is defined in the file 
	                                            getNextToken();								// calls getNextToken method	
	             
	                                            if(token == Token.RIGHT_PAREN)				// if the token in the file represent a RIGHT parenthesize and is labeled for example in the file input.txt, ')'
	                                            {
	                                            	container.setLayout(new GridLayout(rows, columns, horizontalColumnGap, verticalRowGap)); 	// sets layout of container	         	                                  
	                                                return true;		// return true
	                                            }
	                                        }
	                                    }
	                                }
	                            }
	                        }
	                    }
	                }
	            }
		default:		// default statement
        }
        return false;	// returns false
    }
 
    //-----------------------------------------------------------Widgets Method --------------------------------------------------------------------//
    
    /**
     * Widgets method:this method it defined to get the Widgets of the file that is being read
     * in. 
     * 
     * Grammar for this method:
     * widgets ::= 
     * 	  widget widgets |
     * 	  widget	
     *  
     * Terminal Symbols: None
     * Nonterminal Symbols: widgets widgets widget widget
     * BNF Metasymbol's: ::= |
     * 
     * @return false
     * @throws SyntaxError
     * @throws IOException
     */
   
    public boolean Widgets(Container container) throws SyntaxError, IOException
    {
        if(Widget(container))			// if Widget method and passes in a container    	         
        {
        	getNextToken();				// gets the next token	
        	
        	if(Widgets(container))		// if Widgets method and passes in a container    	
        	{
        		return true;			// return true
        	}
        	return true;				// return true
        }
        return false;					// return false
    }


    //-----------------------------------------------------------Widget Method --------------------------------------------------------------------//
    
    /**
     * Widget method: This method implements a switch statement, and is different then most of 
     * the other methods defined throughout the this class.The purpose of this method is to show that 
     * you can use a switch statement to parse the following grammar that is shown below the same way
     * you could if you use if, else if, and else statements. It is more efficient to use a switch statement
     * where you have a number of cases like in this one, BUTTON, GROUP, LABEL, PANEL, TEXTFIELD
     * 
     * Grammar for this method:
     * widget ::= 
     * 	  Button STRING ';' |
     * 	  Group radio_buttons End ';' |
     * 	  Label STRING ';' |
     * 	  Panel layout widgets End ';' |
     * 	  Textfield NUMBER ';'	
     *  
     * Terminal Symbols: Button STRING ';' Group End ';' Label STRING ';' Panel End ';' Textfield NUMBER ';'
     * Nonterminal Symbols: radio_buttons layout widgets
     * BNF Metasymbol's: ::= |
     * @param container 
     * @return false
     * @throws SyntaxError
     * @throws IOException
     */
    
    public boolean Widget(Container container) throws SyntaxError, IOException 
    {   	
    	switch(token)		// start of switch statement 
    	{
	    	case BUTTON:	// case for BUTTON 
	       
	    		getNextToken();					// calls getNextToken method
	            
	            if(token == Token.STRING)		// if token in the file represents the name of the button, where STRING represents name
	            {
	            	JButton button = new JButton(lexer.getLexeme());		// gets the lexeme associated with the current token
	                getNextToken();											// calls getNextToken method
	                
	                if(token == Token.SEMICOLON)	// if token in the file represents the a SEMICOLON ';' 
	                {
	                	  container.add(button);	// adds button to container
                          return true;				// return true
	                }
	            }
	            
	    	case GROUP:		// case for GROUP 
	    		
	    		getNextToken();	
	            bg1 = new ButtonGroup();					// create a new ButtonGroup named bgl
	            											// calls getNextToken method
	            if(RadioButtons(container, bg1))			// calls the RadioButtons method and passes in a container and radio button
	            {
	                if(token == Token.END)					// if the token in the file represents the END of the line 
	                {
	                	getNextToken();						// calls getNextToken method
	                    
	                    if(token == Token.SEMICOLON)		// if token in the file represents the a SEMICOLON ';' 
	                    {	
	                        return true;					// return true
	                    }
	                }
	            }

	    	case LABEL:		// case for LABEL 
	    		
	    		getNextToken();										// calls getNextToken method
	            
	            if(token == Token.STRING)							// if token in the file represents the name of the LABEL, where STRING represents name of that label
	            {
	            	JLabel label = new JLabel(lexer.getLexeme());	// gets the lexeme associated with the current token	
	                getNextToken();									// calls getNextToken method	
	                
	                if(token == Token.SEMICOLON)					// if token in the file represents the a SEMICOLON ';' 
	                {	                  					
                        container.add(label);						// adds label to container
	                    return true;								// returns true
	                }	             
	            }
	     
	    	case PANEL:		// case for PANEL 
	 
	    		 getNextToken();									// calls getNextToken method
                 parentContainer = panel = new JPanel();			// new JPanel named panel
                 container.add(panel);								// adds panel to container
                 container = panel;									// container is panel
                 
	            if(Layout(container))								// calls Layout method and passes in container as a parameter 
	            {
	            	getNextToken();									// calls getNextToken method
	            
	                if(Widgets(container))							// calls Widgets method and passes in container as a parameter 
	                {
	                	container = parentContainer;				// container is parentContainer
	                	
	                    if(token == Token.END)						// if the token in the file represents the END of the line 
	                    {
	                    	getNextToken();							// calls getNextToken method
	                        
	                        if(token == Token.SEMICOLON)			// if token in the file represents the a SEMICOLON ';' 
	                        {
	                            return true;						// return true
	                        }
	                    }
	                }
	            }

	    	case TEXTFIELD:		// case for TEXTFIELD
	    		
	    		getNextToken();										// calls getNextToken method
	            
	            if(token == Token.NUMBER)							// if the token in the file represent a NUMBER, which in our case would be the width of the textfield
	            {
	            	JTextField textFieldWidth = new JTextField((int)lexer.getValue());			// gets the width of the textfield in the file, for example, 20
	                getNextToken();																// calls getNextToken method
	                
	                if(token == Token.SEMICOLON)					// if token in the file represents the a SEMICOLON ';' 
	                {
	                    container.add(textFieldWidth);				// adds the width of the text field to the container
	                    return true;								// return true
	                }
	            }
	            
			default: 	// default	
					
	        }
    	return false;	// return false
    }
    
    //-----------------------------------------------------------RadioButtons Method --------------------------------------------------------------------//
    
    /**
     * RadioButtons method:this method it defined to get the RadioButtons in the file that is being read
     * in. This is used to not only create a new container, but to group the radio buttons.
     * 
     * Grammar for this method:
     * radio_buttons ::= 
     * 	  radio_button radio_buttons |
     * 	  radio_button	
     *  
     * Terminal Symbols: None
     * Nonterminal Symbols: radio_buttons radio_buttons radio_button radio_button
     * BNF Metasymbol's: ::= |
     * 
     * @return false
     * @return true
     * @return true
     * @throws SyntaxError
     * @throws IOException
     */
     
    public boolean RadioButtons(Container container, ButtonGroup group)  throws SyntaxError, IOException
    {
        if(RadioButton(container,group))		// if RadioButton method and passes in a container, group as a parameter		              
        {
        	getNextToken();						// getNextToken
        	
        	if(RadioButtons(container, group))	// if RadioButtons method and passes in a container, group as a parameter	  	
        	{
        		return true;	// return true
        	}
        	return true;		// return true
        }
     return false;				// return false
    }					            

    //-----------------------------------------------------------RadioButton Method --------------------------------------------------------------------//
    
    /**
     * RadioButton method: This method gets the radio button from the file, and creates
     * a new JRadioButton, naming it button, and then calls the getLexeme method (tokenizer.sval)
     * in the Lexer class. Once it gets that it then adds the button to the container, and then 
     * adds that button to the button group.
     * 
     * Grammar for this method:
     * radio_button ::= 
     * 	  Radio STRING ';'
     * 	  
     * Terminal Symbols:  Radio STRING ';'
     * Nonterminal Symbols: radio_button
     * BNF Metasymbol's: ::= 
     * @param group 
     * @param container 
     * 
     * @return false
     * @throws SyntaxError
     * @throws IOException
     */
    
    public boolean RadioButton(Container container, ButtonGroup group) throws SyntaxError, IOException
    {
       if(token == Token.RADIO)						// if token in the file represents the a radio button where Radio represents the button name for example, Radio 'a'
       {     	
    	   getNextToken();							// calls getNextToken method

            if(token == Token.STRING) 				// if token in the file represents the name of the Radio button, where STRING represents name
            { 
                JRadioButton button = new JRadioButton(lexer.getLexeme());	// new JRadioButton
                getNextToken();						// getNextToken			

                if(token == Token.SEMICOLON)		// if token in the file represents the a SEMICOLON ';' 
                {
            	   container.add(button);			// adds button to container
                   bg1.add(button);					// adds button to button group
                   return true;						// return true
                }
            }
        }
        return false;	// return false
    }
 
    //-----------------------------------------------------------Main Method --------------------------------------------------------------------//
    
    /**
     * main method: used to execute program
     * @param args
     */
    
    public static void main(String[] args)
    {
    	 new GUIParser();	// calls class
    }
}