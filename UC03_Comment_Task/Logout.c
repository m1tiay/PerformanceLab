Logout()
{
	lr_start_transaction("UC03_CT06_Logout");

	web_url("logout", 
		"URL=http://{Host_Name}:{Port}/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_url("login_3", 
		"URL=http://{Host_Name}:{Port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC03_CT06_Logout",LR_AUTO);
	
	return 0;
}
