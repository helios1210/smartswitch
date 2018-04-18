#ifndef _HTTPCONFIG_H
#define _HTTPCONFIG_H
#include "stm32f10x.h"
#include "string.h"

uint8_t http1[154]=
"HTTP/1.1 200 OK\r\n"
"Server: Apache-Coyote/1.1\r\n"
"Set-Cookie: JSESSIONID=C97E2B4C55553EAB46079A4F263435A4; Path=/hello\r\n"
"Date: Wed, 25 Sep 2012 04:15:03 GMT\r\n"
"\r\n";

uint8_t http2[40]=
"Content-Type: text/html;charset=UTF-8\r\n";
uint8_t http3[39]=
"Content-Type: text/css;charset=UTF-8\r\n";
uint8_t http4[22]=
"Content-Length: 900\r\n";

uint8_t http5[292]=
"<!DOCTYPE html>\r\n"
"<html>\r\n"
  "<head>\r\n"
    "<link href=\"styles.css\" rel=\"stylesheet\">\r\n"
	"<title>SmartSwitch *^_^*!</title>\r\n"
  "</head>\r\n"
  "<body>\r\n"
	"<div id=\"tit\">\r\n"
	"<img src=\"switch3.png\" id=\"im1\">SmartSwitch\r\n"
	"</div>\r\n"
	"<div class=\"swit\">\r\n"
	  "Control this switch\r\n"
	  "<hr size=0.5/>\r\n"
	  "<form action=\"x.asp\" method=\"post\">\r\n";
	
	uint8_t http6[69]=
		"<input type=\"checkbox\" name=\"s1\" value=\"on\" checked=\"ture\">Switch1\r\n";
		
	uint8_t http7[90]=	
		"<br/><hr size=0.5/>\r\n"
		"<input type=\"checkbox\" name=\"s2\" value=\"on\" checked=\"ture\">Switch2\r\n";
		
	uint8_t http8[54]=
	  "<input type=\"checkbox\" name=\"s1\" value=\"on\">Switch1\r\n";
		
	uint8_t http9[75]=
	  "<br/><hr size=0.5/>\r\n"
		"<input type=\"checkbox\" name=\"s2\" value=\"on\">Switch2\r\n";
		
	uint8_t http10[431]=
		"<br/><hr size=0.5/>SetRange:\r\n"
		"<input type=\"range\" value=80 name=\"range1\" max=\"100\" min=\"0\" step=\"1\">\r\n"
		"<br/><hr size=0.5 />\r\n"
		"<input type=\"submit\" value=\"Submit\">\r\n"
	  "</form>\r\n"
	"</div>\r\n"
	"<div class=\"swit\">\r\n"
	  "Some massage here\r\n"
	  "<p>*Temp:19°Ê</p>\r\n"
	  "<p>*Wetness:25%</p>\r\n"
	 " <p>*</p>\r\n"
	 " <p>*</p>\r\n"
	  "<p>*</p>\r\n"
	"</div>\r\n"
	"<div id=\"last\">\r\n"
	  "<p>power by ∑…—Ô’Ω∂”\r\n"
		"<a href=\"https://github.com/helios1210/smartswitch\">about</a></p>\r\n"
	"</div>\r\n"
	
  "</body>\r\n"
  "</html>\r\n";

uint8_t http11[523]=
"body\r\n"
 "{\r\n"
   "zoom:3.5;\r\n"
   "padding:0px;\r\n"
   "margin:0px;\r\n"
   "background-color:#f4f4f8;\r\n"
   "font-family:monospace;\r\n"
   "font-size:11px;\r\n"
 "}\r\n"


 "#tit{\r\n"
   "height:40px;\r\n"
   "background-color:#303540;\r\n"
   "color:#fff;\r\n"
  "font-size:16px;\r\n"
  "text-align:center;\r\n"
   "line-height:40px;\r\n"
 
 "}\r\n"

 "#im1{\r\n"
   "margin-top:8px;\r\n"
   "width:30px;\r\n"
   "float:right;\r\n"
 "}\r\n"

 ".swit{\r\n"
  "margin-left:15px;\r\n"
  "margin-right:15px;\r\n"
  "margin-top:10px;\r\n"
  "padding:10px;\r\n"
  "border-radius:4px;\r\n"
  "border: 0.8px solid #aaaaaa;\r\n"
  "background-color:#ffffff;\r\n"
  "}\r\n"
 
  "#last{\r\n"
    "margin-top:10px;\r\n"
    "padding:5px;\r\n"
    "background-color:#dddfdf;\r\n"
 "}\r\n";

#endif