import lrapi.lr;
import java.sql.*;

public class Actions{	   
    
	public int init() {
  		try {
    		Class.forName("oracle.jdbc.driver.OracleDriver");
  		} catch (Exception ex) {
    		lr.log_message("Database Driver not found");
    		lr.abort();
  		}
		
  	return 0;
	}

	public int action() {
		String url = "jdbc:oracle:thin:@" + lr.eval_string("{Host_Name}") + ":" + lr.eval_string("{Port}") + ":" + lr.eval_string("{DB_Name}") + "";
		
		try (Connection connection = DriverManager.getConnection(url, lr.eval_string("{Username}"), lr.eval_string("{Password}"));
		     Statement statement = connection.createStatement()) {
			lr.log_message("JDBC Connection Successful");
			connection.setAutoCommit(false);
				
			try {
				lr.start_transaction("UC02_CS01_Update");
				String updateExSys = "UPDATE Ticket SET external_system = 'ASKO' WHERE external_system NOT LIKE 'ASKO'";
				database_query(statement, updateExSys);
				lr.end_transaction("UC02_CS01_Update", lr.AUTO);
			
				lr.start_transaction("UC02_CS02_Insert");
				String insertToTask = "INSERT INTO Task t1(t1.id, " +
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
					"t1.external_system) " +
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
				"WHERE t2.state_id = -1";
				database_query(statement, insertToTask);
				lr.end_transaction("UC02_CS02_Insert", lr.AUTO);

				lr.start_transaction("UC02_CS03_Update");
				String updateTicket = "UPDATE Ticket SET state_id = 1 WHERE state_id = -1";
				database_query(statement, updateTicket);
				lr.end_transaction("UC02_CS03_Update", lr.AUTO);
			
				connection.commit();
				lr.log_message("Commit complete");
		
			} catch (SQLException e) {
				lr.log_message("Caught Exception: " + e.getMessage());
				try {
					connection.rollback();
					lr.log_message("Rollback complete");
				} catch (SQLException ex) {
					ex.printStackTrace();
				}
			}
		} catch (SQLException ex) {
			ex.printStackTrace();
		}
		return 0;
    } 
	
	public int end() {
		return 0;
	}
	
	public int database_query(Statement statement, String SQL_QUERY) throws SQLException {

                statement.executeQuery(SQL_QUERY);


        return 0;
    }
}
