/******************************************************************************
*
*Student: Eddie Corbett
*Date: 10/19/13
*Assignment #: 9.1
*Professor: Farhinger 
*
*
*                       This program asks a user to input a phone number 
*                       in the form XXX-XXX-XXXX containing a combination
*                       of numbers and letters and converts the string to 
*                       just numbers.
*                       
*                       
*
*******************************************************************************/

import javax.swing.JOptionPane;

public class NumberConvert
{  
   public static void main(String[] args)
   {   
   String num1,num2; 
   num1 = JOptionPane.showInputDialog("                     Enter a phone number"+ //Ask user to input number
                              "\ncontaining alphabetic characters in the format"+
                              "\n                         XXX-XXX-XXXX");          
                                                                                   //Sends a copy of user input
   num2=PhoneTranslator(num1);                                                     //to PhoneTranslator Method
  
/******************************************Output*******************************/  
   JOptionPane.showMessageDialog(null, "The number you entered is: " + num1 +                                                                                     
                                 "\nThe numeric version of that number is: " +      
                                                 num2);                          
   }
/**************PhoneTranslator Method - Translates User Input to All Numbers****/  
   public static String PhoneTranslator(String num1)
   {      
      StringBuilder translated = new StringBuilder("");
      for (int index = 0; index < num1.length(); index++)                       //For Method goes through user 
      {                                                                         //input one character at at time
         char ch = getPhoneDigit(num1.charAt(index));                           //Any letters sent to the 
         translated.append(ch);                                                 //getPhoneDigit method are      
      }                                                                         //converted to letters
      
      
      return translated.toString();                                             //Sends new string containing
                                                                                //converted phone number
   }      
/********getPhoneDigit Method - Works within PhoneTranslator Method and Converts**
**********************************Any Letters to Nubmers**************************/
   public static char getPhoneDigit(char c)
   {
      char digit;      
      // Get the uppercase version of the character.
      c = Character.toUpperCase(c);
      // See if it is A, B, or C.
      if (c == 'A' || c == 'B' || c == 'C')
         digit = '2';
      // Otherwise, see if it is D, E, or F.
      else if (c == 'D' || c == 'E' || c == 'F')
         digit = '3';
      // Otherwise, see if it is G, H, or I.
      else if (c == 'G' || c == 'H' || c == 'I')
         digit = '4';
      // Otherwise, see if it is J, K, or L.
      else if (c == 'J' || c == 'K' || c == 'L')
         digit = '5';
      // Otherwise, see if it is M, N, or O.
      else if (c == 'M' || c == 'N' || c == 'O')
         digit = '6';
      // Otherwise, see if it is P, Q, R, or S.
      else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
         digit = '7';
      // Otherwise, see if it is T, U, or V.
      else if (c == 'T' || c == 'U' || c == 'V')
         digit = '8';
      // Otherwise, see if it is W, X, Y, or Z.
      else if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
         digit = '9';
      // Otherwise, leave the character as it is.
      else
         digit = c;      
      // Return the translated character.
      return digit;
   }
}


      
      
      
  

   
  
