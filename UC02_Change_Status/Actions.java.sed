import lrapi.lr;
import java.sql.*;

public class Actions{
	public int init() {

  		try {
    		Class.forName("oracle.jdbc.driver.OracleDriver");
  		} catch (ClassNotFoundException ex) {
    		lr.log_message("Database Driver not found");
    		lr.abort();
  		}
  		
  		return 0;
	}


	public int action() {

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

		return 0;
	}

	
	public int end() {
		return 0;
	}
	
    public int database_query(String SQL_QUERY) {
       String url = "jdbc:oracle:thin:@{Host_Name}:{Port}:orcl";

       try (Connection connection = DriverManager.getConnection(url, "{Login}", "{Password}"); 
            Statement statement = connection.createStatement()) {
            	lr.log_message("JDBC Connection Successful");
            	connection.setAutoCommit(false);
            	
            	try {
            		statement.executeQuery(SQL_QUERY);
	   				lr.log_message("SQL Query Executed Successfully");
	   				connection.commit();
            	} catch (SQLException e) {
            		lr.log_message("Caught Exception: " + e.getMessage());
            		connection.rollback();
	    			lr.log_message("Rollback complete");
            	}
				lr.log_message("Commit complete");
            } catch (SQLException e) {
            	lr.log_message("Caught Exception: " + e.getMessage());
	    		lr.set_transaction_status(lr.STOP);
	    		return 1;
            }
	return 0;
    }
}
