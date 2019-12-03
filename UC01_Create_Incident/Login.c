Login()
{
	lr_start_transaction("UC01_CI01_Home_Page");

	web_url("login",
		"URL=http://{Host_Name}:{Port}/login",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t1.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("UC01_CI01_Home_Page",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC01_CI02_Login");

	web_submit_data("api/login",
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

	web_url("Host_Name:Port",
		"URL=http://{Host_Name}:{Port}/",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{Host_Name}:{Port}/login",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	web_url("api/checkLogin",
		"URL=http://{Host_Name}:{Port}/api/checkLogin",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t4.inf",
		"Mode=HTML",
		LAST);

	web_url("api/user/info",
		"URL=http://{Host_Name}:{Port}/api/user/info",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t5.inf",
		"Mode=HTML",
		LAST);

	web_url("api/ticket/countByState/4",
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/4",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t6.inf",
		"Mode=HTML",
		LAST);

	web_url("api/ticket/countByState",
		"URL=http://{Host_Name}:{Port}/api/ticket/countByState/",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=http://{Host_Name}:{Port}/",
		"Snapshot=t7.inf",
		"Mode=HTML",
		LAST);

	web_custom_request("api/ticket", 
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

	lr_end_transaction("UC01_CI02_Login",LR_AUTO);

	return 0;
}
