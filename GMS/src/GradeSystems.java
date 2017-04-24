/**

* Manage student's grade, respond to user's command.

* @author Leafy

* @Time 2016/3/19 

*

*/

import java.util.Scanner;

import java.util.Vector;

public class GradeSystems {
	
	/**
	 * @uml.property  name="name"
	 */
	public String name = new String();                              //student's name
	/**
	 * @uml.property  name="weight" multiplicity="(0 -1)" dimension="1"
	 */
	public int[] weight = {10,10,10,30,40};                         //origin weight.
	/**
	 * @uml.property  name="position"
	 */
	public int position;                                            //the index of a student in loadstudentfile.	
	
	/**
	 * @uml.property  name="weight_temp" multiplicity="(0 -1)" dimension="1"
	 */
	private int[] weight_temp = {0,0,0,0,0};                        //temporary weight.
	/**
	 * @uml.property  name="input"
	 */
	private Scanner input = new Scanner(System.in) ;
	/**
	 * @uml.property  name="num"
	 */
	private int num = 0;                                            
	/**
	 * @uml.property  name="isload"
	 */
	private	boolean isload = false;                                 //this is used to mark whether the file is loaded.
	private static Grades[] loadstudentfile;                        //all informations of students.
	private static int number;                                      //the number of students.
	/**
	 * @uml.property  name="studentfile"
	 */
	private String studentfile;

	/**
	 * @uml.property  name="markwords" multiplicity="(0 -1)" dimension="1"
	 */
	private String[] markwords = {"lab1          ","lab2          ","lab3          ","mid_term      ","final exam    ","total grade   "};
	/**
	 * @uml.property  name="markwords_grades" multiplicity="(0 -1)" dimension="1"
	 */
	private String[] markwords_grades = {"lab1:         ","lab2:         ","lab3:         ","mid_term:     ","final exam:   ","total grade:  "};
	
	public GradeSystems(String studentfile)
	{
		this.studentfile = studentfile;
		LoadStudentInfo();
	}
	private void is_int()
	{
		/**
		 * judge whether user's input is int.
		 * @exception num the user's input might be wrong.
		 */
		String value = input.next();
		try{
			num = Integer.parseInt(value);} 
		catch (NumberFormatException num) 
		{
			System.out.println("Not an Integer!");
			is_int();
		}
	}
	
	public void findPosition(long ID)
	{
		/**
		 *get the index of the student whose ID is user's current input. 
		 *@param ID  student's ID ,long
		 */
		int i ;
		for(i =0;i<number;i++){
			if(ID==loadstudentfile[i].getID()){
				position = i;
				return;
			}
		}
		position = -1;                      //if ID is wrong, position = -1.
	}
	
	public String contains(long ID)
	{
		/**
		 * judge whether ID exist.
		 * @param ID  student's ID
		 * @return if ID exists,return ID. Else return string "0".
		 */
		findPosition(ID);
		if(position == -1){return "0";}
		return loadstudentfile[position].getName();
	}
	private void notation(int i)
	{
		/**
		 *supply the output with indications of scores under 60.
		 *@param i the index of score which need to be marked in the array of student's score.
		 */
		if (loadstudentfile[position].getGrades()[i] >= 60){
			System.out.println(loadstudentfile[position].getGrades()[i]);}
		else{
			System.out.println(loadstudentfile[position].getGrades()[i] + "*");}
	}
	public void showGrade(long ID)
	{
		/**
		 * show the student's grade.
		 * @param ID  student's ID.
		 */
		loadstudentfile[position].CountAverage(weight);
		for(int i=0;i<6;i++)
		{
			System.out.print(markwords_grades[i]);
			notation(i);
		}
	}
	public int showRank(long ID)
	{
		/**
		 *show the rank.Calculate students' average score with current weight and count how many of them have a higher score.
		 *@pagram ID
		 *@return  return the value of student's rank.
		 */
		int count = 0;                                   
		for(int j=0;j<number;j++){                     //calculate all students' average scores.
				loadstudentfile[j].CountAverage(weight);
			}
		for(int j=0;j<number;j++)                      //count the number of studnets whose score is higher.
		{
				if((loadstudentfile[j].getAverage())> (loadstudentfile[position].getAverage())) 
			    {
					count += 1;
				}
		}
		System.out.println(loadstudentfile[position].getName() + " 排名第 " + (count+1));	
		return (count+1);
	}
	public void showAverage(long ID)
	{
		/**
		 *show average score.
		 *@param ID
		 */
		loadstudentfile[position].CountAverage(weight);
		System.out.println(ID + "  " + loadstudentfile[position].getName() + "   Average:" + loadstudentfile[position].getAverage());
	}
	private void showWeight()
	{  
		/**
		 *show origin weight. 
		 */
		System.out.println("舊配分");
		for(int i=0;i<5;i++)
		{
			System.out.println(markwords[i] + weight[i] + "%");
		}
		System.out.println("輸入新配分");
	}
	public String showNewWeight()
	{
		/**
		 *show the user's new weight and confirm.ask user to input his choice.
		 *@return return user's choice(Y/N/��).
		 */
		System.out.println("請確認新配分");
		for(int i=0;i<5;i++)
		{
			System.out.println(markwords[i] + weight_temp[i] + "%");
		}
		System.out.println("以上正確嗎? Y (Yes) 或 N (No)");
		String confirm = input.next();
		return confirm;
	}
	private void inputWeight()
	{
		/**
		 *get new weight and judge whether it is effective. 
		 */
		for(int i =0;i<5;i++) { 
			System.out.print(markwords[i]);
			is_int();
			weight_temp[i]= num ;
		}
		if(weight_temp[0]+weight_temp[1]+weight_temp[2]+weight_temp[3]+weight_temp[4]!=100){
			System.out.println("Weigths setting error!");
			inputWeight();
		}
	}
	private void confirmWeight()
	{
		/**
		 * let user confirm new weight��
		 */
		String confirm = showNewWeight();
		if("Y".equals(confirm)){
			for(int i=0;i<5;i++) { weight[i] = weight_temp[i]; } 
			}
		else if("N".equals(confirm)) { updateWeight(); }
		else{
			System.out.println("Please input Y or N!");
			confirmWeight();
		}
	}
	public void updateWeight()
	{
		/**
		 * show origin weight, deal with new weight and confirm.
		 */
        showWeight();
	    inputWeight();
	    confirmWeight();
	}
	
	public synchronized static void StoreStuInfo(Vector<String> info){
		number = info.size();
		loadstudentfile = new Grades[number];
		for(int i = 0 ; i< info.size() ; i++){
				try{
					loadstudentfile[i] = new Grades(info.elementAt(i));
				}
				catch(Exception ex){
					System.out.println(ex);
				}
			}			
	}
	
	private synchronized void LoadStudentInfo(){
		/**
		 * load students' information from student file.
		 */
		if(isload) return;
		FileManager fin = new FileManager(studentfile);
		Thread input = new Thread(fin);
		input.start();
		try  
        {  
			input.join();  
        }  
        catch (InterruptedException ex)  
        {  
            ex.printStackTrace();  
        }  
		isload = true;
	}
}
