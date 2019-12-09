Login()
{
	lr_start_transaction("Home_Page");

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/login",
		"URL=http://{Host_Name}:{Port}/login",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t1.inf",
		"Mode=HTML",
		LAST);

    responseCode = web_get_int_property(HTTP_INFO_RETURN_CODE);
    
    if (responseCode >= 200 || responseCode <= 300) {
    	success = "true";
    } else {
    	success = "false";
    }
    
    responseTime = web_get_int_property(HTTP_INFO_DOWNLOAD_TIME);
    after_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
    submit_bytes = after_bytes - before_bytes; 
    after_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
    submit_sentBytes = after_sentBytes - before_sentBytes; 
    lr_save_timestamp("timeStamp", "DIGITS=16", LAST);
    
    sprintf(resultParam,
            "loadrunner,label=%s,responseCode=%d,success=%s responseTime=%d,bytes=%d,sentBytes=%d,URL=\"%s\" %s000",
            "/login", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/login", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("Home_Page",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("Login");

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_submit_data("/api/login",
		"Action=http://{Host_Name}:{Port}/api/login",
		"Method=POST",
		"TargetFrame=",
		"Referer=http://{Host_Name}:{Port}/login",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=login", "Value={Username}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=rememberMe", "Value={RememberMe}", ENDITEM,
		LAST);

    responseCode = web_get_int_property(HTTP_INFO_RETURN_CODE);
    
    if (responseCode >= 200 || responseCode <= 300) {
    	success = "true";
    } else {
    	success = "false";
    }
    
    responseTime = web_get_int_property(HTTP_INFO_DOWNLOAD_TIME);
    after_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
    submit_bytes = after_bytes - before_bytes; 
    after_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
    submit_sentBytes = after_sentBytes - before_sentBytes; 
    lr_save_timestamp("timeStamp", "DIGITS=16", LAST);
    
    sprintf(resultParam,
            "loadrunner,label=%s,responseCode=%d,success=%s responseTime=%d,bytes=%d,sentBytes=%d,URL=\"%s\" %s000",
            "/api/login", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/login", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	web_url("/",
		"URL=http://{Host_Name}:{Port}/",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{Host_Name}:{Port}/login",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	web_url("/api/checkLogin",
		"URL=http://{Host_Name}:{Port}/api/checkLogin",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t4.inf",
		"Mode=HTML",
		LAST);

	web_url("/api/user/info",
		"URL=http://{Host_Name}:{Port}/api/user/info",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t5.inf",
		"Mode=HTML",
		LAST);

	web_url("/api/ticket/countByState",
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/4",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t6.inf",
		"Mode=HTML",
		LAST);

	web_url("/api/ticket/countByState_2",
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t7.inf",
		"Mode=HTML",
		LAST);

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_custom_request("/api/ticket", 
		"URL=http://{Host_Name}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t8.inf",
		"Mode=HTML",
		"EncType=application/json; charset=utf-8",
		LAST);

    responseCode = web_get_int_property(HTTP_INFO_RETURN_CODE);
    
    if (responseCode >= 200 || responseCode <= 300) {
    	success = "true";
    } else {
    	success = "false";
    }
    
    responseTime = web_get_int_property(HTTP_INFO_DOWNLOAD_TIME);
    after_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
    submit_bytes = after_bytes - before_bytes; 
    after_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
    submit_sentBytes = after_sentBytes - before_sentBytes; 
    lr_save_timestamp("timeStamp", "DIGITS=16", LAST);
    
    sprintf(resultParam,
            "loadrunner,label=%s,responseCode=%d,success=%s responseTime=%d,bytes=%d,sentBytes=%d,URL=\"%s\" %s000",
            "/api/ticket", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("Login",LR_AUTO);
	
	lr_think_time(ThinkTime);

	return 0;
}
