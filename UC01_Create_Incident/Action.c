Action()
{
	lr_start_transaction("UC01_CI03_New_Incident");

	web_url("children", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	lr_end_transaction("UC01_CI03_New_Incident",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC01_CI04_Location");

	
	web_reg_save_param_regexp (
    	"ParamName=shopid",
    	"RegExp=\"id\":(.+?),\"location\"",
    	"Ordinal=All",
		LAST );
	
	web_url("shops", 
		"URL=http://{Host_Name}:{Port}/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("children_2", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_save_string(lr_paramarr_random("shopid"), "shopid_rand");
		
	web_reg_save_param_regexp (
    	"ParamName=parentid",
    	"RegExp=\"parentId\":(.+?),\"parentName\"",
    	"Ordinal=All",
		LAST );
	
	web_url("treeview", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/treeview?shopid={shopid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_CI04_Location",LR_AUTO);

	lr_save_string(lr_paramarr_random("parentid"), "parentid_rand");
	
	lr_start_transaction("UC01_CI05_Theme");

	web_url("children_3", 
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
	
	web_url("service", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/{parentid_rand}/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("{parentid_rand}", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/breadcrumbs/{parentid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_save_string(lr_paramarr_random("serviceid"), "serviceid_rand");
	
	web_url("inventoryNumbers", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?serviceId={serviceid_rand}&shopid={shopid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_CI05_Theme",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC01_CI06_Change_Theme");

	lr_save_string(lr_paramarr_random("serviceid"), "serviceid_rand");
	
	web_url("inventoryNumbers_2", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?serviceId={serviceid_rand}&shopid={shopid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_CI06_Change_Theme",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC01_CI07_Inventory");
		
	web_reg_save_param_regexp (
    	"ParamName=inventoryid",
    	"RegExp=\"id\":(.+?),\"number\"",
    	"Ordinal=All",
    	"NotFound=warning",
		LAST );
	
	web_url("inventoryNumbers_3", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?shopid={shopid_rand}&serviceId={serviceid_rand}&serviceId={serviceid_rand}&q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{inventoryid_count}"))>0)
	{
		lr_save_string(lr_paramarr_random("inventoryid"), "inventoryid_rand");
	}
	
	else
	{
		lr_save_string("", "inventoryid_rand");
	}
	
	lr_end_transaction("UC01_CI07_Inventory",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC01_CI08_Add_File");

	web_reg_save_param_regexp (
    	"ParamName=filesid",
    	"RegExp=\"id\":(.+?),\"name\"",
    	"Ordinal=1",
		LAST );
	
	web_submit_data("file", 
		"Action=http://{Host_Name}:{Port}/api/ticket/file/", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=files", "Value=userData.txt", "File=Yes", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_CI08_Add_File",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC01_CI09_Create_inc_and_add_description");

	web_custom_request("ticket_2", 
		"URL=http://{Host_Name}:{Port}/api/ticket/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"BodyBinary={\"text\":\"DTelekhin {Description}\",\"header\":\"\\xD0\\x9F\\xD0\\xBE\\xD1\\x81\\xD0\\xB0\\xD0\\xB4\\xD0\\xBA\\xD0\\xB0 \\xD0\\xBA\\xD1\\x83\\xD1\\x81\\xD1\\x82\\xD0\\xB0\\xD1\\x80\\xD0\\xBD\\xD0\\xB8\\xD0\\xBA\\xD0\\xBE\\xD0\\xB2\",\"ticketStateId\":0,\"serviceId\":\"{serviceid_rand}\",\"files\":[{filesid}],\"inventoryNumberId\":\"{inventoryid_rand}\",\"shopId\":\"{shopid_rand}\"}", 
		LAST);

	lr_end_transaction("UC01_CI09_Create_inc_and_add_description",LR_AUTO);

	lr_start_transaction("UC01_CI010_Confirm");

	web_revert_auto_header("X-Requested-With");

	lr_think_time(5);

	web_url("{Host_Name}:{Port}_2", 
		"URL=http://{Host_Name}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/js/core/jqueryformplugin.js?_=1574682076792", ENDITEM, 
		"Url=/engineer/wrapper/wrapper.dust", ENDITEM, 
		"Url=/engineer/wrapper/wrapper.js", ENDITEM, 
		"Url=/engineer/tickets/tickets.dust", ENDITEM, 
		"Url=/engineer/tickets/tickets.js", ENDITEM, 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("checkLogin_2", 
		"URL=http://{Host_Name}:{Port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info_2", 
		"URL=http://{Host_Name}:{Port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4_2", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_2", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_3", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("ticket_3", 
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

	web_custom_request("ticket_4", 
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

	lr_end_transaction("UC01_CI010_Confirm",LR_AUTO);

	lr_think_time(5);

	return 0;
}