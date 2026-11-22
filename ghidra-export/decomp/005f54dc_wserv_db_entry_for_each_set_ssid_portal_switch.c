// func wserv_db_entry_for_each_set_ssid_portal_switch @ 005f54dc size=1

undefined4 wserv_db_entry_for_each_set_ssid_portal_switch(char param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  for (iVar1 = FUN_004081b0(&g_wserv_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
    iVar2 = DAT_007cbefc + *(int *)(iVar1 + 0x90) * 0x21c;
    if (*(char *)(iVar2 + 0x137) != param_1) {
      uVar3 = 1;
      *(char *)(iVar2 + 0x137) = param_1;
    }
  }
  FUN_00407f30(DAT_007cbef0);
  return uVar3;
}

