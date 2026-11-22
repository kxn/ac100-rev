// func dhcpdef_str2addr @ 004670b8 size=252

undefined4 dhcpdef_str2addr(char param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  if ((param_2 == 0) || (param_3 == 0)) {
    uVar2 = 0xffffffff;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","dhcpdef_str2addr",0xfe,"addr_str && intAddr");
  }
  else if (iVar3 == 1) {
    dhcpdef_str2mac(param_2,param_3);
    uVar2 = 0;
  }
  else if (iVar3 == 2) {
    dhcpdef_str2ipv6(param_2);
    uVar2 = 0;
  }
  else if (iVar3 == 0) {
    dhcpdef_str2ipv4(param_2);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Invalid addr_type %d!\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_str2addr",0x10c,iVar3);
    }
  }
  return uVar2;
}

