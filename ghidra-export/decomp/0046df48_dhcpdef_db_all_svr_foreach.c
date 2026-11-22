// func dhcpdef_db_all_svr_foreach @ 0046df48 size=708

undefined4 dhcpdef_db_all_svr_foreach(code *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if ((g_dhcpdef_info != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_all_svr_foreach",0x6c3,
           "dhcpdef_db_all_svr_foreach");
  }
  if (param_1 == (code *)0x0) {
    uVar6 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_all_svr_foreach",0x6c4,&DAT_0068df1c);
    }
  }
  else {
    FUN_0051ad88(&local_38);
    uVar5 = 0;
    FUN_004082d0(DAT_00767094,0xffffffff);
    while (uVar6 = 0, uVar5 < l_dhcpdef_profile) {
      iVar7 = uVar5 * 0xac;
      uVar1 = *(uint *)(DAT_007670a0 + iVar7);
      if (((int)uVar1 < 0) || (l_dhcpdef_profile <= uVar1)) {
        uVar5 = uVar5 + 1;
      }
      else {
        iVar2 = FUN_004082a0(1,0xb8,0x6d1);
        if (iVar2 == 0) {
          uVar6 = 0xffffffff;
          if ((g_dhcpdef_error != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
            printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                   "dhcpdef_db_all_svr_foreach",0x6d4);
          }
          break;
        }
        uVar5 = uVar5 + 1;
        memcpy((void *)(iVar2 + 0xc),(void *)(DAT_007670a0 + iVar7),0xac);
        FUN_004086b0(&local_38,iVar2);
      }
    }
    FUN_00407f30(DAT_00767094);
    iVar2 = FUN_004081b0(&local_38);
    iVar7 = 0;
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      (*param_1)(iVar7,iVar2 + 0xc,param_2);
      if ((g_dhcpdef_info != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[%s]<%s():%d> cursor: %d\r\n","dhcp_defend","dhcpdef_db_all_svr_foreach",0x6eb,
               iVar7 + 1);
      }
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
      iVar7 = iVar7 + 1;
      iVar2 = iVar3;
    }
  }
  return uVar6;
}

