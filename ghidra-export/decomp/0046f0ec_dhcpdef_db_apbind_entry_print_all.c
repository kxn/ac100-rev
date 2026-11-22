// func dhcpdef_db_apbind_entry_print_all @ 0046f0ec size=408

void dhcpdef_db_apbind_entry_print_all(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  FUN_004082d0(DAT_00767094,0xffffffff);
  if (l_dhcpdef_data != 0) {
    iVar7 = 0;
    uVar6 = 0;
    puts("#####################################################################\r");
    printf("l_dhcpdef_data.apbind_used = %d\r\n",DAT_007670a4);
    while (uVar1 = dhcpdef_db_get_max_ap(), uVar6 < uVar1) {
      iVar5 = uVar6 * 0x11;
      iVar4 = *(int *)(DAT_007670a8 + iVar5);
      if (iVar4 < 0) {
LAB_0046f220:
        iVar4 = *(int *)(DAT_007670a8 + iVar5);
        if (iVar4 < 50000) {
          uVar6 = uVar6 + 1;
        }
        else {
          iVar2 = apmngr_db_get_sensor_max();
          if (iVar4 < iVar2 + 50000) goto LAB_0046f1f8;
          uVar6 = uVar6 + 1;
        }
      }
      else {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        if (iVar2 + iVar3 <= iVar4) goto LAB_0046f220;
LAB_0046f1f8:
        _dhcpdef_db_apbind_entry_print(DAT_007670a8 + iVar5);
        iVar7 = iVar7 + *(int *)(DAT_007670a8 + iVar5 + 9);
        uVar6 = uVar6 + 1;
      }
    }
    puts("#####################################################################\r");
    printf("Total number of bindings: %d\r\n",iVar7);
    puts("#####################################################################\r");
  }
  FUN_00407f30(DAT_00767094);
  return;
}

