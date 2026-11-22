// func _uac_dhcpdef_cap_change_cb @ 00463600 size=168

undefined4 _uac_dhcpdef_cap_change_cb(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  memset(auStack_2e8,0,0x2d8);
  iVar2 = *(int *)(param_2 + 0x14);
  if (((iVar2 == 4) || (iVar2 == 8)) || (uVar3 = 0, iVar2 == 6)) {
    uVar3 = 0;
    if (*(short *)(param_2 + 0x18) != -1) {
      iVar2 = apmngr_db_entry_get_by_id(*(short *)(param_2 + 0x18),auStack_2e8);
      uVar3 = 0xffffffff;
      if (iVar2 == 0) {
        uVar1 = *(undefined2 *)(param_2 + 0x10);
        iVar2 = dhcpdef_db_apbind_entry_inherit(local_2d8,uVar1);
        if ((iVar2 == 0) && (iVar2 = dhcpdef_db_apbind_entry_firm_update(uVar1), iVar2 == 0)) {
          uVar3 = 0;
        }
      }
    }
  }
  return uVar3;
}

