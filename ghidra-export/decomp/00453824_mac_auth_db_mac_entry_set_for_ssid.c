// func mac_auth_db_mac_entry_set_for_ssid @ 00453824 size=1

undefined4 mac_auth_db_mac_entry_set_for_ssid(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (param_1 == (uint *)0x0) {
    if (macauth_err_switch != 0) {
      pcVar3 = "[MACAUTH_ERROR]%s()/%d Invalid mac entry.\n";
      uVar6 = 0x52a;
code_r0x00453954:
      printf(pcVar3,"mac_auth_db_mac_entry_set_for_ssid",uVar6);
      return 0xffffffff;
    }
  }
  else {
    uVar5 = *param_1;
    if (((int)uVar5 < 0) || (g_mac_auth_profile <= uVar5)) {
      if (macauth_err_switch != 0) {
        printf("[MACAUTH_ERROR]%s()/%d Invalid mac entry id[%d].\n",
               "mac_auth_db_mac_entry_set_for_ssid",0x530);
        return 0xffffffff;
      }
    }
    else {
      if (*(int *)(DAT_00767020 + uVar5 * 0xa8) != -1) {
        FUN_004082d0(DAT_00766ff4,0xffffffff);
        puVar1 = (uint *)FUN_00407fa0(DAT_00767008,param_1 + 0x28);
        if ((puVar1 == (uint *)0x0) || (*puVar1 == *param_1)) {
          memcpy((void *)(DAT_00767020 + *param_1 * 0xa8 + 4),param_1 + 1,0x9c);
          uVar6 = 0;
          iVar7 = DAT_00767020 + *param_1 * 0xa8;
          iVar2 = memcmp((void *)(iVar7 + 0xa0),param_1 + 0x28,6);
          if (iVar2 != 0) {
            iVar2 = FUN_00407f40(DAT_00767008,iVar7);
            if (iVar2 == 0) {
              memcpy((void *)(DAT_00767020 + *param_1 * 0xa8 + 0xa0),param_1 + 0x28,6);
              iVar2 = FUN_00408380(DAT_00767008,DAT_00767020 + *param_1 * 0xa8);
              if ((iVar2 == 0) || (uVar6 = 0xffffffff, macauth_err_switch == 0))
              goto code_r0x00453904;
              pcVar3 = 
              "[MACAUTH_ERROR]%s()/%d mac address of mac id(%d) changed, uac_hash_add() failed.\n";
              uVar4 = 0x54d;
            }
            else {
              uVar6 = 0xffffffff;
              if (macauth_err_switch == 0) goto code_r0x00453904;
              pcVar3 = 
              "[MACAUTH_ERROR]%s()/%d mac address of mac id(%d) changed, uac_hash_remove() failed.\n"
              ;
              uVar4 = 0x547;
            }
            uVar6 = 0xffffffff;
            printf(pcVar3,"mac_auth_db_mac_entry_set_for_ssid",uVar4,*param_1);
          }
        }
        else {
          uVar6 = 0xfffffffe;
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d duplicate mac address.\n",
                   "mac_auth_db_mac_entry_set_for_ssid",0x53e);
          }
        }
code_r0x00453904:
        FUN_00407f30(DAT_00766ff4);
        return uVar6;
      }
      if (macauth_err_switch != 0) {
        pcVar3 = "[MACAUTH_ERROR]%s()/%d mac entry is not used.\n";
        uVar6 = 0x536;
        goto code_r0x00453954;
      }
    }
  }
  return 0xffffffff;
}

