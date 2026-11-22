// func arp_defend_db_apbind_entry_get_all_ids @ 0047c5a4 size=472

undefined4 arp_defend_db_apbind_entry_get_all_ids(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if (param_1 == 0) {
    uVar5 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n","arp_defend_db_apbind_entry_get_all_ids",
             0x686);
    }
  }
  else {
    iVar6 = 0;
    iVar7 = 0;
    FUN_004082d0(DAT_007670f8,0xffffffff);
    while( true ) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      if (iVar1 + iVar2 <= iVar7) break;
      if (param_2 <= iVar6) {
        uVar5 = 0;
        if ((arp_defend_debug_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
          printf("[ARP_DEFEND_DEBUG]%s()/%d count[%d] reach ap_num[%d]\n",
                 "arp_defend_db_apbind_entry_get_all_ids",0x690,iVar6,param_2);
        }
        goto LAB_0047c700;
      }
      iVar1 = iVar7 * 0x10;
      iVar2 = *(int *)(DAT_00767104 + iVar1);
      if (iVar2 < 0) {
LAB_0047c688:
        iVar2 = *(int *)(DAT_00767104 + iVar1);
        if (iVar2 < 50000) {
          iVar7 = iVar7 + 1;
        }
        else {
          iVar3 = apmngr_db_get_sensor_max();
          if (iVar2 < iVar3 + 50000) goto LAB_0047c664;
          iVar7 = iVar7 + 1;
        }
      }
      else {
        iVar3 = apmngr_db_get_ap_max();
        iVar4 = apmngr_db_get_template_max();
        if (iVar3 + iVar4 <= iVar2) goto LAB_0047c688;
LAB_0047c664:
        iVar2 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        *(undefined4 *)(param_1 + iVar2) = *(undefined4 *)(DAT_00767104 + iVar1);
        iVar7 = iVar7 + 1;
      }
    }
    uVar5 = 0;
  }
LAB_0047c700:
  FUN_00407f30(DAT_007670f8);
  return uVar5;
}

