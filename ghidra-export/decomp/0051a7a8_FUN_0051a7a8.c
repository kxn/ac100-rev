// func FUN_0051a7a8 @ 0051a7a8 size=8

undefined4 FUN_0051a7a8(char *param_1,undefined1 *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == (char *)0x0) || (param_2 == (undefined1 *)0x0)) {
    uVar3 = 0xffffffff;
    if (uac_ip_err_switch != 0) {
      printf("[UAC_IP_ERROR]%s()/line %d : Invalid params.\n","uac_ipaddr_convert_str2binary",0x44);
    }
  }
  else {
    uVar3 = 0xffffffff;
    memset(param_2,0,0x14);
    if (*param_1 != '\0') {
      pcVar1 = strchr(param_1,0x2e);
      if (pcVar1 == (char *)0x0) {
        pcVar1 = strchr(param_1,0x3a);
        if ((pcVar1 != (char *)0x0) && (iVar2 = inet_pton(10,param_1,param_2 + 4), 0 < iVar2)) {
          uVar3 = 0;
          *param_2 = 2;
        }
      }
      else {
        iVar2 = inet_pton(2,param_1,param_2 + 4);
        if (0 < iVar2) {
          uVar3 = 0;
          *param_2 = 1;
        }
      }
    }
  }
  return uVar3;
}

