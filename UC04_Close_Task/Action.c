Action()
{

	lr_start_transaction("UC04_CT03_Select_Tasks");

	web_url("api/task/countByState", 
		"URL=http://{Host_Name}:{Port}/api/task/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param_regexp (
    	"ParamName=taskid",
    	"RegExp=,\"parentId\":(.+?),\"externalId\"",
    	"Ordinal=All",
		LAST );
		
	web_custom_request("api/task", 
		"URL=http://{Host_Name}:{Port}/api/task/?state=1&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC04_CT03_Select_Tasks",LR_AUTO);

	lr_start_transaction("UC04_CT04_Choose_Task");

	lr_save_string(lr_paramarr_random("taskid"), "taskid_rand");
	
	web_url("api/task_2", 
		"URL=http://{Host_Name}:{Port}/api/task/{taskid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/ticket", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC04_CT04_Choose_Task",LR_AUTO);

	lr_start_transaction("UC04_CT05_To_the_Incident");

	web_custom_request("api/ticket_2", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/ticket_3", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC04_CT05_To_the_Incident",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC04_CT06_Close_Incident");

	web_custom_request("solve", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/solve/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_url("{Host_Name}:{Port}_2", 
		"URL=http://{Host_Name}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/user/info_2", 
		"URL=http://{Host_Name}:{Port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/ticket/countByState_3", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/ticket/countByState_4", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/ticket/countByState_5", 
		"URL=http://{Host_Name}:{Port}/api/task/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("api/ticket_4", 
		"URL=http://{Host_Name}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_custom_request("api/task_3", 
		"URL=http://{Host_Name}:{Port}/api/task/?state=1&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC04_CT06_Close_Incident",LR_AUTO);

	return 0;
}