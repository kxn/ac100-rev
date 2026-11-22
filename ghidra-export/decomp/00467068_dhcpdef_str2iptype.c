// func dhcpdef_str2iptype @ 00467068 size=80

undefined4 dhcpdef_str2iptype(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = strchr(param_1,0x2e);
  uVar2 = 0;
  if (pcVar1 == (char *)0x0) {
    pcVar1 = strchr(param_1,0x3a);
    uVar2 = 2;
    if (pcVar1 == (char *)0x0) {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

