Action()
{

	web_url("login", 
		"URL=http://{host_learning2_pflb_ru_56902}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/tpl/login/login.dust", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Light.eot?", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Regular.eot?", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Medium.eot?", ENDITEM, 
		"Url=/images/logo_2.png", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Thin.eot?", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Bold.eot?", ENDITEM, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_start_transaction("1_transaction");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(8);

	web_submit_data("login_2", 
		"Action=http://{host_learning2_pflb_ru_56902}/api/login", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=http://{host_learning2_pflb_ru_56902}/login", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=login", "Value=master", ENDITEM, 
		"Name=password", "Value=123", ENDITEM, 
		"Name=rememberMe", "Value=false", ENDITEM, 
		LAST);

	web_add_cookie("currentCompany=0; DOMAIN=learning2.pflb.ru");

	web_add_cookie("currentUser=master; DOMAIN=learning2.pflb.ru");

	web_add_cookie("PFLB.pre.login.link=null; DOMAIN=learning2.pflb.ru");

	web_add_cookie("filterSetting="
		"%7B%22page%22%3A%22http%3A%2F%2Flearning2.pflb.ru%3A56902%2F%23tickets%3Fstate%3Dopened%26page%3D1%22%2C%22smho%22%3Anull%2C%22dateStart%22%3A%22%22%2C%22dateEnd%22%3A%22%22%2C%22cat1%22%3Anull%2C%22cat2%22%3Anull%2C%22cat3%22%3Anull%2C%22cat4%22%3Anull%2C%22theme%22%3Anull%2C%22engineer%22%3Anull%2C%22location%22%3Anull%2C%22division%22%3Anull%2C%22overdue%22%3Afalse%2C%22filters%22%3A%7B%22newCheckbox%22%3Atrue%2C%22appointedCheckbox%22%3Atrue%2C%22performedCheckbox%22%3Atrue%2C%22controlCheckbo"
		"x%22%3Atrue%7D%7D; DOMAIN=learning2.pflb.ru");

	web_url("learning2.pflb.ru:56902", 
		"URL=http://{host_learning2_pflb_ru_56902}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_learning2_pflb_ru_56902}/login", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/js/core/jqueryformplugin.js?_=1574681863393", ENDITEM, 
		"Url=/engineer/wrapper/wrapper.dust", ENDITEM, 
		"Url=/engineer/wrapper/wrapper.js", ENDITEM, 
		"Url=/css/fonts/material_icons/MaterialIcons-Regular.woff", ENDITEM, 
		"Url=/engineer/tickets/tickets.dust", ENDITEM, 
		"Url=/engineer/tickets/tickets.js", ENDITEM, 
		"Url=/engineer/catalog/catalog.dust", ENDITEM, 
		"Url=/engineer/catalog/catalog.js", ENDITEM, 
		"Url=/images/logo-5ka.png", ENDITEM, 
		"Url=/engineer/addticket.dust", ENDITEM, 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("checkLogin", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("ticket", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("1_transaction",LR_AUTO);

	lr_start_transaction("2_transaction");

	web_add_cookie("SRCHUID=V=2&GUID=681E405CD19640D19DA5D548FA1A419B&dmnchg=1; DOMAIN=ieonline.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=ieonline.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20190723; DOMAIN=ieonline.microsoft.com");

	web_url("children", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://{host_ieonline_microsoft_com}/iedomainsuggestions/ie11/suggestions.ru-RU", "Referer=", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	lr_end_transaction("2_transaction",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("3_transaction");

	web_url("shops", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(7);

	web_url("children_2", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_url("treeview", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/user/catalog/treeview?shopid=5", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_transaction",LR_AUTO);

	lr_start_transaction("4_transaction");

	lr_end_transaction("4_transaction",LR_AUTO);

	lr_start_transaction("5_transaction");

	lr_end_transaction("5_transaction",LR_AUTO);

	lr_start_transaction("6_transaction");

	lr_end_transaction("6_transaction",LR_AUTO);

	lr_start_transaction("7_transaction");

	web_url("children_3", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/user/catalog/node/146/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("service", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/user/catalog/node/146/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("146", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/user/catalog/breadcrumbs/146", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("inventoryNumbers", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/inventoryNumbers?serviceId=2782&shopId=5", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("7_transaction",LR_AUTO);

	lr_think_time(19);

	lr_start_transaction("8_transaction");

	web_url("inventoryNumbers_2", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/inventoryNumbers?serviceId=2786&shopId=5", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("8_transaction",LR_AUTO);

	lr_think_time(4);

	lr_start_transaction("9_transaction");

	web_url("inventoryNumbers_3", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/inventoryNumbers?shopId=5&serviceId=2786&serviceId=2786&q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("9_transaction",LR_AUTO);

	lr_think_time(69);

	lr_start_transaction("10_transaction");

	lr_end_transaction("10_transaction",LR_AUTO);

	lr_start_transaction("11_transaction");

	web_submit_data("file", 
		"Action=http://{host_learning2_pflb_ru_56902}/api/ticket/file/", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=files", "Value=userData.txt", "File=Yes", ENDITEM, 
		LAST);

	lr_end_transaction("11_transaction",LR_AUTO);

	lr_think_time(11);

	lr_start_transaction("12_transaction");

	web_custom_request("ticket_2", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"BodyBinary={\"text\":\"test description\",\"header\":\"\\xD0\\x9F\\xD0\\xBE\\xD1\\x81\\xD0\\xB0\\xD0\\xB4\\xD0\\xBA\\xD0\\xB0 \\xD0\\xBA\\xD1\\x83\\xD1\\x81\\xD1\\x82\\xD0\\xB0\\xD1\\x80\\xD0\\xBD\\xD0\\xB8\\xD0\\xBA\\xD0\\xBE\\xD0\\xB2\",\"ticketStateId\":0,\"serviceId\":\"2786\",\"files\":[4388],\"inventoryNumberId\":\"11\",\"shopId\":\"5\"}", 
		LAST);

	lr_end_transaction("12_transaction",LR_AUTO);

	lr_start_transaction("13_transaction");

	web_revert_auto_header("X-Requested-With");

	lr_think_time(20);

	web_url("learning2.pflb.ru:56902_2", 
		"URL=http://{host_learning2_pflb_ru_56902}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
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
		"URL=http://{host_learning2_pflb_ru_56902}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info_2", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4_2", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_2", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_3", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("ticket_3", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_custom_request("ticket_4", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("13_transaction",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("14_transaction");

	lr_end_transaction("14_transaction",LR_AUTO);

	lr_start_transaction("15_transaction");

	web_url("logout", 
		"URL=http://{host_learning2_pflb_ru_56902}/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("sessionExpired=false; DOMAIN=learning2.pflb.ru");

	web_revert_auto_header("X-Requested-With");

	web_url("login_3", 
		"URL=http://{host_learning2_pflb_ru_56902}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_learning2_pflb_ru_56902}/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("15_transaction",LR_AUTO);

	return 0;
}