// func arp_defend_api_for_apmngr_cap_change @ 00476f70 size=168

undefined4 arp_defend_api_for_apmngr_cap_change(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = *(int *)(param_2 + 0x14);
  if (((iVar1 == 4) || (iVar1 == 8)) || (uVar2 = 0, iVar1 == 6)) {
    uVar2 = 0;
    if (*(short *)(param_2 + 0x18) != -1) {
      iVar1 = apmngr_db_entry_get_by_id(*(short *)(param_2 + 0x18),auStack_2e8);
      uVar2 = 0xffffffff;
      if (((iVar1 == 0) &&
          (iVar1 = arp_defend_db_ap_inherit(local_2d8,*(undefined2 *)(param_2 + 0x10),param_2),
          iVar1 == 0)) &&
         (iVar1 = arp_defend_db_ap_update(*(undefined2 *)(param_2 + 0x10)), iVar1 == 0)) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

