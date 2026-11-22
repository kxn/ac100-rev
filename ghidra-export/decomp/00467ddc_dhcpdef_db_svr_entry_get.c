// func dhcpdef_db_svr_entry_get @ 00467ddc size=428

undefined4 dhcpdef_db_svr_entry_get(char *param_1,void *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 *__src;
  undefined4 uVar3;
  
  if (param_2 == (void *)0x0) {
    if (g_dhcpdef_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      param_1 = "entry";
      pcVar2 = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
      uVar3 = 0x216;
      goto LAB_00467ee0;
    }
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < l_dhcpdef_profile)) {
      FUN_004082d0(DAT_00767094,0xffffffff);
      __src = (undefined4 *)(DAT_007670a0 + (int)param_1 * 0xac);
      pcVar2 = (char *)*__src;
      if (((int)pcVar2 < 0) || (l_dhcpdef_profile <= pcVar2)) {
        uVar3 = 0xffffffff;
        if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("\x1b[31;49m[%s]<%s():%d> svr_id[%d] is not used!\x1b[0m\r\n","dhcp_defend",
                 "dhcpdef_db_svr_entry_get",0x21a,param_1);
        }
      }
      else {
        memcpy(param_2,__src,0xac);
        uVar3 = 0;
      }
      FUN_00407f30(DAT_00767094);
      return uVar3;
    }
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar2 = "\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n";
      uVar3 = 0x217;
LAB_00467ee0:
      printf(pcVar2,"dhcp_defend","dhcpdef_db_svr_entry_get",uVar3,param_1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

