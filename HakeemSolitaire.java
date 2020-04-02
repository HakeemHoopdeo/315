/*Student Number: 218 067 924
  Name: Hakeem
  Date submitted: 02 / 10 / 2018
  Comp102 PegSolitaire Assessment (10 %)
*/
import java.util.Scanner;
class PegSolitaire {
   //field
   private char[][] cSolArr = new char[9][9]; 
   
   public void fill() {  //Q2
      for (int iRow = 0; iRow < cSolArr.length; iRow++) {
         for (int iCol = 0; iCol < cSolArr.length; iCol++) {
            if (((iRow > 2) && (iRow < 6)) || ((iCol > 2) && (iCol < 6)))
               cSolArr[iRow][iCol] = 'X';
            else
               cSolArr[iRow][iCol] = 'Z';
         }  //for loop (iCol)
      }  //for loop (iRow)
      cSolArr[4][4] = 'O';
   }  //end of fill() method 
     
   public void print() {  //Q3
      String sLine = "";
      String firstLine = "  "; 
      for (int iRow = 0; iRow < cSolArr.length; iRow++) {
      sLine += iRow + " ";  //used to start each row with the index values (0, 1, ... , 9)
      firstLine += iRow + " ";  //used to print a line showing the column position values (0, 1, ... , 9)
         for (int iCol = 0; iCol < cSolArr.length; iCol++) {
            if (cSolArr[iRow][iCol] != 'Z')
               sLine += cSolArr[iRow][iCol] + " ";  //creating the output in string sLine
            else 
               sLine += "  ";
         }  //for loop(iCol)  
         sLine += "\n"; //goes to the next line
      }  //for loop(iRow)
   System.out.println(firstLine + "\n" + sLine);
   }  //end of print() method
  
   public boolean isValid(int fromRow, int fromCol, int toRow, int toCol) {  //Q4 
      if (((((((fromRow == toRow) && (Math.abs(fromCol - toCol) == 2)) && (cSolArr[fromRow][(fromCol + toCol) / 2] == 'X'))) || 
         ((((fromCol == toCol) && (Math.abs(fromRow - toRow) == 2)) && (cSolArr[(fromRow + toRow) / 2][fromCol] == 'X'))))) &&
         (((cSolArr[toRow][toCol] == 'O') && (cSolArr[fromRow][fromCol] == 'X'))))//This method checks the given criteria to determine if it's valid
            return true;      
      return false;
   }  //end of isValid() method
   
   public boolean move(int fromRow, int fromCol, int toRow, int toCol) {  //Q5
      boolean bSuccess = false;  
      cSolArr[fromRow][fromCol] = 'O';
      cSolArr[toRow][toCol] = 'X';
      if (fromRow == toRow)  //if the columns differ by 2, we find average to get the column inbetween
         cSolArr[toRow][(fromCol + toCol) / 2] = 'O';
      else if (fromCol == toCol)  //if the rows differ by 2, we find average to get the row inbetween
              cSolArr[(fromRow + toRow) / 2][toCol] = 'O';   
      bSuccess = true;  //In the test class before we call this method we must check if the move is valid
      return bSuccess;
   }  //end of move() method
    
   public boolean isEmpty() {  //Q6
      int iCount = 0;  //keeps a track of how many pegs are on the board
      for (int iRow = 0; iRow < cSolArr.length; iRow++)
         for (int iCol = 0; iCol < cSolArr.length; iCol++)
            if (cSolArr[iRow][iCol] == 'X')
               iCount++;  //checks how many pegs are left
      if ((iCount == 1) && (cSolArr[4][4] == 'X'))  //checks if there's only 1 peg that is at the centre
         return true;
      else
         return false; 
   }  //end of isEmpty() method
}  //end of PegSolitaire class

class PegSolitaireApplication {
   public static void main(String[] args) {
      boolean bSuccess;   
      PegSolitaire myPegSolitaire = new PegSolitaire();  //creates object
      myPegSolitaire.fill();  //calls fill method
      System.out.println("The initial configuration: ");
      myPegSolitaire.print();  //Prints out the initial configuration
      Scanner key = new Scanner(System.in);
      int iInitialRow, iInitialCol, iNewRow, iNewCol;
      while (myPegSolitaire.isEmpty() == false) {
         try {
            System.out.println("Enter the InitialRow: ");
            iInitialRow = key.nextInt();
            System.out.println("Enter the InitialCol: ");
            iInitialCol = key.nextInt();
            System.out.println("Enter the New Row: ");
            iNewRow = key.nextInt();
            System.out.println("Enter the New Column: ");
            iNewCol = key.nextInt(); 
            if (myPegSolitaire.isValid(iInitialRow, iInitialCol, iNewRow, iNewCol)) {  //Makes a move if it is valid
               bSuccess = myPegSolitaire.move(iInitialRow, iInitialCol, iNewRow, iNewCol);
               System.out.println("The move is successful!\n");  //tells user if move is successful
               myPegSolitaire.print();
            } else {
               System.out.println("The move: (" + iInitialRow + " , " + iInitialCol + ") ---> (" + iNewRow + " , " + iNewCol + ") is unsuccessful!");                    
                   }
             } 
             catch (Exception e) {
               System.out.println("Please enter a valid integer!"); 
               key.nextLine();
             }
      }
      System.out.println("Congratulations! You have won!");
   }
}