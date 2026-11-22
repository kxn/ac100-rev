// func dhcpdef_db_apbind_entry_get_all_ids @ 0046e938 size=580

undefined4 dhcpdef_db_apbind_entry_get_all_ids(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  if ((g_dhcpdef_info != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_apbind_entry_get_all_ids",0x2c0
           ,"dhcpdef_db_apbind_entry_get_all_ids");
  }
  if (param_1 == 0) {
    uVar4 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_apbind_entry_get_all_ids",0x2c1,"aps");
    }
  }
  else {
    iVar5 = 0;
    uVar7 = 0;
    FUN_004082d0(DAT_00767094,0xffffffff);
    while (uVar1 = dhcpdef_db_get_max_ap(), uVar7 < uVar1) {
      if (param_2 <= iVar5) {
        if ((g_dhcpdef_warn != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          printf("\x1b[33;49m[%s]<%s():%d> count[%d] reach ap_num[%d]\x1b[0m\r\n","dhcp_defend",
                 "dhcpdef_db_apbind_entry_get_all_ids",0x2c9,iVar5,param_2);
        }
        break;
      }
      iVar8 = uVar7 * 0x11;
      iVar6 = *(int *)(DAT_007670a8 + iVar8);
      if (iVar6 < 0) {
LAB_0046ea2c:
        iVar6 = *(int *)(DAT_007670a8 + iVar8);
        if (iVar6 < 50000) {
          uVar7 = uVar7 + 1;
        }
        else {
          iVar2 = apmngr_db_get_sensor_max();
          if (iVar6 < iVar2 + 50000) goto LAB_0046ea04;
          uVar7 = uVar7 + 1;
        }
      }
      else {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        if (iVar2 + iVar3 <= iVar6) goto LAB_0046ea2c;
LAB_0046ea04:
        iVar6 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        *(undefined4 *)(param_1 + iVar6) = *(undefined4 *)(DAT_007670a8 + iVar8);
        uVar7 = uVar7 + 1;
      }
    }
    uVar4 = 0;
    FUN_00407f30(DAT_00767094);
  }
  return uVar4;
}

