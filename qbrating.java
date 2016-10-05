/******************************************************************************
*
*Student: Eddie Corbett
*Date: 10/19/13
*Assignment #: 5.1
*Professor: Farhinger 
*
*
*                       This program calculates a quarterback's rating based 
*                       on percentage of completions, average yards gained
*                       per attempt, percentage of touchdown passes, and 
*                       percentage of interceptions.  The program calculates
*                       each percentage using methods and requires the user
*                       to input statistics for each player.
*
*******************************************************************************/
import javax.swing.JOptionPane;
import java.text.DecimalFormat;
public class QBRating
{
/***************************************Methods*********************************/

public static void main(String[] args)       // This is the main method that requests data from 
                                             // all the other methods
	{
		String name;
      int att; 
      double comp, yards, td, intcep, rate;
		
      name=getName();
		att=getAtt();
		comp=calcComp(att);
		yards=calcYards(att);
		td=calcTD(att);
      intcep=calcIntcep(att);
      rate=getRate(comp, yards, td, intcep);
		displayOutput(att, name, rate, comp, yards, td, intcep);				
	}	
public static String getName()               // This method asks the user for the player's name
   {
		String Name;		
		Name =JOptionPane.showInputDialog("Enter player's name"); // User input
		return Name;
	}
public static int getAtt()                   // This method asks the user for total attempted passes
	{                                         // and uses this data to calculate the other methods
		String input;
		int Att;
		input=JOptionPane.showInputDialog("Enter total attempted passes"); // User input
		Att=Integer.parseInt(input);
		return Att;
	}
	
public static double calcComp(int att)       // This method uses data from method getAtt to calculate percentage
	{                                         // of completed passes based on what the user inputs for
                                             // total completed passes
		String input;
      double Comp;		
      input=JOptionPane.showInputDialog("Enter total completed passes"); // User input
		Comp=Integer.parseInt(input);      
		Comp=(((double)Comp/att)-.3)* 5;		   // Calculations
      if (Comp > 2.375)
         Comp = 2.375;                       // If statements to define max and min
      if (Comp < 0)
         Comp = 0;      
		return Comp;
	}
public static double calcYards(int att)      // This method uses data from method getAtt to calculate average
   	{                                      // yards gained per attempt based on what the user inputs for
                                             // total yards gained 
		String input;
      double Yards;		
		input=JOptionPane.showInputDialog("Enter total yards gained"); // User input
		Yards=Integer.parseInt(input);      
      Yards=((Yards/att)-3)*.25;		         // Calculations
      if (Yards > 2.375)
         Yards = 2.375;                      // If statements to define max and min
      if (Yards < 0)
         Yards = 0;      
		return Yards;
	}	
public static double calcTD(int att)         // This method uses data from method getAtt to calculate percentage
	{                                         // of touchdown passes based on what the user inputs for total 
                                             // touchdowns
		String input;
      double TD;		
      input=JOptionPane.showInputDialog("Enter total touchdowns"); // User input
		TD=Integer.parseInt(input);      
      TD=(TD/att)*20;		                  // Calculations
      if (TD > 2.375)                        // If statement to define max
         TD = 2.375;           
		return TD;
	}
public static double calcIntcep(int att)     // This method uses data from method getAtt to calculate percentage
	{                                         // of interceptions based on what the user inputs for total 
		String input;                          // interceptions
      double Int, IntP;		
      input=JOptionPane.showInputDialog("Enter total interceptions"); // User input
		Int=Integer.parseInt(input);      
      Int=((Int/att)*100)*.25;               // Calculations
      IntP=2.375 - Int;      
      if (IntP < 0)                          // If statement to define min
         IntP = 0;		
		return IntP;                           
	}
   
                                             // This method calculates the player's rating using data caluclated
                                             // in previous methods to find the average by recieving arguments
                                             // passed to it from getRate() in the main method and converts
                                             // it to a percentage
public static double getRate(double comp, double yards, double td, double intcep)
	{
		double Rate;		
      Rate=((comp + yards + td + intcep) / 6) * 100;		 // Calculations
		return Rate;
	}
   

//**********************************Output*********************************/   
                                             // This method displays data found in one dialog box and recieves
                                             // arguments passed to it from displayOutput() in the main method
                                      
public static void displayOutput(int att,String name,double rate,double comp,double yards, 
                                       double td,double intcep)
	{			 
      DecimalFormat formatter = new DecimalFormat("#0.000");
		JOptionPane.showMessageDialog(null, name + "'s overall rating is " + formatter.format(rate) +
                                    "\nThe total attempted passes is " + att + 
                                    "\nThe percentage of completions " + formatter.format(comp) +
                                    "\nThe average yards per attempt is " + formatter.format(yards) + 
                                    "\nThe percentage of touchdown passes is " + formatter.format(td) + 
                                    "\nThe percentage of interceptions " + formatter.format(intcep));	
                                    	
		System.exit(0);
	}
	
}
