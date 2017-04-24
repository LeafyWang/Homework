 /**

* Read file and save messages.

* @author Encore

* @Time 2016/3/19

*

*/

import java.io.*;

import java.util.*;

public class FileManager implements Runnable{
	
	/**
	 * @uml.property  name="filename"
	 */
	private String filename;                   //name of file.
	
	public FileManager(String filename){
		this.filename = filename;
	}
	
	public void run() {                    
		try{
			File stufile = new File(filename);
			FileReader fin = new FileReader(stufile);
			BufferedReader input = new BufferedReader(fin);
			String temp ="";
			Vector<String> sendmessage = new Vector<String>();
			while( (temp = input.readLine()) != null){
				sendmessage.add(temp);			
			}
			GradeSystems.StoreStuInfo(sendmessage);
			input.close();
		}
		catch(IOException ex){
			System.out.println(ex);
		}		
	}
	
	
}
