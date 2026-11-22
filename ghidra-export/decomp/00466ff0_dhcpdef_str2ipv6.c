// func dhcpdef_str2ipv6 @ 00466ff0 size=120

void dhcpdef_str2ipv6(char *param_1,void *param_2)

{
  undefined1 auStack_18 [16];
  
  if ((param_1 == (char *)0x0) || (param_2 == (void *)0x0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","dhcpdef_str2ipv6",0xeb,"strIp && intIp");
  }
  else {
    inet_pton(10,param_1,auStack_18);
    memcpy(param_2,auStack_18,0x10);
  }
  return;
}

