/*
 * LoadRunner Java script. (Build: _build_number_)
 * 
 * Script Description: 
 *                     
 */

import lrapi.lr;
import java.sql.*;

public class Actions
{

	// Create global connection variable
	private Connection connection;

	public int init() throws ClassNotFoundException, SQLException {

  		try {
    		// Load Oracle JDBC Driver
    		Class.forName("oracle.jdbc.driver.OracleDriver");
  		} catch (Exception ex) {
    		// If driver load is unsuccessful
    		lr.log_message("Database Driver not found");
    		lr.abort();
  		}
  		try {
    		// Specify the JDBC Connection String (jdbc:oracle:thin:@HOST:PORT:SID)
    		String url = "jdbc:oracle:thin:@192.168.14.53:1522:orcl";
    		// Connect to URL using USERNAME and PASSWORD
    		connection = DriverManager.getConnection(url,"c##x5",lr.decrypt("c##x5"));
    		lr.log_message("JDBC Connection Successful");
  		} catch (SQLException e) {
    		// If Connection Failed
    		lr.log_message("Database Connection Failed, Please check your connection string");
    		lr.abort();
  		}
  		return 0;
	} //end of init


	public int action() throws ClassNotFoundException, SQLException {

		lr.start_transaction("UC02_CS01_Insert");
		database_query("INSERT INTO Task t1(t1.id, "+  
                    "t1.change_id, "+
                    "t1.ticket_id, "+
                    "t1.guid, "+
                    "t1.header, "+
                    "t1.text, "+
                    "t1.priority_id, "+
                    "t1.weight, "+
                    "t1.state_id, "+
                    "t1.client_id, "+
                    "t1.solution_user_id, "+
                    "t1.solution_group_id, "+
                    "t1.create_date, "+
                    "t1.finish_working_date, "+
                    "t1.sync_mask, "+
                    "t1.last_edit_date, "+
                    "t1.last_edit_user_login, "+
                    "t1.engineer_id, "+
                    "t1.contractor_id, "+
                    "t1.specialist_date, "+
                    "t1.external_id, "+
                    "t1.external_system) "+
             "SELECT t2.id, "+
                    "'IDC2D620524153zdzPWAoX9OFgW4UB', "+
                    "t2.id, "+
                    "'d830c5ee-9b77-4bd1-879a-0c4d2c282a67', "+
                    "t2.header, "+
                    "t2.text, "+
                    "'3', "+
                    "t2.weight_id, "+
                    "'1', "+
                    "t2.applicant_id, "+
                    "t2.solution_user_id, "+
                    "'9', "+
                    "t2.create_date, "+
                    "t2.finish_date, "+
                    "t2.sync_mask, "+
                    "t2.last_edit_date, "+
                    "t2.last_edit_user_login, "+
                    "'103', "+
                    "'102', "+
                    "t2.specialist_date, "+
                    "'TSK_1800000', "+
                    "t2.external_system "+
			"FROM Ticket t2 "+
			"WHERE t2.text LIKE 'DTelekhin%' "+
			"AND t2.state_id = -1");
		lr.end_transaction("UC02_CS01_Insert", lr.AUTO);

		lr.start_transaction("UC02_CS02_Update");
		database_query("UPDATE Ticket SET state_id = 1 WHERE state_id = -1 AND TEXT LIKE 'DTelekhin%'");
		lr.end_transaction("UC02_CS02_Update", lr.AUTO);

		lr.start_transaction("UC02_CS03_Commite");
		database_query("COMMIT");
		lr.end_transaction("UC02_CS03_Commite", lr.AUTO);
		
		return 0;
	}//end of action

	
	public int end() throws Throwable {
		connection.close();
		return 0;
	}//end of end
	
    public int database_query(String SQL_QUERY) {
       Statement stmt = null;
       ResultSet rset = null;

       try {
	   connection.setAutoCommit(false);
	   stmt = connection.createStatement();
	   rset = stmt.executeQuery(SQL_QUERY);
	   lr.set_transaction_status(lr.PASS);
	   rset.close();
	} catch (SQLException e) {
	    // SQL Query has failed
	    lr.log_message("Caught Exception: " + e.getMessage());
	    lr.set_transaction_status(lr.FAIL);
	    return 1;
	}
	return 0;
    }
}
