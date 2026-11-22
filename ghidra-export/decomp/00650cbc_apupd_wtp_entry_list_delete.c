// func apupd_wtp_entry_list_delete @ 00650cbc size=628

void apupd_wtp_entry_list_delete(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_188 [64];
  char acStack_148 [128];
  undefined1 auStack_c8 [160];
  
  while (iVar1 = FUN_004081b0(param_1 + 0x7f4), iVar1 != 0) {
    FUN_00408500(iVar1);
    iVar2 = *(int *)(iVar1 + 0x48);
    if ((((iVar2 - 6U < 2) || (iVar2 == 0x13)) || (iVar2 == 0x14)) ||
       ((iVar2 == 0x15 || (iVar2 == 0x16)))) {
      apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
      uVar5 = 0x3811;
      memset(acStack_148,0,0x80);
      sprintf(acStack_148,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar1 + 0x2e),
              (uint)*(byte *)(iVar1 + 0x2f),(uint)*(byte *)(iVar1 + 0x30),
              (uint)*(byte *)(iVar1 + 0x31),(uint)*(byte *)(iVar1 + 0x32),
              (uint)*(byte *)(iVar1 + 0x33));
      memset(auStack_188,0,0x40);
      memset(auStack_c8,0,0x9a);
      FUN_00408190(*(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x1c),
                   *(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x24),
                   *(undefined4 *)(iVar1 + 0x28),auStack_188,0x40,"---");
      if (*(int *)(iVar1 + 0x48) != 6) {
        uVar5 = 0x3814;
      }
      uVar3 = apmngr_db_product_type_str(*(undefined1 *)(param_1 + 0x138));
      uVar4 = FUN_006505b0(iVar1 + 0x2e,auStack_c8);
      loggerk_reg(0x54,uVar5,1,uVar3,1,uVar4,1,auStack_188,1,acStack_148,0);
    }
    FUN_00407f40(apupd_wtp_hash,iVar1);
    if (*(int *)(iVar1 + 0x8c) != 0) {
      if (*(int *)(*(int *)(iVar1 + 0x8c) + 4) != 0) {
        FUN_00407df0();
        *(undefined4 *)(*(int *)(iVar1 + 0x8c) + 4) = 0;
        apupd_import_software_num = apupd_import_software_num + -1;
        if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                 "apupd_wtp_entry_list_delete",0x9c2,apupd_import_software_num);
        }
      }
      FUN_00407df0(*(undefined4 *)(iVar1 + 0x8c));
      *(undefined4 *)(iVar1 + 0x8c) = 0;
    }
    FUN_00408500(iVar1 + 0xc);
    FUN_00407df0(iVar1);
  }
  return;
}

