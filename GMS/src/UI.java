 /**

* UI, get student's ID and prompt command messages.

* @author Leafy

* @Time 2016/3/19

*

*/

import java.util.Scanner;
public class UI {
	
	/**
	 * @uml.property  name="iD"
	 */
	public long ID;                                                     //student ID
	/**
	 * @uml.property  name="input"
	 */
	public Scanner input = new Scanner(System.in) ;                       
	/**
	 * @uml.property  name="gS"
	 * @uml.associationEnd  multiplicity="(1 1)"
	 */
	public GradeSystems GS = new GradeSystems("gradeinput.txt");   //file

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		UI ui = new UI();
		ui.promptID();
		ui.input.close();
	}
	private void isLong(String str)
	{
		/**
		 * judge whether the user's input can be invert to long, str is the user's input, a string 
		 * @param str  the string to be judged
		 */
		boolean islong = true;
		try{
			ID = Long.parseLong(str);
		}
		catch(NumberFormatException ID){
			islong = false;
			System.out.println("Wrong ID!");
			promptID();	
		}
		finally{
			if(islong)checkID(ID);
		}
	}
	
	private void promptID()
	{
		/**
		 * show prompt message and get ID
		 */
		System.out.print("輸入ID或 Q (結束使用)？");
		String str = input.next();
//		System.out.println(str);
		if(str.equals("Q")){
			input.close();
			ShowFinishMsg(); }
		else{
			if( str.length() == 9){ isLong(str); }
			else{
				System.out.println("Wrong ID!");
				promptID(); } }
	}
	
	private void ShowFinishMsg()
	{
		/**
		 *show finish message.
		 */
		System.out.println("結束了");
	}
	private void checkID(long ID)
	{
		/**
		 * check whether the ID is available. if not, show prompt message. 
		 * @param ID  student's ID
		 */
		String name = GS.contains(ID); 
		if("0".equals(name)==false)
		{
			ShowWelcomeMsg(name);
			promptCommand(ID);
		}
		else
		{
			System.out.println("ID錯了!");
			promptID();
		}
	}
	private void ShowWelcomeMsg(String name)
	{
		/**
		 * show welcome message.
		 * @param name  student's name
		 */
		System.out.println("Welcome "+ GS.contains(ID));
		System.out.println("");
	}
	private void switchCommand(String choice)
	{
		/**
		 * deal with input and perform different operation. choice is user's input.
		 * @param choice  user's input
		 */
		switch(choice)
		{
		case "G":                             //show grade
			GS.showGrade(ID);
			promptCommand(ID);
			break;
		case "R":                             //show rank
			GS.showRank(ID);
			promptCommand(ID);
			break;
		case "A":                             //show average
			GS.showAverage(ID);
			promptCommand(ID);
			break;
		case "W":                             //update weight 
			GS.updateWeight();
			promptCommand(ID);
			break;
		case "E":                             //exit
			promptID();
			break;
		default :
			System.out.println("指令錯了!");    //deal with incorrect input
			promptCommand(ID);
		}
	}
	private void promptCommand(long ID)
	{
		/**
		 *show menu and get user's input.
		 *@param ID  student's ID
		 */
		System.out.println("輸入指令 1) G 顯示成績 (Grade)");
		System.out.println("      2) R 顯示排名 (Rank)");
		System.out.println("      3) A 顯示平均 (Average)");
		System.out.println("      4) W更新配分 (Weight)");
		System.out.println("      5) E 離開選單 (Exit)");
		
		String choice=input.next();
		System.out.println(choice);
		
		switchCommand(choice);
	}
}
