Action()
{

	lr_start_transaction("UC03_CT03_Select_Tasks");

	web_url("countByState_2", 
		"URL=http://{Host_Name}:{Port}/api/task/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_regexp (
    	"ParamName=taskid",
    	"RegExp=,\"parentId\":(.+?),\"externalId\"",
    	"Ordinal=All",
		LAST );
		
	web_custom_request("task", 
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

	lr_end_transaction("UC03_CT03_Select_Tasks",LR_AUTO);

	lr_start_transaction("UC03_CT04_Choose_Task");

	lr_save_string(lr_paramarr_random("taskid"), "taskid_rand");
	
	web_url("taskid", 
		"URL=http://{Host_Name}:{Port}/api/task/{taskid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("checkLogin_2", 
		"URL=http://{Host_Name}:{Port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("comment", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC03_CT04_Choose_Task",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC03_CT05_Comment_and_Send");

	web_custom_request("comment_2", 
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

	web_url("comment_3", 
		"URL=http://{Host_Name}:{Port}/api/ticket/{taskid_rand}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC03_CT05_Comment_and_Send",LR_AUTO);

	lr_think_time(5);

	return 0;
}