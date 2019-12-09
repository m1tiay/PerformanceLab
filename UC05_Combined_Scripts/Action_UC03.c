Action_UC03()
{

	lr_start_transaction("UC03_CT01_Select_Tasks");

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/task/countByState_3", 
		"URL=http://{Host_Name}:{Port}/api/task/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t22.inf", 
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
            "/api/task/countByState_3", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/task/countByState/", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	web_reg_save_param_regexp (
    	"ParamName=taskid",
    	"RegExp=,\"parentId\":(.+?),\"externalId\"",
    	"Ordinal=All",
		LAST );
		
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_custom_request("/api/task", 
		"URL=http://{Host_Name}:{Port}/api/task/?state=1&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t23.inf", 
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
            "/api/task", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/task/?state=1&page=0&size=10", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("UC03_CT01_Select_Tasks",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC03_CT02_Choose_Task");

	lr_save_string(lr_paramarr_random("taskid"), "taskid_rand");
	
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/task", 
		"URL=http://{Host_Name}:{Port}/api/task/{taskid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t24.inf", 
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
            "/api/task", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/task/{taskid_rand}", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	web_url("/api/checkLogin_2", 
		"URL=http://{Host_Name}:{Port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/ticket_2", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t26.inf", 
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
            "/api/ticket_2", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("UC03_CT02_Choose_Task",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC03_CT03_Comment_and_Send");

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_custom_request("/api/ticket_3", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"text\":\"DTelekhin {Comment}\"}", 
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
            "/api/ticket_3", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/ticket_4", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
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
            "/api/ticket_4", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("UC03_CT03_Comment_and_Send",LR_AUTO);

	lr_think_time(ThinkTime);

	return 0;
}