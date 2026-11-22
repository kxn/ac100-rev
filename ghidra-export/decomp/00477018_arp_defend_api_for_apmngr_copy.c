// func arp_defend_api_for_apmngr_copy @ 00477018 size=84

undefined4 arp_defend_api_for_apmngr_copy(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  iVar1 = arp_defend_db_ap_inherit
                    (*(undefined2 *)(param_2 + 0x10),*(undefined2 *)(param_1 + 0x10),param_1);
  if ((iVar1 == 0) && (iVar1 = arp_defend_db_ap_update(*(undefined2 *)(param_1 + 0x10)), iVar1 == 0)
     ) {
    uVar2 = 0;
  }
  return uVar2;
}

