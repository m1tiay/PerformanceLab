Logout()
{
	lr_start_transaction("Logout");

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("api/logout", 
		"URL=http://{Host_Name}:{Port}/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t29.inf", 
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
            "api/logout", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/logout", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	web_url("/login_3", 
		"URL=http://{Host_Name}:{Port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);
	
	return 0;
}
