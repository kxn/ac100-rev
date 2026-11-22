// func uac_ipaddr_ip_str_type @ 0051ad10 size=104

undefined4 uac_ipaddr_ip_str_type(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = strchr(param_1,0x2e);
  uVar2 = 1;
  if (pcVar1 == (char *)0x0) {
    pcVar1 = strchr(param_1,0x3a);
    uVar2 = 2;
    if (pcVar1 == (char *)0x0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

