/*****************************************************************************
*
*Student: Eddie Corbett
*Date: 10/9/13
*Assignment #: 4.1
*Professor: Farhinger 
*
*
*                       This program asks a user how many days they will work. 
*                       Their total pay is based on if they were paid one penny
*                       for the first day and each day they work the amount 
*                       doubles.
*
*******************************************************************************/
															
import javax.swing.JOptionPane;
import java.text.DecimalFormat;		

public class PenniesForPay
{
   public static void main(String[] args)
   {
/**************************************Declarations****************************/   
      String inputString, OutMessage;
      int pennies;
      int maxDays;
      int day;
      double totalPay;

/*****************************************Input********************************/      

      inputString = JOptionPane.showInputDialog("How many days will you work? ");
      maxDays = Integer.parseInt(inputString);
      
      day = 1;		

/************************************If Statement For Days < 1*****************/      						
		if (maxDays < 1)
      {
      inputString = JOptionPane.showInputDialog("You must work at least 1 day to get paid "+
                                                "\nPlease enter a number greater than or equal to 1 ");
      maxDays = Integer.parseInt(inputString);
      }
/******************************************For Loop****************************/      
                        
      day = 1;                                                                  //Initialize Variables
      pennies = 1;
      totalPay = 0;																								
																									    	
      OutMessage = ("");                                                        //Initializing OutMessage

      for (day = 1; day < maxDays; day++)
      {
      
      OutMessage = OutMessage + ("Day: " + day + " Pennies Earned: " + pennies + "\n" );
       
      totalPay = totalPay + pennies;

      pennies = pennies * 2;
      }
  
/******************************************Output********************************/ 


      totalPay = totalPay / 100.00;                                             //Calculating Pennies to Dollars
      DecimalFormat formatter = new DecimalFormat("#,##0.00");                  //Format Pennies to Dollars
      
      JOptionPane.showMessageDialog(null, OutMessage + "\nTotal Pay: " + "$" + formatter.format(totalPay), 
                                        "Pennies For Pay", JOptionPane.INFORMATION_MESSAGE);
      
      }
      

}
