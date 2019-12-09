Action_UC01()
{
	lr_start_transaction("UC01_CI01_New_Incident");

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/user/catalog/node/0/children", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t9.inf", 
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
            "/api/user/catalog/node/0/children", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/user/catalog/node/0/children/", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("UC01_CI01_New_Incident",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI02_Location");

	web_reg_save_param_regexp (
    	"ParamName=shopid",
    	"RegExp=\"id\":(.+?),\"location\"",
    	"Ordinal=All",
		LAST );
	
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/shops", 
		"URL=http://{Host_Name}:{Port}/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t10.inf", 
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
            "/api/shops", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/shops?q=&page=0", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/user/catalog/node/0/children_2", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t11.inf", 
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
            "/api/user/catalog/node/0/children_2", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/user/catalog/node/0/children/", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_save_string(lr_paramarr_random("shopid"), "shopid_rand");
		
	web_reg_save_param_regexp (
    	"ParamName=parentid",
    	"RegExp=\"parentId\":(.+?),\"parentName\"",
    	"Ordinal=All",
		LAST );
	
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/user/catalog/treeview", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/treeview?shopid={shopid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t12.inf", 
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
            "/api/user/catalog/treeview", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/user/catalog/treeview?shopid={shopid_rand}", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("UC01_CI02_Location",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_save_string(lr_paramarr_random("parentid"), "parentid_rand");
	
	lr_start_transaction("UC01_CI03_Theme");

	web_url("/api/user/catalog", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/{parentid_rand}/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
		
	web_reg_save_param_regexp (
    	"ParamName=serviceid",
    	"RegExp=\"id\":(.+?),\"name\"",
    	"Ordinal=All",
		LAST );
				
	web_reg_save_param_regexp (
    	"ParamName=servicename",
    	"RegExp=\"name\":\"(.+?)\",\"parentId\"",
    	"Ordinal=All",
		LAST );
		
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/user/catalog_2", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/{parentid_rand}/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t14.inf", 
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
            "/api/user/catalog_2", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/user/catalog/node/{parentid_rand}/service/", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/user/catalog/breadcrumbs", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/breadcrumbs/{parentid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t15.inf", 
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
            "/api/user/catalog/breadcrumbs", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/user/catalog/breadcrumbs/{parentid_rand}", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_save_string(lr_paramarr_random("serviceid"), "serviceid_rand");
	
	lr_save_string(lr_paramarr_random("servicename"), "servicename_rand");
	
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/inventoryNumber", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?serviceId={serviceid_rand}&shopid={shopid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t16.inf", 
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
            "/api/inventoryNumber", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/inventoryNumbers?serviceId={serviceid_rand}&shopid={shopid_rand}", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("UC01_CI03_Theme",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI04_Change_Theme");

	lr_save_string(lr_paramarr_random("serviceid"), "serviceid_rand");
	
	web_url("/api/inventoryNumber_2", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?serviceId={serviceid_rand}&shopid={shopid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_CI04_Change_Theme",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI05_Inventory");
		
	web_reg_save_param_regexp (
    	"ParamName=inventoryid",
    	"RegExp=\"id\":(.+?),\"number\"",
    	"Ordinal=All",
    	"NotFound=warning",
		LAST );
	
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/inventoryNumber_3", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?shopid={shopid_rand}&" 
		"serviceId={serviceid_rand}&serviceId={serviceid_rand}&q=&page=0",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t18.inf", 
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
            "/api/inventoryNumber_3", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/inventoryNumbers?shopid={shopid_rand}&", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	if (atoi(lr_eval_string("{inventoryid_count}")) > 0)	{
		lr_save_string(lr_paramarr_random("inventoryid"), "inventoryid_rand");
	} else {
		lr_save_string("", "inventoryid_rand");
	}
	
	lr_end_transaction("UC01_CI05_Inventory",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI06_Create_inc_and_add_description");

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_custom_request("/api/ticket_2", 
		"URL=http://{Host_Name}:{Port}/api/ticket/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"BodyBinary={\"text\":\"DTelekhin {Description}\"," 
		"\"header\":\"{servicename_rand}\"," 
		"\"ticketStateId\":0," 
		"\"serviceId\":\"{serviceid_rand}\"," 
		"\"inventoryNumberId\":\"{inventoryid_rand}\"," 
		"\"shopId\":\"{shopid_rand}\"}",
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
            "/api/ticket_2", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/ticket/", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("UC01_CI06_Create_inc_and_add_description",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI07_Confirm");

	web_url("/_2", 
		"URL=http://{Host_Name}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/checkLogin_2", 
		"URL=http://{Host_Name}:{Port}/api/checkLogin", 
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
            "/api/checkLogin_2", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/checkLogin", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_url("/api/user/info_2", 
		"URL=http://{Host_Name}:{Port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t23.inf", 
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
            "/api/user/info_2", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/user/info", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	web_url("/api/ticket/countByState_3", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState_4", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState_5", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_custom_request("/api/ticket_3", 
		"URL=http://{Host_Name}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t27.inf", 
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
            "/api/ticket_3", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	before_bytes = web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	before_sentBytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	web_custom_request("/api/ticket_4", 
		"URL=http://{Host_Name}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t28.inf", 
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
            "/api/ticket_4", responseCode, success, responseTime, submit_bytes, submit_sentBytes,"http://{Host_Name}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", lr_eval_string("{timeStamp}"));
	
    lr_save_string(resultParam, "resultBody");
    
    web_custom_request("/write",
                       "Method=POST",
                       "URL=http://{Unflux_Host}:{Unflux_Port}/write?db={Unflux_DB}",
                       "Body={resultBody}",
                       LAST);
    
	lr_end_transaction("UC01_CI07_Confirm",LR_AUTO);

	lr_think_time(ThinkTime);

	return 0;
}