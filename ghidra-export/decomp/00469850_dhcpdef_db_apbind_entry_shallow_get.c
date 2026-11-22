// func dhcpdef_db_apbind_entry_shallow_get @ 00469850 size=856

undefined4 dhcpdef_db_apbind_entry_shallow_get(char *param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_2 == (void *)0x0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    param_1 = "entry";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar3 = 0x3d3;
    goto LAB_00469a78;
  }
  if (-1 < (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar1 + iVar2) ||
       ((49999 < (int)param_1 && (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000))
       )) {
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar1 = DAT_007670a8;
      iVar2 = (int)param_1 * 0x11;
      if (49999 < (int)param_1) {
        iVar2 = apmngr_db_get_ap_max();
        iVar4 = apmngr_db_get_template_max();
        iVar2 = (int)(param_1 + iVar4 + iVar2 + -50000) * 0x11;
      }
      iVar4 = DAT_007670a8;
      if (*(int *)(iVar1 + iVar2) < 0) {
LAB_00469950:
        iVar1 = DAT_007670a8;
        iVar2 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar2 = (int)(param_1 + iVar4 + iVar2 + -50000) * 0x11;
        }
        iVar4 = DAT_007670a8;
        if (49999 < *(int *)(iVar1 + iVar2)) {
          iVar1 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
          }
          iVar2 = *(int *)(iVar4 + iVar1);
          iVar1 = apmngr_db_get_sensor_max();
          if (iVar2 < iVar1 + 50000) goto LAB_004699c8;
        }
        uVar3 = 0xffffffff;
        if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n","dhcp_defend",
                 "dhcpdef_db_apbind_entry_shallow_get",0x3d7,param_1);
        }
      }
      else {
        iVar1 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
        }
        iVar4 = *(int *)(iVar4 + iVar1);
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        if (iVar1 + iVar2 <= iVar4) goto LAB_00469950;
LAB_004699c8:
        iVar1 = DAT_007670a8;
        uVar5 = *(undefined4 *)((int)param_2 + 0xd);
        iVar2 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar2 = (int)(param_1 + iVar4 + iVar2 + -50000) * 0x11;
        }
        memcpy(param_2,(void *)(iVar1 + iVar2),0x11);
        uVar3 = 0;
        *(undefined4 *)((int)param_2 + 0xd) = uVar5;
      }
      FUN_00407f30(DAT_00767094);
      return uVar3;
    }
  }
  if (g_dhcpdef_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  __format = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
  uVar3 = 0x3d4;
LAB_00469a78:
  printf(__format,"dhcp_defend","dhcpdef_db_apbind_entry_shallow_get",uVar3,param_1);
  return 0xffffffff;
}

