/******************************
*                             * 
*Eddie Corbett                *
*9/25/13                      *
*Assignment 3.1               *
*Professor: Daniel Fahringer  * 
*                             *
*This program uses if else    *
*statements to calculate      * 
*shipping costs based on      *
*dimensions of package        *
*and zipcode.  This program   *
*also uses JOptionPane and    *
*DecimalFormat to format the  *
*shipping cost to two decimal *
*places using dollar signs    *
*                             * 
*                             *  
/******************************/
import javax.swing.JOptionPane;	
import java.text.DecimalFormat;


public class ShippingCost2
{
		public static void main(String[] args)
		{    		
          
            //******************************************declarations*************************************//	
		     	String input, outmessage1, outmessage2;
            double weight, length, width, height, dimension, 
            charge,shippingcost,surchargeSubTotal;
            int zipcode, surcharge, surcharge4;                     
				//*********************************************input******************************************//            
            input = JOptionPane.showInputDialog("What is the zipcode? (first five digits only) ");			
		      zipcode = Integer.parseInt(input);
          
		      input = JOptionPane.showInputDialog("What is the weight? (lbs) ");			
		      weight = Double.parseDouble(input);																	
		
            input = JOptionPane.showInputDialog("What is the length? (in) ");
            length = Double.parseDouble(input);
 
            input = JOptionPane.showInputDialog("What is the width? (in) ");
            width = Double.parseDouble(input);
 
            input = JOptionPane.showInputDialog("What is the height? (in) ");
            height = Double.parseDouble(input);
            
            dimension = (length * width * height) + weight;          
            //***********************************calculations via if statements****************************//
  				if (weight <= 5)
               charge = 12;
            else if (dimension > 5 && dimension <= 15)
               charge = 14;
            else if (dimension > 15 && dimension <= 34)
               charge = 17;
            else if (dimension > 34 && dimension <= 45)
               charge = 21;
            else if (dimension > 45 && dimension <= 60)
               charge = 33;
            else 
               charge = 105;
            
            if (zipcode > 40000 && zipcode < 50000)
               surcharge = 5;               
            else if (zipcode > 60000 && zipcode < 70000)
               surcharge = 9;               
            else 
               surcharge = 14;
            
            if (surcharge == 5)
               surchargeSubTotal = (charge * .05);
            else if (surcharge == 9)
               surchargeSubTotal = (charge * .09);
            else
               surchargeSubTotal = (charge * .14);  
                           
            if (zipcode % 2 == 0)
               {surcharge4 = 2;}
            else 
               {surcharge4 = 0;}             
            
            if (surcharge4 == 0)
               shippingcost = surchargeSubTotal + charge;
            else 
               shippingcost = ((surchargeSubTotal + charge) * .02) + surchargeSubTotal + charge;                 
            
            //******************************************output********************************************//
            
            DecimalFormat formatter = new DecimalFormat("$0.00");      
            
            outmessage1 =
            "     Please verify this information is correct: " +
            "\n                                  Zipcode: \n- " + zipcode + 
            "\n                               Dimensions: \n- Weight: " 
            + weight + " lbs" + "\n- Legnth: " +
            length + " in" + "\n- Width: " + width + " in" + "\n- Height: " + height +
            " in\n" + 
            "\n                 Shipping Cost Before Surcharges: \n" +
            "\nIf under 5lbs, shipping cost is $12.00 otherwise," +
            "\nshipping cost is calculated as: " +
            "\nif (length * width * height + weight) is " +
            "\ngreater than 5 and less than or equal to 15 = $14.00" +
            "\ngreater than 15 and less than or equal to 34 = $17.00" +
            "\ngreater than 34 and less than or equal to 45 = $21.00" +
            "\ngreater than 45 and less than or equal to 60 = $33.00" +
            "\ngreater than 60 = $105.00";
                       
            outmessage2 =
            "\n                              Surcharge(s): \nSurcharge 1: " +
            "\n(if zipcode begins with number 4 surcharge = 5%) " +
            "\n(if zipcode begins with number 6 surcharge = 9%) " +
            "\n(all other zipcodes surcharge = 14%) \n" +
            "\nSurcharge 1 total: " + surcharge + "%\n" +           
            "\nSurcharge 2: \n(If zipcode is an even number extra surcharge of 2%) " + 
            "\n              (note: Surcharge 2 is added only" +
            "\n        after Surcharge 1 has been calculated)\n" +
            "\nSurcharge 2 total: " + surcharge4  +"%\n";
          
            JOptionPane.showMessageDialog(null,outmessage1 + "\nShipping Cost: " +
            formatter.format(charge) + "\n" + outmessage2 + "\nShipping cost including surcharges: " +
            formatter.format(shippingcost));
            
            System.exit(0);
      }
}
      
