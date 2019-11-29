Logout()
{
	lr_start_transaction("UC01_CI011_Logout");

	web_url("logout", 
		"URL=http://{Host_Name}:{Port}/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("sessionExpired=false; DOMAIN={Host_Name}");

	web_revert_auto_header("X-Requested-With");

	web_url("login_3", 
		"URL=http://{Host_Name}:{Port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Host_Name}:{Port}/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_CI011_Logout",LR_AUTO);
	
	return 0;
}
