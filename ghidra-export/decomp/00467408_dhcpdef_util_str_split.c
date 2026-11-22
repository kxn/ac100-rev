// func dhcpdef_util_str_split @ 00467408 size=240

int dhcpdef_util_str_split(char *param_1,char *param_2,undefined4 *param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0;
  pcVar1 = strtok(param_1,param_2);
  puVar4 = param_3;
  if (pcVar1 == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    do {
      if (param_4 <= iVar3) {
        iVar2 = iVar3 << 2;
        goto LAB_00467478;
      }
      *puVar4 = pcVar1;
      pcVar1 = strtok((char *)0x0,param_2);
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (pcVar1 != (char *)0x0);
    iVar2 = iVar3 * 4;
  }
LAB_00467478:
  *(undefined4 *)((int)param_3 + iVar2) = 0;
  if (((iVar3 == 0) && (g_dhcpdef_warn != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("\x1b[33;49m[%s]<%s():%d> dhcpdef_util_str_split() return 0, p_ap_str: %s!\x1b[0m\r\n",
           "dhcp_defend","dhcpdef_util_str_split",0x15a,param_1);
  }
  return iVar3;
}

