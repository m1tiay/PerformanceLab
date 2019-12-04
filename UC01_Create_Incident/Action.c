Action()
{
	lr_start_transaction("UC01_CI03_New_Incident");

	web_url("api/user/catalog/node/0/children", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_CI03_New_Incident",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI04_Location");

	
	web_reg_save_param_regexp (
    	"ParamName=shopid",
    	"RegExp=\"id\":(.+?),\"location\"",
    	"Ordinal=All",
		LAST );
	
	web_url("api/shops", 
		"URL=http://{Host_Name}:{Port}/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(ThinkTime);

	web_url("api/user/catalog/node/0/children_2", 
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
	
	web_url("api/user/catalog/treeview", 
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

	web_url("api/user/catalog", 
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
		
	web_url("api/user/catalog_2", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/node/{parentid_rand}/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/user/catalog/breadcrumbs", 
		"URL=http://{Host_Name}:{Port}/api/user/catalog/breadcrumbs/{parentid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_save_string(lr_paramarr_random("serviceid"), "serviceid_rand");
	
	lr_save_string(lr_paramarr_random("servicename"), "servicename_rand");
	
	web_url("api/inventoryNumber", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?serviceId={serviceid_rand}&shopid={shopid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_CI05_Theme",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI06_Change_Theme");

	lr_save_string(lr_paramarr_random("serviceid"), "serviceid_rand");
	
	web_url("api/inventoryNumber_2", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?serviceId={serviceid_rand}&shopid={shopid_rand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_CI06_Change_Theme",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI07_Inventory");
		
	web_reg_save_param_regexp (
    	"ParamName=inventoryid",
    	"RegExp=\"id\":(.+?),\"number\"",
    	"Ordinal=All",
    	"NotFound=warning",
		LAST );
	
	web_url("api/inventoryNumber_3", 
		"URL=http://{Host_Name}:{Port}/api/inventoryNumbers?shopid={shopid_rand}&" 
		"serviceId={serviceid_rand}&serviceId={serviceid_rand}&q=&page=0",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{inventoryid_count}")) > 0)	{
		lr_save_string(lr_paramarr_random("inventoryid"), "inventoryid_rand");
	} else {
		lr_save_string("", "inventoryid_rand");
	}
	
	lr_end_transaction("UC01_CI07_Inventory",LR_AUTO);

	lr_think_time(ThinkTime);

	lr_start_transaction("UC01_CI08_Create_inc_and_add_description");

	web_custom_request("api/ticket_2", 
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

	lr_end_transaction("UC01_CI08_Create_inc_and_add_description",LR_AUTO);

	lr_start_transaction("UC01_CI09_Confirm");

	lr_think_time(ThinkTime);

	web_url("Url_2", 
		"URL=http://{Host_Name}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/checkLogin_2", 
		"URL=http://{Host_Name}:{Port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/user/info_2", 
		"URL=http://{Host_Name}:{Port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/ticket/countByState_3", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/ticket/countByState_4", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("api/ticket/countByState_5", 
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("api/ticket_3", 
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

	web_custom_request("api/ticket_4", 
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

	lr_end_transaction("UC01_CI09_Confirm",LR_AUTO);

	lr_think_time(ThinkTime);

	return 0;
}