// func dhcpdef_db_apbind_entry_get_first_id @ 0046eb7c size=312

undefined4 dhcpdef_db_apbind_entry_get_first_id(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = 0;
  FUN_004082d0(DAT_00767094,0xffffffff);
  do {
    while( true ) {
      uVar1 = dhcpdef_db_get_max_ap();
      if (uVar1 <= uVar6) {
        FUN_00407f30(DAT_00767094);
        return 0xffffffff;
      }
      iVar7 = uVar6 * 0x11;
      iVar5 = *(int *)(DAT_007670a8 + iVar7);
      if (-1 < iVar5) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        if (iVar5 < iVar2 + iVar3) goto LAB_0046ec54;
      }
      iVar5 = *(int *)(DAT_007670a8 + iVar7);
      if (49999 < iVar5) break;
      uVar6 = uVar6 + 1;
    }
    iVar2 = apmngr_db_get_sensor_max();
    uVar6 = uVar6 + 1;
  } while (iVar2 + 50000 <= iVar5);
LAB_0046ec54:
  uVar4 = *(undefined4 *)(DAT_007670a8 + iVar7);
  FUN_00407f30(DAT_00767094);
  return uVar4;
}

