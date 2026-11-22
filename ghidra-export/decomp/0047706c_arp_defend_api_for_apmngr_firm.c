// func arp_defend_api_for_apmngr_firm @ 0047706c size=184

undefined4 arp_defend_api_for_apmngr_firm(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  uVar2 = 0;
  memset(auStack_2e8,0,0x2d8);
  if (*(uint *)(param_1 + 0xc) < 3) {
    uVar2 = 0xffffffff;
    iVar1 = arp_defend_db_ap_firm(*(undefined2 *)(param_1 + 0x10));
    if ((iVar1 == 0) &&
       (((iVar1 = *(int *)(param_1 + 0x14), iVar1 == 4 || (iVar1 == 8)) || (uVar2 = 0, iVar1 == 6)))
       ) {
      uVar2 = 0xffffffff;
      iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x18),auStack_2e8);
      if (((iVar1 == 0) &&
          (iVar1 = arp_defend_db_ap_inherit(local_2d8,*(undefined2 *)(param_1 + 0x10),param_1),
          iVar1 == 0)) &&
         (iVar1 = arp_defend_db_ap_update(*(undefined2 *)(param_1 + 0x10)), iVar1 == 0)) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

